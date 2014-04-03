/*
 * Cell.cpp
 *
 *  Created on: Mar 6, 2014
 *      Author: trekkienz
 */
#include <Cell.h>

namespace core {
Cell::Cell(string _name, string _rawInput)
{
	name = _name;
	rawInput = _rawInput;
	numValue = 0;
	hasNumValue = false;
	hasError = false;
	dependencies = new vector<string>;
	displayValue = _rawInput;
}
}
