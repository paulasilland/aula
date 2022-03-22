
#include "tigr/tigr.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "GUIICONS.h"
#include "GUIXML.h"

Tigr *backdrop, *screen;


int main(int argc, char *argv[])
{
	
	readXml();
	int TotalIcons= ReadTotalIcons();

	struct Icon icons[10];
	for(int i= 0; i< TotalIcons; i++){
		icons[i]= ReadIcon(i);
	}

	// Make a window and an off-screen backdrop.
	screen = tigrWindow(320, 200, "GUI", 0);
	backdrop = tigrBitmap(screen->w, screen->h);

	// Fill in the background.
	tigrClear(backdrop, tigrRGB(255,255,255));
	
    // Repeat till they close the window.
	while (!tigrClosed(screen) && !tigrKeyDown(screen, TK_ESCAPE))
	{
		
	
		// Composite the GUI
		tigrBlit(screen, backdrop, 0,0,0,0, backdrop->w, backdrop->h);

		for(int i= 0; i< TotalIcons; i++){
			printIcon(screen, icons[i].Image, icons[i].Text, icons[i].x, icons[i].y);
		}


		// Update the window.
		tigrUpdate(screen);
	}

	//tigrFree(icono);
	tigrFree(backdrop);
	tigrFree(screen);
	return 0;
}
