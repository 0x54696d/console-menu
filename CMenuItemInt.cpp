#include "CMenuItemInt.h"

CMenuItemInt::CMenuItemInt(const char* name, int32_t* pValue) :
	name(name), pValue(pValue) {}

void CMenuItemInt::render(bool is_active, uint32_t tab_offset)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	if (is_active) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}

	std::string name_output(tab_offset * 7, ' ');
	name_output.replace(0, strlen(name), name);
	printf("] %s | ", name_output.c_str());

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("%d", *pValue);

	printf("\n");
}

const char* CMenuItemInt::get_name()
{
	return name;
}

void CMenuItemInt::increase()
{
	*pValue += 1;
}

void CMenuItemInt::decrease()
{
	*pValue -= 1;
}
