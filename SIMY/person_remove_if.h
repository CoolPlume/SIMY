#pragma once
#include <string>
#include "person.h"

class person_remove_if
{
public:
	std::string username;
	bool operator() (const person&) const;
	person_remove_if(const std::string&);
};

