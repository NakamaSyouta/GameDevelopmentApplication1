#include "Player.h"
#include "../../Utility/InputConttrol.h"
#include "DxLib.h"

Player::Player() :animation_count(0), flip_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;
}
Player::~Player()
{

}
//����������
void Player::Initialize()
{

	//�摜�ǂݍ���
	animation[0] = LoadGraph("Resource/Images/Tri-pilot/1.png");
	animation[1] = LoadGraph("Resource/Images/Tri-pilot/2.png");


	//�G���[�`���b�N
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("���p�C���b�g�̉摜������܂���`n");
	}

	//����
	radian = 0.0f;

	//�����蔻��̑傫���ݒ�
	box_size = 64.0;

	//�����������ݒ�
	image = animation[0];


}
//
void Player::Update()
{
	//�ړ�����
	Movement();

	//�A�j���[�V����
	AnimationControl();
}

//�摜����
void Player::Draw()const
{
	//�v���C���[�摜�̕`��
	DrawRotaGraph(location.x, location.y, 0.8, radian, image, TRUE, flip_flag);
	

	//�f�o�b�N�p
#if _DEBUG
	//
	//Vector2D ul = location - (box_size / 2.0f);
	//Vector2D br = location + (box_size / 2.0f);

	//DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif 
}
//�I������
void Player::Finalize()
{
	//�g�p����摜
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}
//�����蔻��̏���
void Player::OnHitCollision(GameObject* hit_object)
{
	if (hit_object->GetType() == ENEMYBULLET)
	{
		if (dynamic_cast<Player*>(hit_object) != nullptr)
		{

			

		}
	}
}
//�ړ�����
void Player::Movement()
{
	//�ړ��̑���
	Vector2D velocity = 0.0f;
	//���E�ړ�
	if (InputControl::GetKey(KEY_INPUT_LEFT))
	{
		velocity.x += -1.0f;
		flip_flag =TRUE;
	}
	else if (InputControl::GetKey(KEY_INPUT_RIGHT))
	{
		velocity.x += 1.0f;
		flip_flag =  FALSE;
	}
	else
	{
		velocity.x = 0.0f;
	}
	//���݂̈ʒu���W�ɑ���������������
	location += velocity;

}
//�A�j���[�V��������
void Player::AnimationControl()
{
	//�t���[���J�E���g����������
	animation_count++;
	//�U�O�t���[���ɓ��B������
	if (animation_count >= 60)
	{
		//�J�E���g���Z�b�g
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
