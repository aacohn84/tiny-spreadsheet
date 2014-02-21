/*
 * TopSorter.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */

#include "TopSorter.h"

namespace topologicalSort {

TopSorter::TopSorter(const shared_ptr<DAG> &graph)
	: graph(graph)
{
}

TopSorter::~TopSorter()
{
}

} /* namespace core */
