#include "AttackState.h"



AttackState::AttackState(Agent* target, float damage)
{
	this->target = target;
	this->damage = damage;
}


AttackState::~AttackState()
{
}

void AttackState::onEnter(Agent * agent)
{
}

void AttackState::onExit(Agent * agent)
{
}

void AttackState::update(float deltaTime, Agent * agent, StateManager * sm)
{
	Vector3 dir = target->GlobalTransform.position - agent->GlobalTransform.position;
	dir.normalise();

	float distance = Vector3::distance(agent->GlobalTransform.position, target->GlobalTransform.position);

	dir = dir * 100;

	agent->velocity = dir;

	if (Vector3::distance(agent->GlobalTransform.position, target->GlobalTransform.position) < 5.0f)
	{
		target->takeDamage(damage);
	}
	if (Vector3::distance(agent->GlobalTransform.position, target->GlobalTransform.position) > 50.0f)
	{
		sm->changeState(agent, new WanderState(target, 100.f, 0.01f, 100.0f, 100.0f, target));
	}
}
