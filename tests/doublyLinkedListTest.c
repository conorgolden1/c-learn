/*
Author: Conor Golden
Email: conorgolden1@hotmail.com

File: testDoublyLinkedList

Description:
    Code for implementing and testing operations on a doubly linked
list in C, including creation, appending, prepending, inserting, and removing
elements, along with utility functions for printing and string manipulation.

Created On: 05/29/2024
*/

#include "../.test_utils/test_assert.h"
#include "../lib/doublylinkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int testData[] = {0xDEADBEEF, 0xFEEDFACE, 0xCAFEFEED, 0x0D15EA5E};

void printDoublyLinkedList(DoublyLinkedList *list) {
  DoublyLinkedListNode *current = list->head;
  printf("Doubly Linked List: [");
  while (current) {
    printf(" 0x%x,", *(int *)current->data);
    current = current->next;
  }
  printf("] size:%ld\n\n", getDoublyLinkedListSize(list));
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
  DoublyLinkedList *list = createDoublyLinkedList();
  assert(list != NULL);
  freeDoublyLinkedList(list);
}

void testAppend() {

  DoublyLinkedList *list = createDoublyLinkedList();

  appendDoublyLinkedList(list, &testData[0]);
  assert(*(int *)getDoublyLinkedListElement(list, 0) == testData[0]);

  assert(list->size == 1);
  assert(list->head != NULL);
  assert(list->tail != NULL);

  appendDoublyLinkedList(list, &testData[1]);
  assert(*(int *)getDoublyLinkedListElement(list, 1) == testData[1]);

  assert(list->head != list->tail);

  freeDoublyLinkedList(list);
}

void testPrepend() {

  DoublyLinkedList *list = createDoublyLinkedList();

  prependDoublyLinkedList(list, &testData[0]);
  assert(*(int *)getDoublyLinkedListElement(list, 0) == testData[0]);

  assert(list->size == 1);
  assert(list->head != NULL);
  assert(list->tail != NULL);

  prependDoublyLinkedList(list, &testData[1]);
  assert(*(int *)getDoublyLinkedListElement(list, 0) == testData[1]);
  assert(list->head != list->tail);

  freeDoublyLinkedList(list);
}

void testGet() {
  DoublyLinkedList *list = createDoublyLinkedList();

  appendDoublyLinkedList(list, &testData[0]);
  assert(*(int *)getDoublyLinkedListElement(list, 0) == testData[0]);

  assert(list->size == 1);
  assert(list->head != NULL);
  assert(list->tail != NULL);

  freeDoublyLinkedList(list);
}

void testInsert() {
  DoublyLinkedList *list = createDoublyLinkedList();

  insertDoublyLinkedList(list, &testData[0], 0);
  assert(*(int *)getDoublyLinkedListElement(list, 0) == testData[0]);

  assert(list->head != NULL);
  assert(list->tail != NULL);

  insertDoublyLinkedList(list, &testData[1], 0);
  assert(*(int *)getDoublyLinkedListElement(list, 0) == testData[1]);

  assert(list->head != list->tail);

  insertDoublyLinkedList(list, &testData[2], 1);

  assert(*(int *)getDoublyLinkedListElement(list, 1) == testData[2]);
  assert(*(int *)list->head->data != testData[2]);
  assert(*(int *)list->tail->data != testData[2]);

  freeDoublyLinkedList(list);
}

void testRemove() {
  DoublyLinkedList *list = createDoublyLinkedList();

  appendDoublyLinkedList(list, &testData[0]);
  appendDoublyLinkedList(list, &testData[1]);
  appendDoublyLinkedList(list, &testData[2]);

  assert(*(int *)removeDoublyLinkedList(list, 0) == testData[0]);
  assert(*(int *)list->head->data != testData[0]);
  assert(list->size == 2);

  assert(*(int *)removeDoublyLinkedList(list, 1) == testData[2]);
  assert(*(int *)list->tail->data != testData[2]);
  assert(list->size == 1);
  assert(list->tail == list->head);

  assert(*(int *)removeDoublyLinkedList(list, 0) == testData[1]);
  assert(list->size == 0);
  assert(list->tail == NULL);
  assert(list->head == NULL);

  freeDoublyLinkedList(list);
}
