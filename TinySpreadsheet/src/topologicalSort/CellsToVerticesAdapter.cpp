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

CellsToVerticesAdapter::CellsToVerticesAdapter(vector<Cell*> *cells, core::DAG *graph) {
	// convert each Cell* to Vertex* and store in vector
	for (Cell *cell : *cells) {
		VertexPtr vertexPtr(new CellToVertexAdapter(cell, graph));
		add(vertexPtr);
	}
}

CellsToVerticesAdapter::~CellsToVerticesAdapter() {
	// I used smart pointers, so I don't have to deallocate anything myself :-)
}

} /* namespace topologicalSort */
