/*
Author: Conor Golden
Email: conorgolden1@hotmail.com

File: testLinkedList

Description:
    Code for implementing and testing operations on a linked
list in C, including creation, appending, prepending, inserting, and removing
elements, along with utility functions for printing and string manipulation.

Created On: 05/29/2024
*/

#include "../.test_utils/test_assert.h"
#include "../lib/linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int testData[] = {0xDEADBEEF, 0xFEEDFACE, 0xCAFEFEED, 0x0D15EA5E};

void printLinkedList(LinkedList *list) {
  LinkedListNode *current = list->_private_head;
  printf("Linked List: [");
  while (current) {
    printf(" 0x%x,", *(int *)current->_private_data);
    current = current->_private_next;
  }
  printf("] size:%ld\n\n", getLinkedListSize(list));
}

void reverseString(void **ptr) {
  if (ptr == NULL || *ptr == NULL) {
    return;
  }
  int length = strlen(*ptr);
  char *buffer = malloc(length + 1);
  char *str = *ptr;
  int bufferIndex = 0;
  for (int i = length - 1; i >= 0; i--) {
    buffer[bufferIndex++] = str[i];
  }
  buffer[bufferIndex] = '\0';
  strcpy(str, buffer);
  free(buffer);
}

void testCreate() {
  LinkedList *list = createLinkedList();
  assert(list != NULL);
  freeLinkedList(list);
}

void testAppend() {

  LinkedList *list = createLinkedList();

  appendLinkedList(list, &testData[0]);
  assert(*(int *)getLinkedListElement(list, 0) == testData[0]);

  assert(list->_private_size == 1);
  assert(list->_private_head != NULL);
  assert(list->_private_tail != NULL);

  appendLinkedList(list, &testData[1]);
  assert(*(int *)getLinkedListElement(list, 1) == testData[1]);

  assert(list->_private_head != list->_private_tail);

  freeLinkedList(list);
}

void testPrepend() {

  LinkedList *list = createLinkedList();

  prependLinkedList(list, &testData[0]);
  assert(*(int *)getLinkedListElement(list, 0) == testData[0]);

  assert(list->_private_size == 1);
  assert(list->_private_head != NULL);
  assert(list->_private_tail != NULL);

  prependLinkedList(list, &testData[1]);
  assert(*(int *)getLinkedListElement(list, 0) == testData[1]);
  assert(list->_private_head != list->_private_tail);

  freeLinkedList(list);
}

void testGet() {
  LinkedList *list = createLinkedList();

  appendLinkedList(list, &testData[0]);
  assert(*(int *)getLinkedListElement(list, 0) == testData[0]);

  assert(list->_private_size == 1);
  assert(list->_private_head != NULL);
  assert(list->_private_tail != NULL);

  freeLinkedList(list);
}

void testInsert() {
  LinkedList *list = createLinkedList();

  insertLinkedList(list, &testData[0], 0);
  assert(*(int *)getLinkedListElement(list, 0) == testData[0]);

  assert(list->_private_head != NULL);
  assert(list->_private_tail != NULL);

  insertLinkedList(list, &testData[1], 0);
  assert(*(int *)getLinkedListElement(list, 0) == testData[1]);

  assert(list->_private_head != list->_private_tail);

  insertLinkedList(list, &testData[2], 1);

  assert(*(int *)getLinkedListElement(list, 1) == testData[2]);
  assert(*(int *)list->_private_head->_private_data != testData[2]);
  assert(*(int *)list->_private_tail->_private_data != testData[2]);

  freeLinkedList(list);
}

void testRemove() {
  LinkedList *list = createLinkedList();

  appendLinkedList(list, &testData[0]);
  appendLinkedList(list, &testData[1]);
  appendLinkedList(list, &testData[2]);

  assert(*(int *)removeLinkedList(list, 0) == testData[0]);
  assert(*(int *)list->_private_head->_private_data != testData[0]);
  assert(list->_private_size == 2);

  assert(*(int *)removeLinkedList(list, 1) == testData[2]);
  assert(*(int *)list->_private_tail->_private_data != testData[2]);
  assert(list->_private_size == 1);
  assert(list->_private_tail == list->_private_head);

  assert(*(int *)removeLinkedList(list, 0) == testData[1]);
  assert(list->_private_size == 0);
  assert(list->_private_tail == NULL);
  assert(list->_private_head == NULL);

  freeLinkedList(list);
}
