namespace game_framework {

	class Cat
	{
	public:
		Cat() {};
		~Cat() {};
		virtual bool IsHit() { return true; };											// �O�_�J��ĤH
		virtual bool IsAlive() { return true; };											// �O�_����
		virtual bool IsEnemy() { return true; };											// �O�_���ĤH
		virtual void LoadBitmap() {};										// ���J�ϧ�
		virtual void OnMove() {};											// ����
		virtual void OnShow() {};											// �N�ϧζK��e��
		virtual void SetXY(int nx, int ny) {};								// �]�w��ߪ��y��
		virtual void SetIsAlive(bool alive) {};							// �]�w�O�_����
		virtual void SetBlood(int attackCount) {};							// ����
		virtual void Attack(Cat cat) {};									// ����
		virtual void BeAttack(int attack) {};

	protected:

	private:

	};
}