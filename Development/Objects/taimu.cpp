#include "taimu.h"
#include "DxLib.h"

taimu::taimu()
{
}

taimu::~taimu()
{
}

void taimu::Initialize()
{
		taimu_count = 0;
	taima_flag = false;

	//‰æ‘œ‚Ì“Ç‚Ýž‚Ý
	tokei = LoadGraph("Resou/Images/TimeLimit/timer-03.png");
	taimu_image[0] = LoadGraph("Resou/Images/Score/0.png");
	taimu_image[1] = LoadGraph("Resou/Images/Score/0.png");
	taimu_image[2] = LoadGraph("Resou/Images/Score/0.png");
	taimu_image[3] = LoadGraph("Resou/Images/Score/0.png");
	taimu_image[4] = LoadGraph("Resou/Images/Score/0.png");
	taimu_image[5] = LoadGraph("Resou/Images/Score/0.png");
	taimu_image[6] = LoadGraph("Resou/Images/Score/0.png");
	taimu_image[7] = LoadGraph("Resou/Images/Score/0.png");
	taimu_image[8] = LoadGraph("Resou/Images/Score/0.png");
	taimu_image[9] = LoadGraph("Resou/Images/Score/0.png");

	image = tokei;

	// Œü‚«‚ÌÝ’è
	radian = 1.0;
}

void taimu::Update()
{
	++taimu_count;
	if (taimu_count >= 6000)
	{
		taima_flag = true;
	}
}

void taimu::Draw() const
{
	DrawRotaGraphF(500., 30, 0.7, radian, image, TRUE);
	DrawGraphF(520, 30, taimu_image[(taimu_count % 10000) / 1000], TRUE);
	DrawGraphF(540, 30, taimu_image[(taimu_count % 1000) / 100], TRUE);
}

void taimu::Finalize()
{
}

void taimu::Movement()
{
}
bool taimu::Gettam_flag()
{
	return false;
}