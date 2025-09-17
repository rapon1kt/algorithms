#include <stdio.h>
#include <stdlib.h>

/* Check the other file in this folder */
#include "queue.h"

/* Setting max capacity of pointers */
#define MAX_CAP 100

/* Defining data-structure */
struct queuee {
  int start;
  int final;
  point* values;
};

/* Mememory allocation of queue and set begin and end*/
queue create_queue() {
  queue q = (queue) malloc(sizeof(struct queuee));
  q->values = (point*) malloc(sizeof(point) * MAX_CAP);
  q->start = 0;
  q->final = 0;
  return q;
}

/* Verifies if queue is full and insert on final if is not */
void insert_queue(queue q, point p) {
  if ((q->final + 1) % MAX_CAP == q->start) {
    printf ("ERRO: queue is full");
    return;
  }
  q->values[q->final] = p;
  q->final++;
  if (q->final == MAX_CAP) {
    q->final = 0;
  }
  return;
}

/* Takes the first point that was placed in the queue */
point remove_queue(queue q) {
  point p;
  p.x = -1; p.y = -1;
  if (q->final == q->start) {
    printf("ERRO: queue is empty");
    return p;
  }
  p = q->values[q->start];
  q->start++;
  if (q->start == MAX_CAP) {
    q->start = 0;
  }
  return p;
}

/* Verifing if queue don't have points */
int queue_is_empty(queue q){
  if(q->start == q->final){
    return 1;
  }
  return 0;
}

/* Free memory that are allocated */
void free_queue(queue q) {
  free(q->values);
  free(q);
  return;
}
