#pragma once

#include <vector>
#include <thread>
#include <cmath>

#include "CMenuItem.h"
#include "CMenuItemBool.h"
#include "CMenuItemInt.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>A console based menu. </summary>
///
/// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
class CMenu {
private:
    /// <summary>Zero-based index of the selected menu item. </summary>
    int32_t index{ 0 };
    uint32_t tab_offset{ 1 };
    /// <summary>The menu items. </summary>
    std::vector<CMenuItem*> items;
    /// <summary>True if rerendering required. </summary>
    bool update_required{ true };
    /// <summary>True if any arrow key pressed. </summary>
    bool key_pressed{ false };
    /// <summary>Target for the cheat. </summary>
    std::string target;
    /// <summary>The version. </summary>
    std::string version;

private:
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>Renders menu item objects. </summary>
    ///
    /// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
    void render();

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>Adjust tab offset. </summary>
    ///
    /// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
    void adjust_tab_offset();

private:
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>Checks if object is an instance of the given class. </summary>
    ///
    /// <typeparam name="Base">Type of the base class. </typeparam>
    /// <typeparam name="T">   Generic type parameter. </typeparam>
    /// <param name="ptr">     The pointer to the object. </param>
    ///
    /// <returns>True if it succeeds, false if it fails. </returns>
    template<typename Base, typename T>
    inline bool instanceof(const T* ptr) {
        return dynamic_cast<const Base*>(ptr) != nullptr;
    }

public:
    /// <summary>True if is running, false if not. </summary>
    bool is_running{ false };

public:
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>Default constructor. </summary>
    ///
    /// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
    ///
    /// <param name="target"> Target for the cheat. </param>
    /// <param name="version">The version. </param>
    CMenu(std::string target, std::string version);

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>Updates this object. </summary>
    ///
    /// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
    void update();

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>Adds an item to the menu. </summary>
    ///
    /// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
    ///
    /// <param name="item">The item. </param>
    void add_item(CMenuItemBool item);

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    /// <summary>Adds an item to the menu. </summary>
    ///
    /// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
    ///
    /// <param name="item">The item. </param>
    void add_item(CMenuItemInt item);
};