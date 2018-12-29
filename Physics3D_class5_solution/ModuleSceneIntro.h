#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

//#define MAX_SIZE 128
#define WIDE_FLOOR_SIZE vec3(15,2,5)
#define MEDIUM_FLOOR_SIZE vec3(10,2,5)
#define FLOOR_SIZE vec3(5,2,5)
#define OBSTACLE_SIZE vec3(5,5,5)

struct PhysBody3D;
struct PhysMotor3D;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	//void LoadTrack(int* trackx, int postrack);
	//void FloorTypes(vec3 scale, int posX, int posZ, int cir);
	//void Paint();

	void CreateFloor(vec3 size = { 1.0f,1.0f,1.0f }, vec3 pos = { 0.0f, 0.0f, 0.0f }, Color color = White, vec3 u = (0.0f, 0.0f, 0.0f), float angle = 0.0f, float mass = 0.0f);
	void LoadFloor();
	void PaintFloor();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:
	/*
	PhysBody3D* pb_snake[MAX_SNAKE];
	Sphere s_snake[MAX_SNAKE];

	PhysBody3D* pb_snake2[MAX_SNAKE];
	Sphere s_snake2[MAX_SNAKE];
	*/
	/*p2DynArray<PhysBody3D*> pb_cubes;
	p2DynArray<Cube>s_cubes;

	p2DynArray<PhysBody3D*> pb_limits;
	p2DynArray<Cube>s_limits;*/

	

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;

	// primitives
	p2List<Cube> cubes;

	//Track Paramenters
	vec3 zeros = { 0.0f,0.0f,0.0f };
	vec3 Xaxis = { 1.0f,0.0f,0.0f }, 
		 Yaxis = { 0.0f,1.0f,0.0f }, 
		 Zaxis = { 0.0f,0.0f,1.0f };
	bool win = true;
	//int track[MAX_SIZE];

};
