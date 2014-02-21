/*
 * TopSorter.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */

#include "topologicalSort/TopSorter.h"

namespace topologicalSort {

TopSorter::TopSorter(DAG *graph) {
	this->graph = graph;
}

TopSorter::~TopSorter() {}

} /* namespace core */
