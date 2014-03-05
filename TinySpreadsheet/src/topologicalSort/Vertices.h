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
#include <memory>

#include "Vertex.h"

namespace topologicalSort {

using std::vector;
using std::shared_ptr;

class Vertices {
private:
	vector<Vertex> vertices;

public:
	vector<Vertex>::iterator begin() const;
	vector<Vertex>::iterator end() const;

	void add(const Vertex &v);
};

typedef shared_ptr<Vertices> VerticesPtr;

} /* namespace topologicalSort */

#endif /* VERTICES_H_ */
