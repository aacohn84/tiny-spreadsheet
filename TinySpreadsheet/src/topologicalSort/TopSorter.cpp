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

TopSorter::TopSorter(DAGPtr graph)
	: graph(graph)
{
}

TopSorter::~TopSorter()
{
}

void TopSorter::sortByInDegrees(VerticesPtr &v)
{

}

shared_ptr<Vertices> TopSorter::sort()
{
	VerticesPtr vertices = graph->getVertices();
	sortByInDegrees(vertices);

	stack<VertexPtr> s;

	// Mark all vertices unvisited
	for (VertexPtr v : *vertices) {
		v->setVisited(false);
	}

	for (VertexPtr v : *vertices) {
		if (!v->isVisited()) {
			recursiveTopSort(v, s);
		}
	}

	return vertices;
}

void TopSorter::recursiveTopSort(VertexPtr &v, stack<VertexPtr> &s)
{
	v->setVisited(true);
	VerticesPtr adjacent(v->getAdjacent());
	for (VertexPtr a : *adjacent) {
		if (!a->isVisited()) {
			recursiveTopSort(a, s);
		}
	}
	s.push(VertexPtr(v));
}

} /* namespace core */
