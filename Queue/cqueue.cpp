#include <iostream>
#include "queue.h"
using namespace std;

void Queue::createQueue()
{
  front = -1;
  rear = -1;
}

void Queue::enQueue(int val)
{
  rear = (rear + 1) % sizeQueue;
  if (front == rear)
  {
    cout << "Queue is full" << endl;
  }
  else
  {
    queue[rear] = val;
  }
}

int Queue::deQueue()
{
  if (front == rear)
  {
    cout << "Queue is empty" << endl;
  }
  else
  {
    front = (front + 1) % sizeQueue;
  }
  return queue[front];
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
