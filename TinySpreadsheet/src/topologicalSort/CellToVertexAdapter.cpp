/*
 * CellToVertexAdapter.cpp
 *
 *  Created on: Mar 6, 2014
 *      Author: Aaron Cohn
 */

#include "CellToVertexAdapter.h"
#include "CellsToVerticesAdapter.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace topologicalSort {

CellToVertexAdapter::CellToVertexAdapter(Cell *c, core::DAG *graph)
	: graph(graph), underlyingCell(c), visited(false), inDegrees(0),
	adjacentVertices(nullptr)
{
}

CellToVertexAdapter::~CellToVertexAdapter() {
	delete adjacentVertices;
}

Vertices* CellToVertexAdapter::getAdjacent() {
	if (!adjacentVertices) {
		// collect references to the adjacent cells in a vector
		vector<Cell*> adjacentCells;
		for (string dependencyName : underlyingCell->dependencies) {
			Cell *dependencyCell = graph->getCell(dependencyName);
			if (dependencyCell) {
				adjacentCells.push_back(dependencyCell);
			}
		}

		// convert Cells to Vertices
		adjacentVertices = new CellsToVerticesAdapter(adjacentCells, graph);
	}
	return adjacentVertices;
}

Cell* CellToVertexAdapter::getUnderlyingCell() {
	return underlyingCell;
}

int CellToVertexAdapter::getInDegrees() {
	return inDegrees;
}

void CellToVertexAdapter::addInDegree() {
	inDegrees++;
}

bool CellToVertexAdapter::isVisited() {
	return visited;
}

void CellToVertexAdapter::setVisited(bool visited) {
	this->visited = visited;
}

} /* namespace topologicalSort */
