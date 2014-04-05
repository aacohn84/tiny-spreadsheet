/*
 * TopSorter.h
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */

#ifndef TOPSORTER_H_
#define TOPSORTER_H_

#include <memory>

#include "DAG.h"

namespace topologicalSort {

using std::shared_ptr;
using std::stack;

class TopSorter {
private:
	DAGPtr graph;

	void recursiveTopSort(VertexPtr &v, stack<VertexPtr> &s);
	void sortByInDegrees(VerticesPtr &v);

public:
	TopSorter(DAGPtr graph);
	virtual ~TopSorter();

	VerticesPtr sort();
};

} /* namespace core */

#endif /* TOPSORTER_H_ */
