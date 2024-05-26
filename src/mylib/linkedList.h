
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

// Define the structure for a node in the linked list
typedef struct LinkedListNode {
  void *_private_data;
  struct LinkedListNode *_private_next;
} LinkedListNode;

// Define the structure for the linked list
typedef struct {
  LinkedListNode *_private_head;
  LinkedListNode *_private_tail;
  size_t _private_size;
} LinkedList;

// Function prototypes

/**
 * @brief Creates a new empty linked list.
 *
 * @return A pointer to the newly created list, or NULL if memory allocation fails.
 */
LinkedList* createLinkedList();

/**
 * @brief Frees all memory associated with the linked list.
 *
 * @param list A pointer to the list to be freed.
 */
void freeLinkedList(LinkedList *list);

/**
 * @brief Appends an element to the end of the linked list.
 *
 * @param list A pointer to the list.
 * @param data A pointer to the data to be added.
 * @return 0 if successful, -1 if memory allocation fails.
 */
int appendLinkedList(LinkedList *list, void *data);

/**
 * @brief Prepends an element to the beginning of the linked list.
 *
 * @param list A pointer to the list.
 * @param data A pointer to the data to be added.
 * @return 0 if successful, -1 if memory allocation fails.
 */
int prependLinkedList(LinkedList *list, void *data);

/**
 * @brief Inserts an element at a specified position in the linked list.
 *
 * @param list A pointer to the list.
 * @param data A pointer to the data to be added.
 * @param pos The position at which to insert the new element (0-based index).
 * @return 0 if successful, -1 if memory allocation fails or if the position is invalid.
 */
int insertLinkedList(LinkedList *list, void *data, size_t pos);

/**
 * @brief Removes and returns the element at the specified position in the linked list.
 *
 * @param list A pointer to the list.
 * @param pos The position of the element to be removed (0-based index).
 * @return A pointer to the data of the removed element, or NULL if the position is invalid.
 */
void* removeLinkedList(LinkedList *list, size_t pos);

/**
 * @brief Returns the element at the specified position in the linked list without removing it.
 *
 * @param list A pointer to the list.
 * @param pos The position of the element to retrieve (0-based index).
 * @return A pointer to the data of the element, or NULL if the position is invalid.
 */
void* getLinkedList(LinkedList *list, size_t pos);

/**
 * @brief Returns the size of the linked list.
 *
 * @param list A pointer to the list.
 * @return The number of elements in the list.
 */
size_t getLinkedListSize(LinkedList *list);

/**
 * @brief Iterates over each element in the list and applies the given function.
 *
 * @param list A pointer to the list.
 * @param func A pointer to the function to be applied to each element.
 */
void iterateLinkedList(LinkedList *list, void (*func)(void **));

#endif // LINKED_LIST_H

