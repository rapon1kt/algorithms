## Maze Solving Algorithm (C)

#### 🔹 Goal

It receives as input a matrix representing the maze, with:

- `S` → ending point (**Saída**)
- `E` → start point (**Entrada**)
- `0` → free space (walkable path)
- other characters (like `X`) → walls or blocked cells

The algorithm finds a valid path from `S` to `E`, marking the route inside the maze.

---

#### 🔹 Data Structures Used

- **Matrix (`maze`)**: represents the maze.
- **Queue (`queue`)**: used to explore maze positions in **[breadth-first order](https://github.com/rapon1kt/algorithms/blob/master/algorithms/breadth-first-order/breath-first-order.README.md)** (BFS – _Breadth-First Search_).
- **Points (`point`)**: each position has coordinates `(x, y)`.

Movement directions are defined by two arrays:

```c
//      right, left, down, up
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
```

---

#### 🔹 How the Algorithm Works

##### 1. Locating the Start

The code scans the matrix to find the cell marked with `E`.  
That point is inserted into the queue to begin the search.

##### 2. [Breadth-First Search (BFS)](https://github.com/rapon1kt/algorithms/blob/master/algorithms/breadth-first-order)

While the queue is **not empty**:

1. Remove the current point `current` from the queue.
2. Generate up to 4 new points `next` (one for each possible direction).
3. If `next` is inside maze boundaries:
   - If the value is `E`, the maze is solved → **terminate**.
   - If the value is `0`, mark it with an arrow (`^`, `v`, `<`, `>`) showing the movement direction, and insert `next` into the queue.

##### 3. Printing the Result

After execution, the maze is printed again showing the path taken.

---

#### Example

##### Input

```
5 5
#####
#S00#
#X0X#
#00E#
#####
```

##### Output

```
#####
#S>>#
#XvX#
#<>E#
#####
```

---

#### 🔹 Algorithm Complexity

##### Time Complexity

- Each cell in the maze is **visited at most once**.
- For each cell, up to **4 neighbors** are checked.

Therefore, the complexity is: \(
O(W \times H)
\)

where `W` = maze width and `H` = maze height.

##### Space Complexity

- The matrix requires \(
  O(W \times H)
  \).
- The queue, in the worst case, can hold all positions: also \(
  O(W \times H)
  \).

---

##### Why is this Method Effective?

1. **BFS (Breadth-First Search)**:

   - Guarantees that the **first path found to `E` is the shortest path** (optimal).
   - Unlike DFS (Depth-First Search), which might get stuck exploring long paths before finding the exit.

2. **Marking the Maze**:

   - Using arrows replaces visited `0`s.
   - Prevents revisiting the same cell → **efficient search**.

3. **Scalability**:
   - Works for any maze size within memory limits.
   - Linear complexity relative to the number of cells.

---

**Summary:**  
The algorithm applies **Breadth-First Search (BFS)** to a maze, guaranteeing the shortest path from `S` to `E`. It is effective because it systematically explores all possibilities in layers, ensuring an optimal solution with linear complexity in maze size.
