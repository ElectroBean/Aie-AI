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
	if (Vector3::distance(agent->GlobalTransform.position, target->GlobalTransform.position) < 5.0f)
	{
		target->takeDamage(damage);
	}
}
