#pragma once

#include "Thing.hpp"

class Field:
	public Thing
{
public:
	Field();

	virtual void update(const World&) override;
};

