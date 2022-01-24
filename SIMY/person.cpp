#include "pch.h"
#include "person.h"

[[nodiscard]] std::string person::return_username()const
	//�����û���
{
	return username;
}

[[nodiscard]] std::string person::return_password()const
	//��������
{
	return password;
}

[[nodiscard]] std::string person::return_nick_name() const
	//�����ǳ�
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
	//�ı��û���
{
	this->username = username;
}

void person::change_password(const std::string& password)
	//�ı�����
{
	this->password = password;
}

void person::change_nick_name(const std::string& nick_name)
	//�ı��ǳ�
{
	this->nick_name = nick_name;
}
