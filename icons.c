#include "tigr/tigr.h"
#include "icons.h"

int printIcon(Tigr *screen, char image[], char text[], int x, int y){
    Tigr *icono = tigrLoadImage(image);
	if (!icono)
		tigrError(0, "Cannot load icono");


	tigrBlitAlpha(screen, icono, 32*x, 40*y, 0, 0, icono->w, icono->h, 1.0f);
		
	tigrPrint(screen, tfont, 32*x, 40*y +32, tigrRGB(0x00, 0x00, 0x00), text);
}