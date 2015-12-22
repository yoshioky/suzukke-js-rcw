#pragma once

typedef std::vector<std::wstring> StringVector;

class Recipe
{
public:
	Recipe() = default;
	~Recipe() = default;
	Recipe(LPCWSTR filePath);
	std::wstring GetTitle();
	std::wstring GetTitleAt(size_t index);

protected:
	void buildTitles(LPCWSTR filePath);

private:
	StringVector titles;
};