#include "bakudan.h"
#include"../Enemy/Enemy.h"
#include"../Enemy/Enemy2.h"
#include"../Enemy/Enemy3.h"
#include"../Enemy/Harpy.h"
#include"../GameObject.h"
#include"DxLib.h"

bakudan::bakudan()
{
	animation[0] = NULL;
	
}

bakudan::~bakudan()
{

}

void bakudan::Initialize()
{
	animation[0] = LoadGraph("Resource/Images/Bomb/Bomb.png");

	type = BAKUDAN;
	
	// �����̐ݒ�
	radian = DX_PI_F/2;

	//�����蔻��̑傫����ݒ�
	box_size = 64.0f;

	//�����摜�̐ݒ�
	image = animation[0];

	//�����i�s�����̐ݒ�
	direction = Vector2D(0.0f, 1.0f);
}


void bakudan::Update()
{
	//�ړ�����
	Movement();

	//�A�j���[�V��������
	AnimationControl();
}
void bakudan::Draw() const
{
	//������ɔ��e�摜��`�悷��
	DrawRotaGraphF(location.x, location.y, 0.8, radian, image, TRUE);


	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();
}

void bakudan::Finalize()
{
	//�g�p�����摜�����
	DeleteGraph(animation[0]);
}

void bakudan::OnHitCollision(GameObject* hit_object)
{

	//�n�R�e�L�����蔻��
	if (hit_object->GetType() ==ENEMY)
	{
		if (dynamic_cast<Enemy*>(hit_object) != nullptr)
		{
			
			direction = 0.0f;
			box_size = 0.0;
			deleit_fiag = true;

		}
	}

	//�n�R�e�L�����蔻��
	if (hit_object->GetType() == ENEMY2)
	{
		if(dynamic_cast<Enemy2*>(hit_object)!=nullptr)
		{

			direction = 0.0f;
			box_size = 0.0;
			deleit_fiag = true;
		}
	}
	//�n�R�e�L�����蔻��
	if (hit_object->GetType() == ENEMY3)
	{
		if (dynamic_cast<Enemy3*>(hit_object) != nullptr)
		{

			direction = 0.0f;
			box_size = 0.0;
			deleit_fiag = true;
		}
	}
	//�n�R�e�L�����蔻��
	if (hit_object->GetType() == HARPY)
	{
		if (dynamic_cast<Harpy*>(hit_object) != nullptr)
		{

			direction = 0.0f;
			box_size = 0.0;
			deleit_fiag = true;
		}
	}
}

void bakudan::Movement()
{
	//�i�s�����Ɍ������āA�ʒu���W��ύX����
	location += direction;

	if (location.y >= 400)
	{
		deleit_fiag = true;
	}
	if (location.x >= 640 || location.x <= 0)
	{
		Finalize();
	}
}

void bakudan::AnimationControl()
{
	
}
