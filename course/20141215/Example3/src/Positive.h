/*
 * Positive.h
 *
 *  Created on: 2014 dec. 19
 *      Author: vincze.attila
 */

#ifndef POSITIVE_H_
#define POSITIVE_H_
#include "Condition.h"

struct Positive : Condition{
public:
	virtual bool operator()(int a){
		return a > 0;
	}

	Positive();
	virtual ~Positive();
};

#endif /* POSITIVE_H_ */
