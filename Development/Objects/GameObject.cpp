#include "GameObject.h"

//コンストラクタ
GameObject::GameObject() :
	location(0.0f),
	scale(0.0f),
	radian(0.0f),
	image(0),
	sound(0)
{

}
//
GameObject::~GameObject()
{

}
//
void GameObject::Initialize()
{

}
//
void  GameObject::Update()
{

}
void  GameObject::Draw()const
{

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
//
Vector2D GameObject::GetLocation()const
{
	return this->location;
}

void GameObject::SetLocation(const Vector2D location)
{
	this->location = location;
}

