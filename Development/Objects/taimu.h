#pragma once

#include"../Objects/GameObject.h"

class taimu :public GameObject
{
private:
	int taimu_count;       //�^�C�}�[�J�E���g
	int taimu_image[10];   //�^�C�}�[�摜
	int tokei;           //���v�̉摜


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

