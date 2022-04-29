namespace game_framework {

	class Stage10 : public Stage
	{
	public:
		Stage10();
		~Stage10();
		void countEnemyNum() override;
		void LoadBack() override;
		void OnShowBack() override;
		int GetBackWidth() override;
	protected:
		
	private:
		int dc = 50;
		CMovingBitmap	background;	// ­I´º¹Ï
	};
}