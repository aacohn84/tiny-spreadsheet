/*
 * TopSortableDAG.cpp
 *
 *  Created on: Apr 10, 2014
 *      Author: Aaron Cohn
 */
#include "TopSortableDAG.h"

#include <vector>

#include "CellsToVerticesAdapter.h"
#include "CellToVertexAdapter.h"

namespace topologicalSort {

using std::string;
using std::map;
using std::vector;
using core::Cell;

TopSortableDAG::TopSortableDAG(core::DAG *graph)
	: underlyingDag(graph) {

	// map the cells to vertices
	map<string, Cell*> *dagMap = graph->getMap();
	for (auto cellsEntry : *dagMap) {
		Cell *cell = cellsEntry.second;
		Vertex *vertex = new CellToVertexAdapter(cell);
		vertexTable.emplace(cell, vertex);
		cellsAsVertices.add(vertex);
	}
	
	// link each vertex to its adjacent vertices
	for (auto cellsEntry : *dagMap) {
		Cell *cell = cellsEntry.second;
		Vertex *vertex = vertexTable.at(cell);
		for (string dependentName : cell->dependencies) {
			Cell *dependentCell = graph->getCell(dependentName);
			if (dependentCell != nullptr) {
				Vertex *adjacentVertex = vertexTable.at(dependentCell);
				vertex->addAdjacent(adjacentVertex);
			}
		}
	}
}

TopSortableDAG::~TopSortableDAG() {
	for (auto vertexEntry : vertexTable) {
		delete vertexEntry.second;
	}
	vertexTable.clear();
}

Vertices* TopSortableDAG::getVertices() {
	return (Vertices*) &cellsAsVertices;
}

void TopSortableDAG::sort() {
	// do the sorting
	TopSorter topSorter;
	topSorter.sort(cellsAsVertices);

	// dump the old list of cells
	vector<Cell*> *cells = underlyingDag->getCells();
	cells->clear();

	// replace with the new list
	for (Vertex *v : cellsAsVertices) {
		CellToVertexAdapter *cellAsVertex = dynamic_cast<CellToVertexAdapter*>(v);
		cells->push_back(cellAsVertex->getUnderlyingCell());
	}
}

} /* namespace topologicalSort */
