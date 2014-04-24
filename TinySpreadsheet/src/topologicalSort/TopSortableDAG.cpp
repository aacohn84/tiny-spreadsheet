/*
 * TopSortableDAG.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: Aaron Cohn
 */

#include "TopSortableDAG.h"
#include "CellsToVerticesAdapter.h"
#include "CellToVertexAdapter.h"

namespace topologicalSort {

TopSortableDAG::TopSortableDAG(core::DAG *graph)
	: core::DAG(*graph),
	  cellsAsVertices(new CellsToVerticesAdapter(&cells, this))
{
}

TopSortableDAG::~TopSortableDAG() {
	/* Intentionally empty -- the core::DAG owns the "dag" and "cells" objects,
	 * so we won't deallocate them here */
	delete cellsAsVertices;
}

Vertices* TopSortableDAG::getVertices() {
	return (Vertices *) cellsAsVertices;
}

void TopSortableDAG::sort() {
	// do the sorting
	TopSorter topSorter;
	topSorter.sort(cellsAsVertices);

	// dump the old list of cells
	for (Cell *c : this->cells) {
		delete c;
	}
	cells.clear();

	// replace with the new list
	for (Vertex *v : *cellsAsVertices) {
		CellToVertexAdapter *cellAsVertex = dynamic_cast<CellToVertexAdapter*>(v);
		this->cells.push_back((Cell*) cellAsVertex);
	}
}

} /* namespace topologicalSort */
