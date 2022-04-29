namespace game_framework {

	class Stage6 : public Stage
	{
	public:
		Stage6();
		~Stage6();
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