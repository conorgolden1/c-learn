/*
Author: Conor Golden
Email: conorgolden1@hotmail.com
File: linkedList.c
Description:
    Implementation of a singly linked list in C, including functions for
creating, freeing, appending, prepending, inserting, and removing elements.
Created On: 05/29/2024
*/

#include "linkedList.h"
#include "doublylinkedlist.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

LinkedListNode *createLinkedListNode(void *data) {
  LinkedListNode *lln = (LinkedListNode *)malloc(sizeof(LinkedListNode));

  if (!lln) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  lln->_private_data = data;
  lln->_private_next = NULL;
  return lln;
}

LinkedList *createLinkedList() {
  LinkedList *linkedlist = (LinkedList *)malloc(sizeof(LinkedList));

  if (!linkedlist) {
    return NULL;
  }

  linkedlist->_private_head = NULL;
  linkedlist->_private_tail = NULL;
  linkedlist->_private_size = 0;

  return linkedlist;
}

void freeLinkedList(LinkedList *list) {
  if (!list) {
    return;
  }
  LinkedListNode *current = list->_private_head;
  LinkedListNode *nextNode;

  while (current) {
    nextNode = current->_private_next;
    free(current);
    current = nextNode;
  }

  free(list);
}

int insertNewNode(LinkedListNode *node, void *data) {
  if (!node) {
    return -1;
  }
  LinkedListNode *lln = createLinkedListNode(data);
  lln->_private_next = node->_private_next;
  node->_private_next = lln;

  return 0;
}

int appendLinkedList(LinkedList *list, void *data) {
  if (!list) {
    return -1;
  }
  LinkedListNode *lln = createLinkedListNode(data);

  if (!list->_private_head) {
    list->_private_head = lln;
  }

  if (list->_private_tail) {
    list->_private_tail->_private_next = lln;
  }

  list->_private_tail = lln;
  list->_private_size++;

  return 0;
}

int prependLinkedList(LinkedList *list, void *data) {
  if (!list) {
    return -1;
  }
  LinkedListNode *lln = createLinkedListNode(data);
  if (!list->_private_tail) {
    list->_private_tail = lln;
  }

  lln->_private_next = list->_private_head;
  list->_private_head = lln;
  list->_private_size++;

  return 0;
}

LinkedListNode *getLinkedListNode(LinkedList *list, size_t pos) {
  if (!list) {
    return NULL;
  }

  if (pos < 0 || pos >= list->_private_size) {
    fprintf(stderr, "Index out of bounds\n");
    return NULL;
  }

  LinkedListNode *current = list->_private_head;
  for (int i = 0; i < pos; i++) {
    current = current->_private_next;
  }
  return current;
}

int insertLinkedList(LinkedList *list, void *data, size_t pos) {
  if (!list) {
    return -1;
  }

  if (pos < 0 || pos > list->_private_size) {
    fprintf(stderr, "Index out of bounds\n");
    return -1;
  }

  if (pos == list->_private_size) {
    return appendLinkedList(list, data);
  }

  if (pos == 0) {
    return prependLinkedList(list, data);
  }

  LinkedListNode *current = list->_private_head;
  for (int i = 0; i < pos - 1; i++) {
    current = current->_private_next;
  }
  int result = insertNewNode(current, data);

  if (result == 0) {
    list->_private_size++;
  }
  return result;
}

void *removeLinkedList(LinkedList *list, size_t pos) {
  LinkedListNode *prev = NULL;
  LinkedListNode *node;

  if (pos == 0) {
    node = list->_private_head;
    list->_private_head = list->_private_head->_private_next;
  } else {
    prev = getLinkedListNode(list, pos - 1);
    node = prev->_private_next;
    prev->_private_next = node->_private_next;
  }

  if (pos == --list->_private_size) {
    list->_private_tail = prev;
  }

  void *data = node->_private_data;
  free(node);
  return data;
}

void *getLinkedListElement(LinkedList *list, size_t pos) {
  return getLinkedListNode(list, pos)->_private_data;
}

size_t getLinkedListSize(LinkedList *list) { return list->_private_size; }

void iterateLinkedList(LinkedList *list, void (*func)(void **)) {
  LinkedListNode *current = list->_private_head;
  size_t size = getLinkedListSize(list);
  for (int i = 0; i < size; i++) {
    func(&current->_private_data);
    current = current->_private_next;
  }
}
