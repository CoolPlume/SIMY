#pragma once
#include "user.h"
class student :
    public user
{
private:

protected:

public:
	student();
	virtual ~student();
	student(const student&);
	course_information_management CIM;
};

