#include <iostream>
#include "queue.cpp"
using namespace std;

int main()
{
  Queue q1;
  q1.enQueue(4);
  q1.enQueue(5);
  q1.enQueue(6);
  q1.enQueue(7);

  q1.print();

  if(q1.isFull())
  {
    cout << "Queue is full" << endl;
  }

  cout << "deQueue: " << q1.deQueue() << endl;
  cout << "deQueue: " << q1.deQueue() << endl;
  cout << "deQueue: " << q1.deQueue() << endl;
  cout << "deQueue: " << q1.deQueue() << endl;
  if (q1.isEmpty())
  {
    cout << "Queue is empty" << endl;
  }
}
