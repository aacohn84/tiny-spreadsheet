/*
 * Vertex.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */

#include "Vertex.h"

namespace topologicalSort {

Vertex::Vertex() {
	inDegrees = 0;
	visited = false;
}

Vertices* Vertex::getAdjacent() {
	return nullptr;
}

int Vertex::getInDegrees() {
	return 0;
}

void Vertex::addInDegree() {
	inDegrees++;
}

bool Vertex::isVisited() {
	return false;
}

bool Vertex::setVisited(bool visited) {
	return false;
}

} /* namespace topologicalSort */
