#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

typedef Node *NodePtr;
NodePtr top = NULL;

int main(int argc, char **argv)
{
  printf("Checking the parentheses in argv arguments\n");
  int i, N, j;
  char temp;
  int check = 0;
  Stack s;      // FROM stack.h เอาไว้เช็ค size โดยสั่งให้ชี้ไปที่ *top
  s.size = 0;   // ค่าเริ่มต้น
  s.top = NULL; //สั่งให้ pointer top ใน stack struct ชี้ไปที่ NULL
  // () ใช้ไมไ่ด้
  // [] {} ใช้ได้

  for (i = 1; i < argc; i++)
  {

    for (j = 0; j < strlen(argv[i]); j++)
    {
      /* Use stack to help with the parentheses*/
      // [ { push
      // ] } pop + compare
      switch (argv[i][j])
      {
      case '{':
        push(&s, '{');
        break;
      case '[':
        push(&s, '[');
        break;
      case '}':
        temp = pop(&s);
        if (temp != '}')
          check == 1;
        break;
      case ']':
        temp = pop(&s);
        if (temp != ']')
          check == 1;
        break;
      }
      if (check == 1)
        break;
    }
    if (s.size == 0 && check == 0)
      printf("The parentheses match successfully for %s \n", argv[i]);
    else
      printf("The parentheses do not match for %s \n", argv[i]);
    check = 0;
    s.size = 0;
    pop_all(&s);
  }

  printf("\n  *** END ***   \n");

  return 0;
}
