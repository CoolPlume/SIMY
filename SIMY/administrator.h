#pragma once
#include "person.h"
class administrator :
    public person
{
private:
	bool super_administrator;
protected:

public:
	administrator();
	administrator(const std::string&, const std::string&, bool);
	virtual ~administrator();
	void change_super_administrator(bool);
	[[nodiscard]] bool return_super_administrator()const;
	administrator(const administrator&);
};

