#include <irrKlang.h>


using namespace irrklang;

class SoundEngine
{
private:
	ISoundEngine* soundEngine = createIrrKlangDevice();
	irrklang::ISound* sound;
public:

	void Play(const char* filePath, bool repeat = false)
	{
		sound = soundEngine->play2D(filePath, repeat);
	}

	float GetVolume() { return soundEngine->getSoundVolume(); }
	void SetVolume(float volume) { soundEngine->setSoundVolume(volume); }
};
