namespace game_framework {

	class Stage4 : public Stage
	{
	public:
		Stage4();
		~Stage4();
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