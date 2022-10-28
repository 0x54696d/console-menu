#include "CMenuItemBool.h"

CMenuItemBool::CMenuItemBool(const char* name, bool* pValue) :
	name(name), pValue(pValue) {}

void CMenuItemBool::toggle()
{
	*pValue = !*pValue;
}

void CMenuItemBool::render(bool is_active, uint32_t tab_offset)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	if (is_active) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}

	std::string name_output(tab_offset * 7, ' ');
	name_output.replace(0, strlen(name), name);
	printf("] %s | ", name_output.c_str());

	if (*pValue) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		printf("Enabled");
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("Disabled");
	}
	printf("\n");
}

const char* CMenuItemBool::get_name()
{
	return name;
}

void CMenuItemBool::increase()
{
	toggle();
}

void CMenuItemBool::decrease()
{
	toggle();
}