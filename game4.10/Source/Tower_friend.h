namespace game_framework {

	class Tower_friend
	{
	public:
		Tower_friend();
		~Tower_friend();
		void SetBoold();
		void SetAttack();
		bool IsAlive();											// �O�_����
		void LoadBitmap();										// ���J�ϧ�
		void OnShow();											// �N�ϧζK��e��
		void SetXY(int nx, int ny);								// �]�w��ߪ��y��
		void SetIsAlive(bool alive);							// �]�w�O�_����
		void SetBlood(int attackCount);							// ����

	protected:

	private:
		int blood;
		int attackPoint;
		bool is_alive;				// �O�_����
		int defencePoint;
	};
}