#pragma once
#include "State.h"
#include "StateManager.h"
#include <Vector2.h>


class FleeState :
	public State
{
public:
	FleeState(Vector2* target, float maxSpeed);
	~FleeState();

	void onEnter(Agent* agent);
	void onExit(Agent* agent);
	void update(float deltaTime, Agent* agent, StateManager* sm);

private:
	Vector2* target;
	float maxSpeed;
};

