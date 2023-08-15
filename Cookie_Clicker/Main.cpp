#include "config.hpp"
#include "game.hpp"

void Main()
{
	Window::Resize(kWindowSize);
	Window::SetTitle(kWindowName);

	TextureAsset::Register(U"shop",U"imgs/shop.png");
	TextureAsset::Register(U"ice-0", U"imgs/ice-0.png");
	TextureAsset::Register(U"ice-1", U"imgs/ice-1.png");
	TextureAsset::Register(U"ice-2", U"imgs/ice-2.png");
	TextureAsset::Register(U"ice-3", U"imgs/ice-3.png");
	TextureAsset::Register(U"ice-4", U"imgs/ice-4.png");
	TextureAsset::Register(U"ice-5", U"imgs/ice-5.png");

	FontAsset::Register(U"70" ,FontMethod::Bitmap, 70, U"example/font/DotGothic16/DotGothic16-Regular.ttf");
	FontAsset::Register(U"40", FontMethod::Bitmap, 40, U"example/font/DotGothic16/DotGothic16-Regular.ttf");
	FontAsset::Register(U"25", FontMethod::Bitmap, 25, U"example/font/DotGothic16/DotGothic16-Regular.ttf");
	FontAsset::Register(U"18", FontMethod::Bitmap, 20, U"example/font/DotGothic16/DotGothic16-Regular.ttf");

	App manager;

	manager.add<Game>(Scenes::Game);

	while (System::Update()) {

		if (not manager.update()) {
			break;
		}
	}

}
