#include "Panel.h"

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
	// TODO: いずれは画像を返す
	return IsHidden() ? "■ " : std::to_string(number);
}

bool Panel::IsHidden()
{
	return number == HIDDEN_NUM ? true : false;
}
