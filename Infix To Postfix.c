#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ms 50 // maximum size of stack is defined here (chosen as 50 for testing purposes only, can be a large value)

/* Stack functions */

typedef struct stack_ { // stack declaration
    char data[ms];
    int top;
}stack;

stack newStack (stack s) { // stack initialisation (makes top = -1 for a new stack)
    s.top = -1;
    return s;
}

stack push(stack s, char item) { // push operation on the top of stack
    if (s.top == ms-1) {
        printf("Stack Overflow !\n");
    }
    else {
        s.top += 1;
        s.data[s.top] = item;
    }
    return s;
}

stack pop(stack s) { // pop operation to delete top element
    if (s.top == -1) {
        printf("Stack Underflow !\n");
    }
    else {
        s.top -= 1;
    }
    return s;
}

int isEmpty(stack s) { // boolean function to tell if stack is empty
    return (s.top == -1) ? 1 : 0;
}

char top(stack s) { // returns top element if stack is not empty else null
    if (!isEmpty(s))
        return s.data[s.top];
}

/* Infix to Postfix helper methods */

int prec(char a) { // returns the order of precedence of an operator
    switch(a) {
    case '-':
    case '+':
        return 1; break;
    case '*':
    case '/':
        return 2; break;
    case '^':
        return 3; break;
    default:
        return 0;
    }
}

/* Main Program */

int main() {
    char infix[20];
    stack s = newStack(s); // new stack declared and initialised
    int i;
    char ch;
    printf("Enter Infix expression:\n");
    scanf("%s", infix);
    printf("Postfix expression:\n");
    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') { // if character is an operator
            while ( ( ! isEmpty(s) ) && prec(ch) <= prec( top(s) ) ) {
                    printf("%c", top(s)); // print the top element of stack
                    s = pop(s); // remove the top element of stack
            }
            s = push(s, ch);
        }
        else if (ch == '(') { // if character is an opening parentheses
            s = push(s, ch);
        }
        else if (ch == ')') { // if character is a closing parentheses
            while ((! isEmpty(s)) && top(s) != '(') {
                printf("%c", top(s)); // print the top element of stack
                s = pop(s); // remove the top element of stack
            }
            if (top(s) == '(')
                s = pop(s); // remove the extra opening parentheses on top of stack
        }
        else {
            printf("%c", ch);
        }
    }
    while ( (! isEmpty(s)) ) {
        if (top(s) != '(' && top(s) != ')') printf("%c", top(s));
        s = pop(s);
    }
    return 0;
}
