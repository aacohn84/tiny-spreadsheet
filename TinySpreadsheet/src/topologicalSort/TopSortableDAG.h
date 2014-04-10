/*
 * TopSortableDAG.h
 *
 *  Created on: Apr 10, 2014
 *      Author: Aaron Cohn
 */

#ifndef TOPSORTABLEDAG_H_
#define TOPSORTABLEDAG_H_

#include "../core/DAG.h"
#include "DAG.h"
#include "Vertices.h"

namespace topologicalSort {

class TopSortableDAG: public topologicalSort::DAG, public core::DAG {
public:
	TopSortableDAG(core::DAG *graph);
	~TopSortableDAG();

	VerticesPtr getVertices();
};

} /* namespace topologicalSort */

#endif /* TOPSORTABLEDAG_H_ */
