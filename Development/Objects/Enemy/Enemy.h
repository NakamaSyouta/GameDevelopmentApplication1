#pragma once

#include "../GameObject.h"

class Enemy :public GameObject
{
private:

	int patterm;
	int anima[2];               //
	int animation_count;        //
	Vector2D direction;     //  êiçsï˚å¸

public:
	Enemy();
	~Enemy();

	virtual void Initialize()override;
	//
	virtual void Update()override;
	//
	virtual void Draw()const override;
	//
	virtual void Finalize()override;

	//
	virtual void OnHitCollision(GameObject* hit_object)override;

private:
	//
	void Movement();
	//
	void AnimationControl();
};

