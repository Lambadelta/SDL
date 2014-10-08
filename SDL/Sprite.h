#include "Texture.h"
class Sprite : protected Texture
{
public:
	Sprite(int x, int y);
	~Sprite();
	void updateSpritePosition();
	void drawSpritePosition();
	int GetBoundBoxX(void);
	int GetBoundBoxY(void);
	int GetBoundBoxW(void);
	int GetBoundBoxH(void);
protected:
	int BoundBoxX;
	int BoundBoxY;
	int BoundBoxW;
	int BoundBoxH;
};