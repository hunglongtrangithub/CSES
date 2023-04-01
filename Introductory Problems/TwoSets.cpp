#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long n;
    cin >> n;
    /*
    Let sum(s, e) = the sum of consecutive numbers from s to e.
    The sum of the first n positive integers is sum(1, n) = n * (n + 1) / 2.
    Each set must have the same sum, so the sum of a set is sum(1, n) / 2 = n * (n + 1) / 4.
    Because n * (n + 1) / 4 is an integer, n * (n + 1) must be a multiple of 4,
    which means n % 4 = 0 or 3. If n % 4 = 1 or 2, there is no solution.
    */
    if (n % 4 == 1 || n % 4 == 2) {
        cout << "NO";
    } else {
        cout << "YES" << endl;
        long k = (1 + sqrt(1 + 2 * n * (n + 1))) / 2; 
        /*
        k is the solution to the equation sum(1, k - 1) = sum(1, n) / 2 <=> (k - 1) * k / 2 = n * (n + 1) / 4.
        Because of the integer division, sum(1, k - 1) is not exactly equal to sum(1, n) / 2.
        Instead, sum(1, k - 1) <= sum(1, n) / 2 < sum(1, k). 
        Let s = sum(1, n) / 2 - sum(k + 1, n). We can rewrite s as:
        s = sum(1, n) / 2 - (sum(1, n) - sum(1, k)) = sum(1, k) - sum(1, n) / 2 > 0.
        Also, s = sum(1, k) - sum(1, n) / 2 = sum(1, k - 1) - sum(1, n) / 2 + k <= k.
        Therefore, s is a number from 1 to k.
        We can split the numbers 1, ..., n into two sets: 
        the first set consists of s and consecutive numbers from k + 1 to n, 
        and the second set consists of consecutive numbers from 1 to k except for s.
        This way, the sum of the first set is sum(1, n) / 2, and the sum of the second set is also sum(1, n) / 2.
        */
        long s = n * (n + 1) / 4 - (n - k) * (n - k + 1) / 2;
        // the first set consists of s and consecutive numbers from k + 1 to n 
        cout << n - k + 1 << endl;
        cout << s << " ";
        for (long i = k + 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl;
        cout << k - 1 << endl;
        // the second set consists of consecutive numbers from 1 to k except for s
        for (long i = 1; i <= k; i++) {
            if (i != s) {
                cout << i << " ";
            }
        }
    }
    return 0;
}