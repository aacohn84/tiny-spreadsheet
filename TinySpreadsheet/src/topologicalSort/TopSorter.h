/*
 * TopSorter.h
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */

#ifndef TOPSORTER_H_
#define TOPSORTER_H_

#include "DAG.h"

namespace topologicalSort {

class TopSorter {
	DAG *graph;

public:
	TopSorter(DAG *graph);
	virtual ~TopSorter();

	Vertices sort();
};

} /* namespace core */

#endif /* TOPSORTER_H_ */
