#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

typedef struct node_t {
    double info;
    struct node_t *next;
} node_t;

typedef struct array {
    double array[INT_MAX];
} array_t;

void push(node_t **head, double info);

double pop(node_t **head);

void add_at(node_t **head, double val, size_t index);

void push_front(node_t **head, double val); //Einfügen am Anfang: Ein neues Element an die erste Position setzen.

void push_back(node_t **head, double val);  //Einfügen am Ende: Ein neues Element ganz hinten anhängen.

double pop_front(node_t **head);  //Entfernen am Anfang: Das erste Element löschen und seinen Wert zurückgeben.

double pop_back(node_t **head);  //Entfernen am Ende: Das letzte Element löschen und seinen Wert zurückgeben.

int find(node_t *head, double val);  //Suchen: Finden eines Wertes in der Liste (Gibt Position oder Pointer zurück).

void delete_at(node_t **head, size_t index); //Löschen an Stelle X: Ein Element an einem spezifischen Index entfernen.

double* export(node_t *head, size_t *out_size); //Listen-Export: Eine Funktion, die den gesamten Inhalt der Liste (z. B. als Array) zurückgibt, damit das Hauptprogramm die Werte unabhängig formatieren und ausgeben kann.

void clear(node_t **head);  //Leeren: Die gesamte Liste löschen und den Speicher freigeben.
#endif