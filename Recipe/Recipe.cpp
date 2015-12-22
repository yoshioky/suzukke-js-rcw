#include "stdafx.h"
#include "Recipe.h"

Recipe::Recipe(LPCWSTR title_)
	: title(title_)
{

}

std::wstring Recipe::GetTitle() {
	return title.c_str();
}