#include "GameFunction.h"
#include "sfwdraw.h"
#include "GameObject.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace sfw;

void AboutState(GlobalData* gd)
{
	//Cursors
	for (unsigned int i = 0; i < (gd)->Cursors.size(); ++i)
		if ((gd)->Cursors[i].GetScreenID() == 5) (gd)->Cursors[i].OnUpdateLogic(gd);

	//Buttons
	for (unsigned int i = 0; i < (gd)->Buttons.size(); ++i)
		if ((gd)->Buttons[i].GetScreenID() == 5) (gd)->Buttons[i].OnUpdateLogic(gd);

	//Normal Sprites
	for (unsigned int i = 0; i < (gd)->NormalSprites.size(); ++i)
		if ((gd)->NormalSprites[i].GetScreenID() == 5) (gd)->NormalSprites[i].OnUpdateLogic(gd);

	//Normal Texts
	for (unsigned int i = 0; i < (gd)->NormalTexts.size(); ++i)
		if ((gd)->NormalTexts[i].GetScreenID() == 5) (gd)->NormalTexts[i].OnUpdateLogic(gd);
}