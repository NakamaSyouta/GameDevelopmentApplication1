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
//初期化処理
void Enemy3::Initialize()
{
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/WingEnemy/1.png");
	animation[1] = LoadGraph("Resource/Images/WingEnemy/2.png");
	type = ENEMY3;

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("ハネテキの画像がありません`n");
	}


	//初期進行方向の設定
	direction = Vector2D(1.0f, 0.0f);
	if (location.x <= 300.0f)
	{
		direction.x = 1;
	}
	else
	{
		direction.x = -1;
	}
	// 向きの設定
	radian = 0.0f;

	//当たり判定の大きさを設定
	box_size = 64.0f;

	//初期画像の設定
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
//更新処理
void Enemy3::Update()
{
	//移動処理
	Movement();

	//アニメーション制御
	AnimationControl();
}
//描画処理
void Enemy3::Draw()const
{
	//画像反転フラグ
	int flip_flag = FALSE;

	//進行方向によって、反転状態を決定を決定する

	if (direction.x > 0.0f)
	{
		flip_flag = FALSE;
	}
	else
	{
		flip_flag = TRUE;
	}
	//情報を基にハネテキ画像を描画する
	DrawRotaGraphF(location.x, location.y, 0.6, radian, image, TRUE, flip_flag);

	//親クラスの描画処理を呼び出す
	__super::Draw();
}
//終了処理
void Enemy3::Finalize()
{
	//使用した画像を解放
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}
//当たり判定通知処理
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
//移動処理
void Enemy3::Movement()
{
	//画面端に到達したら、消える
	if (((location.x + direction.x) < box_size.x) ||
		(640.0f - box_size.x) < (location.x + direction.x))
	{
		;
	}

	if (location.x >= 640 || location.x <= 0)
	{
		Finalize();
	}
	//進行方向に向かって、位置座標を変更する
	location += direction;
}
//アニメーション制御
void Enemy3::AnimationControl()
{
	//アニメーションカウント加算する
	animation_count++;

	//30フレーム目に到達したら
	if (animation_count >= 30)
	{
		//カウントのリセット
		animation_count = 0;

		//画像の切り替え
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