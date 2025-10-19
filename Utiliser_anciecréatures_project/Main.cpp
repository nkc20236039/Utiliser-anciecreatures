#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	// �������O�̃A�v���ݒ�
#ifdef _DEBUG
	ChangeWindowMode(TRUE);
	SetOutApplicationLogValidFlag(TRUE);
#else
	ChangeWindowMode(FALSE);
	SetOutApplicationLogValidFlag(FALSE);
#endif

	// �c�w���C�u�����̏�����
	if (DxLib_Init() < 0) {
		// �G���[�����������璼���ɏI��
		return -1;
	}

	// �`����ʂ𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	// �y�o�b�t�@��L���ɂ���
	SetUseZBuffer3D(TRUE);

	// �y�o�b�t�@�ւ̏������݂�L���ɂ���
	SetWriteZBuffer3D(TRUE);

	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}