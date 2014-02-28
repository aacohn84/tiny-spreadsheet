/*
 * TopSorter.h
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */

#ifndef TOPSORTER_H_
#define TOPSORTER_H_

#include "DAG.h"
#include <memory>

namespace topologicalSort {

using std::shared_ptr;

class TopSorter {
	shared_ptr<DAG> graph;

public:
	TopSorter(const shared_ptr<DAG> &graph);
	virtual ~TopSorter();

	Vertices sort();
};

} /* namespace core */

#endif /* TOPSORTER_H_ */
