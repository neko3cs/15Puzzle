#include "Panel.hpp"

Panel::Panel(int number)
		: number(number)
{
}

int Panel::GetNumber() const
{
	return number;
}

std::string Panel::ToString()
{
	return IsHidden() ? "■ " : std::to_string(number);
}

bool Panel::IsHidden()
{
	return number == HIDDEN_NUM ? true : false;
}
