const int Stack_Size = 4;
int top;
class Stack
{
  private:
    int stack[Stack_Size];
  public:
    void push(int val);
    int pop();
    int isEmpty();
    int isFull();
    void displayStack();
};
