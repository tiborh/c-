/*
 * Negative.h
 *
 *  Created on: 2014 dec. 19
 *      Author: vincze.attila
 */

#ifndef NEGATIVE_H_
#define NEGATIVE_H_

#include "Condition.h"

struct Negative: Condition {
	virtual bool operator()(int a){
		return a < 0;
	}
	Negative();
	virtual ~Negative();
};

#endif /* NEGATIVE_H_ */
