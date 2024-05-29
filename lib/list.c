/*
Author: Conor Golden
Email: conorgolden1@hotmail.com
File: list.c
Description:
    Implementation of a dynamic array list in C, providing functions for
creation, manipulation, and iteration.
Created On: 05/29/2024
*/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List createList() {
  void **_private_items = malloc(sizeof(void *));
  if (!_private_items) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  List list = {NULL, _private_items, 0};
  return list;
}

void freeList(List *list) {
  if (list->_private_items) {
    free(list->_private_items);
    list->_private_items = NULL;
  }
  list->_private_head = NULL;
  list->_private_allocatedSize = 0;
}

int lengthList(List *list) {
  return list->_private_allocatedSize / sizeof(void *);
}

void *getList(List *list, int index) {
  if (index < 0 || index >= lengthList(list)) {
    return NULL;
  }
  return list->_private_items[index];
}

void **getRangeList(List *list, int from, int to) {
  if (from < 0 || to > lengthList(list) || from > to) {
    return NULL;
  }
  void **range = malloc((to - from) * sizeof(void *));
  if (!range) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  for (int i = from; i < to; i++) {
    range[i - from] = list->_private_items[i];
  }
  return range;
}

void pushList(List *list, void *ptr) {
  list->_private_items = realloc(list->_private_items,
                                 list->_private_allocatedSize + sizeof(void *));
  if (!list->_private_items) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  list->_private_items[list->_private_allocatedSize / sizeof(void *)] = ptr;
  list->_private_allocatedSize += sizeof(void *);
  list->_private_head = ptr;
}

void *popList(List *list) {
  if (lengthList(list) == 0) {
    return NULL;
  }
  void *ptr = list->_private_items[lengthList(list) - 1];
  list->_private_allocatedSize -= sizeof(void *);
  list->_private_items =
      realloc(list->_private_items, list->_private_allocatedSize);
  if (lengthList(list) > 0) {
    list->_private_head = list->_private_items[lengthList(list) - 1];
  } else {
    list->_private_head = NULL;
  }
  return ptr;
}

int insertList(List *list, void *data, int pos) {
  if (index < 0 || pos > lengthList(list)) {
    fprintf(stderr, "Index out of bounds\n");
    return -1;
  }
  list->_private_items = realloc(list->_private_items,
                                 list->_private_allocatedSize + sizeof(void *));
  if (!list->_private_items) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  for (int i = lengthList(list); i > pos; i--) {
    list->_private_items[i] = list->_private_items[i - 1];
  }
  list->_private_items[pos] = data;
  list->_private_allocatedSize += sizeof(void *);
  list->_private_head = list->_private_items[lengthList(list) - 1];
  return 0;
}

void *removeList(List *list, int pos) {
  if (pos < 0 || pos > lengthList(list)) {
    return NULL;
  }
  void *data = list->_private_items[pos];
  for (int i = pos; i < lengthList(list) - 1; i++) {
    list->_private_items[i] = list->_private_items[i + 1];
  }
  list->_private_allocatedSize -= sizeof(void *);
  list->_private_items =
      realloc(list->_private_items, list->_private_allocatedSize);

  if (lengthList(list) > 0) {
    list->_private_head = list->_private_items[lengthList(list) - 1];
  } else {
    list->_private_head = NULL;
  }

  return data;
}

int findList(List *list, void *ptr) {
  for (int i = 0; i < lengthList(list); i++) {
    if (list->_private_items[i] == ptr) {
      return i;
    }
  }

  return -1;
}

void clearList(List *list) {
  freeList(list);
  *list = createList();
}

int replaceList(List *list, void *data, int pos) {
  if (pos < 0 || pos > lengthList(list)) {
    return -1;
  }

  list->_private_items[pos] = data;
  if (pos == lengthList(list) - 1) {
    list->_private_head = data;
  }
  return 0;
}

void iterateList(List *list, void (*func)(void *)) {
  for (int i = 0; i < lengthList(list); i++) {
    func(list->_private_items[i]);
  }
}

int containsList(List *list, void *data) { return findList(list, data) != -1; }
