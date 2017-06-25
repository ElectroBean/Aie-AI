#pragma once
#include <glm\glm.hpp>
#include <iostream>
#include <vector>

class IBehaviour;

class Agent
{
public:
	Agent();
	Agent(glm::vec2 position);
	~Agent();

	void AddForce(glm::vec2 a_force);
	void update(float deltaTime);
	void AddBehaviours(IBehaviour* behaviour);

	glm::vec2 position;
	glm::vec2 acceleration;
	glm::vec2 velocity;

	std::vector<IBehaviour*> behaviours;
};

