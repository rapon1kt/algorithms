## Queue Implementation in C

#### Example codes:

- **[C Example](https://github.com/rapon1kt/algorithms/blob/master/algorithms/queue/c-example/queue.c)**
- **[Typescript Example](https://github.com/rapon1kt/algorithms/blob/master/algorithms/queue/typescript-example/script.ts)**

#### 🔹 What is a Queue?

A **queue** is a linear data structure that follows the **FIFO principle** (**First In, First Out**):

- The **first element inserted** is the **first one removed**.
- Think of it like a line at a bank or supermarket: the first person in line is served first.

---

#### 🔹 Header File (`queue.h`)

```c
typedef struct queuee * queue;

/* Structure that will be stored in the queue  */
typedef struct pooint {
  int x;
  int y;
} point;
```

- `queue` is defined as a pointer to the structure `queuee`.
- Each element in the queue is a `point` with two integer coordinates (`x`, `y`).

Functions declared in the header:

- `queue create_queue();`
- `void insert_queue(queue q, point p);`
- `point remove_queue(queue q);`
- `int queue_is_empty(queue q);`
- `void free_queue(queue q);`

---

#### 🔹 Implementation File (`queue.c`)

##### 1. **Internal Structure**

```c
struct queuee {
  int start;      // Index of the first element
  int final;      // Index where the next element will be inserted
  point* values;  // Dynamic array storing the elements
};
```

- The queue is implemented using a **circular array** with a maximum capacity (`MAX_CAP`).
- `start` points to the first element (front).
- `final` points to the position where the next element will be added (rear).

---

##### 2. **Create Queue**

```c
queue create_queue() {
  queue q = (queue) malloc(sizeof(struct queuee));
  q->values = (point*) malloc(sizeof(point) * MAX_CAP);
  q->start = 0;
  q->final = 0;
  return q;
}
```

- Allocates memory for the queue.
- Initializes the array with maximum capacity.
- Sets both `start` and `final` to `0`.

---

##### 3. **Insert Element (Enqueue)**

```c
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
}
```

- Checks if the queue is **full** (`(final + 1) % MAX_CAP == start`).
- If not full, stores the new element at position `final`.
- Updates `final`, wrapping around to `0` if it reaches `MAX_CAP`.

---

##### 4. **Remove Element (Dequeue)**

```c
point remove_queue(queue q) {
  point p;
  p.x = -1; p.y = -1;  // Default error value
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
```

- Checks if the queue is **empty** (`final == start`).
- If not empty, retrieves the element at `start`.
- Updates `start`, wrapping around if necessary.
- Returns the removed element.

---

##### 5. **Check if Queue is Empty**

```c
int queue_is_empty(queue q){
  if(q->start == q->final){
    return 1;
  }
  return 0;
}
```

- Returns `1` (true) if empty, `0` (false) otherwise.

---

##### 6. **Free Memory**

```c
void free_queue(queue q) {
  free(q->values);
  free(q);
}
```

- Frees the dynamically allocated array and the queue structure itself.
- Prevents **memory leaks**.

---

#### 🔹 Key Concepts of Queues

- **FIFO**: First In, First Out order.
- **Enqueue**: Insert element at the rear.
- **Dequeue**: Remove element from the front.
- **Circular Array**: This implementation uses modulo arithmetic to reuse array space efficiently.
- **Overflow & Underflow**:
  - **Overflow** → Trying to insert into a full queue.
  - **Underflow** → Trying to remove from an empty queue.
- **Memory Management**: Since C uses manual memory allocation, `malloc` and `free` are used.

---

**In summary**:  
This implementation creates a **circular queue** using a dynamic array, supports insertion and removal of `point` elements, checks for empty/full conditions, and properly frees memory when done.
