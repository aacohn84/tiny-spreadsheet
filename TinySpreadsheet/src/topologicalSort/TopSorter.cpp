/*
 * TopSorter.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */
#include "TopSorter.h"

namespace topologicalSort {

using namespace std;

void TopSorter::sort(Vertices &vertices)
{
	deque<Vertex *> s;

	// Mark all vertices unvisited
	for (Vertex *v : vertices) {
		v->setVisited(false);
	}

	// sort into stack
	for (Vertex *v : vertices) {
		if (!v->isVisited()) {
			recursiveTopSort(v, s);
		}
	}

	// re-order the original list
	vertices.clear();
	while (!s.empty()) {
		vertices.add(s.back());
		s.pop_back();
	}
}

void TopSorter::recursiveTopSort(Vertex *v, deque<Vertex *> &s)
{
	v->setVisited(true);
	Vertices *adjacent = v->getAdjacent();
	for (Vertex *a : *adjacent) {
		if (!a->isVisited()) {
			recursiveTopSort(a, s);
		}
	}
	s.push_front(v);
}

} /* namespace core */
