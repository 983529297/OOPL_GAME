namespace game_framework {

	class Cat_friend : public Cat
	{
	public:
		Cat_friend(string name, int blood, int attack, int defence, int speed);
		~Cat_friend();
		bool IsHit() override;											// 是否遇到敵人
		bool IsAlive() override;											// 是否活著
		bool IsEnemy() override;											// 是否為敵人
		void LoadBitmap_Walk() override;										// 載入圖形
		void LoadBitmap_Attack() override;										// 載入圖形
		void OnMove() override;											// 移動
		void OnShow() override;											// 將圖形貼到畫面
		void SetXY(int nx, int ny) override;								// 設定圓心的座標
		void SetIsAlive(bool alive) override;							// 設定是否活著
		void SetBlood(int attackCount) override;							// 扣血
		void BeAttack(int attack) override;
		int Attack() override;
		bool isThere(int x) override;
		int GetAttackRange() override;

	protected:

	private:
		int x, y;
		int attackPoint;
		int blood;
		int defancePoint;
		int speedPoint;
		bool is_alive;				// 是否活著
		bool is_enemy;				// 是否敵人
		int hit_box;
		int attack_range;
		POINT center;
		string name;
		CAnimation animation;
	};
}