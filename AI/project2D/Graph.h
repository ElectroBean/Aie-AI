#pragma once
#include <functional>
#include <Vector3.h>
#include <vector>
using namespace aie;

namespace aie
{
	class Render2D;
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
	};

	struct node
	{
		Vector3 position;
		Vector3 index;
		float gScore;
		bool highlighted;
		node* parent;
		std::vector<edge*> connections;

		static bool compareGScore(node* a, node* b)
		{
			return a->gScore < b->gScore;
		}
	};

	void addNote(node* node);
	void connectNodes(node* a, node* b, float cost);
	node* findNode(Vector3 position);
	std::vector<node*> djikstraSearch(node* startNode, node* endNode);
	void Draw(aie::Render2D* spritebatch);
	std::vector<node*> nodes;

};

