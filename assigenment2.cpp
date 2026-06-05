#include<cmath>
#include <string>
#include <iostream>
using namespace std;

int sumOfSquares(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}
int main() {
    int result = sumOfSquares(5);
    cout << "The sum of squares from 1 to 5 is " << result << endl;
    return 0;
}


