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
	// Variables
	Evaluator e;
	int nInDegrees;
	std::string rawInput;
	std::string displayInput;
public:
	// Variables
	std::vector children;

	// Methods
	Cell(int degree);
	Cell(std::string input, int degree);
	void evalRowInput(std::string input);
	std::string getDisplayString();
};



#endif /* CELL_H_ */
