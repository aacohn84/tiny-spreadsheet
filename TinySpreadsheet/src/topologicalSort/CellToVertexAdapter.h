/*
 * VertexAdapter.h
 *
 *  Created on: Mar 6, 2014
 *      Author: Aaron Cohn
 */

#ifndef VERTEXADAPTER_H_
#define VERTEXADAPTER_H_

#include <memory>

#include "Vertex.h"
#include "../core/Cell.h"
#include "../core/DAG.h"

namespace topologicalSort {

using core::Cell;

class CellToVertexAdapter: public Vertex {
private:
	core::DAG *graph;
	Cell *underlyingCell;
	bool visited;
	int inDegrees;
public:
	CellToVertexAdapter(Cell *c, core::DAG *graph);
	virtual ~CellToVertexAdapter();

	Vertices* getAdjacent();
	int getInDegrees();
	void addInDegree();
	bool isVisited();
	void setVisited(bool visited);
};

} /* namespace topologicalSort */

#endif /* VERTEXADAPTER_H_ */
