/*
 * Cell.h
 *
 *  Created on: Mar 6, 2014
 *      Author: trekkienz
 */

#ifndef CELL_H_
#define CELL_H_

namespace core {

using std::string;
using std::vector;

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

} /* namespace core */

#endif /* CELL_H_ */
