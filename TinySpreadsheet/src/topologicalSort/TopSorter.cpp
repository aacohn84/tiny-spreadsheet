/*
 * TopSorter.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */

#include "TopSorter.h"

#include <stack>

namespace topologicalSort {

using namespace std;

TopSorter::TopSorter(const shared_ptr<DAG> &graph)
	: graph(graph)
{
}

TopSorter::~TopSorter()
{
}

Vertices sort()
{
	/*
	 * Order vertices in a queue by least in-degrees
	 * An error occurs if no vertex has 0 in-degrees.
	 *
	 * Create an empty stack
	 * Mark all vertices unvisited
	 *
	 * For each vertex V:
	 * 	if V not visited:
	 * 		recursively visit all of V's adjacent vertices
	 *
	 * 	While the stack is not empty:
	 * 		pop into a queue
	 */
	return Vertices();
}

void recursiveTopSort()
{
	/*
	 * Mark the current vertex V as visited
	 * For each vertex A adjacent to V:
	 * 		if A not visited:
	 *	 		recursively visit all of A's adjacent vertices
	 *
	 * Push V onto the stack
	 */
}

} /* namespace core */
