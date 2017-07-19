#pragma once
#include <functional>
#include <Vector3.h>
#include <vector>

namespace aie
{
	class Renderer2D;
}

class Graph
{
public:
	Graph();
	~Graph();
	struct node;
	struct edge
	{
		node* nodeA;
		node* nodeB;
		float cost;
	};

	struct node
	{
		Vector3 position;
		Vector3 index;
		float gScore;
		bool highlighted;
		node* parent;
		std::vector<edge*> connections;
		float hScore;
		float fScore;

		static bool compareGScore(node* a, node* b)
		{
			return a->gScore < b->gScore;
		}
		static bool compareFScore(node* a, node* b)
		{
			return a->fScore < b->fScore;
		}
	};

	void addNode(node* node);
	void connectNodes(node* a, node* b, float cost);
	node* findNode(Vector3 position, float distance);
	std::vector<Vector3> djikstraSearch(node* startNode, node* endNode);
	void Draw(aie::Renderer2D* spritebatch);
	std::vector<node*> nodes;

};

