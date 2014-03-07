/*
 * CellToVertexAdapter.cpp
 *
 *  Created on: Mar 6, 2014
 *      Author: Aaron Cohn
 */

#include "CellToVertexAdapter.h"

namespace topologicalSort {

CellToVertexAdapter::CellToVertexAdapter() {
	inDegrees = 0;
	visited = false;
}

CellToVertexAdapter::~CellToVertexAdapter() {
	// TODO Auto-generated destructor stub
}

Vertices* CellToVertexAdapter::getAdjacent() {
	return nullptr;
}

int CellToVertexAdapter::getInDegrees() {
	return 0;
}

void CellToVertexAdapter::addInDegree() {
	inDegrees++;
}

bool CellToVertexAdapter::isVisited() {
	return false;
}

bool CellToVertexAdapter::setVisited(bool visited) {
	return false;
}

} /* namespace topologicalSort */
