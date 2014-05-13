/*
 * CellsToVerticesAdapter.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: Aaron Cohn
 */

#include "CellsToVerticesAdapter.h"

#include "TopSortableDAG.h"
#include "CellToVertexAdapter.h"

namespace topologicalSort {

using std::vector;
using core::Cell;

CellsToVerticesAdapter::CellsToVerticesAdapter() {
	// cellsAsVertices is an initially empty list
}

vector<Vertex*>::iterator CellsToVerticesAdapter::begin()
{
	return cellsAsVertices.begin();
}
vector<Vertex*>::iterator CellsToVerticesAdapter::end()
{
	return cellsAsVertices.end();
}

void CellsToVerticesAdapter::add(Vertex *v) {
	cellsAsVertices.push_back(v);
}

void CellsToVerticesAdapter::clear() {
	cellsAsVertices.clear();
}

} /* namespace topologicalSort */
