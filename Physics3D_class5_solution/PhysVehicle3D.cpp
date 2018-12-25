#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
}

// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Render()
{
	Cylinder wheel;

	wheel.color = Pink;

	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}

	//---CHASSIS
	Cube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());

	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();

	//---CABIN
	Cube cabin(info.cabin_size.x, info.cabin_size.y, info.cabin_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&cabin.transform);
	btVector3 cabinOffset(info.cabin_offset.x, info.cabin_offset.y, info.cabin_offset.z);
	cabinOffset = offset.rotate(q.getAxis(), q.getAngle());

	cabin.transform.M[12] += cabinOffset.getX();
	cabin.transform.M[13] += cabinOffset.getY();
	cabin.transform.M[14] += cabinOffset.getZ();

	cabin.color = Yellow;

	//---LIGTHS---
	//---LEFT
	Cube L_light(info.L_light_size.x, info.L_light_size.y, info.L_light_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&L_light.transform);
	btVector3 LlightOffset(info.L_light_offset.x, info.L_light_offset.y, info.L_light_offset.z);
	LlightOffset = offset.rotate(q.getAxis(), q.getAngle());

	L_light.transform.M[12] += LlightOffset.getX();
	L_light.transform.M[13] += LlightOffset.getY();
	L_light.transform.M[14] += LlightOffset.getZ();

	L_light.color = Red;

	//---RIGHT
	Cube R_light(info.R_light_size.x, info.R_light_size.y, info.R_light_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&R_light.transform);
	btVector3 RlightOffset(info.R_light_offset.x, info.R_light_offset.y, info.R_light_offset.z);
	RlightOffset = offset.rotate(q.getAxis(), q.getAngle());

	R_light.transform.M[12] += RlightOffset.getX();
	R_light.transform.M[13] += RlightOffset.getY();
	R_light.transform.M[14] += RlightOffset.getZ();

	R_light.color = Red;


	chassis.Render();
	cabin.Render();
	L_light.Render();
	R_light.Render();
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}