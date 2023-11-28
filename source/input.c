#include "input.h"
#include "files.h"

#include <nds.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void set_pos(Cursor *c) {

    if ((keysDown() & KEY_UP)) {
        c->position = c->position - 1;
        //iprintf("%i", c->position);
    }

    if (keysDown() & KEY_DOWN) {
        c->position = c->position + 1;
        //iprintf("%i", c->position);
    }

    iprintf("\x1b[2J");
    iprintf("\x1b[%d;%dH*\n", c->position, 0);

}

void undo_pos(Cursor *c) {

    if ((keysCurrent() & KEY_DOWN)) {
        c->position = c->position - 1;
        //iprintf("%i", c->position);
    }

    if (keysCurrent() & KEY_UP) {
        c->position = c->position + 1;
        //iprintf("%i", c->position);
    }

    iprintf("\x1b[2J");
    iprintf("\x1b[%d;%dH*\n", c->position, 0);
}