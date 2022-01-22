#pragma once
#include <string>

class person
{
private:
	std::string username;
	std::string password;
protected:
	std::string nick_name;
public:
	person();
	virtual ~person();
	person(const person&);
	[[nodiscard]] std::string return_username()const;
	[[nodiscard]] std::string return_password()const;
	[[nodiscard]] std::string return_nick_name()const;
	[[noreturn]] void change_username(const std::string&);
	[[noreturn]] void change_password(const std::string&);
	[[noreturn]] void change_nick_name(const std::string&);
};

