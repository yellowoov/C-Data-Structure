#include <string>
using namespace std;

class Node
{
  public:
    int data;
    Node *next;

  friend class List;
};

class List {
  public:
    Node *head;
    List()
    {
      head = 0;
    }
    void insertNode(int data);
    bool isEmpty();
    void traverseList();
    void printListA();
    void printListCS();
};
