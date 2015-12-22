#include "stdafx.h"
#include "Recipe.h"

void suspendCommandLine()
{
	char dummy[256];
	gets_s(dummy);
}

int _tmain(int argc, _TCHAR* argv[])
{
	// 日本語出力用のロケール設定
	setlocale(LC_ALL, "ja-JP");

	// 引数チェック
	if (argc < 1) {
		exit(-1);
	}

	// ファイル名
	LPCWSTR filePath = argv[0];
	// ToDo: ファイル読み込み

	// レシピタイトルの出力
	Recipe recipe(L"recipe_data.txt");
	std::wcout << recipe.GetTitle();

	suspendCommandLine();
	return 0;
}

