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
public:
	virtual ~Vertices() {}
	virtual void clear() = 0;
	virtual std::vector<Vertex*>::iterator begin() = 0;
	virtual std::vector<Vertex*>::iterator end() = 0;
	virtual void add(Vertex *v) = 0;
};

} /* namespace topologicalSort */

#endif /* VERTICES_H_ */
