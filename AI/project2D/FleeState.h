#pragma once
#include "State.h"
#include "StateManager.h"
#include <Vector2.h>
#include "WanderState.h"


class FleeState :
	public State
{
public:
	FleeState(Agent* target, float maxSpeed);
	~FleeState();

	void onEnter(Agent* agent);
	void onExit(Agent* agent);
	void update(float deltaTime, Agent* agent, StateManager* sm);

private:
	Agent* target;
	float maxSpeed;
};

