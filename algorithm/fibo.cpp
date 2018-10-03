#include <iostream>
using namespace std;

int fibonacci(int num);
int main()
{
  int num;

  cout << "Enter a number: " << endl;
  cin >> num;

  if (num == 0 || num == 1) {
    cout << fibonacci(1);
  }
  else {
    cout << fibonacci(num); // num 값 출력
    for(int i = 0; i < num; i++) {
      cout << " " << fibonacci(i); // num까지의 값 출력
    }
  }
}

int fibonacci(int num) {
  if (num == 0) {
    return 1;
  }
  else if (num == 1) {
    return 1;
  }
  else {
    return (fibonacci(num-1) + fibonacci(num-2));
  }
}
