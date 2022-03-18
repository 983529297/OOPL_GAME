namespace game_framework {

	class Cat
	{
	public:
		Cat() {};
		~Cat() {};
		virtual bool IsHit() { return true; };											// 是否遇到敵人
		virtual bool IsAlive() { return true; };											// 是否活著
		virtual bool IsEnemy() { return true; };											// 是否為敵人
		virtual void LoadBitmap() {};										// 載入圖形
		virtual void OnMove() {};											// 移動
		virtual void OnShow() {};											// 將圖形貼到畫面
		virtual void SetXY(int nx, int ny) {};								// 設定圓心的座標
		virtual void SetIsAlive(bool alive) {};							// 設定是否活著
		virtual void SetBlood(int attackCount) {};							// 扣血
		virtual void Attack(Cat cat) {};									// 攻擊
		virtual void BeAttack(int attack) {};

	protected:

	private:

	};
}