#include "Tower_enemy.h"
#include "Tower_friend.h"
#include "Cat.h"
#include "Cat_enemy.h"
#include "Cat_friend.h"
#include "Stage.h"
#include "SimpleFactory.h"


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////
	static int stagenum = 1;
	static int win_lose = -1; //-1���w 0�� 1Ĺ
	static bool music_op = true;
	static bool music_game = true;

	enum AUDIO_ID {				// �w�q�U�ح��Ī��s��
		AUDIO_OP,				// 0
		AUDIO_NORM,				// 1
		AUDIO_HARD				// 2
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C���}�Y�e������
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////
	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnKeyUp(UINT, UINT, UINT); 				// �B�z��LUp���ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@ 
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
	protected:
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		bool ready = false;
		int win_state = 0;
		double game_sound_size;
		double music_sound_size;
		double start_size;
		double option_size;
		double close_size;
		double goBack_size;
		double battle_size;
		double stage1_size, stage2_size, stage3_size, stage4_size, stage5_size, stage6_size, stage7_size, stage8_size, stage9_size, stage10_size;
		CMovingBitmap logo;
		CMovingBitmap start;
		CMovingBitmap option;
		CMovingBitmap about;
		CMovingBitmap win_about;
		CMovingBitmap secretKey;
		CMovingBitmap win_option;
		CMovingBitmap close;
		CMovingBitmap state_back;
		CMovingBitmap map;
		CMovingBitmap goBack;
		CMovingBitmap battle;
		CMovingBitmap cat_spot;
		CMovingBitmap musicSound;
		CMovingBitmap musicSoundAnti;
		CMovingBitmap gameSound;
		CMovingBitmap gameSoundAnti;
		CMovingBitmap stage1, stage2, stage3, stage4, stage5, stage6, stage7, stage8, stage9, stage10;
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnLButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@ 
		void OnRButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnRButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
		void DeleteDeadCat(int position, bool side);
		void VectorSort();
		void readCSV();
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap	background;						// �I����
		CMovingBitmap	upgrade;
		CMovingBitmap	upgrade_black;
		CMovingBitmap	empty_block[5];
		CMovingBitmap	block[5];
		CMovingBitmap	slash;
		CMovingBitmap	slash_T;
		CMovingBitmap	slash_T_1;
		CInteger callPoint;
		CInteger callPointTotal;
		CInteger Point1;
		CInteger Point2;
		CInteger Point3;
		CInteger Point4;
		CInteger Point5;
		CIntegerTower friendTowerBlood;
		CIntegerTower friendTowerBloodTotal;
		CIntegerTower enemyTowerBlood;
		CIntegerTower enemyTowerBloodTotal;
		CIntegerTower upgradePoint;
		Tower_enemy tower_enemy;
		Tower_friend tower_friend;
		vector<Cat*> cat_enemy;
		vector<Cat*> cat_friend;
		vector<vector<string>> data_enemy;
		vector<vector<string>> data_friend;
		Stage *stage = nullptr;
		SimpleFactory *sf = nullptr;
		int enemyTowerHitRange;
		int friendTowerHitRange;
		int addPoint = 1;
		int weight;
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		int counter;									// �˼Ƥ��p�ƾ�
		CMovingBitmap win;
		CMovingBitmap lose;
		CMovingBitmap back;
	};

}