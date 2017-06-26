#pragma once
#include "State.h"
#include "Vector2.h"

class IdleState :
	public State
{
public:
	IdleState(Vector2* target, float maxSpeed);
	void onEnter(Agent* agent);
	void onExit(Agent* agent);
	void update(float deltaTime, Agent* agent, StateManager* sm);
	~IdleState();

private: 
	Vector2* target;
	float maxSpeed;
	Vector2* searchPosition;
	bool directionX;
	bool directionY;
};

