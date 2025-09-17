#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void print_maze(char ** maze, int width, int height);
void solve_maze(char ** maze, int width, int height);

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main(int argc, char * argv[]) {
  int width, height;
  char ** maze;
  scanf("%d %d\n", &width, &height);
  maze = (char**) malloc(sizeof(char*) * width);
  for (int x = 0; x < width; x++) {
    maze[x] = (char*) malloc(sizeof(char)*height);
  }

  for(int y = 0; y < height; y++){
    for(int x = 0; x < width; x++){
      scanf("%c", &maze[x][y]);
    }
    getchar();
  }

  print_maze(maze, width, height);
  solve_maze(maze, width, height);
  print_maze(maze, width, height);
  for(int x = 0; x < width; x++){
    free(maze[x]);
  }
  free(maze);
  return 0;
}

void print_maze(char ** maze, int width, int height) {
  printf("\n");
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", maze[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}

void solve_maze(char ** maze, int width, int height) {
  queue q = create_queue();
  point start;
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      if (maze[i][j] == 'S') {
        start.x = i;
        start.y = j;
        break;
      }
    }
  }
  insert_queue(q, start);
  while (!queue_is_empty(q)) {
    point current = remove_queue(q);
    for (int i =0; i < 4; i++) {
      point next;
      next.x = current.x + dx[i];
      next.y = current.y + dy[i];
      if ((next.x >= 0 && next.x < width) && (next.y >= 0 && next.y < height)) {
        char letter = maze[next.x][next.y];

        if (letter == 'E') {
          free_queue(q);
          return;
        }
        if (letter == '0') {
          if (i == 0)
            maze[next.x][next.y] = '^';
          else if (i == 1)
            maze[next.x][next.y] = 'v';
          else if (i == 2)
            maze[next.x][next.y] = '<';
          else {
            maze[next.x][next.y] = '>';
          }
          insert_queue(q, next);
        }
      }
    }
  }
  free_queue(q);
}