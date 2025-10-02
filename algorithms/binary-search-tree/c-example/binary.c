#include <stdio.h>
#include <stdlib.h>

/* Struct of Binary Tree node*/
struct Node {
  int val;
  struct Node * left;
  struct Node * right;
};

typedef struct Node* node;

/* Principal functions*/
node create_node(int val);
node insert_node(node head, int val);
node search(node head, int val);

/* Simple Example*/
int main(int argc, char * argv[]) {
  node n = create_node(50);
  insert_node(n, 30);
  insert_node(n, 70);
  insert_node(n, 80);
  for (int i = 1; i <= 10; i++) {
    printf("%i: ", i*10);
    printf(search(n, i*10) != NULL ? "Founded\n" : "Not Found\n");
  }
  return 0;
}

node create_node(int val) {
  node temp = (node) (malloc(sizeof(struct Node)));
  temp->left = NULL;
  temp->right = NULL;
  temp->val = val;
  return temp;
}

node insert_node(node head, int val) {
  if (head == NULL) {
    return create_node(val);
  }
  if (val > head->val) {
    head->right = insert_node(head->right, val);
  } else {
    head->left = insert_node(head->left, val);
  }
  return head;
}

node search(node head, int val) {
  if (head == NULL || head->val == val) return head;
  if (val > head->val) {
    return search(head->right, val);
  }
  return search(head->left, val);
}
