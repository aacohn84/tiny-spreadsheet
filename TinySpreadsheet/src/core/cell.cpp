/*
 * cell.cpp
 *
 *  Created on: Mar 4, 2014
 *      Author: trekkienz
 */
#include <cell.h>

class Cell {
private:
	Evaluator e;
	int nInDegrees;
	std::string rawInput;
	std::string displayInput;

public:
	std::vector dependencies;

	Cell(int degree){
		Cell('', degree);
	}

	Cell(std::string input, int degree){
		rawInput = input;
		nInDegrees = degree;
		e = new Evaluator();
		dependencies = new std::vector<Cell>;
	}

	void evalRowInput(std::string input) {
		rawInput = input;
		displayInput = e.eval(rawInput);
	}

	std::string getDisplayString() {
		return displayInput;
	}
};
