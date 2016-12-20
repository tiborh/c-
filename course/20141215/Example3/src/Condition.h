/*
 * Condition.h
 *
 *  Created on: 2014 dec. 19
 *      Author: vincze.attila
 */

#ifndef CONDITION_H_
#define CONDITION_H_

struct Condition {
	virtual bool operator()(int) = 0;
	Condition();
	virtual ~Condition();
};

#endif /* CONDITION_H_ */
