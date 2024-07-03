#include "Enemy3.h"
#include"../bakudan/bakudan.h"
#include "DxLib.h"

Enemy3::Enemy3() :animation_count(0), direction(0.0f), patterm(GetRand(3))
{
	animation[0] = NULL;
	animation[1] = NULL;
}
Enemy3::~Enemy3()
{

}
//����������
void Enemy3::Initialize()
{
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/Images/WingEnemy/1.png");
	animation[1] = LoadGraph("Resource/Images/WingEnemy/2.png");
	type = ENEMY3;

	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("�n�l�e�L�̉摜������܂���`n");
	}


	//�����i�s�����̐ݒ�
	direction = Vector2D(1.0f, 0.0f);
	if (location.x <= 300.0f)
	{
		direction.x = 1;
	}
	else
	{
		direction.x = -1;
	}
	// �����̐ݒ�
	radian = 0.0f;

	//�����蔻��̑傫����ݒ�
	box_size = 64.0f;

	//�����摜�̐ݒ�
	image = animation[0];

	switch (patterm)
	{
	case 1:
		location.y = 250;
		break;
	case 2:
		location.y = 220;
		break;
	case 3:
		location.y = 190;
		break;
	default:
		location.y = 180;
		break;
	}
	
}
//�X�V����
void Enemy3::Update()
{
	//�ړ�����
	Movement();

	//�A�j���[�V��������
	AnimationControl();
}
//�`�揈��
void Enemy3::Draw()const
{
	//�摜���]�t���O
	int flip_flag = FALSE;

	//�i�s�����ɂ���āA���]��Ԃ���������肷��

	if (direction.x > 0.0f)
	{
		flip_flag = FALSE;
	}
	else
	{
		flip_flag = TRUE;
	}
	//������Ƀn�l�e�L�摜��`�悷��
	DrawRotaGraphF(location.x, location.y, 0.6, radian, image, TRUE, flip_flag);

	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();
}
//�I������
void Enemy3::Finalize()
{
	//�g�p�����摜�����
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}
//�����蔻��ʒm����
void Enemy3::OnHitCollision(GameObject* hit_object)
{
	if (hit_object->GetType() == BAKUDAN)
	{
		if (dynamic_cast<bakudan*>(hit_object) != nullptr)
		{

			direction = 0.0f;
			box_size = 0.0;
			Finalize();
			deleit_fiag = true;

		}
	}
}
//�ړ�����
void Enemy3::Movement()
{
	//��ʒ[�ɓ��B������A������
	if (((location.x + direction.x) < box_size.x) ||
		(640.0f - box_size.x) < (location.x + direction.x))
	{
		;
	}

	if (location.x >= 640 || location.x <= 0)
	{
		Finalize();
	}
	//�i�s�����Ɍ������āA�ʒu���W��ύX����
	location += direction;
}
//�A�j���[�V��������
void Enemy3::AnimationControl()
{
	//�A�j���[�V�����J�E���g���Z����
	animation_count++;

	//30�t���[���ڂɓ��B������
	if (animation_count >= 30)
	{
		//�J�E���g�̃��Z�b�g
		animation_count = 0;

		//�摜�̐؂�ւ�
		if (image == animation[0])
		{
			image = animation[1];
		}
		else
		{
			image = animation[0];
		}
	}
}