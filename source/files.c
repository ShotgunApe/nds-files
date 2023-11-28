#include "files.h"

#include <nds.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

Node* load_filesystem(Node* head) {
    DIR *pdir;
	struct dirent *pent;
    u16 y = 0;

    pdir=opendir("/");

    if (pdir) {
		while ((pent = readdir(pdir)) != NULL) {
	    	if(strcmp(".", pent->d_name) == 0 || strcmp("..", pent->d_name) == 0)
	        	continue;

	    	if(pent->d_type == DT_DIR) {
                //iprintf("[\x1b[%d;%dH%s]\n", y, 2, pent->d_name);
                //y++;
            }
	    	else {
	        	//iprintf("\x1b[%d;%dH%s\n", y, 2, pent->d_name);
                //copy name from here so that it saves when applying to create_node
                char *tmp = malloc(sizeof(pent->d_name));
                strcpy(tmp, pent->d_name);
                Node *new = create_node(y, tmp);
                add_node(&head, new);
                y++;
            }
		}
		closedir(pdir);
	}
    else {
        iprintf ("opendir() failure; terminating\n");
    }

    return head;
}

Node* create_node(u8 id, char *name) {
    Node* node = malloc(sizeof(Node));
    node->id = id;
    node->name = name;
    node->next = NULL;
    return node;
}

void free_node(Node* node) {
    if(node){
        if(node->name){
            free(node->name);
        }
        free(node);
    }
}

void add_node(Node** head, Node* node) {
    Node *tmp = *head;
    if(*head == NULL) { //no node (empty)
        *head = node;
    }
    else {
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = node;
    }
}

void output_list(Node* node) {
    while(node){
        iprintf("\x1b[%d;%dH%s", node->id, 2, node->name);
        node = node->next;
    }
}