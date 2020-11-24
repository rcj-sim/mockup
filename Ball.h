#ifndef RCJSIM_MOCKUP_BALL_H
#define RCJSIM_MOCKUP_BALL_H

#include "Thing.h"

class Ball:
	public LocateableThing
{
	const double diameter = 0.08;
public:
	Ball();
};


#endif // RCJSIM_MOCKUP_BALL_H
