#pragma once
#include "Agent.h"
class IBehaviour
{
public:
	IBehaviour() {};
	virtual ~IBehaviour() {};
	virtual void Update(float deltaTime, Agent* agent) = 0;


};