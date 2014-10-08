#include "Texture.h"
class Sprite : protected Texture
{
public:
	Sprite();
	~Sprite();
	void updatePlayerPosition();
	void drawPlayerPosition();
private:
};