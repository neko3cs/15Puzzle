#pragma once
#include <string>

class Panel
{
private:
	int number;
	int HIDDEN_NUM = 16;

public:
	Panel(int number);
	int GetNumber() const;
	std::string ToString();
	bool IsHidden();
};
