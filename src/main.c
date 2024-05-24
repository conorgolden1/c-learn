
#include "mylib/linkedList.h"
#include "mylib/list.h"
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
  printf("] size:%ld\n", getLinkedListSize(ll));
}

void reverseString(void *ptr) {

  // char * str = (char *)ptr;
  // char *buffer = malloc(strlen(str));
  // int i = 0;
  // for (int x = strlen(str) - 1; x >= 0; x--) {
  //   buffer[i++] = str[x];
  // }
  // buffer[i] = '\0';
  // ptr = (void *)buffer;
  free(ptr);
}

int main() {

  LinkedList *ll = createLinkedList();
  char *data[] = {"Hello", "World", "Cool", "Beans", "Test"};
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


