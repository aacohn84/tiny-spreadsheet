/*
 * DAG.h
 *
 *  Created on: Feb 20, 2014
 *      Author: Aaron Cohn
 */

#ifndef DAG_H_
#define DAG_H_

#include "Vertices.h"

namespace topologicalSort {

class DAG {
public:
	virtual ~DAG();

	virtual Vertices getVertices() = 0;
};

} /* namespace topologicalSort */

#endif /* DAG_H_ */
