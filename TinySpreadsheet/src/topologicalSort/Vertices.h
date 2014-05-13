/*
 * Vertices.h
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 *
 *  An adjacency list. Each entry is a vertex. The vertex maps to its adjacent vertices.
 */

#ifndef VERTICES_H_
#define VERTICES_H_

#include <vector>

#include "Vertex.h"

namespace topologicalSort {

class Vertices {
private:
	std::vector<Vertex*> vertices;

public:
	Vertices();
	~Vertices() {}
	void clear();
	std::vector<Vertex*>::iterator begin();
	std::vector<Vertex*>::iterator end();
	void add(Vertex *v);
};

} /* namespace topologicalSort */

#endif /* VERTICES_H_ */
