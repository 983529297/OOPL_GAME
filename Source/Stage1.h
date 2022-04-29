namespace game_framework {

	class Stage1 : public Stage
	{
	public:
		Stage1();
		~Stage1();
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