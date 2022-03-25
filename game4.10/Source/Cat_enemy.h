namespace game_framework {

	class Cat_enemy : public Cat
	{
	public:
		Cat_enemy(string name, int blood, int attack, int defence, int speed);
		~Cat_enemy();
		bool IsHit() override;											// 是否遇到敵人
		bool IsAlive() override;											// 是否活著
		bool IsEnemy() override;											// 是否為敵人
		void LoadBitmap() override;										// 載入圖形
		void OnMove() override;											// 移動
		void OnShow() override;											// 將圖形貼到畫面
		void SetXY(int nx, int ny) override;								// 設定圓心的座標
		void SetIsAlive(bool alive) override;							// 設定是否活著
		void SetBlood(int attackCount) override;							// 扣血
		void BeAttack(int attack) override;
		void Attack(Cat *cat) override;									// 攻擊

	protected:

	private:
		int x, y;
		int attackPoint;
		int blood;
		int defancePoint;
		int speedPoint;
		bool is_alive;				// 是否活著
		bool is_enemy;				// 是否敵人
		string name;
		CAnimation animation;
	};
}