/*
 * Add.h
 *
 *  Created on: 2014 dec. 19
 *      Author: vincze.attila
 */

#ifndef ADD_H_
#define ADD_H_

#include "Operation.h"

struct Add: Operation {
	virtual int operator()(int, int);
};

#endif /* ADD_H_ */
