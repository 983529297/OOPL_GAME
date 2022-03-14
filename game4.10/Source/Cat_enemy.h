namespace game_framework {

	class Cat_enemy : public Cat
	{
	public:
		Cat_enemy(string name, int blood, int attack);
		~Cat_enemy();
		bool IsHit();											// 是否遇到敵人
		bool IsAlive();											// 是否活著
		bool IsEnemy();											// 是否為敵人
		void LoadBitmap();										// 載入圖形
		void OnMove();											// 移動
		void OnShow();											// 將圖形貼到畫面
		void SetXY(int nx, int ny);								// 設定圓心的座標
		void SetIsAlive(bool alive);							// 設定是否活著
		void SetBlood(int attackCount);							// 扣血
		void Attack(Cat cat);									// 攻擊

	protected:

	private:
		int attackPoint;
		int defancePoint;
		bool is_alive;				// 是否活著
		bool is_enemy;				// 是否敵人

	};
}