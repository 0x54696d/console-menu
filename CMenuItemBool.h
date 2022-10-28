#pragma once

#include "CMenuItem.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>A boolean menu item. </summary>
///
/// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
class CMenuItemBool : public CMenuItem
{
private:
	/// <summary>The name. </summary>
	const char* name{};
	/// <summary>The value. </summary>
	bool* pValue;

public:
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>Constructor. </summary>
	///
	/// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
	///
	/// <param name="name">  The name. </param>
	/// <param name="pValue">[in,out] If non-null, true to value. </param>
	CMenuItemBool(const char* name, bool* pValue);

	///////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>Toggles this object. </summary>
	///
	/// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
	void toggle();

	///////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>Renders this object. </summary>
	///
	/// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
	///
	/// <param name="is_active"> True if is active, false if not. </param>
	/// <param name="tab_offset">The tab offset. </param>
	void render(bool is_active, uint32_t tab_offset);

	///////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>Gets the name. </summary>
	///
	/// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
	///
	/// <returns>Null if it fails, else the name. </returns>
	const char* get_name();

	///////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>Increases the value pointed at. </summary>
	///
	/// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
	void increase();

	///////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>Decreases the value pointed at. </summary>
	///
	/// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
	void decrease();
};

