#include <SDL.h>

//fps
const int fpsNum = 20;

extern class FPS 
{
	private:
		int startT;
		int pausedT;
		bool paused;
		bool started;
	public:
		FPS();
		void startFPS();
		void stopFPS();
		void pauseFPS();
		void unpauseFPS();
		int getT();
		bool isStarted();
		bool isPause();
};