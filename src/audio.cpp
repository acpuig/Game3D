#include "audio.h"
#include "utils.h"

std::map<std::string, Audio*> Audio::sLoadedAudios;

Audio::Audio()
{
	sample = 0;
}

Audio::~Audio()
{
	BASS_SampleFree(sample);
}

HCHANNEL Audio::play(float volume) ////lanza el audio y retorna el channel donde suena
{
	HCHANNEL hSampleChannel = BASS_SampleGetChannel(sample, false);
	BASS_SetVolume(volume);
	BASS_ChannelPlay(hSampleChannel, true);
	return hSampleChannel;
}

void Audio::Stop(DWORD dSampleChannel)  //para parar un audio necesitamos su channel
{
	BASS_ChannelStop(dSampleChannel);
}

Audio* Audio::Get(const char* filename) //manager de audios 
{
	std::map<std::string, Audio*>::iterator it = sLoadedAudios.find(filename);
	if (it != sLoadedAudios.end())
		return it->second;

	Audio* a = new Audio();
	std::string name = filename;

	//detect format
	char file_format = 0;
	std::string ext = name.substr(name.find_last_of(".") + 1);

	if (ext == "wab" || ext == "WAB") {
		file_format = 0;
	}
	else {
		std::cout << "Unknown audio format: " << filename << std::endl;
		return NULL;
	}

	sLoadedAudios[filename] = a;
	std::cout << " + Audio loading: " << filename << " ... ";

	return a; //return the resulting resource

}

DWORD Audio::Play(const char* filename) //version estática para ir mas rapido
{
	HSAMPLE hSample = BASS_SampleLoad(false, filename, 0, 0, 3, 0);
	HCHANNEL hSampleChannel = BASS_SampleGetChannel(hSample, false);
	BASS_ChannelPlay(hSampleChannel, false);
	DWORD dSampleChannel = BASS_SampleGetChannels(hSample,&hSampleChannel);

	return dSampleChannel;
}

