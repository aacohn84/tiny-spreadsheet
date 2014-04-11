/*
 * dag.cpp
 *
 *  Created on: Mar 6, 2014
 *      Author: trekkienz
 */

#include "DAG.h"

namespace core {
DAG::DAG() {}

DAG::~DAG(){
	for (auto i: dag){
		delete i.second;
	}
}

void DAG::addCell(Cell* input) {
	if (exists(input->name)){
		dag[input->name] = input;
	}
	else
	{
		dag.emplace(input->name, input);
	}
}

bool DAG::exists(std::string key){
	for (auto& i: dag){	//std::map<std::string, Cell*>::iterator i = dag.begin(); i != dag.end(); i++
		if (i.first == key){
			return true;
		}
	}

	return false;
}

Cell* DAG::getCell(std::string coord){
	try {
		return dag.at(coord);
	} catch (std::exception &e) {
		return nullptr;
	}
}

std::map<std::string, Cell*>* DAG::getMap() {
	return &dag;
}

std::vector<Cell*>* DAG::getCells() {
	return &cells;
}

void DAG::setOrderedCells(std::vector<Cell*> *cells){
	this->cells = *cells;
}

}
