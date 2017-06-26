#pragma once
#include "State.h"
class WanderState :
	public State
{
public:
	WanderState(float wanderRadius, float wanderDistance, float jitterAmount);
	~WanderState();

	void onEnter(Agent* agent);
	void onExit(Agent* agent);
	void update(float deltaTime, Agent* agent, StateManager* sm);

private:
	float wanderRadius;
	float wanderDistance;
	float jitterAmount;
	Vector2 previousTarget;
};

