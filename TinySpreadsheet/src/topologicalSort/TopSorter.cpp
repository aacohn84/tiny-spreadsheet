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

TopSorter::TopSorter(const shared_ptr<DAG> &graph)
	: graph(graph)
{
}

TopSorter::~TopSorter()
{
}

void TopSorter::sortByInDegrees(Vertices &v)
{

}

shared_ptr<Vertices> TopSorter::sort()
{
	VerticesPtr vertices = graph->getVertices();
	sortByInDegrees(*vertices);

	stack<VertexPtr> s;

	// Mark all vertices unvisited
	for (Vertex &v : *vertices) {
		v.setVisited(false);
	}

	for (Vertex &v : *vertices) {
		if (!v.isVisited()) {
			recursiveTopSort(v, s);
		}
	}

	return vertices;
}

void TopSorter::recursiveTopSort(Vertex &v, stack<VertexPtr> &s)
{
	v.setVisited(true);
	VerticesPtr adjacent = v.getAdjacent();
	for (Vertex &a : *adjacent) {
		if (!a.isVisited()) {
			recursiveTopSort(a, s);
		}
	}
	s.push(VertexPtr(&v));
}

} /* namespace core */
