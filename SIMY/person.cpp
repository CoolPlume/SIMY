#include "pch.h"
#include "person.h"

[[nodiscard]] std::string person::return_username()const
	//返回用户名
{
	return username;
}

[[nodiscard]] std::string person::return_password()const
	//返回密码
{
	return password;
}

[[nodiscard]] std::string person::return_nick_name() const
	//返回昵称
{
	return nick_name;
}

person::person()
{
	username = "None";
	password = "None";
	nick_name = "None";
}

person::~person()
{

}

person::person(const person& per)
{
	this->username = per.username;
	this->password = per.password;
	this->nick_name = per.nick_name;
}

void person::change_username(const std::string& username)
	//改变用户名
{
	this->username = username;
}

void person::change_password(const std::string& password)
	//改变密码
{
	this->password = password;
}

void person::change_nick_name(const std::string& nick_name)
	//改变昵称
{
	this->nick_name = nick_name;
}
