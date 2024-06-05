#include "GameObject.h"
#include"DxLib.h"

//�R���X�g���N�^
GameObject::GameObject() :
	location(0.0f),
	box_size(0.0f),
	radian(0.0f),
	image(0),
	sound(0)
{

}
GameObject::~GameObject()
{

}
//������
void GameObject::Initialize()
{

}
//�X�V
void  GameObject::Update()
{

}
//�`��
void  GameObject::Draw()const
{
	//�����蔻��̉���
#ifdef D_PIVOT_CENTER
	Vector2D tl = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);

	DrawBoxAA(tl.x, tl.y, br.x, br.y, GetColor(255, 0, 0), FALSE);

#else
	Vector2D tl = location;
	Vector2D br = location + box_size;

	DrawBoxAA(tl.x, tl.y, br.x, br.y, GetColor(255, 0, 0), FALSE);

#endif // D_PIVOT_CENTER

}
//
void GameObject::Finalize()
{

}
//
void GameObject::OnHitCollision(GameObject* hit_object)
{
	//
}

//�ʒu���ݒ菈��
Vector2D GameObject::GetLocation()const
{
	return location;
}

void GameObject::SetLocation(const Vector2D& location)
{
	this->location = location;
}

Vector2D GameObject::GetBoxSize()const
{
	return box_size;
}
