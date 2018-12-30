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

	return UPDATE_CONTINUE;
}


void ModuleSceneIntro::LoadFloor() {
//	
	CreateFloor(Floor, vec3(zeros.x, zeros.y, zeros.x), Black);

	//ramp
	CreateFloor(DEBUG_FLOOR, vec3(zeros.x, zeros.y, zeros.x - FLOOR.z));
	CreateFloor(Floor, vec3(zeros.x, zeros.y, zeros.x), Green);

	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 100.0f, zeros.x - FLOOR.z), White);
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 100.0f, zeros.x), White);
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 100.0f, zeros.x + FLOOR.z), White);

	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 99.15f, zeros.x + FLOOR.z * 2 - 0.25f), White, Xaxis, 10.0f);  //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 96.6f, zeros.x + FLOOR.z * 3 - 0.75f), White, Xaxis, 20.0f); //ramp

	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 92.95f, zeros.x + FLOOR.z * 4 - 2.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 88.75f, zeros.x + FLOOR.z * 5 - 3.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 84.55f, zeros.x + FLOOR.z * 6 - 4.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(OBSTACLE, vec3(zeros.x, zeros.y + 84.55f, zeros.x + FLOOR.z * 6 - 4.0f), Red, Xaxis, 25.0f); //obstacle
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 80.35f, zeros.x + FLOOR.z * 7 - 5.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(OBSTACLE, vec3(zeros.x + 5.0f, zeros.y + 80.35f, zeros.x + FLOOR.z * 7 - 5.0f), Red, Xaxis, 25.0f); //obstacle
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 76.15f, zeros.x + FLOOR.z * 8 - 6.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 71.95f, zeros.x + FLOOR.z * 9 - 7.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 67.75f, zeros.x + FLOOR.z * 10 - 8.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(OBSTACLE, vec3(zeros.x + 15.0f, zeros.y + 67.75f, zeros.x + FLOOR.z * 10 - 8.0f), Red, Xaxis, 25.0f); //obstacle
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 63.55f, zeros.x + FLOOR.z * 11 - 9.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 59.35f, zeros.x + FLOOR.z * 12 - 10.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 55.15f, zeros.x + FLOOR.z * 13 - 11.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(OBSTACLE, vec3(zeros.x - 20.0f, zeros.y + 55.15f, zeros.x + FLOOR.z * 13 - 11.0f), Red, Xaxis, 25.0f); //obstacle
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 50.95f, zeros.x + FLOOR.z * 14 - 12.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(OBSTACLE, vec3(zeros.x - 15.0f, zeros.y + 50.95f, zeros.x + FLOOR.z * 14 - 12.0f), Red, Xaxis, 25.0f); //obstacle
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 46.75f, zeros.x + FLOOR.z * 15 - 13.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 42.55f, zeros.x + FLOOR.z * 16 - 14.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 38.35f, zeros.x + FLOOR.z * 17 - 15.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 34.15f, zeros.x + FLOOR.z * 18 - 16.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(OBSTACLE, vec3(zeros.x, zeros.y + 34.15f, zeros.x + FLOOR.z * 18 - 16.0f), Red, Xaxis, 25.0f); //obstacle
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 29.95f, zeros.x + FLOOR.z * 19 - 17.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 25.75f, zeros.x + FLOOR.z * 20 - 18.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 21.55f, zeros.x + FLOOR.z * 21 - 19.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 17.35f, zeros.x + FLOOR.z * 22 - 20.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 13.15f, zeros.x + FLOOR.z * 23 - 21.0f), White, Xaxis, 25.0f); //ramp

	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 9.0f, zeros.x + FLOOR.z * 24 - 21.25f), White, Xaxis, 20.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 6.35f, zeros.x + FLOOR.z * 25 - 21.75f), White, Xaxis, 10.0f); //ramp

	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 5.55f, zeros.x + FLOOR.z * 26 - 21.75f), White);
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 5.55f, zeros.x + FLOOR.z * 27 - 21.75f), White);
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 5.55f, zeros.x + FLOOR.z * 28 - 21.75f), White);
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 5.55f, zeros.x + FLOOR.z * 29 - 21.75f), White);

	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 7.35f, zeros.x + FLOOR.z * 30 - 21.75f), White, Xaxis, -20.0f); //ramp
	CreateFloor(WIDE_FLOOR, vec3(zeros.x, zeros.y + 10.65f, zeros.x + FLOOR.z * 31 - 22.75f), White, Xaxis, -20.0f); //ramp


//	CreateFloor(MEDIUM_FLOOR, vec3(zeros.x, zeros.y + 32.65f, zeros.x - FLOOR.z * 4+0.25f), White);
	//target
	//target floor
	Cube target1 = { 100,3,20 };
	target1.SetPos(zeros.x, zeros.y, zeros.x + TARGET1.z * 24);
	target1_s = App->physics->AddBody(target1, 0.0f);
	target1_s->SetAsSensor(true);
	target1_s->GetTransform(&target1.transform);
	target1_s->collision_listeners.add(this);

	Cube target2 = { 100,3,20 };
	target2.SetPos(zeros.x, zeros.y, zeros.x + TARGET1.z * 25);
	target2_s = App->physics->AddBody(target1, 0.0f);
	target2_s->SetAsSensor(true);
	target2_s->GetTransform(&target2.transform);
	target2_s->collision_listeners.add(this);

	Cube target3 = { 100,3,20 };
	target3.SetPos(zeros.x, zeros.y, zeros.x + TARGET1.z * 26);
	target3_s = App->physics->AddBody(target1, 0.0f);
	target3_s->SetAsSensor(true);
	target3_s->GetTransform(&target3.transform);
	target3_s->collision_listeners.add(this);

	Cube target4 = { 100,3,20 };
	target4.SetPos(zeros.x, zeros.y, zeros.x + TARGET1.z * 27);
	target4_s = App->physics->AddBody(target1, 0.0f);
	target4_s->SetAsSensor(true);
	target4_s->GetTransform(&target4.transform);
	target4_s->collision_listeners.add(this);

	Cube target5 = { 100,3,20 };
	target5.SetPos(zeros.x, zeros.y, zeros.x + TARGET1.z * 28);
	target5_s = App->physics->AddBody(target1, 0.0f);
	target5_s->SetAsSensor(true);
	target5_s->GetTransform(&target5.transform);
	target5_s->collision_listeners.add(this);

	CreateFloor(TARGET1, vec3(zeros.x, zeros.y, zeros.x + TARGET1.z * 24), Red);
	CreateFloor(TARGET2, vec3(zeros.x, zeros.y, zeros.x + TARGET2.z * 25), Blue);
	CreateFloor(TARGET3, vec3(zeros.x, zeros.y, zeros.x + TARGET3.z * 26), Green);
	CreateFloor(TARGET4, vec3(zeros.x, zeros.y, zeros.x + TARGET4.z * 27), Yellow);
	CreateFloor(TARGET5, vec3(zeros.x, zeros.y, zeros.x + TARGET5.z * 28), DarkGrey);
	
	//Target walls
	CreateFloor(WALL_STR, vec3(zeros.x - 20.0f, zeros.y, zeros.x + WALL_STR.z * 25 - 25.0f), White);
	CreateFloor(WALL_STR, vec3(zeros.x - 20.0f, zeros.y, zeros.x + WALL_STR.z * 26 - 25.0f), White);
	CreateFloor(WALL_STR, vec3(zeros.x - 20.0f, zeros.y, zeros.x + WALL_STR.z * 27 - 25.0f), White);
	CreateFloor(WALL_STR, vec3(zeros.x - 20.0f, zeros.y, zeros.x + WALL_STR.z * 28 - 25.0f), White);
	CreateFloor(WALL_STR, vec3(zeros.x - 20.0f, zeros.y, zeros.x + WALL_STR.z * 29 - 25.0f), White);

	CreateFloor(WALL_STR, vec3(zeros.x - 20.0f, zeros.y, zeros.x + WALL_STR.z * 25 - 25.0f), White);
	CreateFloor(WALL_STR, vec3(zeros.x - 20.0f, zeros.y, zeros.x + WALL_STR.z * 26 - 25.0f), White);
	CreateFloor(WALL_STR, vec3(zeros.x - 20.0f, zeros.y, zeros.x + WALL_STR.z * 27 - 25.0f), White);
	CreateFloor(WALL_STR, vec3(zeros.x - 20.0f, zeros.y, zeros.x + WALL_STR.z * 28 - 25.0f), White);
	CreateFloor(WALL_STR, vec3(zeros.x - 20.0f, zeros.y, zeros.x + WALL_STR.z * 29 - 25.0f), White);

	CreateFloor(WALL_HOR, vec3(zeros.x - 20.0f, zeros.y, zeros.x + WALL_HOR.z * 25 - 25.0f), White);
	CreateFloor(WALL_HOR, vec3(zeros.x - 20.0f, zeros.y, zeros.x + WALL_HOR.z * 26 - 25.0f), White);
	CreateFloor(WALL_HOR, vec3(zeros.x - 20.0f, zeros.y, zeros.x + WALL_HOR.z * 27 - 25.0f), White);
	CreateFloor(WALL_HOR, vec3(zeros.x - 20.0f, zeros.y, zeros.x + WALL_HOR.z * 28 - 25.0f), White);
	CreateFloor(WALL_HOR, vec3(zeros.x - 20.0f, zeros.y, zeros.x + WALL_HOR.z * 29 - 25.0f), White);
	
//	CreateFloor(MEDIUM_FLOOR, vec3(zeros.x, zeros.y + 32.65f, zeros.x - FLOOR.z * 4+0.25f), White);


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
	for (turn_num; turn_num < 7; turn_num++) {
		//LOG("Points 1=%i /// 2=%i", points1, points2);

		if (turn_num % 2 != 0) {
			if (body2 == target1_s) {
				points1 += 3;
				turn_num++;
			}
			if (body2 == target2_s) {
				points1 += 2;
				turn_num++;
			}
			if (body2 == target3_s) {
				points1 += 1;
				turn_num++;
			}
			if (body2 == target4_s) {
				points1 += 2;
				turn_num++;
			}
			if (body2 == target5_s) {
				points1 += 4;
				turn_num++;
			}
		}
		if (turn_num % 2 == 0) {
			if (body2 == target1_s) {
				points2 += 3;
				turn_num++;
			}
			if (body2 == target2_s) {
				points2 += 2;
				turn_num++;
			}
			if (body2 == target3_s) {
				points2 += 1;
				turn_num++;
			}
			if (body2 == target4_s) {
				points2 += 2;
				turn_num++;
			}
			if (body2 == target5_s) {
				points2 += 4;
				turn_num++;
			}
		}
	}
	//tunrs 1 3 and 5 are for player 1, 2,4 and 6 for player 2
	//if (body2 = floor)
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