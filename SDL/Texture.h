class Texture
{
public:
	/*Constructor*/
	Texture();

	/*Destructor*/
	~Texture();

	/*Function to load texture from file*/
	bool loadFromFile(std::string path);

	/*Deallocate the texture data*/
	void Deallocate();
	/*Sets colour*/
	void setColour();
	/*Clears the colour*/
	void clearColour();
	/*Sets Alpha*/
	void setAlpha();
	/*Create the Renderer*/
	void createRenderer(SDL_Window * window);
	/*Where the texture will be drawn*/
	void setRect();
	/*Function to render the texture*/
	void Render();
	/*Function to send the texture to the screen*/
	void CopyToScreen();
	void ShowScreen();
	void QureyTexture();
	void ProcessTexture(SDL_Window* window, std::string path);

	
	
	SDL_Renderer* getRenderer();


private:
	/*Texture pointer declaration*/
	SDL_Texture* cTexture;
	SDL_Surface* cImage;
	SDL_Renderer* cRenderer;
	SDL_Rect cDestRect;
	/*Height and Width dimensions for the texture*/
	int iWidth;
	int iHeight;
};