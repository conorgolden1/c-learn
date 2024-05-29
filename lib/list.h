/*
Author: Conor Golden
Email: conorgolden1@hotmail.com
File: list.h
Description: Header file for a dynamic list structure that holds generic items.
Creation Date: 05/29/2024
*/

#ifndef _LIST_H_
#define _LIST_H_

/**
 * @brief A dynamic list structure that holds generic items.
 */
typedef struct {
  void *_private_head;
  void **_private_items;
  int _private_allocatedSize;
} List;

/**
 * @brief Creates a new list.
 *
 * Allocates memory for a new list and initializes its members.
 *
 * @return A new list.
 */
List createList();

/**
 * @brief Frees the memory allocated for the list.
 *
 * @param list A pointer to the list to be freed.
 */
void freeList(List *l);

/**
 * @brief Retrieves an item from the list at a specified index.
 *
 * @param list A pointer to the list.
 * @param index The index of the item to retrieve.
 * @return A pointer to the item, or NULL if the index is out of bounds.
 */
void *getList(List *l, int pos);

/**
 * @brief Retrieves a range of items from the list.
 *
 * Allocates memory for an array of pointers and copies the specified range of
 * items.
 *
 * @param list A pointer to the list.
 * @param from The starting index of the range.
 * @param to The ending index of the range.
 * @return An array of pointers to the items in the specified range, or NULL if
 * the range is invalid.
 */
void **getRangeList(List *l, int from, int to);

/**
 * @brief Adds an item to the end of the list.
 *
 * Resizes the list if necessary to accommodate the new item.
 *
 * @param list A pointer to the list.
 * @param ptr A pointer to the item to be added.
 */
void pushList(List *l, void *ptr);

/**
 * @brief Removes and returns the most recently added item from the list.
 *
 * @param list A pointer to the list.
 * @return A pointer to the most recently added item, or NULL if the list is
 * empty.
 */
void *popList(List *l);

/**
 * @brief Returns the number of items in the list.
 *
 * @param list A pointer to the list.
 * @return The number of items in the list.
 */
int lengthList(List *l);

/**
 * @brief Inserts an item at the specified index in the list.
 *
 * @param list A pointer to the list.
 * @param index The index at which to insert the item.
 * @param ptr A pointer to the item to be inserted.
 * @return 1 if successful, 0 if the index is out of bounds.
 */
int insertList(List *list, void *data, int pos);

/**
 * @brief Removes the item at the specified index in the list.
 *
 * @param list A pointer to the list.
 * @param index The index of the item to be removed.
 * @return 0 if successful, -1 if the index is out of bounds.
 */
void *removeList(List *list, int pos);

/**
 * @brief Finds the index of the first occurrence of the specified item in the
 * list.
 *
 * @param list A pointer to the list.
 * @param ptr A pointer to the item to be found.
 * @return The index of the item, or -1 if the item is not found.
 */
int findList(List *list, void *ptr);

/**
 * @brief Clears all items from the list.
 *
 * @param list A pointer to the list.
 */
void clearList(List *list);

/**
 * @brief Replaces the item at the specified index with a new item.
 *
 * @param list A pointer to the list.
 * @param index The index of the item to be replaced.
 * @param ptr A pointer to the new item.
 * @return 0 if successful, -1 if the index is out of bounds.
 */
int replaceList(List *list, void *data, int pos);

/**
 * @brief Applies a function to each item in the list.
 *
 * @param list A pointer to the list.
 * @param func The function to apply to each item.
 */
void iterateList(List *list, void (*func)(void *));

/**
 * @brief Checks if the list contains the specified item.
 *
 * @param list A pointer to the list.
 * @param ptr A pointer to the item to check for.
 * @return 1 if the item is found, 0 otherwise.
 */
int containsList(List *list, void *data);

#endif
