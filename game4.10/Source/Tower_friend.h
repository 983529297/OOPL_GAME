namespace game_framework {

	class Tower_friend
	{
	public:
		Tower_friend();
		~Tower_friend();
		void SetAttack(int);
		void BeAttack(int);
		void SetDefence(int);
		bool IsAlive();										// �O�_����
		int GetHitBox();								// find enemy
		void LoadBitmap();									// ���J�ϧ�
		void OnShow();										// �N�ϧζK��e��
		void SetXY(int, int);								// �]�w��ߪ��y��
		void SetIsAlive(bool);								// �]�w�O�_����
		void SetBlood(int);

	protected:

	private:
		CMovingBitmap bmp;
		int blood;
		int attackPoint;
		bool is_alive;				// �O�_����
		int defencePoint;
		int x, y;
		int centerX;
	};
}