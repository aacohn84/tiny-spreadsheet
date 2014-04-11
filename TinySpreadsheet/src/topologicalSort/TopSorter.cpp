/*
 * TopSorter.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */
#include <stack>
#include <algorithm>

#include "TopSorter.h"

namespace topologicalSort {

using namespace std;

TopSorter::TopSorter(DAG *graph)
	: graph(graph)
{
}

TopSorter::~TopSorter()
{
}

void TopSorter::sortByInDegrees(Vertices *v)
{

}

Vertices* TopSorter::sort()
{
	Vertices *vertices = graph->getVertices();
	sortByInDegrees(vertices);

	stack<Vertex *> s;

	// Mark all vertices unvisited
	for (Vertex *v : *vertices) {
		v->setVisited(false);
	}

	for (Vertex *v : *vertices) {
		if (!v->isVisited()) {
			recursiveTopSort(v, s);
		}
	}

	return vertices;
}

void TopSorter::recursiveTopSort(Vertex *v, stack<Vertex *> &s)
{
	v->setVisited(true);
	Vertices *adjacent = v->getAdjacent();
	for (Vertex *a : *adjacent) {
		if (!a->isVisited()) {
			recursiveTopSort(a, s);
		}
	}
	s.push(v);
}

} /* namespace core */
