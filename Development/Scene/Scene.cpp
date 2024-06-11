#include "Scene.h"
#include"../Objects/Player/Player.h"
#include"../Objects/Enemy/Enemy.h"
#include"../Utility/InputConttrol.h"
#include"DxLib.h"

#define D_PIVOT_CENTER

//�R���X�g���N�^
Scene::Scene() :objects()
{

}

Scene::~Scene()
{
	//�Y��h�~
	Finalize();
}
//����������
void Scene::Initialize()
{
	//�v���C���[�𐶐�����
	CreateObject<Player>(Vector2D(320.0f, 240.0f));



	//�w�i��݂���
	background = LoadGraph("Resource/Images/BackGround.png");

	if (background == -1)
	{
		throw("Resource/images/BacGround������܂���\n");
	}

}
//�X�V����
void Scene::Update()
{
	//�V�[���ɑ��݂���I�u�W�F�N�g�̍X�V����
	for (GameObject* obj : objects)
	{
		obj->Update();
	}


	//�I�u�W�F�N�g���m�̓����蔻��
	for (int i = 0;i < objects.size();i++)
	{
		for (int j = i + 1;j < objects.size();j++)
		{
			//�����蔻��
			HitCheckObject(objects[i], objects[j]);
		}
	}
	//Z�L�[����������A�G�𐶐�����
	if (InputControl::GetKeyDown(KEY_INPUT_Z))
	{
		CreateObject<Enemy>(Vector2D(100.0f, 400.0f));
	}

}

void Scene::Draw()const
{

//�w�i�Ăяo��
	DrawExtendGraph(0, 0,640,480, background, FALSE);

	//�V�[���ɑ��݂���I�u�W�F�N�g�̕`�揈��
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}
	
}

void Scene::Finalize()
{
	//���I�z�񂪋�Ȃ珈�����I������
	if (objects.empty())
	{
		return;
	}
	//�e�I�u�W�F�N�g���폜����
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}
	//���I�z��̉��
	objects.clear();
}
#ifdef D_PIVOT_CENTER
//�����蔻��`�F�b�N�����i�Z�`�̒��S�ł�����͂�Ă������j
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//2�̃I�u�W�F�N�g�̋����擾
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//2�̃I�u�W�F�N�g�̓����蔻��̑傫�����擾
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	//���������傫�����傫���ꍇ�AHit���肷��
	if ((fabs(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		//�����������Ƃ��I�u�W�F�N�g�ɒʒm����
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}
#else
//�����蔻��`�F�b�N�����i���㒸�_�̍��W�󓖂��蔻��v�Z���s���j

void Scene::HitChecKObject(GameObject* a, GameObject* b)
{
	//�E�����_���W���擾����
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D b_lower_right = b->GetLocation() + b->GetBoxSize();

	//�Z�`A�ƒZ�`B�̈ʒu�֌W�𒲂ׂ�
	if ((a->GetLocation().x < b_lower_right.x) &&
		(a->GetLocation().y < b_lower_right.y) &&
		(a_lower_right.x > b->GetLocation().x) &&
		(a_lower_right.y > b->GetLocation().y))
	{
		//�I�u�W�F�N�g�ɑ΂���Hit�����ʒm����
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}
#endif  //D_PIVOT_CNETER