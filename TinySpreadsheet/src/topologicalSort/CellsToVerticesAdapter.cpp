/*
 * CellsToVerticesAdapter.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: Aaron Cohn
 */

#include "CellsToVerticesAdapter.h"
#include "CellToVertexAdapter.h"

namespace topologicalSort {

using std::vector;
using core::Cell;

CellsToVerticesAdapter::CellsToVerticesAdapter(vector<Cell*> *cells, core::DAG *graph) {
	// convert each Cell* to Vertex* and store in vector
	for (Cell *cell : *cells) {
		Vertex *vertexPtr = new CellToVertexAdapter(cell, graph);
		add(vertexPtr);
	}
}

CellsToVerticesAdapter::~CellsToVerticesAdapter() {
	// May need to deallocate vertices here
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
