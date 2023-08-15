#include "config.hpp"
#include "game.hpp"

void Main()
{
	Window::Resize(kWindowSize);
	Window::SetTitle(kWindowName);

	TextureAsset::Register(U"shop",U"imgs/shop.png");
	FontAsset::Register(U"60" ,FontMethod::Bitmap, 60, U"example/font/DotGothic16/DotGothic16-Regular.ttf");

	App manager;

	manager.add<Game>(Scenes::Game);

	while (System::Update()) {

		if (not manager.update()) {
			break;
		}
	}
}
