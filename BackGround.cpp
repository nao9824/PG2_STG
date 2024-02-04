#include "BackGround.h"

BackGround::BackGround()
{
	position_ = { 0.0f,0.0f };
	speed_ = 3.0f;
}

BackGround::~BackGround()
{
}

void BackGround::SetPosition(float x, float y)
{
	position_ = { x,y };
}

void BackGround::SetSpeed(float speed)
{
	speed_ = speed;
}

void BackGround::Update()
{
	position_.x -= speed_;
	if (position_.x < -1275) {
		position_ = { 1275.0f,0.0f };
	}
}

void BackGround::Draw()
{
	Novice::DrawSprite((int)position_.x, (int)position_.y,
		backGround_, 1, 1, 0.0f, WHITE);
}
