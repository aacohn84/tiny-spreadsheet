/*
 * CellsToVerticesAdapter.h
 *
 *  Created on: Apr 3, 2014
 *      Author: Aaron Cohn
 */

#ifndef CELLSTOVERTICESADAPTER_H_
#define CELLSTOVERTICESADAPTER_H_

#include <vector>

#include "Vertices.h"
#include "CellToVertexAdapter.h"
#include "../core/Cell.h"
#include "../core/DAG.h"

namespace topologicalSort {

class CellsToVerticesAdapter: public Vertices {
private:
	std::vector<Vertex*> cellsAsVertices;

public:
	CellsToVerticesAdapter(std::vector<core::Cell*> &cells, core::DAG *graph);
	virtual ~CellsToVerticesAdapter();

	std::vector<Vertex*>::iterator begin();
	std::vector<Vertex*>::iterator end();
	void add(Vertex *v);
	void clear();
};

} /* namespace topologicalSort */

#endif /* CELLSTOVERTICESADAPTER_H_ */
