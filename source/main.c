#include <nds.h>
#include <fat.h>

#include "files.h"

#include <stdio.h>
#include <malloc.h>

int main() {

    //Sets the console to use sub display, VRAM_C, and BG0 and enables MODE_0_2D on the sub display. Init fat filesystem.
    consoleDemoInit();

    if(fatInitDefault()) {
        load_filesystem();
    }
    else {
        iprintf("fatInitDefault failure: terminating\n");
    }
    
    iprintf("\x1b[%d;%dH*\n", 0, 0);

    while(1) {
        swiWaitForVBlank();
		scanKeys();
		if(keysDown()&KEY_START) break;

        

    }

    return 0;
}