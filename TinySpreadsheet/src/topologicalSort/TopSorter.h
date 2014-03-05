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
	shared_ptr<DAG> graph;

public:
	TopSorter(const shared_ptr<DAG> &graph);
	virtual ~TopSorter();

	VerticesPtr sort();
	void recursiveTopSort(Vertex &v, stack<VertexPtr> &s);
	void sortByInDegrees(Vertices &v);
};

} /* namespace core */

#endif /* TOPSORTER_H_ */