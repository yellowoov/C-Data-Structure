#include <iostream>
#include "sll.h"
using namespace std;

#define MAX 6
#define VISITED 2
#define ADJACENCY 1

int matrix[MAX][MAX] =
{{0,1,1,0,0,0},
{1,0,1,1,0,0},
{1,1,0,0,0,1},
{0,1,0,0,1,1},
{0,0,0,1,0,1},
{0,0,1,1,1,0}};

int visited[MAX];
char vc[MAX + 1] = {"012345"};

void dfs(int num);
void print();

int main()
{
  print();
  dfs(0);
}

void dfs(int num)
{
  visited[num] = 1;
  List l0, l1, l2, l3, l4, l5;

  for (int i = 0; i < MAX; i++)
  {
    if (!visited[i] && matrix[num][i] == ADJACENCY)
    {
      visited[i] = VISITED;
      cout << "V" << vc[num] << "에서 " << "V" << vc[i] << "로" << endl;
      dfs(i);
    }
  }
}

void print()
{
  for (int i = 0; i < MAX; i++)
  {
    cout << "V" << i << ": ";
    for (int j = 0; j < MAX; j++)
    {
      if (matrix[i][j] == ADJACENCY)
      {
        cout << j << " ";
      }
    }
    cout << endl;
  }
  cout << endl;
}
