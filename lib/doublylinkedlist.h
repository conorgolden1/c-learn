/*
Author: Conor Golden
Email: conorgolden1@hotmail.com
File: doublylinkedlist.h
Description:
    Header file defining structures and function prototypes for a doubly linked
list in C.
Created On: 05/29/2024
*/

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stddef.h>

// Define the structure for a node in the doubly linked list
typedef struct DoublyLinkedListNode {
  void *data;                        // Pointer to the data
  struct DoublyLinkedListNode *prev; // Pointer to the previous node
  struct DoublyLinkedListNode *next; // Pointer to the next node
} DoublyLinkedListNode;

// Define the structure for the doubly linked list
typedef struct {
  DoublyLinkedListNode *head; // Pointer to the head of the list
  DoublyLinkedListNode *tail; // Pointer to the tail of the list
  size_t size;                // Number of elements in the list
} DoublyLinkedList;

// Function prototypes

/**
 * @brief Creates a new empty doubly linked list.
 *
 * @return A pointer to the newly created list, or NULL if memory allocation
 * fails.
 */
DoublyLinkedList *createDoublyLinkedList();

/**
 * @brief Frees all memory associated with the doubly linked list.
 *
 * @param list A pointer to the list to be freed.
 */
void freeDoublyLinkedList(DoublyLinkedList *list);

/**
 * @brief Appends an element to the end of the doubly linked list.
 *
 * @param list A pointer to the list.
 * @param data A pointer to the data to be added.
 * @return 0 if successful, -1 if memory allocation fails.
 */
int appendDoublyLinkedList(DoublyLinkedList *list, void *data);

/**
 * @brief Prepends an element to the beginning of the doubly linked list.
 *
 * @param list A pointer to the list.
 * @param data A pointer to the data to be added.
 * @return 0 if successful, -1 if memory allocation fails.
 */
int prependDoublyLinkedList(DoublyLinkedList *list, void *data);

/**
 * @brief Inserts an element at a specified position in the doubly linked list.
 *
 * @param list A pointer to the list.
 * @param data A pointer to the data to be added.
 * @param pos The position at which to insert the new element (0-based index).
 * @return 0 if successful, -1 if memory allocation fails or if the position is
 * invalid.
 */
int insertDoublyLinkedList(DoublyLinkedList *list, void *data, size_t pos);

/**
 * @brief Removes and returns the element at the specified position in the
 * doubly linked list.
 *
 * @param list A pointer to the list.
 * @param pos The position of the element to be removed (0-based index).
 * @return A pointer to the data of the removed element, or NULL if the position
 * is invalid.
 */
void *removeDoublyLinkedList(DoublyLinkedList *list, size_t pos);

/**
 * @brief Returns the element at the specified position in the doubly linked
 * list without removing it.
 *
 * @param list A pointer to the list.
 * @param pos The position of the element to retrieve (0-based index).
 * @return A pointer to the data of the element, or NULL if the position is
 * invalid.
 */
void *getDoublyLinkedListElement(DoublyLinkedList *list, size_t pos);

/**
 * @brief Returns the size of the doubly linked list.
 *
 * @param list A pointer to the list.
 * @return The number of elements in the list.
 */
size_t getDoublyLinkedListSize(DoublyLinkedList *list);

/**
 * @brief Iterates over each element in the list and applies the given function.
 *
 * @param list A pointer to the list.
 * @param func A pointer to the function to be applied to each element.
 */
void iterateDoublyLinkedList(DoublyLinkedList *list, void (*func)(void *));

#endif // DOUBLY_LINKED_LIST_H
