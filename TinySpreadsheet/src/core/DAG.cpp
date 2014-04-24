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

void DAG::updateCell(Cell* input) {
	if (exists(input->name)) {
		if (input->rawInput.empty()) {
			dag.erase(input->name);
		}
		dag[input->name] = input;
	}
	else {
		dag.emplace(input->name, input);
	}
}

Cell* DAG::getCell(std::string coord){
	try {
		return dag.at(coord);
	} catch (std::exception &e) {
		return nullptr;
	}
}

bool DAG::exists(std::string key){
	for (auto& i: dag) {
		if (i.first == key){
			return true;
		}
	}
	return false;
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
