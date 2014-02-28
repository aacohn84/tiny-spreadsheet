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
	 * Order vertices by least in-degrees
	 * If no vertex has in-degree 0, exit.
	 *
	 * Create an empty stack
	 * Mark all vertices unvisited
	 *
	 * For each vertex:
	 * 	if vertex not visited:
	 * 		recursively topsort from that vertex using the stack
	 *
	 * 	While the stack is not empty:
	 * 		pop vertex into the final list of vertices
	 */
	return Vertices();
}

void recursiveTopSort()
{

}

} /* namespace core */
