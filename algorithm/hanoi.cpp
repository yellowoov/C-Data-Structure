#include <iostream>
using namespace std;

int count;
int hanoi(int num);

int main() {
  int num;

  cout << "Enter a number: " << endl;
  cin >> num;

  cout << hanoi(num) << "회 이동하였습니다." << endl;
}

int hanoi(int num) {
  if (num == 1) {
    count++;
    return 0;
  }
  hanoi(num - 1);
  count++;
  hanoi(num - 1);

  return count;
}
