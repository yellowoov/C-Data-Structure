#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node* rlink;
  Node *llink;
  Node(int data);
  Node();
};

Node::Node(int data)
{
  this->data = data;
  this->rlink = this->llink = NULL;
}

Node::Node()
{
  this->rlink = this->llink = NULL;
}

class DoubleLinkedList
{
public:
  Node* headNode;
  DoubleLinkedList();
  int find_nth(int num);
  void insertNode(int data);
  void insert_after(int num, int data);
  void insert_before(int num, int data);
  void printList();
  void deleteNode();
  bool isEmpty();
};

DoubleLinkedList::DoubleLinkedList()
{
  this->head = new Node();
  this->head->rlink = this->head->llink = this->head;
}

int DoubleLinkedList::find_nth(int num)
{
  int c_node = head;
  for (int i = 1; i < num; i++)
  {
    c_node = c_node->rlink;
  }
  return c_node;
}

void DoubleLinkedList::insertNode(int data)
{
  Node* newnode = new Node(data);
  newnode->rlink = this->head->rlink;
  newnode->llink = this->head;
  newnode->rlink->llink = newnode;
  newnode->llink->rlink = newnode;
}

void insert_before(int num, int data)
{
  int nthnode = find_nth(num);
  int newdata;
  if (head == NULL)
  {
    insertNode(data);
  }
  else
  {
    int holddata = nthnode->newdata;
    nthnode->newdata = data;
    insert_after(holddata);
  }
}

void insert_after(int num, int data)
{
  int nthnode = find_nth(num);
  new Node(p);
  int newdata;
  p->newdata = data;
  if (head == NULL)
  {
    head = p;
    p->rlink = p;
    p->llink = p;
  }
  else
  {
    p->llink = nthnode;
    p->rlink = nthnode->rlink;
    nthnode->rlink->llink = p;
    nthnode->rlink = p;
  }
}

bool DoubleLinkedList::isEmpty()
{
  return this->head->rlink = this->head;
}

void DoubleLinkedList::deleteNode()
{
  if (this->isEmpty())
  {
    cout << "List is Empty" << endl;
    exit(-1);
  }
  else
  {
    Node* remove = this->head->rlink;
    remove->rlink->llink = this->head;
    this->head->rlink = remove->rlink;
    delete remove;
  }
}

void DoubleLinkedList::printList()
{
  if (this->isEmpty())
  {
    cout << "List is Empty" << endl;
    return;
  }
  else
  {
    Node *tmp = this->head;
    while (tmp->rlink != this->head)
    {
      tmp = tmp->rlink;
      cout << tmp->data << " ";
    }
    cout << endl;
  }
}

int main()
{
  DoubleLinkedList l1;
  l1.insertNode(1);
  l1.insertNode(2);
  l1.insertNode(3);
  l1.insertNode(4);
  l1.printList();
}
