/*
 * CellToVertexAdapter.cpp
 *
 *  Created on: Mar 6, 2014
 *      Author: Aaron Cohn
 */

#include "CellToVertexAdapter.h"

#include <string>
#include <vector>

#include "CellsToVerticesAdapter.h"

using std::string;
using std::vector;

namespace topologicalSort {

CellToVertexAdapter::CellToVertexAdapter(Cell *c)
	: underlyingCell(c), visited(false), inDegrees(0),
	adjacentVertices(new CellsToVerticesAdapter)
{
}

CellToVertexAdapter::~CellToVertexAdapter() {
	delete adjacentVertices;
}

void CellToVertexAdapter::addAdjacent(Vertex *adjacentVertex) {
	adjacentVertices->add(adjacentVertex);
}

Vertices* CellToVertexAdapter::getAdjacent() {
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
