#include "CMenu.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>Main entry-point for this application. </summary>
///
/// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
///
/// <returns>Exit-code for the process - 0 for success, else an error code. </returns>
int main() {
    CMenu menu{"example.exe", "2022.10.28"};

    bool test{ false };
    bool test2{ true };
    int32_t integer{ 30 };
    float_t float_test{ 3.0 };

    menu.add_item(CMenuItemBool{ "Example Boolean One", &test });
    menu.add_item(CMenuItemBool{ "Example Boolean Two", &test2 });
    menu.add_item(CMenuItemInt{ "Example Int One", &integer, 0, 30, 1, 10 });
    menu.add_item(CMenuItemFloat{ "Example Float One", &float_test, 0.0f, 30.0f, 1.25f, 10.0f });

    while (menu.is_running) {
        menu.update();
    }

    return EXIT_SUCCESS;
}