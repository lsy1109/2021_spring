#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "audio.h"
#include "video.h"

class VideoAdapter: public Audio {
Video* vid;
public:
	VideoAdapter(Video *v) : vid(v) {}
	void play() { vid->playVideo(); }
	void pause() { vid->pauseVideo(); }
	std::string getName() { return vid->getName(); }
	void doubleSpeed() { vid->doubleSpeed(); }
};

class Player{
	std::vector<Audio*> playlist;
public:
	void add(Audio* aud){
		playlist.push_back(aud);
	}
	void play(){
		if (playlist.empty())
			std::cout << "Nothing to play" << std::endl;
		for (Audio* aud: playlist)
			aud->play();
	}
	void pause(){
		if (playlist.empty())
			std::cout << "Nothing to pause" << std::endl;
		for (Audio* aud: playlist)
			aud->pause();
	}
	void doubleSpeed(){
		if (playlist.empty())
			std::cout << "Nothing to double" << std::endl;
		for (Audio* aud: playlist) {
			if (aud->getName() == "MP3" || aud->getName() == "WAV") {
				std::cout << "audio cannot be double speed" << std::endl;
			}
			else {
				auto va = dynamic_cast<VideoAdapter*>(aud);
				va->doubleSpeed();
			}		
		}
	}
};
#endif