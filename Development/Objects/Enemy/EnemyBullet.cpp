#include "EnemyBullet.h"
#include"DxLib.h"
#include"../Player/Player.h"



EnemyBullet::EnemyBullet()
{
	anima[0] = NULL;
	anima[1] = NULL;
	anima[2] = NULL;
	anima[3] = NULL;

}

EnemyBullet::~EnemyBullet()
{

}

void EnemyBullet::Initialize()
{
	anima[0] = LoadGraph("Resource/Images/EnemyBullet/1.png");
	anima[1] = LoadGraph("Resource/Images/EnemyBullet/eff1.png");
	anima[2] = LoadGraph("Resource/Images/EnemyBullet/eff2.png");
	anima[3] = LoadGraph("Resource/Images/EnemyBullet/eff3.png");

	type = ENEMYBULLET;

	// �����̐ݒ�
	radian = DX_PI_F / 2;

	//�����蔻��̑傫����ݒ�
	box_size = 64.0f;

	//�����摜�̐ݒ�
	image = anima[0];

	//�����i�s�����̐ݒ�
	direction = Vector2D(0.0f, -1.0f);
}


void EnemyBullet::Update()
{
	//�ړ�����
	Movement();

	//�A�j���[�V��������
	AnimationControl();
}
void EnemyBullet::Draw() const
{
	//������ɔ��e�摜��`�悷��
	DrawRotaGraphF(location.x, location.y, 0.8, radian, image, TRUE);


	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();
}

void EnemyBullet::Finalize()
{
	//�g�p�����摜�����
	DeleteGraph(anima[0]);
}

void EnemyBullet::OnHitCollision(GameObject* hit_object)
{

	//�n�R�e�L�����蔻��
	if (hit_object->GetType() == PLAYER)
	{
		if (dynamic_cast<Player*>(hit_object) != nullptr)
		{

			direction = 0.0f;
			box_size = 0.0;
			deleit_fiag = true;

		}
	}
}

void EnemyBullet::Movement()
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

void EnemyBullet::AnimationControl()
{
	//�A�j���[�V�����J�E���g���Z����
	animation_count++;

	//30�t���[���ڂɓ��B������
	if (animation_count >= 30)
	{
		//�J�E���g�̃��Z�b�g
		animation_count = 0;

		//�摜�̐؂�ւ�
		if (image == anima[0])
		{
			image = anima[1];
		}
		if (image == anima[1])
		{
			image = anima[2];
		}
		if (image == anima[2])
		{
			image = anima[3];
		}
	}

}