
#include "mylib/doublylinkedlist.h"
#include "mylib/linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printLinkedList(LinkedList *ll) {
  LinkedListNode *current = ll->_private_head;
  printf("Linked List: [");
  while (current) {
    printf(" %s,", (char *)current->_private_data);
    current = current->_private_next;
  }
  printf("] size:%ld\n\n", getLinkedListSize(ll));
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
  // printf("%p\n", *ptr);
  // char *str = *ptr;
  // printf("%s\n", str);
  // *ptr = "Hello World";
  // printf("%p\n", *ptr);
  // printf("%s\n\n", str);
  //
}

void testLinkedList() {
  LinkedList *ll = createLinkedList();
  char data[6][50] = {"Hello", "World", "Cool Stuff All Along The Watchtower",
                      "Beans", "Test",  "Super Mega Long String"};
  for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {

    printf("Appending:\t%s\n", data[i]);
    appendLinkedList(ll, data[i]);
    printLinkedList(ll);
  }
  printLinkedList(ll);
  for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
    printf("Prepending:\t%s\n", data[i]);
    prependLinkedList(ll, data[i]);
    printLinkedList(ll);
  }
  for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
    printf("Inserting:\t%s\tpos:%d\n", data[i], i);
    insertLinkedList(ll, data[i], i);
    printLinkedList(ll);
  }
  int size = getLinkedListSize(ll);
  for (int i = 0; i < size; i++) {
    void *data = getLinkedList(ll, i);
    printf("Get:\t%s\tpos:%d\n", (char *)data, i);
  }
  iterateLinkedList(ll, reverseString);
  for (int i = 0; i < size; i++) {
    void *data = getLinkedList(ll, i);
    printf("Iterate:\t%s\tpos:%d\n", (char *)data, i);
  }
  for (int i = 0; i < size; i++) {
    void *data = removeLinkedList(ll, 0);
    printf("Removed:\t%s\tpos:%d\n", (char *)data, i);
    printLinkedList(ll);
  }
  freeLinkedList(ll);
}

void printDoublyLinkedList(DoublyLinkedList *list) {
  DoublyLinkedListNode *current = list->head;
  printf("Doubly Linked List: [");
  while (current) {
    printf(" %s,", (char *)current->data);
    current = current->next;
  }
  printf("] size:%ld\n\n", getDoublyLinkedListSize(list));
}

void testDoublyLinkedList() {
  DoublyLinkedList *list = createDoublyLinkedList();
  char data[7][50] = {"Hello",
                      "World",
                      "Cool Stuff All Along The Watchtower",
                      "Beans",
                      "Test",
                      "Super Mega Long String",
                      "Ligma Balls Becca"};
  for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
    printf("Inserting:\t%s\tpos:%d\n", data[i], i);
    insertDoublyLinkedList(list, data[i], i);
    printDoublyLinkedList(list);
  }
  char *test = malloc(8);
  test[0] = 'K';
  test[1] = '\0';

  printf("Inserting:\t%s\tpos:%d\n", test, 0);
  insertDoublyLinkedList(list, test, 0);
  printDoublyLinkedList(list);
  printf("Inserting:\t%s\tpos:%ld\n", test, list->size - 1);
  insertDoublyLinkedList(list, test, list->size - 1);
  printDoublyLinkedList(list);

  for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
    printf("Appending:\t%s\n", data[i]);
    appendDoublyLinkedList(list, data[i]);
    printDoublyLinkedList(list);
  }
  for (int i = 0; i < (sizeof(data) / sizeof(data[0])); i++) {
    printf("Prepending:\t%s\n", data[i]);
    prependDoublyLinkedList(list, data[i]);
    printDoublyLinkedList(list);
  }
  int size = getDoublyLinkedListSize(list);
  for (int i = 0; i < size; i++) {
    void *data = getDoublyLinkedListElement(list, i);
    printf("Get:\t%s\tpos:%d\n", (char *)data, i);
  }
  for (int i = 0; i < size; i++) {
    void *data = removeDoublyLinkedList(list, 0);
    printf("Removed:\t%s\tpos:%d\n", (char *)data, i);
    printDoublyLinkedList(list);
  }
  free(test);
  freeDoublyLinkedList(list);
}

int main() {

  testLinkedList();
  testDoublyLinkedList();
  return 0;
}
