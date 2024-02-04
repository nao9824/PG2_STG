#pragma once
#include "Vector2.h"
#include "Object.h"
#include "Novice.h"

class BackGround :public Object {
private:
	int backGround_ = Novice::LoadTexture("./Resources/yokohaikei.png");

public:
	BackGround();
	~BackGround();
	Vector2 GetPosition()override { return position_; };
	float GetSpeed()override { return speed_; };
	void SetPosition(float x, float y)override;
	void SetSpeed(float speed)override;
	void Update();
	void Draw()override;
};
