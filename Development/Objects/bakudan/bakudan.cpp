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
	// 向きの設定
	radian = DX_PI_F/2;

	//当たり判定の大きさを設定
	box_size = 64.0f;

	//初期画像の設定
	image = animation[0];

	//初期進行方向の設定
	direction = Vector2D(0.0f, 1.0f);
}


void bakudan::Update()
{
	//移動処理
	Movement();

	//アニメーション制御
	AnimationControl();
}
void bakudan::Draw() const
{
	//情報を基に爆弾画像を描画する
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image,TRUE);

	//親クラスの描画処理を呼び出す
	__super::Draw();
}

void bakudan::Finalize()
{
	//使用した画像を解放
	DeleteGraph(animation[0]);
}

void bakudan::OnHitCollision(GameObject* hit_object)
{
}

void bakudan::Movement()
{
	//進行方向に向かって、位置座標を変更する
	location += direction;

}

void bakudan::AnimationControl()
{
}
