#include <nds.h>
#include <fat.h>

#include "files.h"
#include "input.h"

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

int main() {

    //Sets the console to use sub display, VRAM_C, and BG0 and enables MODE_0_2D on the sub display. Init fat filesystem.
    consoleDemoInit();
    

    //cursor
    iprintf("\x1b[%d;%dH*\n", 0, 0);
    Cursor cursor;
    cursor.position = 0;
    cursor.select = false;
    Cursor *cptr;

    cptr = &cursor;

    //filesystem
    if(fatInitDefault()) {
        load_filesystem();
    }
    else {
        iprintf("fatInitDefault failure: terminating\n");
    }

    while(1) {
        swiWaitForVBlank();
		scanKeys();

        if (keysDown()) {
            set_pos(cptr);
        }

    }

    return 0;
}