/*
 * TopSortableDAG.h
 *
 *  Created on: Apr 10, 2014
 *      Author: Aaron Cohn
 */

#ifndef TOPSORTABLEDAG_H_
#define TOPSORTABLEDAG_H_

#include <map>

#include "CellsToVerticesAdapter.h"
#include "DAG.h"
#include "Vertices.h"
#include "TopSorter.h"
#include "../core/DAG.h"

namespace topologicalSort {

class TopSortableDAG: public topologicalSort::DAG {
private:
	core::DAG *underlyingDag;
	CellsToVerticesAdapter cellsAsVertices;
	std::map<Cell*, Vertex*> vertexTable;

public:
	TopSortableDAG(core::DAG *graph);
	~TopSortableDAG();

	Vertices* getVertices();
	void sort();
};

} /* namespace topologicalSort */

#endif /* TOPSORTABLEDAG_H_ */
