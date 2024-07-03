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

	// 向きの設定
	radian = DX_PI_F / 2;

	//当たり判定の大きさを設定
	box_size = 64.0f;

	//初期画像の設定
	image = anima[0];

	//初期進行方向の設定
	direction = Vector2D(0.0f, -1.0f);
}


void EnemyBullet::Update()
{
	//移動処理
	Movement();

	//アニメーション制御
	AnimationControl();
}
void EnemyBullet::Draw() const
{
	//情報を基に爆弾画像を描画する
	DrawRotaGraphF(location.x, location.y, 0.8, radian, image, TRUE);


	//親クラスの描画処理を呼び出す
	__super::Draw();
}

void EnemyBullet::Finalize()
{
	//使用した画像を解放
	DeleteGraph(anima[0]);
}

void EnemyBullet::OnHitCollision(GameObject* hit_object)
{

	//ハコテキ当たり判定
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
	//進行方向に向かって、位置座標を変更する
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
	//アニメーションカウント加算する
	animation_count++;

	//30フレーム目に到達したら
	if (animation_count >= 30)
	{
		//カウントのリセット
		animation_count = 0;

		//画像の切り替え
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