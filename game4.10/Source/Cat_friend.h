namespace game_framework {

	class Cat_friend : public Cat
	{
	public:
		Cat_friend(string name, int blood, int attack, int defence, int speed);
		~Cat_friend();
		bool IsHit() override;											// �O�_�J��ĤH
		bool IsAlive() override;											// �O�_����
		bool IsEnemy() override;											// �O�_���ĤH
		void LoadBitmap_Walk() override;										// ���J�ϧ�
		void LoadBitmap_Attack() override;										// ���J�ϧ�
		void OnMove() override;											// ����
		void ReOnMove() override;											// ����
		void OnShow_Walk() override;											// �N�ϧζK��e��
		void OnShow_Attack() override;											// �N�ϧζK��e��
		void SetXY(int nx, int ny) override;								// �]�w��ߪ��y��
		void SetIsAlive(bool alive) override;							// �]�w�O�_����
		void AnimationReset() override;							// �]�w�O�_����
		void SetBlood(int attackCount) override;							// ����
		void BeAttack(int attack) override;
		int Attack() override;
		bool isThere(int x) override;
		int GetAttackRange() override;
		int GetAttackPoint() override;
		int GetBloodPoint() override;
		bool GetIsAttack() override;
		bool GetIsFinalAttack() override;

	protected:

	private:
		int x, y;
		int attackPoint;
		int blood;
		int defancePoint;
		int speedPoint;
		bool is_alive;				// �O�_����
		bool is_enemy;				// �O�_�ĤH
		bool is_attack;				// �O�_�ĤH
		bool is_final_attack = false;				// �O�_�ĤH
		int hit_box;
		int attack_range;
		POINT center;
		string name;
		CAnimation animation_walk;
		CAnimation animation_attack;
	};
}