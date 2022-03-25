namespace game_framework {

	class Cat_enemy : public Cat
	{
	public:
		Cat_enemy(string name, int blood, int attack, int defence, int speed);
		~Cat_enemy();
		bool IsHit() override;											// �O�_�J��ĤH
		bool IsAlive() override;											// �O�_����
		bool IsEnemy() override;											// �O�_���ĤH
		void LoadBitmap() override;										// ���J�ϧ�
		void OnMove() override;											// ����
		void OnShow() override;											// �N�ϧζK��e��
		void SetXY(int nx, int ny) override;								// �]�w��ߪ��y��
		void SetIsAlive(bool alive) override;							// �]�w�O�_����
		void SetBlood(int attackCount) override;							// ����
		void BeAttack(int attack) override;
		void Attack(Cat *cat) override;									// ����

	protected:

	private:
		int x, y;
		int attackPoint;
		int blood;
		int defancePoint;
		int speedPoint;
		bool is_alive;				// �O�_����
		bool is_enemy;				// �O�_�ĤH
		string name;
		CAnimation animation;
	};
}