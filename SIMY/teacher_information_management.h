#pragma once
#include "teacher.h"
#include "user_information_management.h"

class teacher_information_management :
    public user_information_management
{
private:
	std::list <teacher> teacher_list;
	teacher* currently_logged_in_teacher;
protected:

public:
	teacher_information_management();
	virtual ~teacher_information_management();
	bool login_decision(const std::string&, const std::string&);
	[[nodiscard]] teacher return_currently_logged_in_teacher()const;
	[[noreturn]] void add_teacher(const teacher&);
	[[nodiscard]] size_t return_teacher_list_size()const;
	[[nodiscard]] teacher* revise_currently_logged_in_teacher()const;
};

