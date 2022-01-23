#pragma once
#include <list>
#include <string>
#include "administrator.h"

class administrator_information_management
{
private:
	std::list<administrator> administrator_list;
	administrator* currently_logged_in_administrator;
protected:

public:
	administrator_information_management();
	~administrator_information_management();
	bool add_manager(const administrator&);
	bool login_decision(const std::string&, const std::string&);
	[[nodiscard]] administrator return_currently_logged_in_administrator()const;
	[[nodiscard]] administrator* revise_currently_logged_in_administrator()const;
};

