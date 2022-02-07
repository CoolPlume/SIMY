#include "pch.h"
#include "student.h"

student::student()
= default;

student::~student()
= default;

student::student(const student& stu) :user(stu)
{
	this->CIM = stu.CIM;
}