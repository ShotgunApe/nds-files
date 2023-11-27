#include "files.h"

#include <nds.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void load_filesystem() {
    DIR *pdir;
	struct dirent *pent;
    u16 y = 0;

    pdir=opendir("/");

    if (pdir) {
		while ((pent = readdir(pdir)) != NULL) {
	    	if(strcmp(".", pent->d_name) == 0 || strcmp("..", pent->d_name) == 0)
	        	continue;

	    	if(pent->d_type == DT_DIR) {
                iprintf("[\x1b[%d;%dH%s]\n", y, 2, pent->d_name);
                y++;
            }
	    	else {
	        	iprintf("\x1b[%d;%dH%s\n", y, 2, pent->d_name);
                y++;
            }
		}
		closedir(pdir);
	}
    else {
        iprintf ("opendir() failure; terminating\n");
    }
}