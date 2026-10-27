#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linkedlist.h"

void push(node_t **head, double info) {
    push_front(head, info);
}

double pop(node_t **head) {
    return pop_front(head);
}

void push_front(node_t **head, double val) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }
    new_node->info = val;
    new_node->next = *head;
    *head = new_node;
}

void push_back(node_t **head, double val) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }
    new_node->info = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node_t *curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}

double pop_front(node_t **head) {
    if (*head == NULL) {
        return NAN;
    }
    node_t *temp = *head;
    double val = temp->info;
    *head = temp->next;
    free(temp);
    return val;
}

double pop_back(node_t **head) {
    if (*head == NULL) {
        return NAN;
    }
    if ((*head)->next == NULL) {
        double val = (*head)->info;
        free(*head);
        *head = NULL;
        return val;
    }

    node_t *curr = *head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }

    double val = curr->next->info;
    free(curr->next);
    curr->next = NULL;
    return val;
}

void add_at(node_t **head, double val, size_t index) {
    if (index == 0) {
        push_front(head, val);
        return;
    }

    node_t *curr = *head;
    for (size_t i = 0; curr != NULL && i < index - 1; i++) {
        curr = curr->next;
    }

    if (curr == NULL) {
        return;
    }

    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }
    new_node->info = val;
    new_node->next = curr->next;
    curr->next = new_node;
}

int find(node_t *head, double val) {
    node_t *curr = head;
    int index = 0;

    while (curr != NULL) {
        if (curr->info == val) {
            return index;
        }
        curr = curr->next;
        index++;
    }

    return -1;
}

void delete_at(node_t **head, size_t index) {
    if (*head == NULL) {
        return;
    }

    if (index == 0) {
        node_t *temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }

    node_t *curr = *head;
    for (size_t i = 0; curr != NULL && i < index - 1; i++) {
        curr = curr->next;
    }

    if (curr == NULL || curr->next == NULL) {
        return;
    }

    node_t *temp = curr->next;
    curr->next = temp->next;
    free(temp);
}

double *export(node_t *head, size_t *out_size) {
    if (head == NULL) {
        *out_size = 0;
        return NULL;
    }

    size_t count = 0;
    node_t *curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    *out_size = count;
    double *arr = malloc(count * sizeof(double));
    if (arr == NULL) {
        return NULL;
    }

    curr = head;
    for (size_t i = 0; i < count; i++) {
        arr[i] = curr->info;
        curr = curr->next;
    }

    return arr;
}

void clear(node_t **head) {
    if (head == NULL || *head == NULL) {
        return;
    }

    node_t *curr = *head;
    while (curr != NULL) {
        node_t *next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}
