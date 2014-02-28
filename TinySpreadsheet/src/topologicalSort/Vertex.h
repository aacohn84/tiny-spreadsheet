/*
 * Vertex.h
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include "Vertices.h"

namespace topologicalSort {

class Vertex {
public:
	Vertex();
	virtual ~Vertex();

	virtual Vertices getEdges() = 0;
	virtual int getInDegrees() = 0;
};

} /* namespace topologicalSort */

#endif /* VERTEX_H_ */
