#pragma once
#include <glm\glm.hpp>
#include <iostream>
#include <vector>
#include <vector2.h>
#include <Vector3.h>
#include <Matrix3D.h>

class IBehaviour;

class Agent
{
public:
	Agent();
	Agent(Vector3 position);
	~Agent();

	void AddForce(Vector3 a_force);
	void update(float deltaTime);
	void AddBehaviours(IBehaviour* behaviour);

	Matrix3 GlobalTransform;
	Vector3 acceleration;
	Vector3 velocity;

	std::vector<IBehaviour*> behaviours;

private:

	float MaxVelocity;
};

