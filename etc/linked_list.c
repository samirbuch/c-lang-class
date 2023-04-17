#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *nextNode;
};

void updateNode(struct Node *nodeToUpdate, struct Node *childNode);
//struct Node *createNode(int data, struct Node *previousNode);
char equalsNode(struct Node *node1, struct Node *node2);

int main(void) {
  struct Node node0 = { 0, NULL };
  struct Node node1 = { 1, NULL };
  struct Node node2 = { 2, NULL };

  updateNode(&node0, &node1);
  updateNode(&node1, &node2);
  printf("[%p] Node 0 data: %i \n- Node 0 next node: %p \n- Node 0 next node data: %i\n",
         node0, node0->data, node0->nextNode, node0->nextNode->data);
  printf("[%p] Node 1 data: %i \n- Node 1 next node: %p \n- Node 1 next node data: %i\n",
         node1, node1->data, node1->nextNode, node1->nextNode->data);
  printf("[%p] Node 2 data: %i \n- Node 2 next node: %p \n- Node 2 next node data: %i\n",
         node2, node2->data, node2->nextNode, node2->nextNode->data);

  // %p is the format for a memory address
  printf("Is node0's nextNode equal to address of node1? %c\n", equalsNode(node0, node1));
}

void updateNode(struct Node *nodeToUpdate, struct Node *childNode) {
  nodeToUpdate->nextNode = childNode;
}

//struct Node *createNode(int data, struct Node *previousNode) {
//  struct Node newNode = { data, previousNode };
//  if(previousNode != NULL) {
//    previousNode->nextNode = &newNode;
//  }
//  return &newNode;
//}

char equalsNode(struct Node *node1, struct Node *node2) {
  if(node1 == node2) {
    return 'T';
  } else {
    return 'F';
  }
}