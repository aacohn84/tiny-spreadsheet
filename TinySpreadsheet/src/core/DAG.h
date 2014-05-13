/*
 * dag.h
 *
 *  Created on: Mar 6, 2014
 *      Author: trekkienz
 */

#ifndef CORE_DAG_H_
#define CORE_DAG_H_

#include <map>
#include <vector>
#include <string>
#include "Cell.h"

namespace core{

class DAG {
protected:
	// Variables
	std::map<std::string, Cell*> dag;
	std::vector<Cell*> cells;

	// Methods
	bool exists(std::string key);

public:
	// Constructor
	DAG();

	// Destructor
	~DAG();

	// Methods
	void updateCell(Cell* input);
	Cell* getCell(std::string coord);
	std::map<std::string, Cell*>* getMap();
	std::vector<Cell*>* getCells();
	void setOrderedCells(std::vector<Cell*>* cells);
};
}


#endif /* CORE_DAG_H_ */
