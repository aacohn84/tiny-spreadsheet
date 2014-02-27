/*
 * cell.h
 *
 *  Created on: Feb 26, 2014
 *      Author: trekkienz
 */

#ifndef CELL_H_
#define CELL_H_

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

class Cell {
private:
	Evaluator e;
	std::vector children;
	int nInDegrees;
	std::string rawInput;
	std::string displayInput;
public:
	Cell();
	Cell(std::string input);
	std::string evalRowInput(std::string input);
	std::string getDisplayString();
};



#endif /* CELL_H_ */
