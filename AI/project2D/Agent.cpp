#include "Agent.h"
#include "IBehaviour.h"
#include <random>

Agent::Agent()
{

}

Agent::Agent(Vector3 position)
{
	this->GlobalTransform.position = position;
}


Agent::~Agent()
{
}

void Agent::AddForce(Vector3 a_force)
{
	acceleration = acceleration + a_force;
}

void Agent::update(float deltaTime)
{
	for (auto iter = behaviours.begin(); iter != behaviours.end(); iter++)
	{
		(*iter)->Update(deltaTime, this);
	}

	AddForce(velocity * -1.0f);
	GlobalTransform.position = GlobalTransform.position + velocity * deltaTime;
	velocity = velocity + acceleration * deltaTime;

	acceleration = Vector3(0, 0, 0);

	if (this->GlobalTransform.position.x > 1280)
		this->GlobalTransform.position.x = 1280;
	if (this->GlobalTransform.position.x < 0)
		this->GlobalTransform.position.x = 0;
	if (this->GlobalTransform.position.y > 720)
		this->GlobalTransform.position.y = 720;
	if (this->GlobalTransform.position.y < 0)
		this->GlobalTransform.position.y = 0;
}

void Agent::AddBehaviours(IBehaviour * behaviour)
{
	this->behaviours.push_back(behaviour);
}