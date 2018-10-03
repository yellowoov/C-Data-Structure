const int sizeQueue = 3;
int front, rear;
class Queue
{
  private:
    int queue[sizeQueue];

  public:
    void createQueue();
    void enQueue(int val);
    int deQueue();
    bool isFull();
    bool isEmpty();
    void print();
};
