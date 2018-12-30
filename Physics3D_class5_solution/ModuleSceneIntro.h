#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

//#define MAX_SIZE 123
#define WIDE_FLOOR vec3(50,2,10)
#define MEDIUM_FLOOR vec3(10,2,10)
#define LARGE_FLOOR vec3(20,2,20)
#define TARGET1 vec3(100,2,20)
#define TARGET2 vec3(100,2,20)
#define TARGET3 vec3(100,2,20)
#define TARGET4 vec3(100,2,20)
#define TARGET5 vec3(100,2,20)
#define FLOOR vec3(5,2,10)
#define WALL_STR vec3(2,30,4)
#define WALL_HOR vec3(4,30,2)
#define OBSTACLE vec3(5,10,5)
#define DEBUG_FLOOR vec3(300,2,300)
#define Floor vec3(1000,1,1000)

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

	void CreateFloor(vec3 size = { 1.0f,1.0f,1.0f }, vec3 pos = { 0.0f, 0.0f, 0.0f }, Color color = White, vec3 u = (0.0f, 0.0f, 0.0f), float angle = 0.0f, float mass = 0.0f);
	void LoadFloor();
	void PaintFloor();
	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:
	PhysBody3D* target1_s;
	PhysBody3D* target2_s;
	PhysBody3D* target3_s;
	PhysBody3D* target4_s;
	PhysBody3D* target5_s;

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
	int turn_num;
	int* points1=0;
	int* points2=0;


};
