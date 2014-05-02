/*
 * ExampleMain.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: Aaron Cohn
 */

#include <string>
#include <stdlib.h>
#include <iostream>
#include "Evaluator.h"
#include "../topologicalSort/TopSorter.h"
#include "../topologicalSort/TopSortableDAG.h"
#include "DAG.h"

using namespace std;
using namespace core;
using topologicalSort::TopSortableDAG;
using topologicalSort::TopSorter;

int main() {
	/*
	 * This file may not be needed since we're using Qt. Bottom line is, there
	 * has to be a main() somewhere, but not necessarily here. Right now, this
	 * file exists just for you to test that you can compile the project
	 * correctly.
	 *
	 * NOTE:
	 * main() cannot be defined in a namespace. It has to live in global scope.
	 */

	DAG theDag;
	Evaluator* myEvaluator = new Evaluator(&theDag);
	Cell* a1 = new Cell("A1", "=B3 + 2");
	Cell* b3 = new Cell("B3", "5");
	Cell* c2 = new Cell("C2", "I love cats");
	Cell* d1 = new Cell("D1", "= C2");

	//myEvaluator.evaluate(c2);


	myEvaluator->evaluate(a1);
	myEvaluator->evaluate(b3);
	myEvaluator->evaluate(c2);
	myEvaluator->evaluate(d1);
	myEvaluator->evalAllCells();
	myEvaluator->printAllCells();
	cout << "done";

	//DAG theDag;
	/*theDag.updateCell(a1);
	theDag.updateCell(b3);
	theDag.updateCell(c2);
	theDag.updateCell(d1);*/
	//TopSortableDAG sortableDag(&theDag);
	//sortableDag.sort();
	myEvaluator->evalAllCells();
	myEvaluator->printAllCells();
	return 0;
}
