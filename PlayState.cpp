#include "PlayState.h"

PlayState PlayState::playstate_t;

//state management functions
void PlayState::Init() 
{
	MilkyWay.generateStellae(1920, 1080);
}
void PlayState::Goodbye()
{

}
void PlayState::Pause()
{

}
void PlayState::Resume()
{

}


void PlayState::HandleEvents(Engine* game)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_RETURN)
			{
				Update(game);
			}
			else if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				game->Quit();
			}
			else if (event.key.keysym.sym == SDLK_n)
			{
				Init();
				MWOverlay.reset();
				freeConstellation.reset();
				needsBackground = true;
				Update(game);
			}
			else if (event.key.keysym.sym == SDLK_BACKSPACE || event.key.keysym.sym == SDLK_DELETE)
			{
				freeConstellation.deleteLastLine();
				needsBackground = true;
				Update(game);
			}
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			click = true;
		}
		else if (event.type == SDL_MOUSEBUTTONUP)
		{
			if (click)
			{
				if (MWOverlay.freeObjects.size() > 1)
				{
					playerObject* nl = MWOverlay.freeObjects.back();
					freeConstellation.addLine(nl);
					MWOverlay.freeObjects.pop_back();
				}
				int x;
				int y;
				SDL_GetMouseState(&x, &y);
				int targetI = MilkyWay.findNearestStar(x, y);
				int targetX = MilkyWay.Stellae[targetI]->xpos;
				int targetY = MilkyWay.Stellae[targetI]->ypos;

				if (MWOverlay.freeObjects.empty())
				{
					selectionArrow* na;
					na = new selectionArrow(targetX, targetY, targetI);
					MWOverlay.freeObjects.push_front(na);
				}
				else if (MWOverlay.testIfSelection(targetX, targetY))
				{
					return;
				}
				else
				{
					selectionArrow* na;
					na = new selectionArrow(targetX, targetY, targetI);
					MWOverlay.freeObjects.pop_front();
					MWOverlay.freeObjects.push_front(na);
					needsBackground = true;
					Update(game);
				}
			}
			click = false;
		}
		else if (event.type == SDL_MOUSEMOTION && click)
		{
			if (MWOverlay.freeObjects.empty())
			{
				return;
			}
			else
			{
				int x;
				int y;
				SDL_GetMouseState(&x, &y);
				int ntari = MWOverlay.getSelectionI();
				int ndestI = MilkyWay.findSecondNearestStar(x, y, ntari);
				line* nl;
				nl = new line(MWOverlay.getSelectionX(), MWOverlay.getSelectionY(), ntari, MilkyWay.Stellae[ndestI]->xpos, MilkyWay.Stellae[ndestI]->ypos, ndestI);
				if (MWOverlay.freeObjects.size() > 1)
				{
					MWOverlay.freeObjects.pop_back();
					MWOverlay.freeObjects.push_back(nl);
				}
				else
				{
					MWOverlay.freeObjects.push_back(nl);
				}
				needsBackground = true;
				Update(game);
			}
		}
		else if (event.type == SDL_MOUSEMOTION)
		{
			int x;
			int y;
			SDL_GetMouseState(&x, &y);
			int targetI = MilkyWay.findNearestStar(x, y);
			int targetX = MilkyWay.Stellae[targetI]->xpos;
			int targetY = MilkyWay.Stellae[targetI]->ypos;

			if (MWOverlay.freeObjects.empty())
			{
				selectionArrow* na;
				na = new selectionArrow(targetX, targetY, targetI);
				MWOverlay.freeObjects.push_front(na);
			}
			else if (MWOverlay.testIfSelection(targetX, targetY))
			{
				return;
			}
			else
			{
				selectionArrow* na;
				na = new selectionArrow(targetX, targetY, targetI);
				MWOverlay.freeObjects.pop_front();
				MWOverlay.freeObjects.push_front(na);
				needsBackground = true;
				Update(game);
			}
		}
		else if (event.type == SDL_QUIT)
		{
			game->Quit();
		}
	}
}


void PlayState::Update(Engine* game)
{
	if (needsBackground)
	{
		SDL_SetRenderDrawColor(game->ren, 0, 0, 0, 255);
		SDL_RenderClear(game->ren);
		SDL_RenderDrawRect(game->ren, NULL);
		needsBackground = false;
	}
	MilkyWay.renderGalaxy(game->ren);
	MWOverlay.render(game->ren);
	freeConstellation.render(game->ren);
	SDL_RenderPresent(game->ren);
}


void PlayState::Draw(Engine* game)
{
	
}
