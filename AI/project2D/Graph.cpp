#include "Graph.h"
#include <list>
#include <iostream>
#include <algorithm>

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

std::vector<Graph::node*> Graph::djikstraSearch(node * startNode, node * endNode)
{
	// set all the nodes to null and gscores to infinity
	//for (auto node : nodes)
	//{
	//	node = NULL;
	//	node->gScore = INFINITY;
	//}

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
		bool sorting = true;
		node* currentNode = openList.front();

		openList.sort(node::compareGScore);

		currentNode = openList.front();

		if (currentNode == endNode)
			break;

		openList.remove(currentNode);
		closedList.push_back(currentNode);

		for (int i = 0; i < currentNode->connections.size(); i++)
		{
			if (std::find(closedList.begin(), closedList.end(), currentNode) != closedList.end())
			{
				openList.push_back(currentNode->connections[i]->nodeB);
			}
			currentNode->connections[i]->nodeB->gScore = currentNode->gScore + currentNode->connections[i]->cost;
			currentNode->connections[i]->nodeB->parent = currentNode;
		}
		currentNode++;
	}

	std::vector<node*> path;
	node* currentPathNode = endNode;
	while (currentPathNode != nullptr)
	{
		path.push_back(currentPathNode);
		currentPathNode->highlighted = true;
		currentPathNode = currentPathNode->parent;
	}
	return path;
}

void Graph::Draw(aie::Render2D * spritebatch)
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
}
