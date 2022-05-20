namespace game_framework {

	class Cat_enemy : public Cat
	{
	public:
		Cat_enemy(string name, int blood, int attack, int defence, int speed, int attack_pic, int walk_pic, int as);
		~Cat_enemy();
		bool IsHit() override;											// 是否遇到敵人
		bool IsAlive() override;											// 是否活著
		bool IsEnemy() override;											// 是否為敵人
		void LoadBitmap_Walk() override;										// 載入圖形
		void LoadBitmap_Attack() override;										// 載入圖形
		void OnMove() override;											// 移動
		void ReOnMove() override;											// 移動
		void OnShow_Walk() override;											// 將圖形貼到畫面
		void OnShow_Attack() override;											// 將圖形貼到畫面
		void SetXY(int nx, int ny) override;								// 設定圓心的座標
		void SetIsAlive(bool alive) override;							// 設定是否活著
		bool GetReset() override;							// 設定是否活著
		void AnimationReset() override;							// 設定是否活著
		void SetAnimationReset() override;							// 設定是否活著
		void SetBlood(int attackCount) override;							// 扣血
		void BeAttack(int attack) override;						// 攻擊
		int Attack() override;						// 攻擊
		bool isThere(int x) override;
		int GetAttackRange() override;
		int GetAttackPoint() override;
		int GetBloodPoint() override;
		bool GetIsAttack() override;
		bool GetIsFinalAttack() override;

	protected:

	private:
		int attackSpeed;
		int x, y;
		int attackPoint;
		int blood;
		int defancePoint;
		int speedPoint;
		int attack_pic;
		int walk_pic;
		bool is_alive;				// 是否活著
		bool is_enemy;				// 是否敵人
		bool is_attack;				// 是否敵人
		bool is_final_attack = false;				// 是否敵人
		bool reset = false;
		int hit_box;
		int attack_range;
		vector<string> walkPath;
		vector<string> attackPath;
		POINT center;
		string name;
		CAnimation animation_walk;
		CAnimation animation_attack;
	};
}