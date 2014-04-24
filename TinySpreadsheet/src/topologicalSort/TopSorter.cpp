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

void TopSorter::sortByInDegrees(Vertices *v)
{
	// is this necessary?
}

void TopSorter::sort(Vertices *vertices)
{
	sortByInDegrees(vertices);

	stack<Vertex *> s;

	// Mark all vertices unvisited
	for (Vertex *v : *vertices) {
		v->setVisited(false);
	}

	// sort into stack
	for (Vertex *v : *vertices) {
		if (!v->isVisited()) {
			recursiveTopSort(v, s);
		}
	}

	// re-order the original list
	vertices->clear();
	while (!s.empty()) {
		vertices->add(s.top());
		s.pop();
	}
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
