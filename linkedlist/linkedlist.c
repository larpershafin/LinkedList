#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void push(node_t **head, double info) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
        exit(0);
    }
    new_node->info = info;
    new_node->next = *head;
    *head = new_node;
}

double pop(node_t **head) {
    if (*head == NULL) {
        printf("Liste ist leer");
    }
    node_t *temp = *head;
    double val = temp->info;
    *head = temp->next;
    free(temp);
    return val;
}

void add_at(node_t **head, double val, size_t index) {
    if (index == 0) {
        node_t *new_node = malloc(sizeof(node_t));
        if (new_node == NULL) {
            return;
            exit(0);
        }
        new_node->info = val;
        new_node->next = *head;
        *head = new_node;
        return;
    }
    node_t *current = *head;
    for (size_t i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Index %zu ist ausserhalb der Liste\n", index);
        return;
    }
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }

    new_node->info = val;
    new_node->next = current->next;
    current->next = new_node;
}

void push_front(node_t **head, double val) {     //Einfügen am Anfang: Ein neues Element an die erste Position setzen.
    node_t *new_node = malloc(sizeof(node_t));
    if (!new_node) {
        return;
        exit(0);
    }
    new_node->info = val;
    new_node->next = *head;
    *head = new_node;
}

void push_back(node_t **head, double val) {  //Einfügen am Ende: Ein neues Element ganz hinten anhängen.
    node_t *new_node = malloc(sizeof(node_t));
    if (!new_node) {
        return;
        exit(0);
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

double pop_front(node_t **head) {  //Entfernen am Anfang: Das erste Element löschen und seinen Wert zurückgeben.
    if (*head == NULL) {
        printf("Liste ist leer");
    }
    node_t *temp = *head;
    double val = temp->info;
    *head = temp->next;
    free(temp);
    return val;
}

double pop_back(node_t **head) {  //Entfernen am Ende: Das letzte Element löschen und seinen Wert zurückgeben.
    if (*head == NULL) {
        return 0.0;
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

int find(node_t *head, double val) {  //Suchen: Finden eines Wertes in der Liste (Gibt Position oder Pointer zurück).
    node_t *curr = head;
    size_t index = 0;

    while (curr != NULL) {
        if (curr->info == val) {
            return index;
        }
        curr = curr->next;
        index++;
    }

    return -1; //Wert wurde nd gefunden
}

void delete_at(node_t **head, size_t index) { //Löschen an Stelle X: Ein Element an einem spezifischen Index entfernen.
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
    if (curr == NULL) {
        printf("Index %zu ist leer", index);
    }
    curr = curr->next;
    free(curr);
}

double* export(node_t *head, size_t *out_size) { //Listen-Export: Eine Funktion, die den gesamten Inhalt der Liste (z. B. als Array) zurückgibt, damit das Hauptprogramm die Werte unabhängig formatieren und ausgeben kann.
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
    //Leeren: Die gesamte Liste löschen und den Speicher freigeben.
    if (head == NULL || *head == NULL) {
        return;
    }
    node_t *curr = *head;
    while (curr != NULL) {
        node_t *next = curr->next;
        free(curr);
        curr = next;
    }
    *head=NULL;
}
