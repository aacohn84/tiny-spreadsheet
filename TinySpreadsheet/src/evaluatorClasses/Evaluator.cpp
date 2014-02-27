/*
 * Evaluator.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: Grell
 */
#include "Evaluator.h"
#include <cctype>

Cell::Cell(string _name, string _rawInput)
{
	name = _name;
	rawInput = _rawInput;
	numValue = 0;
	hasNumValue = false;
	hasError = false;
	dependencies = 0;
}


Evaluator::Evaluator()
{
}

void Evaluator::evaluate(Cell* targetCell)
{
	currentCell = targetCell;
	if (currentCell->rawInput.length())
	{
		currentChar = currentCell->rawInput[0];
		if ( currentChar == '=')
		{
			evaluateExpression();
		}
		else if(isNumber())
		{
			currentCell->numValue = ::atof(currentCell->rawInput.c_str());
			currentCell->hasNumValue = true;
			currentCell->hasError = false;
			currentCell->dependencies = 0;
		}
		else
		{
			currentCell->hasNumValue = false;
			currentCell->dependencies = 0;
			currentCell->hasError = false;
		}
	}
}

bool Evaluator::isNumber()
{
	bool hasDot = false;
	int length = currentCell->rawInput.length();
	for (int i = 0; i < length; i++)
	{
		currentChar = currentCell->rawInput[i];
		if(currentChar == '.')
		{
			if (hasDot)
				return false;
			else
				hasDot = true;
		}
		else if (!isdigit(currentChar))
			return false;
	}
	return true;
}

enum types{
	CELLNAME = 0,
	NUMBER = 1,
	OPERATOR = 2,
	SPACE = 3
};

void Evaluator::evaluateExpression() //a10
{
	if (currentCell->rawInput.length() > 1)
	{
		string aCellName;
		string aNumber;
		double aNumberValue;
		char anOperator;
		for(int i = 0; i < currentCell->rawInput.length(); i++)
		{
			currentChar = currentCell->rawInput[i];
			if (currentChar == ' ')
			{}
		}
	}
}
