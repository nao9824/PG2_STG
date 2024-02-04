#pragma once
#include "Vector2.h"
#include "Bullet.h"
#include "Object.h"
#include "Novice.h"

class Player : public Object {
private:
	int playerHP_;
	int player_ = Novice::LoadTexture("./Resources/co-la1.4.png");
	int Hp = Novice::LoadTexture("./Resources/life.png");
public:
	Bullet* bullet[5];


	Player();
	~Player();
	Vector2 GetPosition()override { return position_; };
	float GetSpeed()override { return speed_; };
	float GetRadius()override { return radius_; };
	int GetPlayerHP() { return playerHP_; };
	void SetPosition(float x, float y)override;
	void SetSpeed(float speed)override;
	void SetPlayerHP(int playerHP);
	void Update(char* keys, char* preKeys);
	void Draw()override;
};