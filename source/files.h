#pragma once

#include <nds.h>
#include <stdbool.h>

struct node {
    u8 id;
    char *name;
    struct node *next;
};

typedef struct node Node;

Node* load_filesystem(Node* head);

Node* create_node(u8 id, char *name);
bool get_node(u8 id, Node* head);
void free_node(Node* node);
void add_node(Node** head, Node* node);
void output_list(Node* node);