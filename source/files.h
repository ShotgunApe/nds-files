#pragma once

#include <nds.h>

struct node {
    u8 id;
    char *name;
    struct node *next;
};

typedef struct node Node;

Node* load_filesystem(Node* head);

Node* create_node(u8 id, char *name);
void free_node(Node* node);
void add_node(Node** head, Node* node);
void output_list(Node* node);