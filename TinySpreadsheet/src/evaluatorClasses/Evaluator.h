/*
 * Evaluator.h
 *
 *  Created on: Feb 20, 2014
 *      Author: Grell
 */

#ifndef EVALUATOR_H_
#define EVALUATOR_H_
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Cell
{
public:
	Cell(string _name, string _rawInput);
	~Cell();
	string name;
	bool hasNumValue;
	bool hasError;
	string rawInput;
	double numValue;
	vector<Cell*>* dependencies;
};


class Evaluator
{
	Cell* currentCell;
	char currentChar;
	vector<char*> operators;
	vector<char*> values;
public:
	Evaluator();
	~Evaluator();
	void evaluate(Cell* targetCell);
private:
	void evaluateExpression();
	double calculateNumValue();
	bool isNumber();
};



#endif /* EVALUATOR_H_ */
