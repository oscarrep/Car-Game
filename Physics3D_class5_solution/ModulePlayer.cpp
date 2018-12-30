#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"
#include "ModuleSceneIntro.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(3.0f, 1.0f, 6.0f);
	car.chassis_offset.Set(0.0f, 0.7f, 0.0f);
	
	car.cabin_size.Set(2.9f, 1.5f, 3.0f);
	car.cabin_offset.Set(0.0f, 1.2f, -0.5f);

	car.L_light_size.Set(0.4f, 0.2f, 6.05f);
	car.L_light_offset.Set(1.0f, 0.9f, 0.0f);
	
	car.R_light_size.Set(0.4f, 0.2f, 6.05f);
	car.R_light_offset.Set(-1.0f, 0.9f, 0.0f);
	
	car.L_spoiler_foot_size.Set(0.2f, 1.0f, 0.4f);
	car.L_spoiler_foot_offset.Set(-1.0f, 1.3f, -2.7f);

	car.R_spoiler_foot_size.Set(0.2f, 1.0f, 0.4f);
	car.R_spoiler_foot_offset.Set(1.0f, 1.3f, -2.7f);

	car.spoiler_size.Set(3.0f, 0.2f, 1.0f);
	car.spoiler_offset.Set(0.0f, 1.9f, -3.0f);

	car.front_size.Set(3.0f, 0.2f, 1.0f);
	car.front_offset.Set(0.0f, -0.4f, 2.9f);

	car.front2_size.Set(3.0f, 0.5f, 0.2f);
	car.front2_offset.Set(0.0f, 0.0f, 3.0f);

	car.back_size.Set(3.0f, 0.5f, 0.2f);
	car.back_offset.Set(0.0f, 0.0f, -2.9f);

	car.L_size.Set(0.2f, 0.5f, 3.0f);
	car.L_offset.Set(-1.5f, 0.0f, 0.0f);

	car.R_size.Set(0.2f, 0.5f, 3.0f);
	car.R_offset.Set(1.5f, 0.0f, 0.0f);

	car.neon_size.Set(3.2f, 0.1f, 6.1f);
	car.neon_offset.Set(0.0f, -0.25f, 0.0f);

	car.mass = 500.0f;
	car.suspensionStiffness = 15.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.88f;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 50.5;
	car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float wheel_radius = 0.9f;
	float wheel_width = 0.7f;
	float suspensionRestLength = 1.0f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(0, 200, 0);
	
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");
	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	vec3 position = vehicle->GetPos();
	vec3 fvec = vehicle->GetForwardVector();
	// To change relative camera position. {x, z} are in the plane {y} is the vertical dimension
	App->camera->Position.Set(position.x - fvec.x, 20+position.y - fvec.y , -20+position.z - fvec.z);
	App->camera->LookAt(vehicle->GetPos());
	turn = acceleration = brake = 0.0f;

	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		acceleration = MAX_ACCELERATION;
	}

	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		acceleration = -MAX_ACCELERATION;
	}

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		if(turn < TURN_DEGREES)
			turn =  TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		if(turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
	{
		brake = BRAKE_POWER;
	}

	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
	{
	//resets the game
		IdentityMatrix = IDENTITY;
		vehicle->SetTransform(IdentityMatrix.M);
		vehicle->SetPos(startPos.x, startPos.y, startPos.z);
		vehicle->GetBody()->setAngularVelocity({ 0, 0, 0 });
		vehicle->GetBody()->setLinearVelocity({ 0, 0, 0 });
	}
		
	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);
	vehicle->Render();
	pointsp1 = App->scene_intro->points1;
	pointsp2 = App->scene_intro->points2;
	turn_number = App->scene_intro->turn_num;

	if (turn_number < 7) {
		sprintf_s(title, "%.1f Km/h --- Player 1 Points: %i --- Player 2 Points: %i --- Turn: %i ", vehicle->GetKmh(), pointsp1, pointsp2, turn_number);
		App->window->SetTitle(title);
	}

	else if (turn_number  >= 7) {
		if (pointsp1 > pointsp2) {
			sprintf_s(title, "Player 1 Wins! Player 1 Points: %i  --- Player 2 Points: %i - Press R or ESC", pointsp1, pointsp2);
			App->window->SetTitle(title);
		}
		else if (pointsp1 < pointsp2) {
			sprintf_s(title, "Player 2 Wins! Player 2 Points: %i  --- Player 1 Points: %i - Press R or ESC", pointsp2, pointsp1);
			App->window->SetTitle(title);
		}
		else if (pointsp1 == pointsp2) {
			sprintf_s(title, "Draw! Player 1 Points: %i  --- Player 2 Points: %i - Press R or ESC", pointsp1, pointsp2);
			App->window->SetTitle(title);
		}
	}
	
	return UPDATE_CONTINUE;
}

void ModulePlayer::Restart(int turn_num, bool collision) {
	if (turn_num < 6) {
		IdentityMatrix = IDENTITY;
		vehicle->SetTransform(IdentityMatrix.M);
		vehicle->SetPos(startPos.x, startPos.y, startPos.z);
		vehicle->GetBody()->setAngularVelocity({ 0, 0, 0 });
		vehicle->GetBody()->setLinearVelocity({ 0, 0, 0 });
		collision = false;
	}

	if (turn_num >= 6) {
		IdentityMatrix = IDENTITY;
		vehicle->SetTransform(IdentityMatrix.M);
		vehicle->SetPos(50, 1510, 50);
		vehicle->GetBody()->setAngularVelocity({ 0, 0, 0 });
		vehicle->GetBody()->setLinearVelocity({ 0, 0, 0 });
	}

}










