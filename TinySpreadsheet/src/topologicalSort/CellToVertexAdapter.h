/*
 * VertexAdapter.h
 *
 *  Created on: Mar 6, 2014
 *      Author: Aaron Cohn
 */

#ifndef VERTEXADAPTER_H_
#define VERTEXADAPTER_H_

#include "Vertex.h"

namespace topologicalSort {

class CellToVertexAdapter: public Vertex { // , private Cell
private:
	bool visited;
	int inDegrees;
public:
	CellToVertexAdapter();
	virtual ~CellToVertexAdapter();

	Vertices* getAdjacent();
	int getInDegrees();
	void addInDegree();
	bool isVisited();
	bool setVisited(bool visited);
};

} /* namespace topologicalSort */

#endif /* VERTEXADAPTER_H_ */
