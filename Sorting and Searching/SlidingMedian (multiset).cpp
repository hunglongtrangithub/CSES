#include <iostream>
#include <set>
#include <vector>
using namespace std;

// We will use two multiset to store an bunch of numbers:
multiset<long> right_half; // contains the upper half of the elements
multiset<long> left_half; // contains the lower half of the elements  
/* 
The left half always has the same or one more element than the right half 
(right_half.size() <= left_half.size() && left_half.size() <= right_half.size() + 1), 
so the median is the largest element in the left half. 
*/

void add(long value) { // insert value into sets 
	// if value is greater than the largest element in the left half, it belongs to the right half
	if (*left_half.rbegin() < value) { 
		right_half.insert(value);
		if (right_half.size() > left_half.size()) { 
			// take the smallest element in the right half to the left half
			left_half.insert(*right_half.begin());
			right_half.erase(right_half.find(*right_half.begin()));
		}
	} else {
		left_half.insert(value);
		if (left_half.size() > right_half.size() + 1) {
			// take the largest element in the left half to the right half
			right_half.insert(*left_half.rbegin());
			left_half.erase(left_half.find(*left_half.rbegin()));
		}
	}
}
 
void remove(long value) { // erase from sets
	if (right_half.find(value) != right_half.end()) {
		right_half.erase(right_half.find(value));
		if (right_half.size() < left_half.size() - 1) {
			// take the largest element in the left half to the right half
			right_half.insert(*left_half.rbegin());
			left_half.erase(left_half.find(*left_half.rbegin()));
		}
	} else {
		left_half.erase(left_half.find(value));
		if (left_half.size() < right_half.size()) {
			// take the smallest element in the right half to the left half
			left_half.insert(*right_half.begin());
			right_half.erase(right_half.find(*right_half.begin()));
		}
	}
}
 
int main() {
	long n, k;
	cin >> n >> k;
	vector<long> x(n);
	for (long i = 0; i < n; i++) {
		cin >> x[i];
	}
	//the first median
	/* 
	the add() function only works when the left half has at least one element 
	(to make left_half.rbegin() exists), so we insert first element to the left half 
	*/
	left_half.insert(x[0]); 
	for (long i = 1; i < k; i++) { // insert first k - 1 elements
		add(x[i]);
	}
	cout << *left_half.rbegin() << " "; // first median
	/* 
	In case k = 1, right_half is empty, so we can't use right_half.begin() in the remove() function. 
	So we make a special case for k = 1 by printing x[i]. 
	*/
	// the rest of medians
	for (long i = k; i < n; i++) {
		if (k == 1) { 
			cout << x[i] << " ";
		} else {
			remove(x[i - k]);
			add(x[i]);
			cout << *left_half.rbegin() << " ";
		}
	}
	cout << endl;
}