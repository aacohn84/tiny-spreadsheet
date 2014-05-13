/*
 * Cell.h
 *
 *  Created on: Mar 6, 2014
 *      Author: trekkienz
 */

#ifndef CELL_H_
#define CELL_H_

#include <string>
#include <vector>

namespace core {

using std::string;
using std::vector;

class Cell
{
public:
	Cell(string _name, string _rawInput);
	string displayValue;
	string name;
	bool hasNumValue;
	bool hasError;
	string rawInput;
	string errorMessage;
	double numValue;
	vector<string> dependencies;
};

} /* namespace core */

#endif /* CELL_H_ */
