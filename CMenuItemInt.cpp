#include "CMenuItemInt.h"

CMenuItemInt::CMenuItemInt(const char* name, int32_t* pValue, int32_t min_val, int32_t max_val, int32_t step_value, int32_t increased_step_value) :
	name(name), pValue(pValue), min_val(min_val), max_val(max_val), step_value(step_value), increased_step_value(increased_step_value) {}

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
	if (*pValue < max_val) {
		if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
			*pValue += increased_step_value;
			if (*pValue > max_val)
				*pValue = max_val;
			return;
		}

		*pValue += step_value;
	}
}

void CMenuItemInt::decrease()
{
	if (*pValue > min_val) {
		if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
			*pValue -= increased_step_value;
			if (*pValue < min_val)
				*pValue = min_val;
			return;
		}
		*pValue -= 1;
	}
}
