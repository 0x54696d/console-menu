#include "CMenu.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>Main entry-point for this application. </summary>
///
/// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
///
/// <returns>Exit-code for the process - 0 for success, else an error code. </returns>
int main() {
    CMenu menu{"notepad.exe", "2022.10.28"};

    bool test{ false };
    menu.add_item(CMenuItemBool{ "Aimbot", &test });

    bool test2{ true };
    menu.add_item(CMenuItemBool{ "ESP", &test2 });

    int32_t integer{ 30 };
    menu.add_item(CMenuItemInt{ "FOV", &integer });

    while (menu.is_running) {
        menu.update();
    }
    return EXIT_SUCCESS;
}