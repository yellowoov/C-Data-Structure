/*
*********************************************************
* Name: 이정훈
* Student ID : 20171678
* Program ID : hw02
* Description: 싱글 링크드 리스트를 이용해 학생들의 성적을 기록하기 위함.
* Algorithm : data 파일의 데이터를 한 줄 한 줄 읽어와 char형 배열에 저장.
*             배열의 데이터를 L1 리스트에 insert.
*             프로그램이 시작되면, 1, 2, 3, 4 중 하나를 입력받는데,
*             프로그램 이용자가 4를 입력할 때까지 while문을 반복함.
*             1을 입력하면 data1 파일의 데이터를 오름차순 정렬한 리스트를 출력함.
*             2를 입력하면 data1 파일의 데이터 중, Grade가 A인 학생 리스트를 출력함.
*             3을 입력하면 data1 파일과 data2 파일을 합친 후, Major가 CS인 학생 리스트를 출력함.
*             4를 입력하면 "프로그램을 종료합니다." 라는 문구와 함께 프로그램이 종료됨.
* Variables: insertNode - 링크드 리스트에 노드 삽입.
*            isEmpty - 링크드 리스트가 비어있는지 검사.
*            traverseList - 링크드 리스트의 노드 출력.
*            printListA - 링크드 리스트의 노드 중, Grade가 'A' 인 노드 출력.
*            printListCS - 링크드 리스트의 노드 중, Major가 "CS" 인 노드 출력.
**********************************************************
*/

#include <fstream>
#include "sll.cpp"
using namespace std;

int main()
{
    List l1;

    ifstream in, in1;
    in.open("data1.txt");
    in1.open("data2.txt");

    char data1[100];
    char data2[100];

    while (in.getline(data1, 100))
    {
      l1.insertNode(data1);
    }

    int menu = 1;

    while (menu != 4)
    {
      cout << "*********************" << endl;
      cout << "1. 오름차순 정렬 출력" << endl;
      cout << "2. A 성적 출력" << endl;
      cout << "3. CS 전공 출력" << endl;
      cout << "4. 프로그램 종료" << endl;
      cout << "*********************" << endl;
      cin >> menu;
      cout << endl;

      switch (menu)
      {
        case 1:
        {
          l1.traverseList();
          break;
        }
        case 2:
        {
          l1.printListA();
          break;
        }
        case 3:
        {
          while (in1.getline(data2, 100))
          {
            l1.insertNode(data2);
          }
          l1.printListCS();
          break;
        }
        case 4:
        {
          cout << "프로그램을 종료합니다." << endl;
          break;
        }
      }
    }
}
