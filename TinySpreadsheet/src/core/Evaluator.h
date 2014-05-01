/*
* Evaluator.h
*
*  Created on: Feb 20, 2014
*      Author: Grell
*/

#ifndef EVALUATOR_H
#define EVALUATOR_H
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Cell.h"
#include "DAG.h"

namespace core{

	using namespace std;



	class Evaluator
	{
	public:
		Evaluator(DAG* aDAG);
		~Evaluator();
		Cell* evaluate(Cell* targetCell);
		DAG* myDAG;
		void evalAllCells();
		void printAllCells();
	private:
		void evaluateExpression(Cell* targetCell);
		double calculateNumValue();
		bool isNumber(string rawInput);
		int getCharType(char input);
		void evaluateBuffer(string myBuffer, vector<float>* myValues, Cell* myCell, bool* includeNonNumCell);
		float addUp(vector<float>* values, vector<char>* operators, Cell* currentCell);
	};

}

#endif /* EVALUATOR_H_ */
