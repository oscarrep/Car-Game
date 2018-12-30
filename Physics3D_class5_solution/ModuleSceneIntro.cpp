#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

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

	/*int track[128]{
		0,3,3,3,3,3,3,0,
		0,3,1,1,1,1,3,0,
		0,3,1,1,1,1,3,0,
		0,3,4,4,4,4,3,0,
		0,3,2,4,4,2,3,0,
		0,0,4,4,4,4,0,0,
		0,0,4,2,2,4,0,0,
		0,0,3,1,1,3,0,0,
		0,0,5,5,5,5,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,3,1,1,1,1,3,0,
		0,3,1,1,1,1,3,0,
		0,3,1,1,1,1,3,0,
		0,3,1,1,1,1,3,0,
		0,3,3,3,3,3,3,0,
	};*/

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
	//Plane p(0, 1, 0, 0);
	//p.axis = true;
	//p.Render();

	PaintFloor();

	return UPDATE_CONTINUE;
}

//void ModuleSceneIntro

//void ModuleSceneIntro::FloorTypes(vec3 scale, int posX, int posZ, int cir)
//{
//	Cube cubes;
//	PhysBody3D* pb_cube;
//
//	Cube cubes2;
//	PhysBody3D* pb_cube2;
//
//
//	switch (cir)
//	{
//	case 0:
//		//out of bounds
//		cubes2.Size(scale.x, scale.y, scale.z);
//		s_limits.PushBack(cubes2);
//		pb_cube2 = App->physics->AddBody(cubes2, 0);
//		pb_cube2->SetPos(posX, 1, posZ);
//		pb_limits.PushBack(pb_cube2);
//		break;
//
//	case 1:
//		//floor
//		cubes.Size(scale.x, scale.y, scale.z);
//		s_cubes.PushBack(cubes);
//		pb_cube = App->physics->AddBody(cubes, 0);
//		pb_cube->SetPos(posX, 1, posZ);
//		pb_cube->painting = true;
//		pb_cubes.PushBack(pb_cube);
//		break;
//	
//	/*case 2:
//		//ramp with obstacle
//		cubes2.Size(scale.x, scale.y, scale.z);
//		s_limits.PushBack(cubes2);
//		pb_cube2 = App->physics->AddBody(cubes2, 0);
//		pb_cube2->SetPos(posX, 1, posZ);
//		pb_limits.PushBack(pb_cube2);
//		break;*/
//
//	case 3:
//		//wall
//		cubes.Size(1, 100, 500);
//		cubes.color = Black;
//		s_cubes.PushBack(cubes);
//		pb_cube = App->physics->AddBody(cubes, 0);
//		pb_cube->SetPos(posX, 1, posZ);
//		pb_cube->painting = true;
//		pb_cubes.PushBack(pb_cube);
//		break;
//
//	case 4:
//		//ramp begin
//		cubes.Size(scale.x, scale.y, scale.z - 15);
//		cubes.SetRotation(-15, vec3(1, 0, 0));
//		s_cubes.PushBack(cubes);
//		pb_cube = App->physics->AddBody(cubes, 0);
//		pb_cube->SetPos(posX, 3, posZ - 10);
//		pb_cube->painting = true;
//		pb_cubes.PushBack(pb_cube);
//		break;
//
//	case 5:
//		//ramp end
//		cubes.Size(scale.x, scale.y, scale.z - 15);
//		cubes.SetRotation(10, vec3(1, 0, 0));
//		s_cubes.PushBack(cubes);
//		pb_cube = App->physics->AddBody(cubes, 0);
//		pb_cube->SetPos(posX, 3, posZ + 10);
//		pb_cube->painting = true;
//		pb_cubes.PushBack(pb_cube);
//		break;
//
//	case 6:
//	
//	default:
//		break;
//	}
//}
//
//void ModuleSceneIntro::Paint()
//{
//	Cube* floor_cube = new Cube(5000.0f, 0.0f, 5000.0f);
//	floor_cube->color = Green;
//	floor_cube->Render();
//
//	if (pb_cubes.Count() != 0 && s_cubes.Count() != 0 && s_cubes.Count() == pb_cubes.Count())
//	{
//		for (int i = 0; i < s_cubes.Count(); i++) {
//			pb_cubes[i]->GetTransform(&s_cubes[i].transform);
//
//			//We paint only the cubes that we need to paint
//			if (pb_cubes[i]->painting == true)
//			{
//				s_cubes[i].Render();
//			}
//			
//		}
//
//	}
//	delete floor_cube;
//	floor_cube = nullptr;
//}
//
//void ModuleSceneIntro::LoadTrack(int * trackx, int postrack)
//{
//
//	int desp = postrack * 8 * 30;
//	
//	for (int j = 0; j < 10; j++) {
//		for (int i = 0; i < 7; i++) {
//			FloorTypes(vec3(30, 1, 30), 30 * i + desp, 30 * j, track[(7 * j) + i]);
//		}
//	}
//	//create sensors
//	/*if (pb_limits.Count() != 0 && s_limits.Count() != 0 && s_limits.Count() == pb_limits.Count())
//	{
//		for (int i = 0; i < s_limits.Count(); i++)
//		{
//			pb_limits[i]->SetAsSensor(true);
//			pb_limits[i]->collision_listeners.add(this);
//		}
//
//		for (int i = 0; i < s_endlvl.Count(); i++)
//		{
//			pb_endlvl[i]->SetAsSensor(true);
//			pb_endlvl[i]->collision_listeners.add(this);
//		}
//	}*/
//}

void ModuleSceneIntro::LoadFloor() {
//	
//	CreateFloor(FLOOR, vec3(x position, y position, z position), color, rotation axis, rotation angle, mass);
	
//	CreateFloor(DEBUG_FLOOR, vec3(zeros.x, zeros.y, zeros.x - FLOOR.z));
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
	CreateFloor(TARGET1, vec3(zeros.x, zeros.y, zeros.x + TARGET1.z * 25), Red);
	CreateFloor(TARGET2, vec3(zeros.x, zeros.y, zeros.x + TARGET2.z * 26), Blue);
	CreateFloor(TARGET3, vec3(zeros.x, zeros.y, zeros.x + TARGET3.z * 27), Green);
	CreateFloor(TARGET4, vec3(zeros.x, zeros.y, zeros.x + TARGET4.z * 28), Yellow);
	CreateFloor(TARGET5, vec3(zeros.x, zeros.y, zeros.x + TARGET5.z * 29), DarkGrey);

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