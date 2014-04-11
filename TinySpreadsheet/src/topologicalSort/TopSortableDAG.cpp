/*
 * TopSortableDAG.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: Aaron Cohn
 */

#include "TopSortableDAG.h"
#include "CellsToVerticesAdapter.h"

namespace topologicalSort {

TopSortableDAG::TopSortableDAG(core::DAG *graph)
	: core::DAG(*graph), cellsAsVertices(new CellsToVerticesAdapter(&cells, this))
{
}

TopSortableDAG::~TopSortableDAG() {
	/* Intentionally empty -- the core::DAG owns the "dag" and "cells" objects,
	 * so we won't deallocate them here */
}

Vertices* TopSortableDAG::getVertices() {
	return (Vertices *) cellsAsVertices;
}

Cell* TopSortableDAG::getCells() {
	cells.clear();
	return nullptr;
}

} /* namespace topologicalSort */
