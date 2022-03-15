namespace game_framework {

	class Tower_enemy
	{
	public:
		Tower_enemy();
		~Tower_enemy();
		void SetAttack(int);
		void BeAttack(int);
		void SetDefence(int);
		bool IsAlive();										// �O�_����
		//bool CheckEnemy(Cat*);									// find enemy
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
	};
}