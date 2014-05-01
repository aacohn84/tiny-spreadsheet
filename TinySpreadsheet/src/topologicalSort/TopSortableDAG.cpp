/*
 * TopSortableDAG.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: Aaron Cohn
 */

#include <vector>

#include "TopSortableDAG.h"
#include "CellsToVerticesAdapter.h"
#include "CellToVertexAdapter.h"

namespace topologicalSort {

using std::string;
using std::map;
using std::vector;
using core::Cell;

TopSortableDAG::TopSortableDAG(core::DAG *graph)
	: core::DAG(*graph)
{
	map<string, Cell*> *dagMap = graph->getMap();
	vector<Cell*> newCells;
	for (auto cellsEntry : *dagMap) {
		newCells.push_back(cellsEntry.second);
	}
	cellsAsVertices = new CellsToVerticesAdapter(newCells, this);
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
	cells.clear();

	// replace with the new list
	for (Vertex *v : *cellsAsVertices) {
		CellToVertexAdapter *cellAsVertex = dynamic_cast<CellToVertexAdapter*>(v);
		this->cells.push_back(cellAsVertex->getUnderlyingCell());
	}
}

} /* namespace topologicalSort */
