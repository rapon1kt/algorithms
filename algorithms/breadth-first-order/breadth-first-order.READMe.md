## Breadth-First Search (BFS) Overview

#### Introduction

Breadth-First Search (BFS) is a fundamental graph traversal algorithm. It explores nodes level by level, ensuring that all nodes at a given depth are visited before moving to the next. This makes it especially useful for finding the shortest path in **unweighted graphs**.

#### Core Principles

- **Level-based traversal**: Expands outward from the start node, layer by layer.
- **Queue-based implementation**: Uses a FIFO queue to manage exploration order.
- **Visited set**: Prevents revisiting nodes and ensures termination.

#### Algorithm Steps

1. Initialize an empty queue and visited set.
2. Add the start node to both.
3. While the queue is not empty:
   - Dequeue the front node and process it.
   - For each unvisited neighbor, mark it visited and enqueue it.

##### Pseudocode

```pseudo
procedure BFS(G, start_node):
  let Q be a queue
  let visited be a set

  Q.enqueue(start_node)
  visited.add(start_node)

  while Q is not empty:
    current = Q.dequeue()
    process(current)
    for each neighbor of current:
      if neighbor not in visited:
        visited.add(neighbor)
        Q.enqueue(neighbor)
```

If you want to see an application in a resolution algorithm, here is a list of some that use this type of search:

- **[Solving a Maze](https://github.com/rapon1kt/algorithms/blob/master/algorithms/maze-algorithm)**

#### Performance

- **Time Complexity**: `O(V + E)` (vertices + edges)
- **Space Complexity**: `O(V)` (for queue and visited set)

#### Properties

- **Completeness**: Always finds a solution if one exists.
- **Optimality**: Finds the shortest path in unweighted graphs.

#### BFS vs DFS

| Feature          | BFS (Breadth-First Search) | DFS (Depth-First Search)         |
| ---------------- | -------------------------- | -------------------------------- |
| Strategy         | Level-by-level             | Deep along one branch            |
| Data Structure   | Queue (FIFO)               | Stack (LIFO) / Recursion         |
| Completeness     | Guaranteed                 | Not guaranteed (infinite graphs) |
| Optimality       | Shortest path (unweighted) | Not guaranteed                   |
| Space Complexity | O(V), can be high          | O(V) worst case, O(d) avg        |

#### Applications

- Pathfinding in mazes and navigation systems
- Web crawlers and indexing
- Social network analysis (degrees of separation, friend suggestions)
- Network broadcasting and peer-to-peer systems
- Puzzle solving (e.g., Rubik’s Cube, 15-puzzle)
- Checking bipartite graphs and connected components

#### Limitations

- High memory usage for wide graphs
- May become impractical for large-scale problems

#### Variations

- **Bidirectional BFS**: Runs BFS from both start and target nodes, meeting in the middle. This reduces complexity from `O(b^d)` to `O(b^(d/2))`, making it far more efficient.

#### Conclusion

BFS remains a cornerstone algorithm in computer science. Its simplicity, reliability, and guaranteed optimality for shortest paths make it indispensable across domains from networking to AI. Despite memory limitations, optimized versions like **Bidirectional BFS** extend its usefulness for large-scale applications.
