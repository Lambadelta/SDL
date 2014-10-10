#ifndef VEC4_H
#define VEC4_H

struct Vec4
{
	float f_x;
	float f_y;
	float f_w;
	float f_h;

	Vec4()
	{

	}

	Vec4(float x, float y, float w, float h)
	{
		f_x = x;
		f_y = y;
		f_w = w;
		f_h = h;
	}
};

#endif