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
	// �w��C���f�b�N�X�̃^�C�g�����Ȃ��ꍇ
	if (titles.size() <= index) {
		return L"(�^�C�g��������܂���)";
	}

	return titles[index].c_str();
}

namespace 
{
//�}���`�o�C�g�����񂩂烏�C�h������
//���P�[���ˑ�
void widenString(const std::string &src, std::wstring &dest) {
	wchar_t *wcs = new wchar_t[src.length() + 1];
	mbstowcs(wcs, src.c_str(), src.length() + 1);
	dest = wcs;
	delete[] wcs;
}
}


void Recipe::buildTitles(LPCWSTR filePath)
{
	// �O�ɓo�^���Ă������̂�����ꍇ�́A�������񃁃����������
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