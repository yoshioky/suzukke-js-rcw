#include "stdafx.h"
#include "Recipe.h"

void suspendCommandLine()
{
	char dummy[256];
	gets_s(dummy);
}

int _tmain(int argc, _TCHAR* argv[])
{
	// ���{��o�͗p�̃��P�[���ݒ�
	setlocale(LC_ALL, "ja-JP");

	// �����`�F�b�N
	if (argc < 1) {
		exit(-1);
	}

	// �t�@�C����
	LPCWSTR filePath = argv[0];
	// ToDo: �t�@�C���ǂݍ���

	// ���V�s�^�C�g���̏o��
	Recipe recipe(L"recipe_data.txt");
	std::wcout << recipe.GetTitle();

	suspendCommandLine();
	return 0;
}

