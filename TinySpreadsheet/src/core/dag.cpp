/*
 * dag.cpp
 *
 *  Created on: Mar 6, 2014
 *      Author: trekkienz
 */

#include <dag.h>

DAG::DAG() {}

void DAG::addCell(std::string coord, Cell* input) {
	if (exists(coord)){
		dag[coord] = input;
	}
	else
	{
		dag.emplace(coord, input);
	}
}

bool DAG::exists(std::string key){
	for (auto& i: dag){	//std::map<std::string, Cell>::iterator i = dag.begin(); i != dag.end(); i++
		if (i.first == key){
			return true;
		}
	}

	return false;
}

Cell* DAG::getCell(std::string coord){
	try {
		return dag.at(coord);
	} catch (std::exception e) {
		return nullptr;
	}
}

std::map<std::string, Cell>* DAG::getMap() {
	return &dag;
}

std::vector<Cell>* DAG::getCells() {
	return &cells;
}

void DAG::setOrderedCells(std::vector<Cell>* cells){
	this->cells = cells;
}
