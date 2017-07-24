#include "Graph.h"
#include <list>
#include <iostream>
#include <algorithm>
#include <Renderer2D.h>
Graph::Graph()
{
	for (auto node : nodes)
	{
		node->highlighted = true;
	}
}


Graph::~Graph()
{
}

void Graph::addNode(node * node)
{
	nodes.push_back(node);
}

void Graph::connectNodes(node * a, node * b, float cost)
{
	edge* edge = new Graph::edge();
	edge->cost = cost;
	edge->nodeA = a; edge->nodeB = b;
	//a->connections.push_back(edge);
	b->connections.push_back(edge);
}

Graph::node * Graph::findNode(Vector3 position, float distance)
{
	for (auto node : nodes)
	{
		//if (node->position == position)
		//	return node;
		float mag = Vector3::distance(node->position, position);

		if (mag < distance)
			return node;

	}
	return nullptr;
}

std::vector<Vector3> Graph::djikstraSearch(node * startNode, node * endNode)
{
	//list of nodes yet to be visited
	std::list<node*> openList;
	//list ofnodes that have been traversed
	std::list<node*> closedList;

	// set the start nde parent to null
	startNode->parent = nullptr;
	// push the start
	openList.push_back(startNode);
	
	while (!openList.empty())
	{
		openList.sort(node::compareGScore);

		auto cNode = openList.front();

		if (cNode == endNode)
			break;

		openList.remove(cNode);
		closedList.push_back(cNode);
		
		for (auto connections : cNode->connections)
		{
			bool foundNode = false;
			for (auto iter : closedList)
			{
				if (iter == connections->nodeA)
				{
					foundNode = true;
				}
			}
			if ( foundNode == false)//dis dont work
			{
				openList.push_back(connections->nodeA);
				connections->nodeA->gScore = cNode->gScore + connections->cost;
				connections->nodeA->parent = cNode;
				
			}
		}
	}

	std::vector<Vector3> path;
	node* currentPathNode = endNode;
	while (currentPathNode != nullptr)
	{
		path.push_back(currentPathNode->position);
		currentPathNode->highlighted = true;
		currentPathNode = currentPathNode->parent;
	}

	return path;
}

void Graph::Draw(aie::Renderer2D * spritebatch)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		if (!nodes[i]->highlighted)
		{
			//->setRenderColour(1, 0, 0, 1);
			//->drawBox(nodes[i]->position.x, nodes[i]->position.y, 10, 10);
			//->setRenderColour(1, 1, 1, 1);
		}
	}

	for (auto node : nodes)
	{
		//spritebatch->drawBox(node->position.x, node->position.y, 10, 10);

		if (!node->highlighted)
		{
			spritebatch->setRenderColour(1, 0, 0, 1);
			spritebatch->drawBox(node->position.x, node->position.y, 10, 10);
			spritebatch->setRenderColour(1, 1, 1, 1);
		}
		else if (node->highlighted)
		{
			spritebatch->setRenderColour(0, 1, 0, 1);
			spritebatch->drawBox(node->position.x, node->position.y, 10, 10);
			spritebatch->setRenderColour(1, 1, 1, 1);
		}

		for (auto e : node->connections)
		{
			spritebatch->drawLine(e->nodeA->position.x, e->nodeA->position.y, e->nodeB->position.x, e->nodeB->position.y);
		}

		//spritebatch->drawBox(node->position.x, node->position.y, 10, 10);
	}
}
