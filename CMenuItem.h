#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

///////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>A menu item. </summary>
///
/// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
class CMenuItem
{
public:

	///////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>Renders the given menu item. </summary>
	///
	/// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
	///
	/// <param name="is_active">True if is active, false if not. </param>
	virtual void render(bool is_active, uint32_t tab_offset) = 0;

	///////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>Gets the menu item name. </summary>
	///
	/// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
	///
	/// <returns>Null if it fails, else the name. </returns>
	virtual const char* get_name() = 0;

	///////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>Increases the value pointed at. </summary>
	///
	/// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
	virtual void increase() = 0;

	///////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>Decreases the value pointed at. </summary>
	///
	/// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
	virtual void decrease() = 0;
};

