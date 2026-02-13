#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureManager.h"

#ifndef _Game_Engine_
#define _Game_Engine_

class Game_Engine
{
public:
	Game_Engine(){};
	~Game_Engine(){};

	bool init(const char *title, int xpos, int ypos, int width, int height, bool flags);
	void render();
	void update();
	void handleEvents();
	void clean();

	bool running() { return g_running; }

private:
	bool g_running;
	SDL_Window *m_pWindow;
	SDL_Renderer *m_pRenderer;
	int m_currentFrame;
	TextureManager m_textureManager;
};

#endif
