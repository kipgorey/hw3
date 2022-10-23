#include "stack.h"

#include <iostream>
#include <string>


using namespace std;




int main()
{


  Stack<int> test;
  Stack<string> test2;

  test.push(5);
  test.push(3);
  test.push(1);

  while(!test.empty())
  {
    cout << test.top() << endl;
    test.pop();
  }

  test2.pop();

  return 0;
}