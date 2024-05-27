#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *createStack() {
  Stack *stack = malloc(sizeof(Stack));
  if (!stack) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  stack->top = NULL;
  stack->size = 0;

  return stack;
}

void freeStack(Stack *stack) {

}
