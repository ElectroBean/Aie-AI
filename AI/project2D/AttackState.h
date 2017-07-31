#pragma once
#include "State.h"
#include "WanderState.h"
#include "StateManager.h"
class AttackState :
	public State
{
public:
	AttackState(Agent* target, float damage);
	~AttackState();

	void onEnter(Agent* agent);
	void onExit(Agent* agent);
	void update(float deltaTime, Agent* agent, StateManager* sm);

	Agent* target;
	float damage;
};

