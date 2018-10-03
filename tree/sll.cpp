#include <string>
#include <iostream>
#include "sll.h"
using namespace std;

class Node
{
  public:
    int data;
    Node *next;

  friend class List;
};

class List {
  private:
    Node *head;

  public:
    List()
    {
      head = 0;
    }

    void insertNode(int data)
    /*
    **********************************************************
    * function: insertNode
    * description: insertNode의 사용목적은 주어진 데이터 한 줄을 스트링
    *              형식으로 받아 링크드 리스트에 노드를 삽입하기 위함이다.
    * variables: head - 첫 노드,
    *            data - data파일에서 입력 받은 학생들의 데이터 string,
    *            temp - head 앞에 노드가 삽입될 경우, head 저장 변수,
    *            next - 다음 노드
    **********************************************************
    */
    {
      Node *temp = new Node;
      temp -> data = data;
      temp -> next = 0;
      Node *p, *q;

      if(head == 0)
      {
        head = temp;
      }
      else if (temp -> data < head -> data)
      {
        temp -> next = head;
        head = temp;
      }

      else
      {
        p = head;
        while ((p != 0) && (p -> data < temp -> data))
        {
          q = p;
          p = p -> next;
        }
        if(p != 0)
        {
          temp -> next = p;
          q -> next = temp;
        }
        else
        {
          q -> next = temp;
        }
      }
    }

    bool isEmpty()
    /*
    **********************************************************
    * function: isEmpty
    * description: isEmpty의 사용목적은 현재 링크드 리스트가 비어있는지
    *              여부를 검사하기 위함이다.
    * variables: head - 첫 노드
    **********************************************************
    */
    {
      if (head == 0)
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    void traverseList()
    /*
    **********************************************************
    * function: traverseList
    * description: traverseList의 사용목적은 현재 링크드 리스트가 비어있지
    *              않으면 링크드 리스트의 값을 출력하기 위함이다.
    * variables: head - 첫 노드,
    *            data - data파일에서 입력 받은 학생들의 데이터 string
    **********************************************************
    */
    {
      Node *p;

      if (!isEmpty())
      {
        p = head;
        while (p)
        {
          cout << p -> data << " " << endl;
          p = p -> next;
        }
        cout << endl;
      }
      else
      {
        cout << "List is empty!\n";
      }
    }

    void printListA()
    /*
    **********************************************************
    * function: printListA
    * description: printListA의 사용목적은 현재 링크드 리스트의 데이터 중,
    *              성적이 A인 학생의 데이터를 출력하기 위함이다.
    * variables: head - 첫 노드,
    *            data - data파일에서 입력 받은 학생들의 데이터 string
    **********************************************************
    */
    {
      Node *p;
      p = head;

      while (p) {
        if (p -> data[9] == 'A') {      // data의 9번째 인덱스에 해당하는 character가
          cout << p -> data << endl;    // 'A'일 때만 출력
        }
        p = p -> next;
      }
      cout << endl;
    }

    void printListCS()
    /*
    **********************************************************
    * function: printListCS
    * description: printListCS의 사용목적은 현재 링크드 리스트의 데이터 중,
    *              전공이 CS인 학생의 데이터를 출력하기 위함이다.
    * variables: head - 첫 노드,
    *            data - data파일에서 입력 받은 학생들의 데이터 string
    **********************************************************
    */
    {
      Node *p;
      p = head;

      while (p) {
        if (p -> data.substr(6, 2) == "CS") {    // data의 6번째 인덱스부터 +2 인덱스의 character가
          cout << p -> data << endl;             // "CS"일 때만 출력
        }
        p = p -> next;
      }
      cout << endl;
    }
};
