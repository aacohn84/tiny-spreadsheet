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
	: graph(graph), underlyingCell(c), visited(false), inDegrees(0)
{
}

CellToVertexAdapter::~CellToVertexAdapter() {
	// TODO Auto-generated destructor stub
}

Vertices* CellToVertexAdapter::getAdjacent() {
	// collect references to the adjacent cells in a vector
	vector<Cell*> *adjacentCells = new vector<Cell*>();
	for (string dependency : *(underlyingCell->dependencies)) {
		adjacentCells->push_back(graph->getCell(dependency));
	}

	// convert Cells to Vertices
	Vertices *adjacentVertices = new CellsToVerticesAdapter(adjacentCells, graph);

	return adjacentVertices;
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
