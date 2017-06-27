#pragma once
#include "State.h"
#include "Vector2.h"

class PatrolState :
	public State
{
public:
	PatrolState(Agent* target, float maxSpeed);
	void onEnter(Agent* agent);
	void onExit(Agent* agent);
	void update(float deltaTime, Agent* agent, StateManager* sm);
	~PatrolState();

private: 
	Agent* target;
	float maxSpeed;
	Matrix3 searchPosition;
	bool directionX;
	bool directionY;
};

