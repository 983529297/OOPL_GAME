namespace game_framework {

	class Cat
	{
	public:
		Cat() {};
		virtual ~Cat() {};
		virtual bool IsHit() { return true; };								// 是否遇到敵人
		virtual bool IsAlive() { return true; };							// 是否活著
		virtual bool IsEnemy() { return true; };							// 是否為敵人
		virtual void LoadBitmap_Walk() {};									// 載入圖形
		virtual void LoadBitmap_Attack() {};								// 載入圖形
		virtual void OnMove() {};											// 移動
		virtual void ReOnMove() {};											// 移動
		virtual void OnShow_Walk() {};										// 將圖形貼到畫面
		virtual void OnShow_Attack() {};									// 將圖形貼到畫面
		virtual void SetXY(int nx, int ny) {};								// 設定圓心的座標
		virtual void SetIsAlive(bool alive) {};								// 設定是否活著
		virtual bool GetReset() { return false; };							// 設定是否活著
		virtual void AnimationReset() {};									// 設定是否活著
		virtual void SetAnimationReset() {};								// 設定是否活著
		virtual void SetBlood(int attackCount) {};							// 扣血
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