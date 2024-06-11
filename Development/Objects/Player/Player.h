#pragma once

#include "../GameObject.h"

class Player :public GameObject
{
private:
	int animation[2];//アニメーション画像
	int animation_count;//アニメーション時間
	int flip_flag;//反転フラグ


public:
	Player();
	~Player();

	//
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