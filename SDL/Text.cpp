#include "Text.h"
Text::Text()
{
	font = TTF_OpenFont("Asset/Text/PressStart2P.ttf", 8);
}

Text::~Text()
{

}

bool Text::create(std::string text, SDL_Renderer* renderer)
{
	SDL_Color colour = { 1, 1, 1 };
	SDL_Surface* temp = TTF_RenderText_Solid(font, text.c_str(), colour);
	if (temp == NULL)
	{
		return false;
	}
	width = temp->w;
	height = temp->h;
	textTexture = SDL_CreateTextureFromSurface(renderer, temp);
	if (textTexture == NULL)
	{
		return false;
	}
	SDL_FreeSurface(temp);
	return true;
}
void Text::setRect(SDL_Rect rect)
{
	descRect.x = rect.x;
	descRect.y = rect.y;
}
void Text::callDraw(SDL_Renderer* renderer)
{
	descRect.w = width * 2;
	descRect.h = height * 2;
	SDL_RenderCopy(renderer, textTexture, NULL, &descRect);
}

