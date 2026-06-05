
#include <iostream>
#include <cmath>
#include<string>
#include <iostream>
using namespace std;

int doubleGame(int num) {
    return num * 2;
}

int main() {
    for (int i = 1; i <= 5; i++) {
        cout << "Double of " << i << " is " << doubleGame(i) << endl;
    }
    return 0;
}
