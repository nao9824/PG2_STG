#pragma once
#include "Vector2.h"

class Object {
protected:
	Vector2 position_ ;
	float speed_;
	float radius_;
	float height_;
	float width_;

public:
	virtual Vector2 GetPosition() { return position_; };
	virtual float GetSpeed() { return speed_; };
	virtual float GetRadius() { return radius_; };
	virtual float GetHeight() { return height_; };
	virtual float GetWidth() { return width_; };
	virtual void SetPosition(float x, float y);
	virtual void SetSpeed(float speed);
	virtual void Draw();
};