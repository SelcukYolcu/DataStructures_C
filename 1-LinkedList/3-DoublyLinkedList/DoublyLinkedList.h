#ifndef DoublyLinkedList
#define DoublyLinkedList

typedef struct n{
    int val;
    struct n* next;
    struct n* prev;
}node;

node* createList(unsigned int size);
node* append(node* root, int val);
node* extendList(node* root, unsigned int size);
node* insertSequentially(node* root, int val);
int printNode(node *root);
int printReversedNode(node* const endNode);
node* deleteAll(node* const root);
node* deleteVal(node* root, int val);

#endif