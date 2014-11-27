#ifndef RECT_H
#define RECT_H

/**
@brief A structure containing four floats

This structure is used for creating Source Rects for sprite maps
*/
struct Rect
{
	float f_x;
	float f_y;
	float f_w;
	float f_h;
	Rect()
	{

	}
	/**
	@brief A constructor for the structure that takes in four parameters

	@param float - A float containing the x axises
	@param float - A float containing the y axises
	@param float - A float containing the width
	@param float - A float containing the height
	*/
	Rect(float x, float y, float w, float h)
	{
		f_x = x;
		f_y = y;
		f_w = w;
		f_h = h;
	}
};
#endif