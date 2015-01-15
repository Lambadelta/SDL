#ifndef TEXT_H
#define TEXT_H

#include <SDL_ttf.h>
#include <SDL.h>
#include <string>

class Text
{
public:
	Text();
	~Text();
	
	bool create(std::string, SDL_Renderer*);
	void callDraw(SDL_Renderer*);
private:

	SDL_Texture* textTexture;
	TTF_Font* font;
	int width;
	int height;
};

#endif