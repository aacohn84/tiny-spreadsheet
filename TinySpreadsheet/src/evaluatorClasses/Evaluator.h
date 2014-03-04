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
	string displayValue;
	string name;
	bool hasNumValue;
	bool hasError;
	string rawInput;
	double numValue;
	vector<Cell*>* dependencies;
};


class Evaluator
{

public:
	Evaluator();
	~Evaluator();
	void evaluate(Cell* targetCell);
private:
	Cell* getCell(string cellName);
	void evaluateExpression(Cell* targetCell);
	double calculateNumValue();
	bool isNumber(string rawInput);
	int getCharType(char input);
	bool evaluateBuffer(string myBuffer);
};



#endif /* EVALUATOR_H_ */
