namespace game_framework {

	class Cat_enemy : public Cat
	{
	public:
		Cat_enemy(string name, int blood, int attack, int defence);
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
		void BeAttack(int attack) override;
		void Attack(Cat cat);									// ����

	protected:

	private:
		int attackPoint;
		int blood;
		int defancePoint;
		bool is_alive;				// �O�_����
		bool is_enemy;				// �O�_�ĤH
		string name;
	};
}