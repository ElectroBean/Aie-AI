#include "SeekState.h"
#include "PatrolState.h"


SeekState::SeekState(Agent* target, float maxSpeed)
{
	this->target = target;
	this->maxSpeed = maxSpeed;
}


SeekState::~SeekState()
{
}

void SeekState::onEnter(Agent * agent)
{

}

void SeekState::onExit(Agent * agent)
{

}

void SeekState::update(float deltaTime, Agent * agent, StateManager * sm)
{
	Vector3 dir = target->GlobalTransform.position - agent->GlobalTransform.position;
	dir.normalise();

	float distance = Vector3::distance(agent->GlobalTransform.position, target->GlobalTransform.position);

	dir = dir * maxSpeed;

	agent->velocity = dir;

	if (Vector3::distance(agent->GlobalTransform.position, target->GlobalTransform.position) > 250.0f)
	{
		//change states if the distance between agent and target is above 250 units
		sm->changeState(agent, new WanderState(target, 100.f, 0.01f, 100.0f, 100.0f, target));
		std::cout << "wandering" << std::endl;
	}
	if (Vector3::distance(agent->GlobalTransform.position, target->GlobalTransform.position) < 5.0f)
	{
		//change states if the distance between agent and target is above 250 units
		sm->changeState(agent, new AttackState(target, 1));
		std::cout << "wandering" << std::endl;
	}
}
