#pragma once
#include "../GameObject.h"
class bakudan:public GameObject
	{
	private:
		int animation[1];        //
		Vector2D direction;     //  êiçsï˚å¸

	public:
		bakudan();
		~bakudan();

		virtual void Initialize()override;
		//
		virtual void Update()override;
		//
		virtual void Draw()const override;
		//
		virtual void Finalize()override;

		//
		virtual void OnHitCollision(GameObject* hit_object)override;

	private:
		//
		void Movement();
		//
		void AnimationControl();

};

