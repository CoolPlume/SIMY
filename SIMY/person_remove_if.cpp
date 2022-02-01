	#include "pch.h"
#include "person_remove_if.h"

bool person_remove_if::operator()(const person& per) const
{
    return per.return_username() == username;
}

person_remove_if::person_remove_if(const std::string& username)
{
    this->username = username;
}
