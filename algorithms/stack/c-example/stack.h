typedef struct staack * stack;

stack create_stack();

void stack_element(stack s, char c);

char unstack_element(stack s);

void free_stack(stack s);

int is_empty_stack(stack s);