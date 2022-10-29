#pragma once

#include "CMenuItem.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>An integer menu item. </summary>
///
/// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
class CMenuItemInt : public CMenuItem
{
private:
	/// <summary>The name. </summary>
	const char* name;
	/// <summary>The value. </summary>
	int32_t* pValue;
	/// <summary>The minimum. </summary>
	int32_t min_val;
	/// <summary>The maximum. </summary>
	int32_t max_val;
	/// <summary>The step value. </summary>
	int32_t step_value;
	/// <summary>The increased step value. </summary>
	int32_t increased_step_value;

public:

	///////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>Constructor. </summary>
	///
	/// <remarks>Tim Jäger [0x54696d], 28/10/2022. </remarks>
	///
	/// <param name="name">				   The name. </param>
	/// <param name="pValue">			   [in,out] If non-null, the int 32 t. </param>
	/// <param name="min_val">			   The minimum value. </param>
	/// <param name="max_val">			   The maximum value. </param>
	/// <param name="step_value">		   The step value. </param>
	/// <param name="increased_step_value">The increased step value. </param>
	CMenuItemInt(const char* name, int32_t* pValue, int32_t min_val, int32_t max_val, int32_t step_value, int32_t increased_step_value);

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

