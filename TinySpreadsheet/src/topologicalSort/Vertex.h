/*
 * Vertex.h
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */

#ifndef VERTEX_H_
#define VERTEX_H_

namespace topologicalSort {

class Vertices;

class Vertex {
public:
	virtual ~Vertex() {}
	virtual void addAdjacent(Vertex *adjacentVertex) = 0;
	virtual Vertices* getAdjacent() = 0;
	virtual bool isVisited() = 0;
	virtual void setVisited(bool visited) = 0;
};

} /* namespace topologicalSort */

#endif /* VERTEX_H_ */
