
#include "tigr/tigr.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


Tigr *backdrop, *screen;


int main(int argc, char *argv[])
{
	// Load our sprite.
	Tigr *icono = tigrLoadImage("./icons/trash.png");
	if (!icono)
		tigrError(0, "Cannot load icono");
	
	
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
		//dibuja el icono
		tigrBlitAlpha(screen, icono, 64, 64, 0, 0, icono->w, icono->h, 1.0f);
		//dibuja el texto
		tigrPrint(screen, tfont, 120, 110, tigrRGB(0x00, 0x00, 0x00), "Hello, world.");


		// Update the window.
		tigrUpdate(screen);
	}

	tigrFree(icono);
	tigrFree(backdrop);
	tigrFree(screen);
	return 0;
}
