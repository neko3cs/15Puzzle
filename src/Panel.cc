#include "Panel.h"

Panel::Panel(Grid grid)
		: grid(grid)
{
}

std::string Panel::ToString()
{
	// TODO: いずれは画像を返す
	return IsHidden() ? "■ " : std::to_string(grid.GetNum());
}

Grid Panel::GetGrid()
{
	return grid;
}

bool Panel::IsHidden()
{
	return grid.GetNum() == HIDDEN_NUM ? true : false;
}

void Panel::SwapPanel(Panel dest)
{
	auto x = this->GetGrid().GetX();
	auto y = this->GetGrid().GetY();

	this->GetGrid().SetX(dest.GetGrid().GetX());
	this->GetGrid().SetY(dest.GetGrid().GetY());

	dest.GetGrid().SetX(x);
	dest.GetGrid().SetY(y);
}
