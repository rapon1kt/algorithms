## Matching Parentheses Program

#### Overview

This program uses a **[stack data structure](https://github.com/rapon1kt/algorithms/blob/master/data-structures/stack/stack-README.md)** implemented in C to verify if all types of brackets --- parentheses `()`, square brackets `[]`, and curly braces `{}` --- in a given string are properly opened and closed in the correct order.

The stack implementation is custom-built (not from the standard library).

The stack code is also in this repository and can be founded [here](https://github.com/rapon1kt/algorithms/blob/master/algorithms/stack/c-example/stack.c).

---

#### Algorithm for Parentheses Matching

The `main` function reads a string from the user and uses the stack to validate proper matching of brackets.

##### Step-by-Step Process

1.  **Read Input**

    ```c
    char string[100];
    scanf("%s", string);
    ```

    - The program reads a string of up to 100 characters.

2.  **Iterate Through Characters**

    ```c
    for (int i = 0; i < 100 && string[i] != '\0'; i++) {
        char c = string[i];
    }
    ```

3.  **If Opening Bracket → Push**

    - If `c` is `{`, `[`, or `(`, it is pushed onto the stack.

4.  **If Closing Bracket → Pop and Check**

    - If a closing bracket is found: - If the stack is empty → **error** (nothing was opened). - Otherwise, pop the top element and check if it matches the
      type of closing bracket. - If mismatched → **error**.
      Example:

    ```c
    if (c == ')' && top != '(') {
        printf("Error: closed ) but did not open!\n");
    }
    ```

5.  **After Processing**
    - If no mismatches are found, the program confirms success:
    ```c
    printf("All parentheses, brackets and braces have been closed correctly!\n");
    ```

---

#### Example Execution

##### Input

    {[()]}

##### Process

- `{` → push
- `[` → push
- `(` → push
- `)` → pop `(` → matches ✔
- `]` → pop `[` → matches ✔
- `}` → pop `{` → matches ✔

##### Output

    All parentheses, brackets and braces have been closed correctly!

---

#### Conclusion

This program demonstrates the classic use of a **stack** to solve the problem of balanced symbols. Each opening symbol is pushed onto the stack, and each closing symbol must correspond to the most recent unmatched opening symbol at the top of the stack. If the rules are violated, the program reports an error immediately.
