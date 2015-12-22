#include "stdafx.h"
#include "Recipe.h"

#define _CRT_SECURE_NO_WARNINGS

Recipe::Recipe(LPCWSTR filePath)
: titles()
{
	buildTitles(filePath);
}

std::wstring Recipe::GetTitle()
{
	return GetTitleAt(0);
}


std::wstring Recipe::GetTitleAt(size_t index)
{
	// 指定インデックスのタイトルがない場合
	if (titles.size() <= index) {
		return L"(タイトルがありません)";
	}

	return titles[index].c_str();
}

namespace 
{
//マルチバイト文字列からワイド文字列
//ロケール依存
void widenString(const std::string &src, std::wstring &dest) {
	wchar_t *wcs = new wchar_t[src.length() + 1];
	mbstowcs(wcs, src.c_str(), src.length() + 1);
	dest = wcs;
	delete[] wcs;
}
}


void Recipe::buildTitles(LPCWSTR filePath)
{
	// 前に登録していたものがある場合は、いったんメモリ解放する
	titles.clear();
	titles.shrink_to_fit();

	std::ifstream ifs(filePath);
	std::string lineString;
	if (ifs.fail())
	{
		return;
	}
	while (getline(ifs, lineString))
	{
		std::wstring strW;
		widenString(lineString, strW);
		titles.push_back(strW);
	}
}