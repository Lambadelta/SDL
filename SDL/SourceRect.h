#ifndef SOURCERECT_H
#define SOURCERECT_H
struct SourceRect
{
	float f_x;
	float f_y;
	float f_w;
	float f_h;
	SourceRect()
	{

	}

	SourceRect(float x, float y, float w, float h)
	{
		f_x = x;
		f_y = y;
		f_w = w;
		f_h = h;
	}
};
#endif