/*
 * Evaluator.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: Grell
 */
#include "Evaluator.h"
#include <cctype>
//valid cell names consist of a single letter followed by a string of digits that doesn't start with 0
#include <iostream>
#include <sstream>

using namespace std;
Cell::Cell(string _name, string _rawInput)
{
	name = _name;
	rawInput = _rawInput;
	numValue = 0;
	hasNumValue = false;
	hasError = false;
	dependencies = 0;
	displayValue = _rawInput;
}


Evaluator::Evaluator()
{
}
Evaluator::~Evaluator()
{}
Dag::Dag()
{
	allCells = new vector<Cell*>();
}
Dag::~Dag()
{}



Cell* Dag::getCell(string cellName)
{
	for(unsigned i = 0; i < allCells->size(); i++)
	{
		if (allCells->at(i)->name == cellName)
		{
			return allCells->at(i);
		}
	}
	return NULL;
}


void Dag::addCell(Cell* newCell)
{
	Cell* temp = getCell(newCell->name);
	if (newCell->hasNumValue)
	{
		stringstream ss (stringstream::in | stringstream::out);
		ss << newCell->numValue;
		newCell->displayValue = ss.str();
	}
	if(!temp)
	{
		allCells->push_back(newCell);
	}
	else
	{
		temp->rawInput = newCell->rawInput;
		temp->numValue = newCell->numValue;
		temp->hasNumValue = newCell->hasNumValue;
		temp->hasError = newCell->hasError;
		temp->dependencies = newCell->dependencies;
		temp->displayValue = newCell->displayValue;
	}
}

void Evaluator::evalAllCells()
{
	for (unsigned i = 0; i < myDag.allCells->size(); i++)
	{
		evaluate(myDag.allCells->at(i));
	}
}

void Evaluator::printAllCells()
{
	Cell* temp;
	for (unsigned i = 0; i < myDag.allCells->size(); i++)
	{
		temp = myDag.allCells->at(i);
		cout << "Cell " << temp->name << endl;
		cout << "Has " << temp->dependencies << " dependencies\n";
		cout << "Raw Input: " << temp->rawInput << endl;
		cout << "Display Value: " << temp->displayValue << endl;
		if (temp->hasNumValue)
			cout << "Numerical value: " << temp->numValue << endl << endl;
		else
			cout << "No numerical value.\n\n";
	}
}

void Evaluator::evaluate(Cell* targetCell)
{
	Cell* currentCell = targetCell;
	currentCell->dependencies = 0;
	currentCell->hasError = false;
	currentCell->hasNumValue = false;


	if (currentCell->rawInput.length())
	{
		if ( currentCell->rawInput[0] == '=')
		{
			evaluateExpression(currentCell);
		}
		else if(isNumber(currentCell->rawInput))
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
	myDag.addCell(currentCell);
}

bool Evaluator::isNumber(string rawInput)
{
	char currentChar;
	bool hasDot = false;
	int length = rawInput.length();
	for (int i = 0; i < length; i++)
	{
		currentChar = rawInput[i];
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
	LETTER = 0,
	NUMBER = 1,
	OPERATOR = 2,
	SPACE = 3,
	ERROR = 4
};

int Evaluator::getCharType(char input)
{
	if((isdigit(input)) || (input == '.'))
		return NUMBER;
	else if(isalpha(input))
		return LETTER;
	else if(input == ' ')
		return SPACE;
	else if((input == '-') || (input == '+') || (input == '/') || (input == '*'))
		return OPERATOR;
	else
		return ERROR;
}

void Evaluator::evaluateBuffer(string buffer, vector<float>* values, Cell* currentCell, bool* includesNonNumCell)
{
	if (buffer != "")
	{
		char currentChar = buffer[0];
		int charType = getCharType(currentChar);
		if (charType == NUMBER)
		{
			if(isNumber(buffer))
				values->push_back(::atof(buffer.c_str()));
		}
		else if (charType == LETTER)
		{
			if (buffer.length() > 1)
			{
				for(unsigned i = 1; i < buffer.length(); i++)
				{
					if (!isdigit(buffer[i]))
						currentCell->hasError = true;
				}
				currentCell->dependencies++;
				Cell* aCell = myDag.getCell(buffer);
				if(myDag.getCell(buffer))
				{
					if (aCell->hasNumValue)
					{
						values->push_back(aCell->numValue);
						buffer = "";
					}
					else
					{
						if (values->size() != 0)
						{
			//### Expression contains non-numeric value!!!
							currentCell->hasError = true;
						}
						else
						{
							*includesNonNumCell = true;
							currentCell->hasNumValue = false;
							currentCell->displayValue = aCell->displayValue;
						}
					}
				}
				else
				{
					*includesNonNumCell = true;
					currentCell->hasNumValue = false;
					currentCell->displayValue = "Unresolved Dependency";
				}
			}
		}
	}
}

void Evaluator::evaluateExpression(Cell* currentCell) //a10
{
	if (currentCell->rawInput.length() > 1)
	{
		bool negativeStart = false;
		bool* includesNonNumCell = new bool();
		*includesNonNumCell = false;
		vector<char>* operators = new vector<char>();
		vector<float>* values = new vector<float>();
		char currentChar;
		int prevType = SPACE;
		int charType;
		string buffer = "";

		for(unsigned i = 1; i < currentCell->rawInput.length(); i++)
		{
			currentChar = currentCell->rawInput[i];
			charType = getCharType(currentChar);
			if (charType == SPACE)
			{
				if(buffer != "")
				{
					evaluateBuffer(buffer,values,currentCell, includesNonNumCell);
					buffer = "";
				}
				prevType = SPACE;
			}
			else if (charType == OPERATOR)
			{
				if((prevType == OPERATOR) || (*includesNonNumCell == true))
				{
					currentCell->hasError = true;
					cout << "double operator or nonNumCell + operator\n";
					break;
				}
				else
				{
					if(buffer != "")
					{
						evaluateBuffer(buffer,values,currentCell, includesNonNumCell);
						buffer = "";

					}
					if(values->size() == 0)
					{
						if(currentChar == '-')
						{
							negativeStart = true;
						}
						else
						{
							currentCell->hasError = true;
							currentCell->displayValue = "Invalid Syntax";
							cout << "Expression started on an operator other than '-'.\n";
							break;
						}
					}
					else
					{
						operators->push_back(currentChar);
						prevType = OPERATOR;
					}
				}
			}
			else if (charType == LETTER)
			{
				if ((prevType == NUMBER) || (prevType == LETTER) || (*includesNonNumCell == true))
				{
					currentCell->hasError = true;
					break;
				}
				else
				{
					buffer.push_back(currentChar);
					prevType = LETTER;
				}
			}
			else if ((charType == NUMBER) && (*includesNonNumCell == false))
			{
				prevType = NUMBER;
				buffer.push_back(currentChar);
			}
			else
			{
				cout << "illegal character\n";
				currentCell->hasError = true;
				break;
			}
		}
		if (buffer != "")
		{
			evaluateBuffer(buffer,values,currentCell, includesNonNumCell);
			buffer = "";

		}




//######## calculating the numerical value if possible. ################
		if((!currentCell->hasError) && (!*includesNonNumCell) && (values->size() > 0))
		{
			if(negativeStart)
				values->at(0) *= -1.0;

			for(unsigned i = 0; i < operators->size(); i++)
			{
				if(operators->at(i) == '*')
				{
					values->at(i) *= values->at(i+1);
					values->erase(values->begin() + i + 1);
					operators->erase(operators->begin() + i);
					i--;
				}
				else if (operators->at(i) == '/')
				{
					if(values->at(i + 1) == 0)
					{
						currentCell->hasError = true;
						currentCell->displayValue = "Division by zero";
						break;
					}
					values->at(i) /= values->at(i + 1);
					values->erase(values->begin() + i + 1);
					operators->erase(operators->begin() + i);
					i--;
				}
			}
			for(unsigned i = 0; i < operators->size(); i++)
			{
				if(currentCell->hasError)
					break;
				if(operators->at(i) == '+')
				{
					values->at(i) += values->at(i + 1);
					values->erase(values->begin() + i + 1);
					operators->erase(operators->begin() + i);
					i--;
				}
				else if (operators->at(i) == '-')
				{
					values->at(i) -= values->at(i + 1);
					values->erase(values->begin() + i + 1);
					operators->erase(operators->begin() + i);
					i--;
				}
			}
			currentCell->hasNumValue = true;
			currentCell->numValue = values->at(0);

		}

	}
	else//if there's nothing but an equal sign in there
	{
		currentCell->hasError = true;
	}
	if (currentCell->hasError)
	{
		currentCell->hasNumValue = false;
		currentCell->dependencies = 0;
	}
}
