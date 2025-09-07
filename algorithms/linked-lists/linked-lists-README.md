## Linked List Concepts

#### 🔹 What is a Linked List?

A **linked list** is a linear data structure where elements (called **nodes**) are stored in separate memory locations and connected through **pointers**.  
Each **node** contains:

- **Data** (in this case, an integer `val`)
- **A pointer** to the next node in the sequence (`next`)

Unlike arrays, linked lists are **dynamic**:

- Memory is allocated as needed.
- Size does not need to be known in advance.
- Insertions and deletions are generally more efficient, but accessing elements requires traversal.

---

#### 🔹 Structure Definition

```c
typedef struct ListNode Node;

struct ListNode {
  int val;       // Value stored in the node
  Node* next;    // Pointer to the next node
};
```

- `typedef` allows us to use `Node` instead of `struct ListNode`.
- Each node stores an integer and a pointer to the **next node**.

---

#### 🔹 Functions Implemented

##### 1. **Create the Head Node**

```c
Node* create_list(int val);
```

- Allocates memory for a new node.
- Stores the given value.
- Sets `next` to `NULL` (no further nodes yet).
- Returns the created node.

---

##### 2. **Insert a Node at the Beginning**

```c
Node* insert_list(Node* head, int val);
```

- Creates a new node with the given value.
- Makes this new node point to the current head.
- Returns the new node as the updated head of the list.  
  This implementation always inserts **at the front**.

---

##### 3. **Delete a Node**

```c
void delete_node(Node* node, int val);
```

- Searches for the node with the given value.
- Instead of removing it directly (which would break links), it **copies the value of the next node** into the current one, and frees the next node.
- Special case: it cannot remove the last node, since it relies on accessing the `next` node.

---

##### 4. **Print the List**

```c
void print_list(Node* head);
```

- Recursively traverses the list.
- Prints each node’s value.

---

##### 5. **Free the List**

```c
void free_list(Node* head);
```

- Uses recursion to free all nodes in memory.
- Prevents **memory leaks** by ensuring every allocated node is released.

---

#### 🔹 Main Function Workflow

```c
int main() {
  Node* head = create_list(50);      // Create first node
  head = insert_list(head, 40);      // Insert new head (40)
  head = insert_list(head, 30);      // Insert new head (30)
  head = insert_list(head, 20);      // Insert new head (20)
  head = insert_list(head, 10);      // Insert new head (10)
  delete_node(head, 10);             // Attempt to delete node with value 10
  print_list(head);                  // Print all nodes
  free_list(head);                   // Free allocated memory
  return 0;
}
```

**Execution steps**:

1. Creates a list starting with `50`.
2. Inserts nodes at the head → final order: **10 → 20 → 30 → 40 → 50**
3. Deletes node with value `10`.
4. Prints the resulting list.
5. Frees all nodes from memory.

---

#### 🔹 Key Linked List Concepts

- **Head**: The first node in the list, used as the entry point.
- **Dynamic Memory Allocation**: Nodes are created with `malloc` and must be freed manually.
- **Traversal**: To access or print elements, you must follow `next` pointers.
- **Insertion/Deletion**:
  - Insertion at head is fast (`O(1)`).
  - Deletion is efficient if you have a pointer to the node (but trickier if you need to find it first).
- **Recursive Operations**: Both printing and freeing the list are implemented recursively here.

---

**In summary**:  
This code builds a **singly linked list** where each insertion happens at the head. It allows deletion (with restrictions), printing, and safe memory cleanup.
