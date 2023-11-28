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
    fatInitDefault();
    Node *head = NULL;
    head = load_filesystem(head);
    output_list(head);

    while(1) {
        swiWaitForVBlank();
		scanKeys();

        if (keysDown()) {
            set_pos(cptr);
            output_list(head);
        }

    }

    return 0;
}