#pragma once
#include "person.h"
class user :
    public person
{
private:
	//timer last_login_time;
	//timer date_of_birth;
	std::string actual_name;
	int gender;
	//course_information_management* CIM;
protected:

public:
	user();
	~user();
	user(const user&);
	[[noreturn]] void change_gender(int);
	[[nodiscard]] int return_gender()const;
	[[noreturn]] void change_actual_name(const std::string&);
	[[nodiscard]] std::string return_actual_name()const;
	//[[nodiscard]] course_information_management* revise_course_information_management()const;
	//[[nodiscard]] course_information_management return_course_information_management()const;
};

