/*
 * Evaluator.cpp
 *
 *  Created on: Feb 20, 2014
 *      Author: Grell
 */
#include "Evaluator.h"
#include <cctype>
//valid cell names consist of a single letter followed by a string of digits that doesn't start with 0


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
	Cell* currentCell = targetCell;

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

Cell* Evaluator::getCell(string cellName)
{
	//actually return the cell here plz
	return NULL;
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

bool Evaluator::evaluateBuffer(string myBuffer)
{
	if (myBuffer != "")
	{
		char currentChar = myBuffer[0];
		int charType = getCharType(currentChar);
		if (charType == NUMBER)
		{
			if(isNumber(myBuffer))
				return true;
		}
		else if (charType == LETTER)
		{
			if (myBuffer.length() > 1)
			{
				for(int i = 1; i < myBuffer.length; i++)
				{
					if (!isdigit(myBuffer[i]))
						return false;
				}
				return true;
			}
		}
	}
	return false;
}

void Evaluator::evaluateExpression(Cell* currentCell) //a10
{
	if (currentCell->rawInput.length() > 1)
	{
		bool negativeStart = false;
		bool includesNonNumCell = false;
		vector<char>* operators;
		vector<float>* values;
		char currentChar;
		int prevType = SPACE;
		int charType;
		string buffer = "";

		for(int i = 1; i < currentCell->rawInput.length(); i++)
		{
			currentChar = currentCell->rawInput[i];
			charType = getCharType(currentChar);
			if (charType == SPACE)
			{
				if(buffer != "")
				{
					if(evaluateBuffer(buffer))
					{
						if (getCharType(buffer[0]) == NUMBER)
						{
							values->push_back(::atof(buffer.c_str()));
							buffer = "";
						}
						else
						{
							currentCell->dependencies++;
							Cell* aCell = getCell(buffer);
							if(getCell(buffer))
							{
								if (aCell->hasNumValue)
								{
									values->push_back(aCell->numValue);
								}
								else
								{
									if ((operators->size() != 0) || (values->size() != 0))
									{
						//### Expression contains non-numeric value!!!
										currentCell->hasError = true;
										break;
									}
									else
									{
										includesNonNumCell = true;
										currentCell->hasNumValue = false;
										currentCell->displayValue = aCell->displayValue;
									}
								}
							}
							else
							{
								includesNonNumCell = true;
								currentCell->hasNumValue = false;
								currentCell->displayValue = "Unresolved Dependency";
							}
						}
						if (values->size() > operators->size() + 1)
						{
							currentCell->hasError = true;
							currentCell->displayValue = "invalid syntax";
							break;
						}
					}
				}
				prevType == SPACE;
			}
			else if (charType == OPERATOR)
			{
				if((prevType == OPERATOR) || (includesNonNumCell == true))
				{
					currentCell->hasError = true;
					break;
				}
				else
				{
					if(buffer != "")
					{
						if(evaluateBuffer(buffer))
						{
							//ought to make this part of the function
							if (getCharType(buffer[0]) == NUMBER)
							{
								values->push_back(::atof(buffer.c_str()));
								buffer = "";
							}
							else
							{
								currentCell->dependencies++;
								Cell* aCell = getCell(buffer);
								if(getCell(buffer))
								{
									if (aCell->hasNumValue)
									{
										values->push_back(aCell->numValue);
									}
									else
									{
										if ((operators->size() != 0) || (values->size() != 0))
										{
									//### Expression contains non-numeric value!!!
											currentCell->hasError = true;
											break;
										}
										else
										{
											includesNonNumCell = true;
											currentCell->hasNumValue = false;
											currentCell->displayValue = aCell->displayValue;
										}
									}
								}
								else
								{
									includesNonNumCell = true;
									currentCell->hasNumValue = false;
									currentCell->displayValue = "Unresolved Dependency";
								}
							}
							if (values->size() > operators->size() + 1)
							{
								currentCell->hasError = true;
								currentCell->displayValue = "invalid syntax";
								break;
							}
							//put stuff into stacks
						}
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
							break;
						}
					}
					operators->push_back(currentChar);
					prevType = OPERATOR;
				}
			}
			else if (charType == LETTER)
			{
				if ((prevType == NUMBER) || (prevType == LETTER) || (includesNonNumCell == true))
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
			else if ((charType == NUMBER) && (includesNonNumCell == false))
			{
				prevType = NUMBER;
				buffer.push_back(currentChar);
			}
			else
			{
				currentCell->hasError = true;
				break;
			}
		}
//calculating the numerical value if possible.
		if((!currentCell->hasError) && (!includesNonNumCell))
		{

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
