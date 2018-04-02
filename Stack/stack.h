const int Stack_Size = 4;
class Stack
{
  public:
    void create_stack();
    void push(int val);
    int pop();
    int isEmpty();
    int isFull();
    void displayStack();
};
