#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode Node;

/* Basic struct of a Linked List*/
struct ListNode {
  int val;
  Node* next;
};

/* Principal functions */
void print_list(Node* head);
Node* create_list(int val);
Node* insert_list(Node* head, int val);
void delete_node(Node* node, int val);
void free_list(Node* head);

int main() {
  Node* head = create_list(50);
  head = insert_list(head, 40);
  head = insert_list(head, 30);
  head = insert_list(head, 20);
  head = insert_list(head, 10);
  delete_node(head, 10);
  print_list(head);
  free_list(head);
  return 0;
}

/* Print all values of the list */
void print_list(Node* head) {
  if (head == NULL) return;
  printf("  %d  ", head->val);
  print_list(head->next);
}

/* Create the head of List */
Node* create_list(int val) {
  Node* node = (Node*) (malloc(sizeof(Node)));
  node->val=val;
  node->next= NULL;
  return node;
}

/* Insert one Node, but this node is the new head */
Node* insert_list(Node* head, int val) {
  Node* node = create_list(val);
  node->next = head;
  return node;
}

/* Remove any node from the list */
void delete_node(Node* node, int val) {
  if (node == NULL || node->next == NULL) {
    return;
  }

  if (node->val == val) {
    struct ListNode* aux = node->next;
    node->val = aux->val;   
    node->next = aux->next;    
    free(aux);
  }
}

/* This function frees up memory stacked */
void free_list(Node* head) {
  if (head == NULL) return;
  free_list(head->next);
  free(head);
}