typedef struct queuee * queue;

/* Structure that will be stored in the queue  */
typedef struct pooint {
  int x;
  int y;
} point;

/* Initialize queue */
queue create_queue();

/* Add a point at the end of the queue  */
void insert_queue(queue q, point p);

/* Get the oldest point in the queue */
point remove_queue(queue q);

/* Verifies if final == start */
int queue_is_empty(queue q);

/* Clean memory */
void free_queue(queue q);