#pragma once
#include "Vector2.h"
#include "Object.h"
#include "Novice.h"

class Enemy : public Object {
private:
	bool isEnemyAlive_;
	int enemy_ = Novice::LoadTexture("./Resources/kabihei1.3.png");
public:
	Enemy();
	~Enemy();
	float GetSpeed()override { return speed_; };
	float GetRadius()override { return radius_; };
	bool GetisEnemyAlive_() { return isEnemyAlive_; };
	void SetPosition(float x, float y)override;
	void SetSpeed(float speed)override;
	void SetisEnemyAlive(bool isEnemyAlive);
	void Update(char* keys, char* preKeys);
	void Draw()override;
};