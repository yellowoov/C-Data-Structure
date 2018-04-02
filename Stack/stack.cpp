#include "stack.h"
using namespace std;

void Stack::push(int val)
{
  stack[++top] = val;
}

int Stack::pop()
{
  return stack[top--];
}

int Stack::isFull()
{
  return top == Stack_Size - 1;
}

int Stack::isEmpty()
{
  return top == -1;
}

void Stack::displayStack()
{
  int sp;
  sp = top;
  while (sp != -1)
  {
    cout << stack[sp--] << " ";
  }
  cout << endl;
};
