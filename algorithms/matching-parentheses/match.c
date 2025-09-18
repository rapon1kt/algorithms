#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char * argv[]) {
  char string[100];
  scanf("%s", string);
  stack s = create_stack();
  for (int i = 0; i < 100 && string[i] != '\0'; i++) {  
    char c = string[i];
    if (c == '{' || c == '[' || c == '(') {
      stack_element(s, c);
    } else {
      if (is_empty_stack(s)) {
        printf("Erro: did not opened!");
        free_stack(s);
        return -1;
      }
      char top = unstack_element(s);
      if (c == ')' && top != '(') {
        printf("Erro: closed ) but did not open!\n");
        free_stack(s);
        return -1;
      } else if (c == ']' && top != '[') {
        printf("Erro: closed ] but did not open!\n");
        free_stack(s);
        return -1;
      } else if (c == '}' && top != '{') {
        printf("Erro: closed } but did not open!\n");
        free_stack(s);
        return -1;
      }
    }
  }
  free_stack(s);
  printf("All parentheses, brackets and braces have been closed correctly!\n");
  return 0;
}