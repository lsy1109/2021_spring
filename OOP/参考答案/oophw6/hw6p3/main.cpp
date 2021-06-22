#include <iostream>
#include "player.h"
#include "mp3.h"
#include "wav.h"
#include "mp4.h"
#include "avi.h"

int main(){
	std::cout << "Create a player" << std::endl;
	Player* player = new Player();
	MP3* mp3 = new MP3();
	WAV* wav = new WAV();
	MP4* mp4 = new MP4();
	AVI* avi = new AVI();
	player->add(mp3);
	player->add(wav);
	player->add(new VideoAdapter(mp4));
	player->add(new VideoAdapter(avi));
	std::cout << "play all" << std::endl;
	player->play();
	std::cout << "pause all" << std::endl;
	player->pause();
	std::cout << "double speed" << std::endl;
	player->doubleSpeed();
	delete mp3;
	delete wav;
	delete mp4;
	delete avi;
	delete player;
	return 0;
}
