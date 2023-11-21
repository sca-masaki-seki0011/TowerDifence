// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Game.h"
#include "Enemy.h"
#include "SDL_mixer.h"
#define MUS_PATH "Assets/moriya.ogg"
Game game;

int main(int argc, char** argv)
{
	Mix_Music* music = NULL;
	// ���y�t�@�C���̃��[�h
	//music = Mix_LoadMUS(MUS_PATH);
	//if (music == NULL)
		//return -1;


	
	
	bool success = game.Initialize();
	if (success)
	{
		game.surface = TTF_RenderUTF8_Blended(game.font, "GAME START!!", { 255, 255, 255, 255 });
		game.texture = SDL_CreateTextureFromSurface(game.mRenderer, game.surface);
		SDL_SetRenderDrawColor(game.mRenderer, 0, 0, 0, 255);
		SDL_RenderClear(game.mRenderer);
		//������`�ʂ���Texture�̃T�C�Y���擾����      
		int iw, ih;
		SDL_QueryTexture(game.texture, NULL, NULL, &iw, &ih);

		SDL_Rect txtRect = { 0,0,iw,ih };
		SDL_Rect pasteRect = { 300,300,iw,ih };

		//Texture��`�ʂ���      
		//�`�ʌ��̕`�ʂ��镔��,�`�ʐ�̕`�ʂ��镔��)      
		//�T�C�Y���Ⴄ�Ə����Texture��L�W���Ă����      
		SDL_RenderCopy(game.mRenderer, game.texture, &txtRect, &pasteRect);
		//window�Ƀ����_�����O����      
		SDL_RenderPresent(game.mRenderer);

		SDL_Delay(3000);


		Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
		music = Mix_LoadMUS(MUS_PATH);
		Mix_PlayMusic(music, -1);
		game.RunLoop();
	}
	
	Mix_HaltMusic();
	Mix_FreeMusic(music);
	Mix_CloseAudio();
	SDL_Quit();
	game.Shutdown();
	return 0;
}
