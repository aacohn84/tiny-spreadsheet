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
#include <DAG.cpp>
using namespace std;

//class Dag
//{
//public:
//	Dag();
//	~Dag();
//	vector<Cell*>* allCells;
//	Cell* getCell(string cellName);
//	void addCell(Cell* newCell);
//};

namespace core {

class Evaluator
{
public:
	Evaluator();
	~Evaluator();
	void evaluate(Cell* targetCell);
	DAG myDag;
	void evalAllCells();
	void printAllCells();
private:
	void evaluateExpression(Cell* targetCell);
	double calculateNumValue();
	bool isNumber(string rawInput);
	int getCharType(char input);
	void evaluateBuffer(string myBuffer, vector<float>* myValues, Cell* myCell, bool* includeNonNumCell);

};

}


#endif /* EVALUATOR_H_ */
