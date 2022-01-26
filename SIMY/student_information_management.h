#pragma once

#include "user_information_management.h"
#include "student.h"

class student_information_management :
    public user_information_management
{
private:
	std::list<student> student_list;
	student* currently_logged_in_student;
protected:

public:
	student_information_management();
	virtual ~student_information_management();
	bool login_decision(const std::string&, const std::string&);
	[[nodiscard]] student return_currently_logged_in_student()const;
	void add_student(const student&);
	[[nodiscard]] size_t return_student_list_size()const;
	[[nodiscard]] student* revise_currently_logged_in_student()const;
	[[nodiscard]] student* find_student(const std::string&)const;
	[[nodiscard]] std::list<student> return_student_list()const;
};

