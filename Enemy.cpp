#include "Enemy.h"
#include "Novice.h"

Enemy::Enemy()
{
	position_ = { 900.0f,300.0f };
	speed_ = 5.0f;
	radius_ = 80.0f;
	height_ = 192.0f;
	width_ = 192.0f;
	isEnemyAlive_ = true;

}

Enemy::~Enemy()
{
}

void Enemy::SetPosition(float x, float y)
{
	position_ = { x,y };
}

void Enemy::SetSpeed(float speed)
{
	speed_ = speed;
}

void Enemy::SetisEnemyAlive(bool isEnemyAlive)
{
	isEnemyAlive_ = isEnemyAlive;
}

void Enemy::Update(char* keys, char* preKeys)
{
	if (isEnemyAlive_ == true) {
		position_.y += speed_;
		if (position_.y >= 720 - radius_ || position_.y <= 0 + radius_) {
			speed_ = -speed_;
		}

	}
	if (isEnemyAlive_ == false && keys[DIK_R] && !preKeys[DIK_R]) {
		isEnemyAlive_ = true;
	}
}

void Enemy::Draw()
{
	if (isEnemyAlive_ == true) {
		Novice::DrawSprite((int)position_.x - ((int)width_ / 2), (int)position_.y - ((int)height_ / 2),
			enemy_, 1, 1, 0.0f, WHITE);

		}
}