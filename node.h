//
//  linkedlist.h
//  LinkedList_simple
//
//  Created by Mingmanas Sivaraksa on 5/2/2564 BE.
//

#ifndef linkedlist_h
#define linkedlist_h
struct node
{
    char data;
    struct node *nextPtr;
}; // ทำ linklisted สำหรับnode่ใหม่

typedef struct node Node;
typedef struct node *NodePtr;

#endif
