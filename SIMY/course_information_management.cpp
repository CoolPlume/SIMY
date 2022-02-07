#include "pch.h"
#include "course_information_management.h"

course_information_management::course_information_management()
{
	for (auto& i : course_list)
	{
		i = course();
	}
	course_list[static_cast<int>(course_Type::chinese)].change_the_selection_status(true);
	course_list[static_cast<int>(course_Type::mathematics)].change_the_selection_status(true);
	course_list[static_cast<int>(course_Type::foreign_language)].change_the_selection_status(true);
}

course_information_management::~course_information_management()
= default;

int course_information_management::return_total_score()
{
	total_score = 0;
	for (const auto& i : course_list)
	{
		if (i.return_the_selection_status() == true)
		{
			total_score += i.return_course_results();
		}
	}
	return total_score;
}

void course_information_management::change_the_selection_status(int subject, bool state)
{
	if (subject == 11)
	{
		course_list[static_cast<int>(course_Type::common_technology)].change_the_selection_status(state);
		course_list[static_cast<int>(course_Type::information_technology)].change_the_selection_status(state);
	}
	else
	{
		course_list[subject].change_the_selection_status(state);
	}
}

void course_information_management::change_course_results(int subject, int score)
{
	course_list[subject].change_course_results(score);
}

[[nodiscard]] int course_information_management::return_course_results(int subject) const
{
	return course_list[subject].return_course_results();
}

[[nodiscard]] bool course_information_management::return_the_selection_status(int subject) const
{
	return course_list[subject].return_the_selection_status();
}