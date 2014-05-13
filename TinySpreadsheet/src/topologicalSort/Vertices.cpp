/*
 * Vertices.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */

#include "Vertices.h"

namespace topologicalSort {
	
	using std::vector;

	Vertices::Vertices() {
		// vertices is an initially empty list
	}

	vector<Vertex*>::iterator Vertices::begin()
	{
		return vertices.begin();
	}
	vector<Vertex*>::iterator Vertices::end()
	{
		return vertices.end();
	}

	void Vertices::add(Vertex *v) {
		vertices.push_back(v);
	}

	void Vertices::clear() {
		vertices.clear();
	}

} /* namespace topologicalSort */
