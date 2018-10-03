#include <iostream>
#include "queue.h"
using namespace std;

void Queue::createQueue()
{
  front = -1;
  rear = -1;
}

char Queue::enQueue(int val)
{
  if (rear == sizeQueue - 1)
  {
    isFull();
  }
  queue[++rear] = val;
  return queue[rear];
}

int Queue::deQueue()
{
  if (front == rear)
  {
    return isEmpty();
  }
  return queue[++front];
}

bool Queue::isFull()
{
  if (rear == sizeQueue - 1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Queue::isEmpty()
{
  if (front == rear)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Queue::print()
{
  int i;
  if (isEmpty())
  {
    cout << "Queue is Empty!" << endl;
  }
  else
  {
    i = front + 1;
    cout << "--Print Queue--" << endl;
    while (i <= rear)
    {
      cout << queue[i] << " ";
      i = i + 1;
    }
    cout << endl;
  }
}
