#pragma once

#include "../Utility/Vector2D.h"

#define D_PIVOT_CENTER  //

#define BAKUDAN      (0)
#define ENEMY        (1)
#define ENEMY2       (2)
#define ENEMY3       (3)
#define HARPY        (4)
#define PLAYER       (5)
#define ENEMYBULLET  (6)


//�Q�[���I�[�u�W�F�N�g�K��N���X
class GameObject
{
protected:

	Vector2D location;     //�ʒu���
	Vector2D box_size;     //�Z�`�̑傫��
	double radian;         //����
	int image;             //�`�悷��摜
	int sound;             //�Đ����鉹��
	int type;              //�^�C�v
	




public:

   
	bool deleit_fiag;
	bool Deleteobj();

	GameObject();
	virtual ~GameObject();
	virtual void Initialize();  //�����摜
	virtual void Update();      //�X�V����
	virtual void Draw()const;   //�`�揈��
	virtual void Finalize();    //�I��������

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object);

	//�ʒu���擾����
	Vector2D GetLocation()const;

	//�ʒu���ύX����
	void SetLocation(const Vector2D& location);

	//�����蔻��̑傫�����擾����
	Vector2D GetBoxSize()const;

	int GetType();

	bool Getliv();
};