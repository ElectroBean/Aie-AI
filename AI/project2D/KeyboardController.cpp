#include "KeyboardController.h"



KeyboardController::KeyboardController()
{
	inputs = aie::Input::getInstance();
}


KeyboardController::~KeyboardController()
{
}

void KeyboardController::Update(float a_dt, Agent * a_agent)
{
	if (inputs->wasKeyPressed(aie::INPUT_KEY_UP))
	{
		a_agent->acceleration.y += 5.0f;
	}
	if (inputs->wasKeyPressed(aie::INPUT_KEY_DOWN))
	{
		a_agent->acceleration.y -= 2.0f;
	}
	if (inputs->wasKeyPressed(aie::INPUT_KEY_RIGHT))
	{
		a_agent->acceleration.x += 5.0f;
	}
	if (inputs->wasKeyPressed(aie::INPUT_KEY_LEFT))
	{
		a_agent->acceleration.x -= 5.0f;
	}
}
