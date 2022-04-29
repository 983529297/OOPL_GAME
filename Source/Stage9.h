namespace game_framework {

	class Stage9 : public Stage
	{
	public:
		Stage9();
		~Stage9();
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