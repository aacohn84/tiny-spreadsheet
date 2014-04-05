/*
 * Vertex.h
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include <memory>

namespace topologicalSort {

using std::shared_ptr;

class Vertices;

class Vertex {
public:
	virtual ~Vertex() {}
	virtual Vertices* getAdjacent() = 0;
	virtual int getInDegrees() = 0;
	virtual void addInDegree() = 0;
	virtual bool isVisited() = 0;
	virtual void setVisited(bool visited) = 0;
};

typedef shared_ptr<Vertex> VertexPtr;

} /* namespace topologicalSort */

#endif /* VERTEX_H_ */
