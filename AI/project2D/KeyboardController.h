#pragma once
#include "IBehaviour.h"
#include <Input.h>

class KeyboardController :
	public IBehaviour
{
public:
	KeyboardController();
	~KeyboardController();

	void virtual Update(float a_dt, Agent* a_agent);

protected:
	aie::Input* inputs;
};

