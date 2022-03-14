namespace game_framework {

	class Tower_friend
	{
	public:
		Tower_friend();
		~Tower_friend();
		void SetBoold();
		void SetAttack();
		bool IsAlive();											// 是否活著
		void LoadBitmap();										// 載入圖形
		void OnShow();											// 將圖形貼到畫面
		void SetXY(int nx, int ny);								// 設定圓心的座標
		void SetIsAlive(bool alive);							// 設定是否活著
		void SetBlood(int attackCount);							// 扣血

	protected:

	private:
		int blood;
		int attackPoint;
		bool is_alive;				// 是否活著
		int defencePoint;
	};
}