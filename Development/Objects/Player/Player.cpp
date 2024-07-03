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
//初期化処理
void Player::Initialize()
{

	//画像読み込み
	animation[0] = LoadGraph("Resource/Images/Tri-pilot/1.png");
	animation[1] = LoadGraph("Resource/Images/Tri-pilot/2.png");


	//エラーチャック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("鳥パイロットの画像がありません`n");
	}

	//向き
	radian = 0.0f;

	//当たり判定の大きさ設定
	box_size = 64.0;

	//初期がそう設定
	image = animation[0];


}
//
void Player::Update()
{
	//移動処理
	Movement();

	//アニメーション
	AnimationControl();
}

//画像処理
void Player::Draw()const
{
	//プレイヤー画像の描画
	DrawRotaGraph(location.x, location.y, 0.8, radian, image, TRUE, flip_flag);
	

	//デバック用
#if _DEBUG
	//
	//Vector2D ul = location - (box_size / 2.0f);
	//Vector2D br = location + (box_size / 2.0f);

	//DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif 
}
//終了処理
void Player::Finalize()
{
	//使用する画像
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}
//当たり判定の処理
void Player::OnHitCollision(GameObject* hit_object)
{
	if (hit_object->GetType() == ENEMYBULLET)
	{
		if (dynamic_cast<Player*>(hit_object) != nullptr)
		{

			

		}
	}
}
//移動処理
void Player::Movement()
{
	//移動の速さ
	Vector2D velocity = 0.0f;
	//左右移動
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
	//現在の位置座標に速さを加速させる
	location += velocity;

}
//アニメーション制御
void Player::AnimationControl()
{
	//フレームカウントを加速する
	animation_count++;
	//６０フレームに到達したら
	if (animation_count >= 60)
	{
		//カウントリセット
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
