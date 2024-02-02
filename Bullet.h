#pragma once
#include "Vector2.h"
#include "Object.h"
#include "Novice.h"

class Bullet : public Object {
private:
	bool isBulletShot_;
	int foam_ = Novice::LoadTexture("./Resources/foam.png");
public:
	Bullet();
	~Bullet();
	Vector2 GetPosition()override { return position_; };
	float GetSpeed()override { return speed_; };
	float GetRadius()override { return radius_; };
	bool GetisBulletShot() { return isBulletShot_; };
	void SetPosition(float x, float y)override;
	void SetSpeed(float speed)override;
	void SetisBulletShot(bool isBulletShot);
	void Update();
	void Draw()override;
};