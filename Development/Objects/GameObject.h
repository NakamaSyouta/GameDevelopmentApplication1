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


//ゲームオーブジェクト規定クラス
class GameObject
{
protected:

	Vector2D location;     //位置情報
	Vector2D box_size;     //短形の大きさ
	double radian;         //向き
	int image;             //描画する画像
	int sound;             //再生する音源
	int type;              //タイプ
	




public:

   
	bool deleit_fiag;
	bool Deleteobj();

	GameObject();
	virtual ~GameObject();
	virtual void Initialize();  //初期画像
	virtual void Update();      //更新処理
	virtual void Draw()const;   //描画処理
	virtual void Finalize();    //終了時処理

	//当たり判定通知処理
	virtual void OnHitCollision(GameObject* hit_object);

	//位置情報取得処理
	Vector2D GetLocation()const;

	//位置情報変更処理
	void SetLocation(const Vector2D& location);

	//当たり判定の大きさを取得する
	Vector2D GetBoxSize()const;

	int GetType();

	bool Getliv();
};