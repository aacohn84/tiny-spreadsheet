/*
 * VertexAdapter.h
 *
 *  Created on: Mar 6, 2014
 *      Author: Aaron Cohn
 */

#ifndef VERTEXADAPTER_H_
#define VERTEXADAPTER_H_

#include "Vertex.h"
#include "Vertices.h"
#include "../core/Cell.h"

namespace topologicalSort {

using core::Cell;

class CellToVertexAdapter: public Vertex {
private:
	Cell *underlyingCell;
	bool visited;
	Vertices *adjacentVertices;

public:
	CellToVertexAdapter(Cell *c);
	virtual ~CellToVertexAdapter();

	void addAdjacent(Vertex *adjacentVertex);
	Vertices* getAdjacent();
	Cell* getUnderlyingCell();
	bool isVisited();
	void setVisited(bool visited);
};

} /* namespace topologicalSort */

#endif /* VERTEXADAPTER_H_ */
