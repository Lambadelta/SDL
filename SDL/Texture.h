#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <string>
#include <iostream>
class Texture
{
public:
	/*Constructor*/
	Texture(std::string path, int, int);

	/*Destructor*/
	~Texture();

	/*Function to load texture from file*/
	bool loadFromFile(std::string path);

	/*Deallocate the texture data*/
	void Deallocate();
	/*Sets colour*/
	void setColour(SDL_Renderer* BackRenderer);
	/*Clears the colour*/
	void clear(SDL_Renderer* BackRenderer);
	/*Sets Alpha*/
	void setAlpha();
	/*Where the texture will be drawn*/
	/*void setRect();*/
	/*Function to render the texture*/
	void Render(SDL_Renderer* BackRenderer);
	/*Function to send the texture to the screen*/
	void CopyToScreen(SDL_Renderer* BackRenderer);
	void ShowScreen(SDL_Renderer* BackRenderer);
	void QureyTexture();
	void ProcessTexture(SDL_Renderer* BackRenderer);



protected:
	/*Texture pointer declaration*/
	SDL_Texture* cTexture;
	SDL_Surface* cImage;
	SDL_Rect cDestRect;
	/*Height and Width dimensions for the texture*/
	int iWidth;
	int iHeight;
};

#endif