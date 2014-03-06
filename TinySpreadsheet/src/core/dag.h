/*
 * dag.h
 *
 *  Created on: Mar 6, 2014
 *      Author: trekkienz
 */

#ifndef DAG_H_
#define DAG_H_

#include <map>
#include <vector>
#include <string>

class DAG {
private:
	// Variables
	std::map<std::string, Cell> dag;
	std::vector<Cell> cells;

	// Methods
	bool exists(std::string key);

public:
	// Constructor
	DAG();

	// Methods
	void addCell(std::string coord, Cell* input);
	Cell* getCell(std::string coord);
	std::map<std::string, Cell>* getMap();
	std::vector<Cell>* getCells();
	void setOrderedCells(std::vector<Cell>* cells);
};



#endif /* DAG_H_ */
