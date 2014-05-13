/*
 * TopSortableDAG.h
 *
 *  Created on: Apr 10, 2014
 *      Author: Aaron Cohn
 */

#ifndef TOPSORTABLEDAG_H_
#define TOPSORTABLEDAG_H_

#include <map>

#include "Vertices.h"
#include "TopSorter.h"
#include "../core/DAG.h"

namespace topologicalSort {

using core::Cell;

class TopSortableDAG {
private:
	core::DAG *underlyingDag;
	Vertices cellsAsVertices;
	std::map<Cell*, Vertex*> vertexTable;

public:
	TopSortableDAG(core::DAG *graph);
	~TopSortableDAG();

	void sort();
};

} /* namespace topologicalSort */

#endif /* TOPSORTABLEDAG_H_ */
