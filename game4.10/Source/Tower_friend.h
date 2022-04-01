namespace game_framework {

	class Tower_friend
	{
	public:
		Tower_friend();
		~Tower_friend();
		void SetAttack(int);
		void BeAttack(int);
		void SetDefence(int);
		bool IsAlive();										// 是否活著
		int GetHitBox();								// find enemy
		void LoadBitmap();									// 載入圖形
		void OnShow();										// 將圖形貼到畫面
		void SetXY(int, int);								// 設定圓心的座標
		void SetIsAlive(bool);								// 設定是否活著
		void SetBlood(int);

	protected:

	private:
		CMovingBitmap bmp;
		int blood;
		int attackPoint;
		bool is_alive;				// 是否活著
		int defencePoint;
		int x, y;
		int centerX;
	};
}