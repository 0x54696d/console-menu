#include "CMenu.h"

CMenu::CMenu(std::string target, std::string version) :
	target(target), version(version)
{
	is_running = true;
}

void CMenu::render()
{
	if (!update_required)
		return;

	system("cls");

	printf("[%s] [v%s]\n\n", target.c_str(), version.c_str());

	uint32_t index_render{ 0 };
	for (auto& item : items) {
		bool is_active{ false };
		if (index_render == index)
			is_active = true;
		
		item->render(is_active, tab_offset);
		index_render += 1;
	}

	update_required = false;
}

void CMenu::adjust_tab_offset()
{
	uint32_t max_length{ 0 };
	for (auto& item : items) {
		const auto name{ item->get_name() };
		const auto length{ strlen(name) + 2 };
		if (length > max_length)
			max_length = length;
	}
	tab_offset = ceil(max_length / static_cast<double>(7));
}

void CMenu::update()
{
	if ((GetAsyncKeyState(VK_UP) & 0x8000) && !key_pressed) {
		key_pressed = true;

		if (index > 0) {
			index -= 1;
			update_required = true;
		}
	}

	if ((GetAsyncKeyState(VK_DOWN) & 0x8000) && !key_pressed) {
		key_pressed = true;

		if (index < items.size() - 1) {
			index += 1;
			update_required = true;
		}
	}

	const auto current_item{ items.at(index) };

	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && !key_pressed) {
		if (instanceof<CMenuItemBool>(current_item)) {
			key_pressed = true;
		}
		else {
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
			
		current_item->increase();
		update_required = true;
	}

	if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && !key_pressed) {
		if (instanceof<CMenuItemBool>(current_item)) {
			key_pressed = true;
		}
		else {
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}

		current_item->decrease();
		update_required = true;
	}

	render();
	if (GetAsyncKeyState(VK_UP) == 0 && GetAsyncKeyState(VK_DOWN) == 0 && GetAsyncKeyState(VK_RIGHT) == 0 && GetAsyncKeyState(VK_LEFT) == 0)
		key_pressed = false;
}

void CMenu::add_item(CMenuItemBool item)
{
	items.push_back(&item);
	adjust_tab_offset();
}

void CMenu::add_item(CMenuItemInt item)
{
	items.push_back(&item);
	adjust_tab_offset();
}

void CMenu::add_item(CMenuItemFloat item)
{
	items.push_back(&item);
	adjust_tab_offset();
}
