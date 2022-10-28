# console-menu
A small class I made to provide a nice arrow key driven console menu that's able to edit numeric values and toggle booleans.

![ezgif-2-9bc90f504d](https://user-images.githubusercontent.com/39867997/198736907-a0f31980-d928-4898-9ebe-0767f27fdaa8.gif)

## Usage
Simply add `CMenuItemBool` or `CMenuItemInt` objects to your menu instance using the `add_item` function. The `CMenuItem` objects need a reference to their respective values or they won't work. Run `update()` after adding all menu items in order to use the menu.


## Example
```cpp
CMenu menu{"example.exe", "2022.10.28"};

bool test{ false };
bool test2{ true };
int32_t integer{ 30 };

menu.add_item(CMenuItemBool{ "Example Boolean One", &test });
menu.add_item(CMenuItemBool{ "Example Boolean Two", &test2 });
menu.add_item(CMenuItemInt{ "Example Int One", &integer });

while (menu.is_running) {
    menu.update();
}
```
