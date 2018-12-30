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
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

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
//	CreateFloor(FLOOR_SIZE, vec3(x position, y position, z position), color, rotation axis, rotation angle, mass);
	
//	CreateFloor(DEBUG_FLOOR_SIZE, vec3(zeros.x, zeros.y, zeros.x - FLOOR_SIZE.z));
	CreateFloor(Floor, vec3(zeros.x, zeros.y, zeros.x), Green);

	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 70.0f, zeros.x - FLOOR_SIZE.z), White);
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 70.0f, zeros.x), White);
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 70.0f, zeros.x + FLOOR_SIZE.z), White);
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 69.15f, zeros.x + FLOOR_SIZE.z * 2 - 0.25f), White, Xaxis, 10.0f);  //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 66.6f, zeros.x + FLOOR_SIZE.z * 3 - 0.75f), White, Xaxis, 20.0f); //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 62.95f, zeros.x + FLOOR_SIZE.z * 4 - 2.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 58.75f, zeros.x + FLOOR_SIZE.z * 5 - 3.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 54.55f, zeros.x + FLOOR_SIZE.z * 6 - 4.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 50.35f, zeros.x + FLOOR_SIZE.z * 7 - 5.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 46.15f, zeros.x + FLOOR_SIZE.z * 8 - 6.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 41.95f, zeros.x + FLOOR_SIZE.z * 9 - 7.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 37.75f, zeros.x + FLOOR_SIZE.z * 10 - 8.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 33.55f, zeros.x + FLOOR_SIZE.z * 11 - 9.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 29.35f, zeros.x + FLOOR_SIZE.z * 12 - 10.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 25.15f, zeros.x + FLOOR_SIZE.z * 13 - 11.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 20.95f, zeros.x + FLOOR_SIZE.z * 14 - 12.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 16.75f, zeros.x + FLOOR_SIZE.z * 15 - 13.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 12.55f, zeros.x + FLOOR_SIZE.z * 16 - 14.0f), White, Xaxis, 25.0f); //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 9.0f, zeros.x + FLOOR_SIZE.z * 17 - 15.25f), White, Xaxis, 20.0f); //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 6.35f, zeros.x + FLOOR_SIZE.z * 18 - 15.75f), White, Xaxis, 10.0f); //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 6.35f, zeros.x + FLOOR_SIZE.z * 18 - 15.0f), White);
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 6.35f, zeros.x + FLOOR_SIZE.z * 19 - 15.0f), White);
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 6.35f, zeros.x + FLOOR_SIZE.z * 20 - 15.0f), White);
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 6.35f, zeros.x + FLOOR_SIZE.z * 21 - 15.0f), White);
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 8.15f, zeros.x + FLOOR_SIZE.z * 22 - 15.0f), White, Xaxis, -20.0f); //ramp
	CreateFloor(WIDE_FLOOR_SIZE, vec3(zeros.x, zeros.y + 11.55f, zeros.x + FLOOR_SIZE.z * 23 - 16.0f), White, Xaxis, -20.0f); //ramp


//	CreateFloor(MEDIUM_FLOOR_SIZE, vec3(zeros.x, zeros.y + 32.65f, zeros.x - FLOOR_SIZE.z * 4+0.25f), White);


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
	Cube c(dim.x, dim.y, dim.z);
	c.SetPos(pos.x, pos.y, pos.z);
	c.color = color;

	if (angle != 0)
		c.SetRotation(angle, vec3(u.x, u.y, u.z));


	App->physics->AddBody(c, mass);

	cubes.add(c);
	
}