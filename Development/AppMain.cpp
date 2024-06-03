#include"DxLib.h"
#include"Utility/InputConttrol.h"
#include"Scene/Scene.h"


//���C���֐��i�v���O�����͂�������n�܂�܂��j
int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)

{
	//Window ���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//�E�B���h�E�T�C�Y�i���F�U�S�O�����A�c�F�S�W�O�����j��ݒ�
	SetGraphMode(640, 480, 32);

	//DX���C�u�����[�̏�����
	if (DxLib_Init() == -1)
	{
		//�ُ��ʒm
		return -1;

	}
	//���[�J���ϐ���`
	Scene* scene = new Scene();     //�V�[�����
	int result = 0;                 //�I���󋵏��

	//�`���𗠉�ʂ���͂��߂�悤�ɂ��Ă�����


	SetDrawScreen(DX_SCREEN_BACK);

	try
	{
		//�V�[���̏�����
		scene->Initialize();

		//���C�����[�v�i�E�B���h�E�ُ̈픭��orESC�L�[�������ꂽ�烋�[�v�I���j
		//
		while (ProcessMessage() != -1 &&
			InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)
		{
			//���͑ҋ@�̍X�V
			InputControl::Update();

			//�V�[���̍X�V����
			scene->Update();

			//��ʂ̏�����
			ClearDrawScreen();

			//�V�[���̕`�揈��
			scene->Draw();

			//����ʂ̓��e��\��ʂɔ��f
			ScreenFlip();
		}
	}
	catch (const char* error_log)
	{
		//�G���[����Log.txt�ɏo�͂���
		OutputDebugString(error_log);
		//�ُ��ԂɕύX����
		result = -1;

	}
	//�V�[�����̍폜����
	if (scene != nullptr)
	{
		scene->Finalize();
		delete scene;
		scene = nullptr;
	}
	//Dx���C�u�����̏I�����̏���
	DxLib_End();
	//�I����Ԃ�ʒm
	return result;
};