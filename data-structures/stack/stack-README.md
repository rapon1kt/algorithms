## Stack Data Structure and Implementation in C

#### Code Examples

- **[C example](https://github.com/rapon1kt/algorithms/blob/master/algorithms/stack/c-example/stack.c)**
- **[Typescript example](https://github.com/rapon1kt/algorithms/blob/master/algorithms/stack/typescript-example/script.ts)**

#### What is a Stack?

A **stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle:

- The **last element inserted** is the **first one removed**.
- Real-world analogy: a stack of plates — you add plates on top and remove from the top.

##### Main Operations

1. **Push** → insert an element at the top.
2. **Pop** → remove the element at the top.
3. **Peek/Top** → check the element at the top without removing it.
4. **IsEmpty** → verify if the stack is empty.

---

#### Code Explanation

##### 1. Data Structures

```c
typedef struct elem {
  char c;
  struct elem* prox;
} elem;

struct staack {
  elem* top;
};
```

- Each **`elem`** stores a character (`char c`) and a pointer to the **next element** (`prox`).
- The `staack` structure contains only a pointer to the **top of the stack**.

This design makes the stack a **[linked list](https://github.com/rapon1kt/algorithms/blob/master/data-structures/linked-lists/linked-lists-README.md)** where insertions and removals happen only at the head.

---

##### 2. Create a Stack

```c
stack create_stack() {
  stack s = (stack) malloc(sizeof(struct staack));
  s->top = NULL;
  return s;
}
```

- Allocates memory for the stack.
- Initializes the `top` pointer as `NULL` (empty stack).

---

##### 3. Push Operation (Insert Element)

```c
void stack_element(stack s, char c) {
  elem * e = (elem*) malloc(sizeof(elem));
  e->prox = s->top;
  s->top = e;
  e->c = c;
}
```

- Allocates a new node.
- Sets its `prox` pointer to the current top.
- Updates `s->top` to the new node.
- Stores the character `c` in the element.

---

##### 4. Pop Operation (Remove Element)

```c
char unstack_element(stack s) {
  elem* aux = s->top;
  s->top = aux->prox;
  char caux = aux->c;
  free(aux);
  return caux;
}
```

- Stores the current top in `aux`.
- Moves the `top` pointer to the next element.
- Saves the character of the removed node.
- Frees the memory of the removed node.
- Returns the stored character.

---

##### 5. Freeing Memory

```c
void free_elements(elem* e) {
  if (e == NULL) return;
  free(e->prox);
  free(e);
}

void free_stack(stack s) {
  free_elements(s->top);
  free(s);
}
```

- Recursively frees all nodes.
- Finally frees the stack itself.

---

##### 6. Checking if the Stack is Empty

```c
int is_empty_stack(stack s) {
  if (s == NULL || s->top == NULL) return 1;
  return 0;
}
```

- Returns `1` (true) if the stack has no elements.
- Returns `0` (false) otherwise.

---

#### Complexity Analysis

- **Push (insert)**: `O(1)`
- **Pop (remove)**: `O(1)`
- **IsEmpty**: `O(1)`
- **Free stack**: `O(n)`, where `n` is the number of elements.

---

#### Why Use a Stack?

- Efficient insertion and removal (constant time).
- Useful in many problems, such as:
  - Expression evaluation (infix → postfix).
  - Function call management (call stack).
  - Undo/Redo operations in editors.
  - Depth-First Search (DFS) in graphs.

---

**Summary**:  
This implementation uses a **linked list** to represent a **stack**. Each new element is pushed on top, and removal always happens from the top. It ensures constant-time operations and dynamic memory allocation, making it efficient and flexible for different use cases.
