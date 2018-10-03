#include <iostream>
using namespace std;

int factorial(int num);
int main() {
  int num;

  cout << "Enter a number: " << endl;
  cin >> num;

  cout << factorial(num) << endl;

  return 0;
}

int factorial(int num) {
  if (num == 1) {
    return num;
  }
  else {
    return num * factorial(num-1);
  }
}
