#include <iostream>
#include <fstream>
using namespace std;
const int m = 2;
const int n = 8;

void transpose(int aArray[m + 1][n + 1], int bArray[m + 1][n + 1]);

int main()
{
  ifstream in;
  int row, col, value, i;

  int aArray[m + 1][n + 1];
  int bArray[m + 1][n + 1];

  in.open("lab2-1.txt");

  for (i = 0; i < 9; i++)
  {
    in >> row >> col >> value;

    aArray[0][i] = row;
    aArray[1][i] = col;
    aArray[2][i] = value;

    cout << aArray[0][i] << " " << aArray[1][i] << " " << aArray[2][i] << endl;
  }

  cout << "\n";

  transpose(aArray, bArray);

  return 0;
}

void transpose(int aArray[m + 1][n + 1], int bArray[m + 1][n + 1])
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
      for (j = 0; j <= aArray[0][2]; j++)
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
    cout << bArray[0][u] << " " << bArray[1][u] << " " << bArray[2][u] << endl;
  }
}
