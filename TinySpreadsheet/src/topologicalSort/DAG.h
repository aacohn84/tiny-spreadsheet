/*
 * DAG.h
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */

#ifndef TOPOLOGICAL_SORT_DAG_H_
#define TOPOLOGICAL_SORT_DAG_H_

#include "Vertices.h"

namespace topologicalSort {

// An interface representing a directed acyclic graph
class DAG {
public:
	virtual ~DAG() {}

	virtual Vertices* getVertices() = 0;
};

} /* namespace topologicalSort */

#endif /* TOPOLOGICAL_SORT_DAG_H_ */
