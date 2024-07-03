#pragma once
#include "../GameObject.h"
class EnemyBullet:public GameObject
{
private:
	int anima[4];               //
	int animation_count;        //
	Vector2D direction;     //  êiçsï˚å¸

public:
	EnemyBullet();
	~EnemyBullet();

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

