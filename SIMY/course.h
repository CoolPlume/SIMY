#pragma once

enum class course_Type
{
	chinese = 0,
	mathematics = 1,
	foreign_language = 2,
	politics = 3,
	history = 4,
	geography = 5,
	physics = 6,
	chemical = 7,
	biology = 8,
	information_technology = 9,
	common_technology = 10,
	technology = 11
};

class course
{
private:
	int course_results;
	//int course_hours;
	//int course_classroom;
	bool is_select_subjects;
protected:

public:
	course();
	~course();
	void change_the_selection_status(bool);
	void change_course_results(int);
	[[nodiscard]] bool return_the_selection_status()const;
	[[nodiscard]] int return_course_results()const;
};

constexpr int main_subject_full_score = 150;
constexpr int associate_subjects_full_score = 100;
constexpr int technical_subjects_full_score = 50;
