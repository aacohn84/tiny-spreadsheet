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
private:
	bool visited;
	int inDegrees;
public:
	Vertices* getAdjacent()
	{
		return nullptr;
	}
	int getInDegrees()
	{
		return 0;
	}
	bool isVisited()
	{
		return false;
	}
	bool setVisited(bool visited)
	{
		return false;
	}
};

typedef shared_ptr<Vertex> VertexPtr;

} /* namespace topologicalSort */

#endif /* VERTEX_H_ */
