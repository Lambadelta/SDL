#ifndef VEC2_H
#define VEC2_H
/**
@brief A structure that represents a Vector of 2 dimensions

This structure contains two floating point numbers
*/
struct Vec2
{
	///Float that represents the X axises
	float f_x;
	///Float that represents the Y axises
	float f_y;
	/**
	@brief A default constructor for the structure
	
	*/
	Vec2()
	{

	}
	/**
	@brief A constructor for the structure

	Takes in two float parameters, and assigns them to x/y
	@param float - A float with the X axises
	@param float - A float with the Y axises
	*/
	Vec2(float x, float y)
	{
		f_x = x;
		f_y = y;
	}
};

#endif