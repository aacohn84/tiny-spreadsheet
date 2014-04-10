/*
 * DAG.h
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */

#ifndef TOPOLOGICAL_SORT_DAG_H_
#define TOPOLOGICAL_SORT_DAG_H_

#include <memory>

#include "Vertices.h"

namespace topologicalSort {

using std::shared_ptr;

// An interface representing a directed acyclic graph
class DAG {
public:
	virtual ~DAG() {}

	virtual VerticesPtr getVertices() = 0;
};

typedef shared_ptr<DAG> DAGPtr;

} /* namespace topologicalSort */

#endif /* TOPOLOGICAL_SORT_DAG_H_ */
