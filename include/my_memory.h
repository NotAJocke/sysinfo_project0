#ifndef MY_MEMORY_H
#define MY_MEMORY_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

uint8_t MY_HEAP[64000];

void init();

/*
 * Renvoie un pointeur vers une zone de mémoire d'une taille minimum de
 * size octets issue de ce tableau. La zone mémoire commençant à l’adresse à
 * laquelle renvoie le pointeur doit rester utilisable dans son entièreté
 * pendant toute la durée de l’utilisation de celui-ci, càd jusqu’à sa
 * libération avec la fonction free.
 */
void *my_malloc(size_t size);

/**
 * Libère une zone mémoire précédemment réservée indiquée par le pointeur ptr.
 */
void my_free(void *ptr);

bool is_block_free(void *ptr);

void print_state(int max);

#endif // !MY_MEMORY_H
