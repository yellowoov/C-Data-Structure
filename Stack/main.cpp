#include <iostream>
#include <fstream>
#include "stack.cpp"

using namespace std;

int main()
{
  Stack s1;
  top = -1;

  s1.push(10);
  s1.push(20);
  s1.push(30);
  s1.push(40);

  s1.displayStack();

  if(s1.isFull())
  {
    cout << "Stack is full" << endl;
  }

  cout << "POP: " << s1.pop() << endl;
  cout << "POP: " << s1.pop() << endl;
  cout << "POP: " << s1.pop() << endl;
  cout << "POP: " << s1.pop() << endl;
  if (s1.isEmpty())
  {
    cout << "Stack is empty" << endl;
  }
  return 0;
}
