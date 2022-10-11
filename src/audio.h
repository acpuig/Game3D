#ifndef AUDIO //macros to ensure the code is included once
#define AUDIO

#include <bass.h>
#include <map>
#include <string>


class Audio
{
public:
	static std::map<std::string, Audio*> sLoadedAudios; //para nuestro manager
	HSAMPLE sample; //aqui guardamos el handler del sample que retorna BASS_SampleLoad


	Audio(); //importante poner sample a cero aqui
	~Audio(); //aqui deberiamos liberar el sample con BASS_SampleFree

	HCHANNEL play(float volume); //lanza el audio y retorna el channel donde suena

	static void Stop(DWORD dSampleChannel); //para parar un audio necesitamos su channel
	static Audio* Get(const char* filename); //manager de audios 
	static DWORD Play(const char* filename); //version estática para ir mas rapido

};

#endif
