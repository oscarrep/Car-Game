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

	int track[128]{
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
	};

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
	/*Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();*/

	return UPDATE_CONTINUE;
}

//void ModuleSceneIntro

void ModuleSceneIntro::FloorTypes(vec3 scale, int posX, int posZ, int cir)
{
	Cube cubes;
	PhysBody3D* pb_cube;

	Cube cubes2;
	PhysBody3D* pb_cube2;


	switch (cir)
	{
	case 0:
		//out of bounds
		cubes2.Size(scale.x, scale.y, scale.z);
		s_limits.PushBack(cubes2);
		pb_cube2 = App->physics->AddBody(cubes2, 0);
		pb_cube2->SetPos(posX, 1, posZ);
		pb_limits.PushBack(pb_cube2);
		break;

	case 1:
		//floor
		cubes.Size(scale.x, scale.y, scale.z);
		s_cubes.PushBack(cubes);
		pb_cube = App->physics->AddBody(cubes, 0);
		pb_cube->SetPos(posX, 1, posZ);
		pb_cube->painting = true;
		pb_cubes.PushBack(pb_cube);
		break;
	
	/*case 2:
		//ramp with obstacle
		cubes2.Size(scale.x, scale.y, scale.z);
		s_limits.PushBack(cubes2);
		pb_cube2 = App->physics->AddBody(cubes2, 0);
		pb_cube2->SetPos(posX, 1, posZ);
		pb_limits.PushBack(pb_cube2);
		break;*/

	case 3:
		//wall
		cubes.Size(1, 100, 500);
		cubes.color = Black;
		s_cubes.PushBack(cubes);
		pb_cube = App->physics->AddBody(cubes, 0);
		pb_cube->SetPos(posX, 1, posZ);
		pb_cube->painting = true;
		pb_cubes.PushBack(pb_cube);
		break;

	case 4:
		//ramp begin
		cubes.Size(scale.x, scale.y, scale.z - 15);
		cubes.SetRotation(-15, vec3(1, 0, 0));
		s_cubes.PushBack(cubes);
		pb_cube = App->physics->AddBody(cubes, 0);
		pb_cube->SetPos(posX, 3, posZ - 10);
		pb_cube->painting = true;
		pb_cubes.PushBack(pb_cube);
		break;

	case 5:
		//ramp end
		cubes.Size(scale.x, scale.y, scale.z - 15);
		cubes.SetRotation(10, vec3(1, 0, 0));
		s_cubes.PushBack(cubes);
		pb_cube = App->physics->AddBody(cubes, 0);
		pb_cube->SetPos(posX, 3, posZ + 10);
		pb_cube->painting = true;
		pb_cubes.PushBack(pb_cube);
		break;

	case 6:
	
	default:
		break;
	}
}

void ModuleSceneIntro::Paint()
{
	Cube* floor_cube = new Cube(5000.0f, 0.0f, 5000.0f);
	floor_cube->color = Green;
	floor_cube->Render();

	if (pb_cubes.Count() != 0 && s_cubes.Count() != 0 && s_cubes.Count() == pb_cubes.Count())
	{
		for (int i = 0; i < s_cubes.Count(); i++) {
			pb_cubes[i]->GetTransform(&s_cubes[i].transform);

			//We paint only the cubes that we need to paint
			if (pb_cubes[i]->painting == true)
			{
				s_cubes[i].Render();
			}
			
		}

	}
	delete floor_cube;
	floor_cube = nullptr;
}

void ModuleSceneIntro::LoadTrack(int * trackx, int postrack)
{

	int desp = postrack * 8 * 30;
	
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 7; i++) {
			FloorTypes(vec3(30, 1, 30), 30 * i + desp, 30 * j, track[(7 * j) + i]);
		}
	}
	//create sensors
	/*if (pb_limits.Count() != 0 && s_limits.Count() != 0 && s_limits.Count() == pb_limits.Count())
	{
		for (int i = 0; i < s_limits.Count(); i++)
		{
			pb_limits[i]->SetAsSensor(true);
			pb_limits[i]->collision_listeners.add(this);
		}

		for (int i = 0; i < s_endlvl.Count(); i++)
		{
			pb_endlvl[i]->SetAsSensor(true);
			pb_endlvl[i]->collision_listeners.add(this);
		}
	}*/
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

