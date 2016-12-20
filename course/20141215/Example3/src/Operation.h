/*
 * Operation.h
 *
 *  Created on: 2014 dec. 19
 *      Author: vincze.attila
 */

#ifndef OPERATION_H_
#define OPERATION_H_

struct Operation {
	virtual int operator()(int, int) = 0;
	virtual ~Operation();
};

#endif /* OPERATION_H_ */
