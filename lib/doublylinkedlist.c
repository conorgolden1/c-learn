/*
Author: Conor Golden
Email: conorgolden1@hotmail.com
File: doublylinkedlist.c
Description:
    Implementation of a doubly linked list in C, including functions for
creating, freeing, appending, prepending, inserting, and removing elements, as
well as utility functions for traversing, accessing, and iterating over the
list.
Created On: 05/29/2024
*/

#include "doublylinkedlist.h"
#include <stdio.h>
#include <stdlib.h>

DoublyLinkedListNode *createDoublyLinkedListNode(void *data) {
  DoublyLinkedListNode *listNode =
      (DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));

  if (!listNode) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  listNode->data = data;
  listNode->next = NULL;
  listNode->prev = NULL;

  return listNode;
}

DoublyLinkedList *createDoublyLinkedList() {
  DoublyLinkedList *list = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
  if (!list) {
    return NULL;
  }

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return list;
}

void freeDoublyLinkedList(DoublyLinkedList *list) {
  if (!list) {
    return;
  }

  DoublyLinkedListNode *current = list->head;
  DoublyLinkedListNode *nextNode;

  while (current) {
    nextNode = current->next;
    free(current);
    current = nextNode;
  }

  free(list);

  list = NULL;
}

int appendDoublyLinkedList(DoublyLinkedList *list, void *data) {
  if (!list) {
    return -1;
  }

  DoublyLinkedListNode *node = createDoublyLinkedListNode(data);
  DoublyLinkedListNode *current = list->tail;
  DoublyLinkedListNode *nextNode;

  list->size++;

  if (!current) {
    list->head = node;
    list->tail = node;
    return 0;
  }

  current->next = node;
  node->prev = current;
  list->tail = node;

  return 0;
}

int prependDoublyLinkedList(DoublyLinkedList *list, void *data) {
  if (!list) {
    return -1;
  }

  DoublyLinkedListNode *node = createDoublyLinkedListNode(data);
  DoublyLinkedListNode *current = list->head;

  list->size++;

  if (!current) {
    list->head = node;
    list->tail = node;
    return 0;
  }

  current->prev = node;
  node->next = current;
  list->head = node;

  return 0;
}

DoublyLinkedListNode *traverseForward(DoublyLinkedListNode *node, int *index) {
  (*index)++;
  return node->next;
}

DoublyLinkedListNode *traverseBackward(DoublyLinkedListNode *node, int *index) {
  (*index)--;
  return node->prev;
}

DoublyLinkedListNode *getDoublyLinkedListNode(DoublyLinkedList *list, size_t pos) {
  if (!list) {
    return NULL;
  }

  if (pos < 0 || pos > list->size) {
    fprintf(stderr, "Index out of bounds\n");
    return NULL;
  }

  if (pos == list->size) {
    return list->tail;
  }

  if (pos == 0) {
    return list->head;
  }

  DoublyLinkedListNode *current;
  DoublyLinkedListNode *(*traverseFunc)(DoublyLinkedListNode *, int *);
  int index;
  size_t length = getDoublyLinkedListSize(list);

  if (pos > length / 2) {
    current = list->tail;
    traverseFunc = &traverseBackward;
    index = length;
  } else {
    current = list->head;
    traverseFunc = &traverseForward;
    index = 0;
  }

  while (index != pos) {
    current = traverseFunc(current, &index);
  }

  return current;
}

int insertDoublyLinkedList(DoublyLinkedList *list, void *data, size_t pos) {
  if (!list) {
    return -1;
  }

  if (pos < 0 || pos > list->size) {
    fprintf(stderr, "Index out of bounds\n");
    return -1;
  }

  if (pos == list->size) {
    return appendDoublyLinkedList(list, data);
  }

  if (pos == 0) {
    return prependDoublyLinkedList(list, data);
  }

  DoublyLinkedListNode *node = createDoublyLinkedListNode(data);
  DoublyLinkedListNode *current = getDoublyLinkedListNode(list, pos - 1);

  node->next = current->next;
  current->next = node;
  node->prev = current;

  list->size++;

  return 0;
}

void *removeDoublyLinkedList(DoublyLinkedList *list, size_t pos) {
  DoublyLinkedListNode *node = getDoublyLinkedListNode(list, pos);
  DoublyLinkedListNode *prev = node->prev;
  DoublyLinkedListNode *next = node->next;

  if (!node) {
    return NULL;
  }

  if (prev) {
    prev->next = next;
  } else {
    list->head = next;
  }

  if (next) {
    next->prev = prev;
  } else {
    list->tail = prev;
  }

  void *data = node->data;
  free(node);
  list->size--;

  return data;
}

void *getDoublyLinkedListElement(DoublyLinkedList *list, size_t pos) {
  return getDoublyLinkedListNode(list, pos)->data;
}

void iterateDoublyLinkedList(DoublyLinkedList *list, void (*func)(void *)) {
  DoublyLinkedListNode *current = list->head;
  size_t size = getDoublyLinkedListSize(list);
  for (int i = 0; i < size; i++) {
    func(&current->data);
    current = current->next;
  }
}

size_t getDoublyLinkedListSize(DoublyLinkedList *list) { return list->size; }
