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
#include <regex>

namespace core{

	using namespace std;


	Evaluator::Evaluator(DAG* aDag)
	{
		myDAG = aDag;
	}
	Evaluator::~Evaluator()
	{}


	void Evaluator::evalAllCells()
	{
		cout << "evaling all cells\n";
		vector<Cell*>* myCells = myDAG->getCells();
		for (unsigned i = 0; i < myCells->size(); i++)
		{
			evaluate(myCells->at(i));
		}
	}

	void Evaluator::printAllCells()
	{
		vector<Cell*>* myCells = myDAG->getCells();
		Cell* temp;
		for (unsigned i = 0; i < myCells->size(); i++)
		{
			temp = myCells->at(i);
			cout << "Cell " << temp->name << endl;
			cout << "Has " << temp->dependencies->size() << " dependencies:";
			for (unsigned j = 0; j < temp->dependencies->size(); j++)
			{
				cout << " " << temp->dependencies->at(j);
			}
			cout << "\nRaw Input: " << temp->rawInput << endl;
			cout << "Display Value: " << temp->displayValue << endl;
			if (temp->hasNumValue)
				cout << "Numerical value: " << temp->numValue << endl;
			else
				cout << "No numerical value.\n";
			cout << "Errors: " << temp->errorMessage << endl << endl;
		}
	}

	Cell* Evaluator::evaluate(Cell* targetCell)
	{
		Cell* currentCell = targetCell;
		currentCell->hasError = false;
		currentCell->hasNumValue = false;
		currentCell->displayValue = currentCell->rawInput;
		currentCell->errorMessage = "No errors.";
		currentCell->dependencies->clear();


		if (currentCell->rawInput.length())
		{
			if (currentCell->rawInput[0] == '=')
			{
				evaluateExpression(currentCell);
			}
			else if (isNumber(currentCell->rawInput))
			{
				currentCell->numValue = ::atof(currentCell->rawInput.c_str());
				currentCell->hasNumValue = true;
				stringstream ss(stringstream::in | stringstream::out);
				ss << currentCell->numValue;
				currentCell->displayValue = ss.str();
			}
			else
			{
				currentCell->hasNumValue = false;
			}
		}
		myDAG->updateCell(currentCell);
		return currentCell;
	}

	bool Evaluator::isNumber(string rawInput)
	{
		char currentChar;
		bool hasDot = false;
		int length = rawInput.length();
		for (int i = 0; i < length; i++)
		{
			currentChar = rawInput[i];
			if (currentChar == '.')
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
		ERROR = 4,
		LEFT_PAREN = 5,
		RIGHT_PAREN = 6
	};

	int Evaluator::getCharType(char input)
	{
		if ((isdigit(input)) || (input == '.'))
			return NUMBER;
		else if (isalpha(input))
			return LETTER;
		else if (input == ' ')
			return SPACE;
		else if ((input == '-') || (input == '+') || (input == '/') || (input == '*'))
			return OPERATOR;
		else if (input == '(')
			return LEFT_PAREN;
		else if (input == ')')
			return RIGHT_PAREN;
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
				if (isNumber(buffer))
					values->push_back(::atof(buffer.c_str()));
			}
			else if (charType == LETTER)
			{
				if (buffer.length() > 1)
				{
					for (unsigned i = 1; i < buffer.length(); i++)
					{
						if (!isdigit(buffer[i]))
						{
							currentCell->errorMessage = "Expression contains an invalid cell name.";
							currentCell->hasError = true;
						}
						else
						{
							bool alreadyThere = false;
							for (unsigned i = 0; i < currentCell->dependencies->size(); i++)
							{
								if (currentCell->dependencies->at(i) == buffer)
								{
									alreadyThere = true;
									break;
								}
							}
							if (!alreadyThere)
								currentCell->dependencies->push_back(buffer);
						}
					}
					Cell* aCell = myDAG->getCell(buffer);
					if (aCell)
					{
						if (aCell->hasNumValue)
						{
							values->push_back(aCell->numValue);
							buffer = "";
						}
						else
						{
							*includesNonNumCell = true;
							if (values->size() != 0)
							{
								//### Expression contains non-numeric value!!!
								currentCell->errorMessage = "Expression contains a reference to a cell with a non-numeric value, says buffer evaluator.";
								currentCell->hasError = true;
							}
							else
							{
								currentCell->hasNumValue = false;
								currentCell->displayValue = aCell->displayValue;
							}
						}
					}
					else
					{
						*includesNonNumCell = true;
						currentCell->hasNumValue = false;
						currentCell->displayValue = currentCell->rawInput;
						currentCell->errorMessage = "Expression contains reference to an uninitialized cell.";
					}
				}
				else
				{
					currentCell->hasError = true;
					currentCell->errorMessage = "Expression contains incomplete cell name.";
				}
			}
		}
	}

	void Evaluator::evaluateExpression(Cell* currentCell)
	{
		if (currentCell->rawInput.length() > 1)
		{
			bool* includesNonNumCell = new bool();
			*includesNonNumCell = false;
			vector<char>* operators = new vector<char>();
			vector<float>* values = new vector<float>();
			char currentChar;
			int parenCount = 0;
			int prevType = LEFT_PAREN;
			int charType;
			string buffer = "";
			int deepestParenNest = 0;

			for (unsigned i = 1; i < currentCell->rawInput.length(); i++)
			{
				currentChar = currentCell->rawInput[i];
				charType = getCharType(currentChar);
				if (charType == SPACE)
				{
					if (buffer != "")
					{
						evaluateBuffer(buffer, values, currentCell, includesNonNumCell);
						buffer = "";
					}
					//prevType = SPACE;
				}
				else if (charType == OPERATOR)
				{
					if (prevType == OPERATOR)
					{
						currentCell->errorMessage = "Expression contains subsequent operators.";
						currentCell->hasError = true;
						break;
					}
					else if (prevType == LEFT_PAREN)
					{
						if (currentChar != '-')
						{
							currentCell->hasError = true;
							currentCell->errorMessage = "Expression in paren started with an operator other than '-'.";
							break;
						}
						else
						{
							operators->push_back(currentChar);
							prevType = OPERATOR;
							//dealing with paren stuffs.
						}
					}
					else
					{
						if (buffer != "")
						{
							evaluateBuffer(buffer, values, currentCell, includesNonNumCell);
							buffer = "";
						}
						if (*includesNonNumCell == true)
						{
							currentCell->hasError = true;
							currentCell->errorMessage = "Expression contains a reference to a cell with a non-numeric value, says expression evaluator.";
							break;
						}
						else if ((values->size() == 0) && (currentChar != '-'))
						{
							currentCell->hasError = true;
							currentCell->errorMessage = "Expression started on an operator other than '-'.\n";
							break;
						}
						else
						{
							operators->push_back(currentChar);
						}
						prevType = OPERATOR;
					}
				}
				else if (charType == LETTER)
				{
					if ((prevType == NUMBER) || (prevType == LETTER) || (*includesNonNumCell == true))
					{
						currentCell->hasError = true;
						currentCell->errorMessage = "Invalid expression.";
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
					if ((buffer == "") && (prevType != OPERATOR) && (prevType != LEFT_PAREN))
					{
						currentCell->hasError = true;
						currentCell->errorMessage = "Invalid expression. You may have omitted an operator.";
						break;
					}
					prevType = NUMBER;
					buffer.push_back(currentChar);
				}
				else if (charType == LEFT_PAREN)
				{
					if ((prevType == OPERATOR) || (prevType == LEFT_PAREN))
					{
						parenCount++;
						if (parenCount > deepestParenNest)
							deepestParenNest = parenCount;
						prevType = LEFT_PAREN;
						operators->push_back('(');
						values->push_back('(');
					}
					else
					{
						currentCell->hasError = true;
						currentCell->errorMessage = "Illegal expression. You may have omitted an operator in front of left paren.";
						break;
					}
				}
				else if (charType == RIGHT_PAREN)
				{
					if (parenCount < 0)
					{
						currentCell->hasError = true;
						currentCell->errorMessage = "Expression contains mismatched parenthesis.";
						break;
					}
					else if (prevType == OPERATOR)
					{
						currentCell->hasError = true;
						currentCell->errorMessage = "Invalid expression within parenthesis.";
						break;
					}
					parenCount--;
					prevType = RIGHT_PAREN;
					operators->push_back(')');
					if (buffer != "")
					{
						evaluateBuffer(buffer, values, currentCell, includesNonNumCell);
						buffer = "";
					}
					values->push_back(')');
				}
				else
				{
					currentCell->errorMessage = "illegal character\n";
					currentCell->hasError = true;
					break;
				}
			}
			if (buffer != "")
			{
				evaluateBuffer(buffer, values, currentCell, includesNonNumCell);
				buffer = "";
			}
			if ((parenCount != 0) && (!currentCell->hasError))
			{
				currentCell->hasError = true;
				currentCell->errorMessage = "Expression contains mismatched parenthesis.";
			}

			//######## calculating the numerical value if possible. ################
			if (*includesNonNumCell && (values->size() > 1))
			{
				currentCell->hasError = true;
				currentCell->errorMessage = "Expression contains a reference to a cell with a non-numeric value.";
			}
			else if (values->size() == 0 && !(*includesNonNumCell))
			{
				currentCell->hasError = true;
				currentCell->errorMessage = "Expression is blank.";
			}
			else if ((values->size() != operators->size() + 1) && (values->size() != operators->size()))
			{
				currentCell->hasError = true;
				currentCell->errorMessage = "Mismatched number of operators and values.";
			}
			else
			{
				if (deepestParenNest != 0)
				{
					//deal with parens.
					unsigned depth = 0;
					vector<char>* tempOperators = new vector<char>();
					vector<float>* tempValues = new vector<float>();

					for (unsigned i = deepestParenNest; i > 0; i--)
					{
						for (unsigned j = 0; j < values->size(); j++)
						{
							if (values->at(j) == '(')
								depth++;
							else if (values->at(j) == ')')
								depth--;
							if (depth == i)
							{
								values->erase(values->begin() + j);
								while (values->at(j) != ')')
								{
									tempValues->push_back(values->at(j));
									values->erase(values->begin() + j);
								}
								depth = 0;
								for (unsigned k = 0; k < operators->size(); k++)
								{
									if (operators->at(k) == '(')
										depth++;
									else if (operators->at(k) == ')')
										depth--;
									if (depth == i)
									{
										operators->erase(operators->begin() + k);
										while (operators->at(k) != ')')
										{
											tempOperators->push_back(operators->at(k));
											operators->erase(operators->begin() + k);
										}
										values->at(j) = addUp(tempValues, tempOperators, currentCell);
										operators->erase(operators->begin() + k);
										tempValues->clear();
										tempOperators->clear();
										depth--;
									}
								}
							}
						}
					}
					delete(tempValues);
					delete(tempOperators);
				}
				if (!currentCell->hasError && !(*includesNonNumCell))
				{
					currentCell->numValue = addUp(values, operators, currentCell);
					if (!currentCell->hasError)
					{
						currentCell->hasNumValue = true;
					}
				}
			}
			delete(includesNonNumCell);
			delete(operators);
			delete(values);
		}
		else//if there's nothing but an equal sign in there
		{
			currentCell->hasError = true;
			currentCell->errorMessage = "Expression is blank";
		}
		if (currentCell->hasError)
		{
			currentCell->hasNumValue = false;
			currentCell->displayValue = currentCell->rawInput;
		}
	}

	float Evaluator::addUp(vector<float>*values, vector<char>*operators, Cell* currentCell)
	{
		if (values->size() == operators->size() && values->size())
		{
			if (operators->at(0) == '-')
			{
				values->at(0) *= -1;
				operators->erase(operators->begin());
			}
			else
			{
				currentCell->hasError = true;
				currentCell->errorMessage = "Expression starts with a non '-' operator.";
				currentCell->hasNumValue = false;
				return 0;
			}
		}
		else if (values->size() != (operators->size() + 1))
		{
			currentCell->hasError = true;
			currentCell->errorMessage = "Mismatched number of values and operators.";
			currentCell->hasNumValue = false;
		}

		for (unsigned i = 0; i < operators->size(); i++)
		{
			if (operators->at(i) == '*')
			{
				values->at(i) *= values->at(i + 1);
				values->erase(values->begin() + i + 1);
				operators->erase(operators->begin() + i);
				i--;
			}
			else if (operators->at(i) == '/')
			{
				if (values->at(i + 1) == 0)
				{
					currentCell->hasError = true;
					currentCell->errorMessage = "Error: Division by zero";
					currentCell->hasNumValue = false;
					return 0;
				}
				values->at(i) /= values->at(i + 1);
				values->erase(values->begin() + i + 1);
				operators->erase(operators->begin() + i);
				i--;
			}
		}
		for (unsigned i = 0; i < operators->size(); i++)
		{
			if (currentCell->hasError)
				return 0;
			if (operators->at(i) == '+')
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
		if (values->size())
			return values->at(0);
		else
			return 0;
	}

}
