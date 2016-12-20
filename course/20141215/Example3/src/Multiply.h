/*
 * Multiply.h
 *
 *  Created on: 2014 dec. 19
 *      Author: vincze.attila
 */

#ifndef MULTIPLY_H_
#define MULTIPLY_H_

#include "Operation.h"

struct Multiply: Operation {
	virtual int operator()(int, int);
};

#endif /* MULTIPLY_H_ */
