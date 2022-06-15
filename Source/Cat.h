namespace game_framework {

	class Cat
	{
	public:
		Cat() {};
		virtual ~Cat() {};
		virtual bool IsHit() { return true; };								// �O�_�J��ĤH
		virtual bool IsAlive() { return true; };							// �O�_����
		virtual bool IsEnemy() { return true; };							// �O�_���ĤH
		virtual void LoadBitmap_Walk() {};									// ���J�ϧ�
		virtual void LoadBitmap_Attack() {};								// ���J�ϧ�
		virtual void OnMove() {};											// ����
		virtual void ReOnMove() {};											// ����
		virtual void OnShow_Walk() {};										// �N�ϧζK��e��
		virtual void OnShow_Attack() {};									// �N�ϧζK��e��
		virtual void SetXY(int nx, int ny) {};								// �]�w��ߪ��y��
		virtual void SetIsAlive(bool alive) {};								// �]�w�O�_����
		virtual bool GetReset() { return false; };							// �]�w�O�_����
		virtual void AnimationReset() {};									// �]�w�O�_����
		virtual void SetAnimationReset() {};								// �]�w�O�_����
		virtual void SetBlood(int attackCount) {};							// ����
		virtual void BeAttack(int attack) {};
		virtual bool isThere(int x) { return false; };
		virtual int GetAttackRange() { return 0; };
		virtual int GetAttackPoint() { return 0; };
		virtual int GetBloodPoint() { return 0; };
		virtual bool GetIsAttack() { return 0; };
		virtual bool GetIsFinalAttack() { return 0; };
		virtual int Attack() { return 0; };

	protected:

	private:

	};
}