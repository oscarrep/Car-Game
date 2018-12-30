#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "ModulePlayer.h"
#include "math.h"


ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;
	
	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));
	App->audio->PlayMusic("Audio/Bush-Week.ogg");
	crash = App->audio->LoadFx("Audio/Glass_Break.wav");
	LoadFloor();

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");
	
	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	PaintFloor();

	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
	{
		//resets the game
		points1 = 0;
		points2 = 0;
		turn_num = 1;
	}

	return UPDATE_CONTINUE;
}


void ModuleSceneIntro::LoadFloor() {
	//	
	CreateFloor(BaseFloor, vec3(zeros.x, zeros.y, zeros.x), Blue);


	//CreateFloor(DEBUG_FLOOR, vec3(zeros.x, zeros.y, zeros.x - FLOOR.z));
	CreateFloor(BaseFloor, vec3(zeros.x, zeros.y, zeros.x), Green);

	//MAIN RAMP
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 200.0f, zeros.x - FLOOR.z), LightBlue);
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 200.0f, zeros.x), LightBlue);
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 200.0f, zeros.x + FLOOR.z), LightBlue);

	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 199.15f, zeros.x + FLOOR.z * 2 - 0.25f), LightBlue, Xaxis, 10.0f);  //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 196.6f, zeros.x + FLOOR.z * 3 - 0.75f), LightBlue, Xaxis, 20.0f); //ramp

	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 192.95f, zeros.x + FLOOR.z * 4 - 2.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 188.75f, zeros.x + FLOOR.z * 5 - 3.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(RAMP, vec3(zeros.x, zeros.y + 190.75f, zeros.x + FLOOR.z * 5 - 5.0f), LightBlue, Xaxis, 10.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 184.55f, zeros.x + FLOOR.z * 6 - 4.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(OBSTACLE, vec3(zeros.x, zeros.y + 184.55f, zeros.x + FLOOR.z * 6 - 4.0f), Green, Xaxis, 25.0f); //obstacle
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 180.35f, zeros.x + FLOOR.z * 7 - 5.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(OBSTACLE, vec3(zeros.x + 5.0f, zeros.y + 180.35f, zeros.x + FLOOR.z * 7 - 5.0f), Green, Xaxis, 25.0f); //obstacle
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 176.15f, zeros.x + FLOOR.z * 8 - 6.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 171.95f, zeros.x + FLOOR.z * 9 - 7.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 167.75f, zeros.x + FLOOR.z * 10 - 8.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(OBSTACLE, vec3(zeros.x + 15.0f, zeros.y + 167.75f, zeros.x + FLOOR.z * 10 - 8.0f), Green, Xaxis, 25.0f); //obstacle
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 163.55f, zeros.x + FLOOR.z * 11 - 9.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 159.35f, zeros.x + FLOOR.z * 12 - 10.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 155.15f, zeros.x + FLOOR.z * 13 - 11.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(OBSTACLE, vec3(zeros.x - 20.0f, zeros.y + 155.15f, zeros.x + FLOOR.z * 13 - 11.0f), Green, Xaxis, 25.0f); //obstacle
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 150.95f, zeros.x + FLOOR.z * 14 - 12.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(OBSTACLE, vec3(zeros.x - 15.0f, zeros.y + 150.95f, zeros.x + FLOOR.z * 14 - 12.0f), Green, Xaxis, 25.0f); //obstacle
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 146.75f, zeros.x + FLOOR.z * 15 - 13.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 142.55f, zeros.x + FLOOR.z * 16 - 14.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 138.35f, zeros.x + FLOOR.z * 17 - 15.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 134.15f, zeros.x + FLOOR.z * 18 - 16.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(OBSTACLE, vec3(zeros.x + 5.0f, zeros.y + 134.15f, zeros.x + FLOOR.z * 18 - 16.0f), Green, Xaxis, 25.0f); //obstacle
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 129.95f, zeros.x + FLOOR.z * 19 - 17.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 125.75f, zeros.x + FLOOR.z * 20 - 18.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 121.55f, zeros.x + FLOOR.z * 21 - 19.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(OBSTACLE, vec3(zeros.x, zeros.y + 121.55f, zeros.x + FLOOR.z * 21 - 19.0f), Green, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 117.35f, zeros.x + FLOOR.z * 22 - 20.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 113.15f, zeros.x + FLOOR.z * 23 - 21.0f), LightBlue, Xaxis, 25.0f); //ramp////
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 108.95f, zeros.x + FLOOR.z * 24 - 22.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(OBSTACLE, vec3(zeros.x - 15.0f, zeros.y + 108.95f, zeros.x + FLOOR.z * 24 - 22.0f), Green, Xaxis, 25.0f); //ramp
	CreateFloor(OBSTACLE, vec3(zeros.x + 15.0f, zeros.y + 108.95f, zeros.x + FLOOR.z * 24 - 22.0f), Green, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 104.75f, zeros.x + FLOOR.z * 25 - 23.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 100.55f, zeros.x + FLOOR.z * 26 - 24.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 96.35f, zeros.x + FLOOR.z * 27 - 25.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 92.15f, zeros.x + FLOOR.z * 28 - 26.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 87.95f, zeros.x + FLOOR.z * 29 - 27.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 83.75f, zeros.x + FLOOR.z * 30 - 28.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 79.55f, zeros.x + FLOOR.z * 31 - 29.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(OBSTACLE, vec3(zeros.x - 5.0f, zeros.y + 79.55f, zeros.x + FLOOR.z * 31 - 29.0f), Green, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 75.35f, zeros.x + FLOOR.z * 32 - 30.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 71.15f, zeros.x + FLOOR.z * 33 - 31.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 66.95f, zeros.x + FLOOR.z * 34 - 32.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 62.75f, zeros.x + FLOOR.z * 35 - 33.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 58.55f, zeros.x + FLOOR.z * 36 - 34.0f), LightBlue, Xaxis, 25.0f); //ramp//
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 54.35f, zeros.x + FLOOR.z * 37 - 35.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 50.15f, zeros.x + FLOOR.z * 38 - 36.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 45.95f, zeros.x + FLOOR.z * 39 - 37.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 41.75f, zeros.x + FLOOR.z * 40 - 38.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 37.55f, zeros.x + FLOOR.z * 41 - 39.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 33.35f, zeros.x + FLOOR.z * 42 - 40.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 29.15f, zeros.x + FLOOR.z * 43 - 41.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 24.95f, zeros.x + FLOOR.z * 44 - 42.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 20.75f, zeros.x + FLOOR.z * 45 - 43.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 16.55f, zeros.x + FLOOR.z * 46 - 44.0f), LightBlue, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 12.35f, zeros.x + FLOOR.z * 47 - 45.0f), LightBlue, Xaxis, 25.0f); //ramp

	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 8.45f, zeros.x + FLOOR.z * 48 - 45.750f), LightBlue, Xaxis, 20.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 5.75f, zeros.x + FLOOR.z * 49 - 45.75f), LightBlue, Xaxis, 10.0f); //ramp

	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 5.0f, zeros.x + FLOOR.z * 50 - 45.75f), LightBlue);
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 5.0f, zeros.x + FLOOR.z * 51 - 45.75f), LightBlue);
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 5.0f, zeros.x + FLOOR.z * 52 - 45.75f), LightBlue);
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 5.0f, zeros.x + FLOOR.z * 53 - 45.75f), LightBlue);

	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 6.8f, zeros.x + FLOOR.z * 54 - 45.75f), LightBlue, Xaxis, -20.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 10.05f, zeros.x + FLOOR.z * 55 - 46.75f), LightBlue, Xaxis, -20.0f); //ramp


	CreateFloor(Box, vec3(zeros.x + 50.0f, zeros.y, zeros.z), Green);
	CreateFloor(Box, vec3(zeros.x + 25.0f, zeros.y, zeros.z + 25.0f), Green, Yaxis, 90.0f);
	CreateFloor(Box, vec3(zeros.x + 75.0f, zeros.y, zeros.z + 25.0f), Green, Yaxis, 90.0f);
	CreateFloor(Box, vec3(zeros.x + 50.0f, zeros.y, zeros.z + 50.0f), Green);
	CreateFloor(Box, vec3(zeros.x + 50.0f, zeros.y, zeros.z + 25.0f), Green, Xaxis, 90.0f);


	//	CreateFloor(MEDIUM_FLOOR, vec3(zeros.x, zeros.y + 32.65f, zeros.x - FLOOR.z * 4+0.25f), LightBlue);
	//target
	//target floor
	Cube target1 = { 100,2,20 };
	target1.SetPos(zeros.x, zeros.y, zeros.x + TARGET1.z * 46);
	target1_s = App->physics->AddBody(target1, 0.0f);
	target1_s->SetAsSensor(true);
	target1_s->GetTransform(&target1.transform);
	target1_s->collision_listeners.add(this);

	Cube target2 = { 100,2,20 };
	target2.SetPos(zeros.x, zeros.y, zeros.x + TARGET1.z * 47);
	target2_s = App->physics->AddBody(target2, 0.0f);
	target2_s->SetAsSensor(true);
	target2_s->GetTransform(&target2.transform);
	target2_s->collision_listeners.add(this);

	Cube target3 = { 100,2,20 };
	target3.SetPos(zeros.x, zeros.y, zeros.x + TARGET1.z * 48);
	target3_s = App->physics->AddBody(target3, 0.0f);
	target3_s->SetAsSensor(true);
	target3_s->GetTransform(&target3.transform);
	target3_s->collision_listeners.add(this);

	Cube target4 = { 100,2,20 };
	target4.SetPos(zeros.x, zeros.y, zeros.x + TARGET1.z * 49);
	target4_s = App->physics->AddBody(target4, 0.0f);
	target4_s->SetAsSensor(true);
	target4_s->GetTransform(&target4.transform);
	target4_s->collision_listeners.add(this);

	Cube target5 = { 100,2,20 };
	target5.SetPos(zeros.x, zeros.y, zeros.x + TARGET1.z * 50);
	target5_s = App->physics->AddBody(target5, 0.0f);
	target5_s->SetAsSensor(true);
	target5_s->GetTransform(&target5.transform);
	target5_s->collision_listeners.add(this);

	CreateFloor(TARGET1, vec3(zeros.x, zeros.y, zeros.x + TARGET1.z * 46), Red);
	CreateFloor(TARGET2, vec3(zeros.x, zeros.y, zeros.x + TARGET2.z * 47), Blue);
	CreateFloor(TARGET3, vec3(zeros.x, zeros.y, zeros.x + TARGET3.z * 48), Green);
	CreateFloor(TARGET4, vec3(zeros.x, zeros.y, zeros.x + TARGET4.z * 49), Yellow);
	CreateFloor(TARGET5, vec3(zeros.x, zeros.y, zeros.x + TARGET5.z * 50), DarkGrey);

	//	CreateFloor(MEDIUM_FLOOR, vec3(zeros.x, zeros.y + 32.65f, zeros.x - FLOOR.z * 4+0.25f), LightBlue);


}

void ModuleSceneIntro::PaintFloor() {

	p2List_item<Cube>* cube = cubes.getFirst();

	while (cube != nullptr) {
		cube->data.Render();
		cube = cube->next;
	}
}


void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
			if ((body2 == target1_s && body1 == (PhysBody3D*)App->player->vehicle) || ((body1 == target1_s && body2 == (PhysBody3D*)App->player->vehicle))) {
				if (turn_num % 2 != 0) {
					points1 += 3;
					collision = true;
					App->audio->PlayFx(crash);
					App->player->Restart(turn_num,collision);
				}
				else {
					points2 += 3;
					collision = true;
					App->audio->PlayFx(crash);
					App->player->Restart(turn_num, collision);
				}
				turn_num++;
			}
			if ((body2 == target2_s && body1 == (PhysBody3D*)App->player->vehicle) || ((body1 == target2_s && body2 == (PhysBody3D*)App->player->vehicle))) {
				if (turn_num % 2 != 0) {
					points1 += 2;
					collision = true;
					App->audio->PlayFx(crash);
					App->player->Restart(turn_num, collision);
				}
				else {
					points2 += 2;
					collision = true;
					App->audio->PlayFx(crash);
					App->player->Restart(turn_num, collision);
				}
				turn_num++;
			}
			if ((body2 == target3_s && body1 == (PhysBody3D*)App->player->vehicle) || ((body1 == target3_s && body2 == (PhysBody3D*)App->player->vehicle))) {
				if (turn_num % 2 != 0) {
					points1 += 1;
					collision = true;
					App->audio->PlayFx(crash);
					App->player->Restart(turn_num, collision);
				}
				else {
					points2 += 1;
					collision = true;
					App->audio->PlayFx(crash);
					App->player->Restart(turn_num, collision);
				}
				turn_num++;
			}
			if ((body2 == target4_s && body1 == (PhysBody3D*)App->player->vehicle) || ((body1 == target4_s && body2 == (PhysBody3D*)App->player->vehicle))) {
				if (turn_num % 2 != 0) {
					points1 += 2;
					collision = true;
					App->audio->PlayFx(crash);
					App->player->Restart(turn_num, collision);
				}
				else {
					points2 += 2;
					collision = true;
					App->audio->PlayFx(crash);
					App->player->Restart(turn_num, collision);
				}
				turn_num++;
			}
			if ((body2 == target5_s && body1 == (PhysBody3D*)App->player->vehicle) || ((body1 == target5_s && body2 == (PhysBody3D*)App->player->vehicle))) {
				if (turn_num % 2 != 0) {
					points1 += 3;
					collision = true;
					App->audio->PlayFx(crash);
					App->player->Restart(turn_num, collision);
				}
				else {
					points2 += 3;
					collision = true;
					App->audio->PlayFx(crash);
					App->player->Restart(turn_num, collision);
				}
				turn_num++;
			}
			if ((body2 == floor_s && body1 == (PhysBody3D*)App->player->vehicle) || ((body1 == floor_s && body2 == (PhysBody3D*)App->player->vehicle))) {
				if (turn_num % 2 != 0) {
					points1 -= 1;
					collision = true;
					App->audio->PlayFx(crash);
					App->player->Restart(turn_num, collision);
				}
				else {
					points2 -= 1;
					collision = true;
					App->audio->PlayFx(crash);
					App->player->Restart(turn_num, collision);
				}
				turn_num++;
			}
	
	//tunrs 1 3 and 5 are for player 1, 2,4 and 6 for player 2
}

void ModuleSceneIntro::CreateFloor(vec3 dim, vec3 pos, Color color,  vec3 u, float angle, float mass)
{
	Cube cube(dim.x, dim.y, dim.z);
	cube.SetPos(pos.x, pos.y, pos.z);
	cube.color = color;

	if (angle != 0)
		cube.SetRotation(angle, vec3(u.x, u.y, u.z));


	App->physics->AddBody(cube, mass);

	cubes.add(cube);
	
}