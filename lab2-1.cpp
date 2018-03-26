#include <iostream>
#include <fstream>
using namespace std;
const int m = 2;
const int n = 8;

int aArray[m + 1][n + 1] = {};
int bArray[m + 1][n + 1] = {};

void transpose(int aArray[][n + 1], int bArray[][n + 1]);

int main()
{
  ifstream in;
  int row, col, value, i;

  in.open("lab2-1.txt");

  for (i = 0; i < 9; i++)
  {
    in >> row >> col >> value;

    aArray[i][0] = row;
    aArray[i][1] = col;
    aArray[i][2] = value;

    cout << aArray[i][0] << " " << aArray[i][1] << " " << aArray[i][2] << endl;

  }
  cout << "\n";

  transpose(aArray, bArray);

  return 0;
}

void transpose(int aArray[][n + 1], int bArray[][n + 1])
{
  int i, j, currentb;

  bArray[0][0] = aArray[0][1];
  bArray[0][1] = aArray[0][0];
  bArray[0][2] = aArray[0][2];

  if (aArray[0][2] > 0)
  {
    currentb = 1;
    for (i = 0; i < aArray[0][1]; i++)
    {
      for (j = 1; j < aArray[0][2] + 1; j++)
      {
        if (aArray[j][1] == i)
        {
          bArray[currentb][0] = aArray[j][1];
          bArray[currentb][1] = aArray[j][0];
          bArray[currentb][2] = aArray[j][2];
          currentb++;
        }
      }
    }
  }
  for (int u = 0; u < 9; u++)
  {
    cout << bArray[u][0] << " " << bArray[u][1] << " " << bArray[u][2] << endl;
  }
}
