#include <iostream>
#include <set>
#include <vector>
using namespace std;

// We will use two multiset to store an bunch of numbers:
multiset<long> right_half; // contains the upper half of the elements
multiset<long> left_half; // contains the lower half of the elements  
/* The left half always has the same or one more element than the right half 
(right_half.size() <= left_half.size() && left_half.size() <= right_half.size() + 1), 
so the median is the largest element in the left half. */
long min_cost = 0; // the minimum cost
/* The minimum cost is the difference between the sum of the lengths longer than the median and the sum of the lengths shorter 
than the median. In this prolem, we calculate the the minimum cost by taking the difference between the sum of the lengths 
in the left half and the sum of the lengths in the right half. This method holds true when k is even. But when k is odd, 
the median is the largest element in the left half, so we need to add the median to the minimum cost. */

void add(long value) { // insert value into sets 
	// if value is greater than the largest element in the left half, it belongs to the right half
	if (*left_half.rbegin() < value) { 
		min_cost += value; // add to right half -> min_cost increases
		right_half.insert(value);
		if (right_half.size() > left_half.size()) { 
			// take the smallest element in the right half to the left half and update min_cost
			min_cost -= 2 * *right_half.begin(); 
			left_half.insert(*right_half.begin());
			right_half.erase(right_half.find(*right_half.begin()));
		}
	} else {
		left_half.insert(value);
		min_cost -= value; // add to left half -> min_cost decreases
		if (left_half.size() > right_half.size() + 1) {
			// take the largest element in the left half to the right half and update min_cost
			min_cost += 2 * *left_half.rbegin();
			right_half.insert(*left_half.rbegin());
			left_half.erase(left_half.find(*left_half.rbegin()));
		}
	}
}
 
void remove(long value) { // erase from sets
	if (right_half.find(value) != right_half.end()) {
		right_half.erase(right_half.find(value));
		min_cost -= value; // remove from right half -> min_cost decreases
		if (right_half.size() < left_half.size() - 1) {
			// take the largest element in the left half to the right half and update min_cost
			min_cost += 2 * *left_half.rbegin();
			right_half.insert(*left_half.rbegin());
			left_half.erase(left_half.find(*left_half.rbegin()));
		}
	} else {
		left_half.erase(left_half.find(value));
		min_cost += value; // remove from left half -> min_cost increases
		if (left_half.size() < right_half.size()) {
			// take the smallest element in the right half to the left half and update min_cost
			min_cost -= 2 * *right_half.begin(); 
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
	// the first minimum cost
	/* the add() function only works when the left half has at least one element 
	(to make left_half.rbegin() exists), so we insert first element to the left half and update min_cost */
	left_half.insert(x[0]);
	min_cost -= x[0]; 
	for (long i = 1; i < k; i++) { // insert first k - 1 elements 
		add(x[i]);
	}
	cout << min_cost + (k % 2) * *left_half.rbegin() << " "; // if k is odd -> add median to min_cost
	/* In case k = 1, right_half is empty, so we can't use right_half.begin() in the remove() function.
	So we make a special case for k = 1 by printing the min_cost as 0. */
	// the rest of minimum costs
	for (long i = k; i < n; i++) {
		if (k == 1) { 
			cout << 0 << " ";
		} else {
			remove(x[i - k]);
			add(x[i]);
			cout << min_cost + (k % 2) * *left_half.rbegin() << " "; // if k is odd -> add median to min_cost
		}
	}
	cout << endl;
}