#include "pch.h"
#include "user.h"

user::user()
{
	gender = NULL;
	//CIM = new course_information_management();
}

user::~user()
{
	//delete CIM;
}

user::user(const user& user) :person(user)
{
	//this->last_login_time = user.last_login_time;
	//this->date_of_birth = user.date_of_birth;
	this->gender = user.gender;
	this->actual_name = user.actual_name;
}

void user::change_gender(int gender)
	//�ı��Ա�
{
	this->gender = gender;
}

[[nodiscard]] int user::return_gender() const
	//�����Ա�
{
	return gender;
}

void user::change_actual_name(const std::string& actual_name)
	//�ı�����
{
	this->actual_name = actual_name;
}

[[nodiscard]] std::string user::return_actual_name() const
	//��������
{
	return actual_name;
}

//[[nodiscard]] course_information_management* user::revise_course_information_management() const
//{
//	return CIM;
//}
//
//[[nodiscard]] course_information_management user::return_course_information_management() const
//{
//	return course_information_management(*CIM);
//}