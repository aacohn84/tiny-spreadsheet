/*
 * Vertices.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */

#include "Vertices.h"

namespace topologicalSort {

vector<VertexPtr>::iterator Vertices::begin()
{
	return vertices.begin();
}
vector<VertexPtr>::iterator Vertices::end()
{
	return vertices.end();
}

void Vertices::add(VertexPtr v) {
	vertices.push_back(v);
}

} /* namespace topologicalSort */
