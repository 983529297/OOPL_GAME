namespace game_framework {

	class Cat
	{
	public:
		Cat() {};
		~Cat() {};
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
		virtual void BeAttack(int attack);

	protected:

	private:

	};
}