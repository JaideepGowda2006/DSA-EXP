#include <stdio.h>
// For standard input/output functions.
#include <ctype.h>
// For the 'isalnum()' function, which checks if a character is alphanumeric (a letter or a number).

#define MAX 50
// Defines the maximum size of our stack and expression arrays.

char stack[MAX];
// Declares a character array to be used as a stack for operators.
int top = -1;
// Initializes 'top' for our operator stack.

void push(char c) {
    // A function to push a character onto the stack.
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c; // Increments top, then adds the character.
}

char pop() {
    // A function to pop a character from the stack.
    if (top == -1)
        return -1; // Indicates an empty stack.
    else
        return stack[top--]; // Returns the character at 'top', then decrements 'top'.
}

int precedence(char c) {
    // A function that returns the precedence (priority) of an operator.
    if (c == '^')
        return 3; // Exponentiation has the highest precedence.
    else if (c == '*' || c == '/')
        return 2; // Multiplication and Division are next.
    else if (c == '+' || c == '-')
        return 1; // Addition and Subtraction are lowest.
    else
        return 0; // For non-operators like '('.
}

int main() {
    char infix[] = "A+B*C";
    // The infix expression we want to convert.
    char postfix[MAX];
    // An array to store the resulting postfix expression.
    int i = 0, k = 0;
    // 'i' is the index for scanning the infix string, 'k' is for building the postfix string.
    char ch;
    // A character variable to hold the currently scanned character.

    printf("Infix Expression: %s\n", infix);

    while ((ch = infix[i++]) != '\0') {
        // Loop through each character of the infix string until the end ('\0').

        if (isalnum(ch)) {
            // If the character is an operand (a letter or number)...
            postfix[k++] = ch; // ...add it directly to the postfix string.
        }
        else if (ch == '(') {
            // If it's an opening parenthesis...
            push(ch); // ...push it onto the stack.
        }
        else if (ch == ')') {
            // If it's a closing parenthesis...
            while (stack[top] != '(') {
                // ...pop all operators from the stack and add them to postfix...
                postfix[k++] = pop();
            }
            pop(); // ...and finally, pop the opening parenthesis '(' itself.
        }
        else { // operator
            // If the character is an operator...
            while (precedence(stack[top]) >= precedence(ch)) {
                // ...while the operator at the top of the stack has higher or equal precedence...
                postfix[k++] = pop(); // ...pop it and add it to postfix.
            }
            push(ch); // ...then push the current operator onto the stack.
        }
    }

    while (top != -1) {
        // After the loop, if any operators are left in the stack...
        postfix[k++] = pop(); // ...pop them all and add them to postfix.
    }

    postfix[k] = '\0';
    // Add the null terminator to mark the end of the postfix string.

    printf("Postfix Expression: %s\n", postfix);
    // Print the final result.

    return 0;
}
