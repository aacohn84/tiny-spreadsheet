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
	vector<string>* dependencies;
};

class Dag
{
public:
	Dag();
	~Dag();
	vector<Cell*>* allCells;
	Cell* getCell(string cellName);
	void addCell(Cell* newCell);
};

class Evaluator
{
public:
	Evaluator();
	~Evaluator();
	void evaluate(Cell* targetCell);
	Dag myDag;
	void evalAllCells();
	void printAllCells();
private:
	void evaluateExpression(Cell* targetCell);
	double calculateNumValue();
	bool isNumber(string rawInput);
	int getCharType(char input);
	void evaluateBuffer(string myBuffer, vector<float>* myValues, Cell* myCell, bool* includeNonNumCell);

};



#endif /* EVALUATOR_H_ */
