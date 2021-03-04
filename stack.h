
#ifndef stack_h
#define stack_h
#include <stdio.h>
#include "node.h"
typedef struct
{
	NodePtr top;
	int size;
} Stack; // เอาไว้ชี้ตัวบนสุดกับเช็คsize

typedef Stack *StackPtr;
void push(StackPtr s, char value);
char pop(StackPtr s);
void pop_all(StackPtr s);

void push(StackPtr s, char value)
{
	Node *new_node = (Node *)malloc(sizeof(Node)); //จัดพื้นที่ให้ข้อมูลใหม่
	if (new_node)
	{
		new_node->data = value;
		new_node->nextPtr = s->top;
		s->top = new_node;
		s->size++; // ทุกครั้งที่เข้า จำนวนชั้นจะเพิ่มขึ้น
	}
}

char pop(StackPtr s)
{
	NodePtr t = s->top;
	char value;
	if (s->top != NULL)
	{
		value = t->data;
		s->top = t->nextPtr; //สั่งให้ Ptrtop ชี้ไปตัวถัดไป
		free(t);
		s->size--; // ทุกครั้งที่เอาออก จำนวนชั้นจะลดลง
	}
}

void pop_all(StackPtr s)
{
	NodePtr t = s->top; // ชี้ไปตัวบนเหมือน pop
	char value;
	while (s->top)
	{
		value = t->data;
		printf("Popping : %c \n", value);
		s->top = t->nextPtr;
		free(t);
		t = s->top;
	}
	s->size = 0; // หมดแย้วว
}
#endif
