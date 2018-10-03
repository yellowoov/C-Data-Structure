#include <iostream>
using namespace std;

int gcd(int num1, int num2);
int main() {

  int num1, num2, temp;

  cout << "Enter a number1: " << endl;
  cin >> num1;

  cout << "Enter a number2: " << endl;
  cin >> num2;

  if (num1 > num2) {
    temp = num1;
    num1 = num2;
    num2 = temp;
  }

  cout << gcd(num1, num2) << endl;

  return 0;

}

int gcd(int num1, int num2) {
  if (num1 == 0) {
    return num2;
  }
  else {
    return gcd(num2 % num1, num1);
  }
}
