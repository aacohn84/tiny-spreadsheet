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
	: core::DAG(*graph)
{
}

TopSortableDAG::~TopSortableDAG() {
	/* Intentionally empty -- the core::DAG owns the "dag" and "cells" objects,
	 * so we won't deallocate them here */
}

VerticesPtr TopSortableDAG::getVertices() {
	VerticesPtr vertices(new CellsToVerticesAdapter(&cells, this));
	return vertices;
}

} /* namespace topologicalSort */
