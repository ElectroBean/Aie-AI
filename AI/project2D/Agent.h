#pragma once
#include <glm\glm.hpp>
#include <iostream>
#include <vector>
#include <vector2.h>

class IBehaviour;

class Agent
{
public:
	Agent();
	Agent(Vector2 position);
	~Agent();

	void AddForce(Vector2 a_force);
	void update(float deltaTime);
	void AddBehaviours(IBehaviour* behaviour);

	Vector2 position;
	Vector2 acceleration;
	Vector2 velocity;

	std::vector<IBehaviour*> behaviours;

private:

	float MaxVelocity;
};

