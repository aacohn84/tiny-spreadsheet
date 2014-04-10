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

class CellsToVerticesAdapter: public Vertices {
public:
	CellsToVerticesAdapter(std::vector<Cell*> *cells, core::DAG *graph);
	virtual ~CellsToVerticesAdapter();
};

} /* namespace topologicalSort */

#endif /* CELLSTOVERTICESADAPTER_H_ */
