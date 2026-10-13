#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdio.h>

#include <math.h>
#include <stdlib.h>
// hier fehlt noch die strict mit head und tail pointer und der anzahl an elementen

typedef struct node {
    double info; // DATA ..
    struct node *next;
    struct node *prev;
} node_t;


void push(node_t **head, double info);
double pop(node_t **head);
void add_at(node_t **head, double val, size_t index);
void push_front(node_t **head, double val);
void push_back(node_t **head, double val);
double pop_front(node_t **head);
double pop_back(node_t **head);
int find(node_t *head, double val);
void delete_at(node_t **head, size_t index);
double *export(node_t *head, size_t *out_size);
void clear(node_t **head);

#endif