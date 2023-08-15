#include "button.hpp"

Button::Button(const Vec2 pos, const Size size, const int level,const int need_ice_num, const String title, const String sub_title, const String asset_id)
	: pos{ pos }
	, size{ size }
	, level{ level }
	, need_ice_num { need_ice_num }
	, title{ title }
	, sub_title{ sub_title }
	, asset_id{ asset_id } {

	}

void Button::update(){

}

void Button::draw() const {

	RectF{ pos,size }.rounded(10).draw(Color{ U"#051637" }).drawFrame(2);
	RectF title_rect = FontAsset(U"40")(title).drawBase({ pos.x + 10 , pos.y + (size.y * 0.45) });
	RectF sub_title_rect = FontAsset(U"25")(U"Lv." + ToString(level)).drawBase({ pos.x + title_rect.w + 20 , pos.y + (size.y * 0.4) });

	FontAsset(U"18")(sub_title).drawBase({ pos.x + 10 , pos.y + (size.y * 0.8) });

	Vec2 btn_pos{ pos.x + 10 + title_rect.w + 20 + sub_title_rect.w + 50,pos.y + 10 };

	RectF{ btn_pos,75,80 }.rounded(10).drawFrame(2);
	Line{ btn_pos.movedBy(37,65),btn_pos.movedBy(37,20) }
			.drawArrow(10, Vec2{ 20, 20 }, Palette::White);

	FontAsset(U"18")(U"-" + ToString(need_ice_num)).drawAt(btn_pos.movedBy(35,95));

}

bool Button::IsClick() const
{
	return false;
}

void Button::updateLevel(const int new_level){
	level = new_level;
}

void Button::SetState(bool state) {

}
