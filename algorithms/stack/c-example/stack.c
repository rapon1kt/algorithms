#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
 *  This struct can store whatever you want,
 *  I used only a char and a pointer to the next
 *  because this code is reused to solve an exercise
 *  which can be found in the algorithms folder.
 *  Exercise:
 *  -> Match Operators
*/
typedef struct elem {
  char c;
  struct elem* prox;
} elem;

struct staack {
  elem* top;
};

/* Alloc memory to create a new stack */
stack create_stack() {
  stack s = (stack) malloc(sizeof(struct staack));
  s->top = NULL;
  return s;
}

/* Push element to the top */
void stack_element(stack s, char c) {
  elem * e = (elem*) malloc(sizeof(elem));
  e->prox = s->top;
  s->top = e;
  e->c = c;
  return;
}

/* Check and remove the last elemnt that are pushed */
char unstack_element(stack s) {
  elem* aux = s->top;
  s->top=aux->prox;
  char caux = aux->c;
  free(aux);
  return caux;
}

/* Use recursion to release every element in heap */
void free_elements(elem* e) {
  if (e == NULL) return;
  free(e->prox);
  free(e);
}

/* After releasing the elements, the stack is released */
void free_stack(stack s) {
  free_elements(s->top);
  free(s);
  return;
}

/* Verifies if the stack contains a top */
int is_empty_stack(stack s) {
  if (s == NULL || s->top == NULL) return 1;
  return 0;
}