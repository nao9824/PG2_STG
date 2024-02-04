#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet()
{
	position_ = {};
	speed_ = 7.0f;
	radius_ = 30.0f;
	height_ = 64.0f;
	width_ = 64.0f;
	isBulletShot_ = false;
}

Bullet::~Bullet()
{
}

void Bullet::SetPosition(float x, float y)
{
	position_ = { x,y };
}

void Bullet::SetSpeed(float speed)
{
	speed_ = speed;
}

void Bullet::SetisBulletShot(bool isBulletShot)
{
	isBulletShot_ = isBulletShot;
}

void Bullet::Update()
{
	if (isBulletShot_ == true) {
		position_.x += speed_;
		if (position_.x >= 1290) {
			isBulletShot_ = false;
		}
	}
}

void Bullet::Draw()
{
	if (isBulletShot_ == true) {

		Novice::DrawSprite((int)position_.x - ((int)width_ / 2), (int)position_.y - ((int)height_ / 2),
			foam_, 1, 1, 0.0f, WHITE);
		}
}