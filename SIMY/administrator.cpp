#include "pch.h"
#include "administrator.h"

administrator::administrator()
{
	super_administrator = false;
}

administrator::administrator(const std::string& username, const std::string& password, bool super_administrator)
{
	change_username(username);
	change_password(password);
	this->super_administrator = super_administrator;
}

administrator::~administrator()
{

}

void administrator::change_super_administrator(bool super_administrator)
	//改变管理员状态
{
	this->super_administrator = super_administrator;
}

[[nodiscard]] bool administrator::return_super_administrator()const
	//返回管理员状态
{
	return super_administrator;
}

administrator::administrator(const administrator& admin) :person(admin)
{
	this->super_administrator = admin.super_administrator;
}