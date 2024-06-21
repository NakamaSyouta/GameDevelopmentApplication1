#include "bakudan.h"
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
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image,TRUE);

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
}

void bakudan::Movement()
{
	//�i�s�����Ɍ������āA�ʒu���W��ύX����
	location += direction;

}

void bakudan::AnimationControl()
{
}
