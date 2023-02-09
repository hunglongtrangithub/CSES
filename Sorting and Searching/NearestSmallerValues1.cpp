#include <iostream>
#include <utility>
#include <stack>
using namespace std;
 
int main() {
    long n, x;
    cin >> n;
    stack<pair<long, long>> s; // stack of pairs of (value, index)
    /* For each number, pop all elements in the stack that are greater than or equal to it 
    and push the current element into the stack. This means that the elements in the stack 
    at any given time are in descending order from top to bottom.
    If the next number is smaller than the top element, then it is also smaller than all 
    the elements that have been popped from the stack, so we don't need to check them and 
    only need to check the ones that are currently in the stack by popping them one by one
    until we find the element that is smaller than the current number. That element is the
    nearest smaller element. If the stack is empty, then there is no smaller element.
    The time complexity is O(n) because each element is pushed and popped at most once. */
    for (long i = 0; i < n; i++) {
        cin >> x;
        // pop all elements that are greater than or equal to x
        while (!s.empty() && s.top().first >= x) {
            s.pop();
        }
        // if the stack is empty, then there is no smaller element
        if (s.empty()) {
            cout << 0 << " ";
        } else {
            cout << s.top().second << " "; // the index of the nearest smaller element
        }
        s.push({x, i + 1}); // push the current element into the stack
    }
    /* We can also use a vector instead of a stack to store the elements in the stack, and
    use push_back and pop_back instead of push and pop. The time complexity is still O(n). */ 
    return 0;
}