/*
Author: Conor Golden
Email: conorgolden1@hotmail.com

File: testList

Description:
    Code for testing operations on a dynamic array list in C
Created On: 05/29/2024
*/

#include "../lib/list.h"
#include "../.test_utils/test_assert.h"
#include <stdlib.h>

int testData[] = {0xDEADBEEF, 0xFEEDFACE, 0xCAFEFEED, 0x0D15EA5E};

// void printList(List *list) {
//   ListNode *current = list->_private_head;
//   printf("List: [");
//   while (current) {
//     printf(" 0x%x,", *(int *)current->_private_data);
//     current = current->_private_next;
//   }
//   printf("] size:%ld\n\n", getListSize(list));
// }

void testCreate() {
  List list = createList();
  assert(list._private_items != NULL);
  freeList(&list);
}

void testPush() {
  List list = createList();
  int i;
  for (i = 0; i < 4; i++) {
    pushList(&list, &testData[i]);
  }

  freeList(&list);
}

void testLength() {
  List list = createList();
  int size = 0;

  for (int i = 0; i < 4; i++) {
    pushList(&list, &testData[i]);
    assert(lengthList(&list) == size + 1);
    popList(&list);
    assert(lengthList(&list) == size);
    insertList(&list, &testData[i], 0);
    assert(lengthList(&list) == size + 1);
    removeList(&list, 0);
    assert(lengthList(&list) == size++);
    pushList(&list, &testData[i]);
  }

  freeList(&list);
}

void testPop() {
  List list = createList();

  for (int i = 0; i < 4; i++) {
    pushList(&list, &testData[i]);
  }
  for (int i = 3; i >= 0; i--) {
    assert(popList(&list) == &testData[i]);
  }

  freeList(&list);
}

void testGet() {
  List list = createList();

  pushList(&list, &testData[0]);
  assert(*(int *)getList(&list, 0) == testData[0]);

  freeList(&list);
}

void testGetRange() {
  List list = createList();
  for (int i = 0; i < 4; i++) {
    pushList(&list, &testData[i]);
  }
  void **range = getRangeList(&list, 0, 4);
  for (int i = 0; i < 4; i++) {
    assert(*(int *)range[i] == testData[i]);
  }
  free(range);
  freeList(&list);
}

void testInsert() {
  List list = createList();

  assert(insertList(&list, &testData[0], 0) == 0);
  assert(*(int *)getList(&list, 0) == testData[0]);

  assert(insertList(&list, &testData[1], 0) == 0);
  assert(*(int *)getList(&list, 0) == testData[1]);

  assert(insertList(&list, &testData[2], 1) == 0);
  assert(*(int *)getList(&list, 1) == testData[2]);

  freeList(&list);
}

void testRemove() {
  List list = createList();

  pushList(&list, &testData[0]);
  pushList(&list, &testData[1]);
  pushList(&list, &testData[2]);

  assert(*(int *)removeList(&list, 0) == testData[0]);

  assert(*(int *)removeList(&list, 1) == testData[2]);

  assert(*(int *)removeList(&list, 0) == testData[1]);

  freeList(&list);
}

void testFind() {
  List list = createList();

  for (int i = 0; i < 4; i++) {
    pushList(&list, &testData[i]);
  }

  for (int i = 0; i < 4; i++) {
    assert(findList(&list, &testData[i]) != -1);
  }

  freeList(&list);
}

void testClear() {
  List list = createList();

  for (int i = 0; i < 4; i++) {
    pushList(&list, &testData[i]);
  }
  clearList(&list);
  assert(lengthList(&list) == 0);
  freeList(&list);
}

void testReplace() {
  List list = createList();
  int test = 0xC000C000;
  for (int i = 0; i < 4; i++) {
    pushList(&list, &testData[i]);
  }

  assert(replaceList(&list, &test, -1) == -1);

  for (int i = 0; i < 4; i++) {
    assert(replaceList(&list, &test, i) != -1);
    assert(getList(&list, i) == &test);
  }

  assert(replaceList(&list, &test, 5) == -1);

  freeList(&list);
}

void testContains() {
  List list = createList();
  int test = 0xC000C000;
  for (int i = 0; i < 4; i++) {
    pushList(&list, &testData[i]);
  }

  assert(containsList(&list, &test) == 0);

  for (int i = 0; i < 4; i++) {
    assert(containsList(&list, &testData[i]) == 1);
  }

  freeList(&list);
}
// void iterateList(List *list, void (*func)(void *));
//
