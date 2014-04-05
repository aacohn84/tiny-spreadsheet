/*
 * CellsToVerticesAdapter.h
 *
 *  Created on: Apr 3, 2014
 *      Author: Aaron Cohn
 */

#ifndef CELLSTOVERTICESADAPTER_H_
#define CELLSTOVERTICESADAPTER_H_

#include "Vertices.h"
#include "../core/Cell.h"
#include "../core/DAG.h"
#include <vector>

namespace topologicalSort {

using core::Cell;
using core::DAG;

class CellsToVerticesAdapter: public Vertices {
public:
	CellsToVerticesAdapter(std::vector<Cell*> *cells, DAG *graph);
	virtual ~CellsToVerticesAdapter();
};

} /* namespace topologicalSort */

#endif /* CELLSTOVERTICESADAPTER_H_ */
