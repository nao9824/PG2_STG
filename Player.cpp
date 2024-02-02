#include "Player.h"
#include "Novice.h"

Player::Player()
{
	position_ = { 200.0f,360.0f };
	speed_ = 4.0f;
	radius_ = 90.0f;
	height_ = 256.0f;
	width_ = 256.0f;
	playerHP_ = 3;

	for (int i = 0; i < 5; i++) {
		bullet[i] = new Bullet;
	}
}

Player::~Player()
{
	for (int i = 0; i < 5; i++) {
		delete bullet[i];
	}
}

void Player::SetPosition(float x,float y)
{
	position_ = { x,y };
}

void Player::SetSpeed(float speed)
{
	speed_ = speed;
}

void Player::SetPlayerHP(int playerHP)
{
	playerHP_ = playerHP - 1;
	position_ = { 200.0f,360.0f };
}

void Player::Update(char* keys, char* preKeys)
{
	if (playerHP_ > 0) {
		if (keys[DIK_W]) {
			position_.y -= speed_;
		}
		if (keys[DIK_S]) {
			position_.y += speed_;
		}
		if (keys[DIK_A]) {
			position_.x -= speed_;
		}
		if (keys[DIK_D]) {
			position_.x += speed_;
		}

		for (int i = 0; i < 5; i++) {
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]
				&& bullet[i]->GetisBulletShot() == false) {
				bullet[i]->SetisBulletShot(true);
				bullet[i]->SetPosition(position_.x + 40, position_.y);
				break;
			}
			bullet[i]->Update();
		}
	}

	if (playerHP_ == 0 && keys[DIK_R] && !preKeys[DIK_R]) {
		playerHP_ = 3;
		position_ = { 200.0f,360.0f };
	}
}

void Player::Draw()
{
	if (playerHP_ > 0) {
		for (int i = 0; i < 5; i++) {
			bullet[i]->Draw();
		}
	
	Novice::DrawSprite((int)position_.x - ((int)width_ / 2) - 20, (int)position_.y - ((int)height_ / 2),
		player_, 1, 1, 0.0f, WHITE);

	Novice::DrawEllipse((int)position_.x, (int)position_.y,
		(int)radius_, (int)radius_, 0.0f, WHITE, kFillModeWireFrame);
	}
}