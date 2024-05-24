#include "list.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

List createList() {
  void **_private_items = malloc(sizeof(void *));
  if (!_private_items) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  List list = {NULL, _private_items, 0};
  return list;
}

void listFree(List *list) {
  if (list->_private_items) {
    free(list->_private_items);
    list->_private_items = NULL;
  }
  list->_private_head = NULL;
  list->_private_allocatedSize = 0;
}

int listLength(List *list) { return list->_private_allocatedSize / sizeof(void *); }

void *listGet(List *list, int index) {
  if (index < 0 || index >= listLength(list)) {
    return NULL;
  }
  return list->_private_items[index];
}

void **listGetRange(List *list, int from, int to) {
  if (from < 0 || to > listLength(list) || from > to) {
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

void listPush(List *list, void *ptr) {
  list->_private_items = realloc(list->_private_items, list->_private_allocatedSize + sizeof(void *));
  if (!list->_private_items) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  list->_private_items[list->_private_allocatedSize / sizeof(void *)] = ptr;
  list->_private_allocatedSize += sizeof(void *);
  list->_private_head = ptr;
}

void *listPop(List *list) {
  if (listLength(list) == 0) {
    return NULL;
  }
  void *ptr = list->_private_items[listLength(list) - 1];
  list->_private_allocatedSize -= sizeof(void *);
  list->_private_items = realloc(list->_private_items, list->_private_allocatedSize);
  if (listLength(list) > 0) {
    list->_private_head = list->_private_items[listLength(list) - 1];
  } else {
    list->_private_head = NULL;
  }
  return ptr;
}

int listInsert(List *list, int index, void *ptr) {
  if (index < 0 || index > listLength(list)) {
    fprintf(stderr, "Index out of bounds\n");
    return -1;
  }
  list->_private_items = realloc(list->_private_items, list->_private_allocatedSize + sizeof(void *));
  if (!list->_private_items) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  for (int i = listLength(list); i > index; i--) {
    list->_private_items[i] = list->_private_items[i - 1];
  }
  list->_private_items[index] = ptr;
  list->_private_allocatedSize += sizeof(void *);
  list->_private_head = list->_private_items[listLength(list) - 1];
  return 0;
}

int listRemove(List *list, int index) {
  if (index < 0 || index > listLength(list)) {
    return -1;
  }

  for (int i = index; i < listLength(list) - 1; i++) {
    list->_private_items[i] = list->_private_items[i + 1];
  }
  list->_private_allocatedSize -= sizeof(void *);
  list->_private_items = realloc(list->_private_items, list->_private_allocatedSize);

  if (listLength(list) > 0) {
    list->_private_head = list->_private_items[listLength(list) - 1];
  } else {
    list->_private_head = NULL;
  }

  return 0;
}

int listFind(List *list, void *ptr) {
  for (int i = 0; i < listLength(list); i++) {
    if (list->_private_items[i] == ptr) {
      return i;
    }
  }

  return -1;
}

void listClear(List *list) {
  listFree(list);
  *list = createList();
}

int listReplace(List *list, int index, void *ptr) {
  if (index < 0 || index > listLength(list)) {
    return -1;
  }

  list->_private_items[index] = ptr;
  if (index == listLength(list) - 1) {
    list->_private_head = ptr;
  }
  return 0;
}

void listIterate(List *list, void (*func)(void *)) {
  for (int i = 0; i < listLength(list); i++) {
    func(list->_private_items[i]);
  }
}

int listContains(List *list, void *ptr) {
    return listFind(list, ptr) != -1;
}
