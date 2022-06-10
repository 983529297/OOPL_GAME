namespace game_framework {

	class Stage
	{
	public:
		Stage() {};
		virtual ~Stage() {};
		int getEnemyNum() { return enemynum; }
		virtual void countEnemyNum() { };
		virtual void LoadBack() { };
		virtual void OnShowBack() { };
		virtual int GetBackWidth() { return 0; };
	protected:
		int enemynum = -1;
		int count = 0;
	private:

	};
}