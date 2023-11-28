#pragma once

#include <nds.h>
#include <stdbool.h>

struct curs {
    u8 position;
    bool select;
};

typedef struct curs Cursor;
void set_pos(Cursor *c);
void undo_pos(Cursor *c);