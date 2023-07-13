#include <iostream>
using namespace std;
int countEmails(int n) {
    int memo[50 + 1];
    memo[0] = 1;
    memo[1] = 1;
    for (int i = 2; i <= 50; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
        cout<<memo[i]<<endl;
    }
    return memo[50];
}

int main() {
    int n = 50; // change this value to compute for different values of n
    cout << "Total number of ways of e-mail delivery for n=" << n << " is: " << countEmails(n) << endl;
    return 0;
}
