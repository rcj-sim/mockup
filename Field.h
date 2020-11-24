#ifndef RCJSIM_MOCKUP_FIELD_H
#define RCJSIM_MOCKUP_FIELD_H

#include "Thing.h"

class Field:
	public Thing
{
public:
	Field();

	virtual void update(const World&) override;
};

#endif // RCJSIM_MOCKUP_FIELD_H
