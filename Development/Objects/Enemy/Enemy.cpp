#include "Enemy.h"
#include"../../Objects/bakudan/bakudan.h"
#include "DxLib.h"

Enemy::Enemy() :animation_count(0), direction(0.0f), patterm(GetRand(3))
{
	anima[0] = NULL;
	anima[1] = NULL;
}
Enemy::~Enemy()
{

}

//����������
void Enemy::Initialize()
{
	//�摜�̓ǂݍ���
	anima[0] = LoadGraph("Resource/Images/BoxEnemy/1.png");
	anima[1] = LoadGraph("Resource/Images/BoxEnemy/2.png");

	type = ENEMY;
	

	//�G���[�`�F�b�N
	if (anima[0] == -1 || anima[1] == -1)
	{
		throw("�n�R�e�L�̉摜������܂���`n");
	}
	//�����i�s�����̐ݒ�
	direction = Vector2D(1.0f,0.0f);
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
	image = anima[0];

	switch (patterm)
	{
	case 1:
		location.y = 400;
		break;
	case 2:
		location.y = 390;
		break;
	case 3:
		location.y = 380;
		break;
	default:
		location.y = 370;
		break;
	}
	
}
//�X�V����
void Enemy::Update()
{
	//�ړ�����
	Movement();

	//�A�j���[�V��������
	AnimationControl();
}
//�`�揈��
void Enemy::Draw()const
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
	//������Ƀn�R�e�L�摜��`�悷��
	DrawRotaGraphF(location.x, location.y, 0.7, radian, image, TRUE, flip_flag);

	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();
}
//�I������
void Enemy::Finalize()
{
	//�g�p�����摜�����
	DeleteGraph(anima[0]);
	DeleteGraph(anima[1]);
	box_size = 0;
}
//�����蔻��ʒm����
void Enemy::OnHitCollision(GameObject* hit_object)
{
	if(hit_object->GetType()==BAKUDAN)
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
void Enemy::Movement()
{
	//��ʒ[�ɓ��B������A������
	
	
	if (location.x >= 690 || location.x <= -50)
	{
		Finalize();
	}

	//�i�s�����Ɍ������āA�ʒu���W��ύX����
	location += direction;
}
//�A�j���[�V��������
void Enemy::AnimationControl()
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
		else
		{
			image = anima[0];
		}
	}
}
