#ifndef STACK_H
#define STACK_H

#include <stddef.h>

// Define the structure for a node in the stack
typedef struct StackNode {
    void *data;                      // Pointer to the data
    struct StackNode *next;          // Pointer to the next node
} StackNode;

// Define the structure for the stack
typedef struct {
    StackNode *top;                  // Pointer to the top of the stack
    size_t size;                     // Number of elements in the stack
} Stack;

// Function prototypes

/**
 * Creates a new stack.
 *
 * @return A pointer to the newly created stack, or NULL if memory allocation fails.
 */
Stack* createStack();

/**
 * Frees all memory associated with the stack.
 *
 * @param stack A pointer to the stack to free.
 */
void freeStack(Stack *stack);

/**
 * Pushes an element onto the top of the stack.
 *
 * @param stack A pointer to the stack.
 * @param data A pointer to the data to push onto the stack.
 * @return 0 on success, -1 if memory allocation fails.
 */
int push(Stack *stack, void *data);

/**
 * Pops an element from the top of the stack.
 *
 * @param stack A pointer to the stack.
 * @return A pointer to the data popped from the stack, or NULL if the stack is empty.
 */
void* pop(Stack *stack);

/**
 * Peeks at the top element of the stack without removing it.
 *
 * @param stack A pointer to the stack.
 * @return A pointer to the data at the top of the stack, or NULL if the stack is empty.
 */
void* peek(Stack *stack);

/**
 * Returns the number of elements in the stack.
 *
 * @param stack A pointer to the stack.
 * @return The number of elements in the stack
 */
size_t getStackSize(Stack *stack);

#endif // STACK_H
