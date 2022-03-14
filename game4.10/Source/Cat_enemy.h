namespace game_framework {

	class Cat_enemy : public Cat
	{
	public:
		Cat_enemy(string name, int blood, int attack);
		~Cat_enemy();
		bool IsHit();											// �O�_�J��ĤH
		bool IsAlive();											// �O�_����
		bool IsEnemy();											// �O�_���ĤH
		void LoadBitmap();										// ���J�ϧ�
		void OnMove();											// ����
		void OnShow();											// �N�ϧζK��e��
		void SetXY(int nx, int ny);								// �]�w��ߪ��y��
		void SetIsAlive(bool alive);							// �]�w�O�_����
		void SetBlood(int attackCount);							// ����
		void Attack(Cat cat);									// ����

	protected:

	private:
		int attackPoint;
		int defancePoint;
		bool is_alive;				// �O�_����
		bool is_enemy;				// �O�_�ĤH

	};
}