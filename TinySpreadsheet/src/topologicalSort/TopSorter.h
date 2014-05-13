/*
 * TopSorter.h
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */

#ifndef TOPSORTER_H_
#define TOPSORTER_H_

#include <deque>

#include "Vertices.h"

namespace topologicalSort {

class TopSorter {
private:
	void recursiveTopSort(Vertex *v, std::deque<Vertex *> &s);

public:
	void sort(Vertices &vertices);
};

} /* namespace core */

#endif /* TOPSORTER_H_ */
