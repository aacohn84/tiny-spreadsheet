/*
 * TopSorter.h
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */

#ifndef TOPSORTER_H_
#define TOPSORTER_H_

#include <stack>

#include "DAG.h"

namespace topologicalSort {

class TopSorter {
private:
	DAG *graph;

	void recursiveTopSort(Vertex *v, std::stack<Vertex *> &s);
	void sortByInDegrees(Vertices *v);

public:
	TopSorter(DAG *graph);
	virtual ~TopSorter();

	void sort();
};

} /* namespace core */

#endif /* TOPSORTER_H_ */
