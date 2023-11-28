#pragma once

#include <stdbool.h>

struct curs {
    int position;
    bool select;
};

typedef struct curs Cursor;
void set_pos(Cursor *c);