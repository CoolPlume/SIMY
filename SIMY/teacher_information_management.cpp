#include "pch.h"
#include "teacher_information_management.h"

std::vector <std::string> teacher_storage_field_description =
{
	" ",
	"Username:",
	"Password:",
	"Gender:",
	"END",
	"Actual_name:",
	"Nick_name:",
};

enum class teacher_storage_field_Type
{
	Space = 0,
	Username = 1,
	Password = 2,
	Gender = 3,
	END = 4,
	Actual_name = 5,
	Nick_name = 6,
};

std::map <std::string, int> teacher_storage_field_Map
{
	{" ",0},
	{"Username:",1},
	{"Password:",2},
	{"Gender:",3},
	{"END",4},
	{"Actual_name:",5},
	{"Nick_name:",6},
};

enum class login_decision_return_code_Type
{
	login_failed = 0,
	login_successful = 1
};

teacher_information_management::teacher_information_management()
{
	std::ofstream create_local_file("teacher_list.txt", std::ios::app);
	if (create_local_file.is_open())
	{

	}
	else
	{
		//initialization_failed(static_cast<int>(error_code_Type::Open_failed));
	}
	create_local_file.flush();
	create_local_file.close();

	std::ifstream read_local_date("teacher_list.txt", std::ios::in | std::ios::_Nocreate);
	if (read_local_date.is_open())
	{
		while (read_local_date.peek() != EOF)
		{
			std::string* judge;
			judge = new std::string;
			teacher* tea;
			tea = new teacher;
			bool read_end = false;
			do
			{
				read_local_date >> *judge;
				switch (teacher_storage_field_Map[*judge])
				{
				case static_cast<int>(teacher_storage_field_Type::Username):
				{
					read_local_date >> *judge;
					tea->change_username(*judge);
					break;
				}
				case static_cast<int>(teacher_storage_field_Type::Password):
				{
					read_local_date >> *judge;
					tea->change_password(*judge);
					break;
				}
				case static_cast<int>(teacher_storage_field_Type::Gender):
				{
					read_local_date >> *judge;
					tea->change_gender(std::stoi(*judge));
					break;
				}
				case static_cast<int>(teacher_storage_field_Type::Actual_name):
				{
					read_local_date >> *judge;
					tea->change_actual_name(*judge);
					break;
				}
				case static_cast<int>(teacher_storage_field_Type::Nick_name):
				{
					read_local_date >> *judge;
					tea->change_nick_name(*judge);
					break;
				}
				case static_cast<int>(teacher_storage_field_Type::END):
				{
					teacher_list.push_back(*tea);
					break;
				}
				default:
				{
					if (read_local_date.peek() == EOF)
						read_end = true;
					break;
				}
				}
			} while (*judge != "END" && read_end == false);
			delete judge;
			delete tea;
		}
	}
	else
	{
		//initialization_failed(static_cast<int>(error_code_Type::Open_failed));
	}
	read_local_date.close();
}

teacher_information_management::~teacher_information_management()
{
	std::ofstream write_local_data("teacher_list.txt", std::ios::out | std::ios::trunc | std::ios::_Nocreate);
	if (write_local_data.is_open())
	{
		for (const auto& i : teacher_list)
		{
			const teacher* tea = new teacher(i);
			write_local_data << teacher_storage_field_description[static_cast<int>(teacher_storage_field_Type::Username)] << teacher_storage_field_description[static_cast<int>(teacher_storage_field_Type::Space)] << tea->return_username() << teacher_storage_field_description[static_cast<int>(teacher_storage_field_Type::Space)]
				<< teacher_storage_field_description[static_cast<int>(teacher_storage_field_Type::Password)] << teacher_storage_field_description[static_cast<int>(teacher_storage_field_Type::Space)] << tea->return_password() << teacher_storage_field_description[static_cast<int>(teacher_storage_field_Type::Space)]
				<< teacher_storage_field_description[static_cast<int>(teacher_storage_field_Type::Gender)] << teacher_storage_field_description[static_cast<int>(teacher_storage_field_Type::Space)] << tea->return_gender() << teacher_storage_field_description[static_cast<int>(teacher_storage_field_Type::Space)]
				<< teacher_storage_field_description[static_cast<int>(teacher_storage_field_Type::Actual_name)] << teacher_storage_field_description[static_cast<int>(teacher_storage_field_Type::Space)] << tea->return_actual_name() << teacher_storage_field_description[static_cast<int>(teacher_storage_field_Type::Space)]
				<< teacher_storage_field_description[static_cast<int>(teacher_storage_field_Type::Nick_name)] << teacher_storage_field_description[static_cast<int>(teacher_storage_field_Type::Space)] << tea->return_nick_name() << teacher_storage_field_description[static_cast<int>(teacher_storage_field_Type::Space)]
				<< teacher_storage_field_description[static_cast<int>(teacher_storage_field_Type::END)] << std::endl;
			delete tea;
		}
	}
	else
	{
		//save_failed(static_cast<int>(error_code_Type::Open_failed));
	}
	write_local_data.flush();
	write_local_data.close();
}

bool teacher_information_management::login_decision(const std::string& username, const std::string& password)
{
	bool return_code = false;
	auto i = teacher_list.begin();
	for (i; i != teacher_list.end(); ++i)
	{
		teacher* tea = new teacher(*i);
		if ((tea->return_username() == username) && (tea->return_password() == password))
		{
			return_code = static_cast<int>(login_decision_return_code_Type::login_successful);
			currently_logged_in_teacher = &*i;
		}
		delete tea;
	}
	if ((return_code != static_cast<int>(login_decision_return_code_Type::login_successful)) && (i == teacher_list.end()))
	{
		return_code = static_cast<int>(login_decision_return_code_Type::login_failed);
	}
	return return_code;
}

[[nodiscard]] teacher teacher_information_management::return_currently_logged_in_teacher() const
{
	return *currently_logged_in_teacher;
}

[[noreturn]] void teacher_information_management::add_teacher(const teacher& tea)
{
	teacher_list.push_back(tea);
}

[[nodiscard]] size_t teacher_information_management::return_teacher_list_size() const
{
	return teacher_list.size();
}

[[nodiscard]] teacher* teacher_information_management::revise_currently_logged_in_teacher() const
{
	return currently_logged_in_teacher;
}
