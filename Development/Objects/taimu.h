#pragma once

#include"../Objects/GameObject.h"

class taimu :public GameObject
{
private:
	int taimu_count;       //タイマーカウント
	int taimu_image[10];   //タイマー画像
	int tokei;           //時計の画像


public:

	bool taima_flag;
	bool Gettam_flag();


	taimu();
	~taimu();

	//
	virtual void Initialize()override;
	//
	virtual void Update()override;
	//
	virtual void Draw()const override;
	//
	virtual void Finalize()override;

private:
	//
	void Movement();

};

