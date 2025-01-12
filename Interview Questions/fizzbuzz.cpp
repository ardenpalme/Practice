#include<iostream>

using namespace std;

void fizzBuzz(int n) {
    for(int i=1; i<=n; i++) 
    {
        if(i % 5 == 0){
            if(i % 3 == 0) {
                cout << "FizzBuzz" << endl;
            }else{
                cout << "Buzz" << endl;
            }
        }else{
            if(i % 3 == 0) {
                cout << "Fizz" << endl;
            }else{
                cout << i << endl;
            }
        }
    }
}

int main()
{
    fizzBuzz(15);
    return 0;
}
