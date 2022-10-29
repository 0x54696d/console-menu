#include "CMenuItemFloat.h"

CMenuItemFloat::CMenuItemFloat(const char* name, float_t* pValue, float_t min_val, float_t max_val, float_t step_value, float_t increased_step_value) :
	name(name), pValue(pValue), min_val(min_val), max_val(max_val), step_value(step_value), increased_step_value(increased_step_value) {}

void CMenuItemFloat::render(bool is_active, uint32_t tab_offset)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	if (is_active) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}

	std::string name_output(tab_offset * 7, ' ');
	name_output.replace(0, strlen(name), name);
	printf("] %s | ", name_output.c_str());

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("%f", *pValue);

	printf("\n");
}

const char* CMenuItemFloat::get_name()
{
	return name;
}

void CMenuItemFloat::increase()
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

void CMenuItemFloat::decrease()
{
	if (*pValue > min_val) {
		if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
			*pValue -= increased_step_value;
			if (*pValue < min_val)
				*pValue = min_val;
			return;
		}
		*pValue -= step_value;
	}
}
