#include "stdafx.h"
#include "Recipe.h"

int _tmain(int argc, _TCHAR* argv[])
{
	// 日本語出力用のロケール設定
	setlocale(LC_ALL, "ja-JP");

	// レシピタイトルの出力
	Recipe recipe(L"オムライス");
	std::wcout << recipe.GetTitle();
	return 0;
}

