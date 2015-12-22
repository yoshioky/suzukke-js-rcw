#pragma once

class Recipe
{
public:
	Recipe(LPCWSTR title_);
	std::wstring GetTitle();
private:
	std::wstring title;
};