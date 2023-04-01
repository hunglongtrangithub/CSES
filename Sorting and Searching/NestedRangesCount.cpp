#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
 
// make a segment tree whose nodes store the total frequency of the elements in the subtree
/* 
This segment tree will be used to store the frequency of a right bound in a leaf node 
whose tree index corresponds to that right bound.
*/
struct node {
	// left child manages data from left to midpoint
	// right child manages data from midpoint + 1 to right
    long left, right, midpoint;
	node* left_child;
	node* right_child;
	node* parent;
	long freq; // stores the total frequency of the elements in the subtree
	node(long left, long right, node* parent) : left(left), right(right), midpoint((left + right) / 2), parent(parent) {
		if (left != right) {
			left_child = new node(left, midpoint, this);
			right_child = new node(midpoint + 1, right, this);
			freq = left_child->freq + right_child->freq;
		} else {
			freq = 0; // initialize to 0
		}
	}
	// this function adds the frequency of the given index by 1
	void add(long index) {
		if (index < left || index > right) {
	        return; // when the given index is outside the range of the current subtree
	    } else {
			freq++;
			if (left == right) {
				return; // when the current subtree is a leaf node
	    	} else if (index <= midpoint) {
	        	left_child->add(index);
			} else {
				right_child->add(index);
			}
		}
	}
	// this function returns the sum of all of the elements's occurences in the index range [left, right]
	long sum_of_freq(long left, long right) {
	    if (left > this->right || right < this->left) {
	        return 0; // when the given range is outside the range of the current subtree
	    } else if (left <= this->left && right >= this->right) {
	        return freq; // when the range of the current subtree is inside the given range
	    } else {
	        return left_child->sum_of_freq(left, right) + right_child->sum_of_freq(left, right);
	    }
	}
};
 
// define a custom function to compare in the sort() function
bool compare(const pair<pair<long, long>, long> &a, const pair<pair<long, long>, long> &b) {
    if (a.first.first == b.first.first) {
		//sort by right bound in descending order if left bounds are equal
        return a.first.second > b.first.second;
	}
    return a.first.first < b.first.first; // sort by left bound in ascending order
}
 
int main() {
    long n, left, right;
	cin >> n;
	vector<pair<pair<long, long>, long>> ranges(n); 
    vector<long> contains(n), contained(n), right_bound(n); // right_bound keeps the right bounds of the ranges
	for (int i = 0; i < n; i++) {
		cin >> left >> right;
		ranges[i] = {{left, right}, i};
		right_bound[i] = right;
	}
	sort(ranges.begin(), ranges.end(), compare);
	/* 
	map the right bounds to the indices in the tree
	by keeping only the unique elements in the right_bound vector and arrange them in ascending order 
	*/
	sort(right_bound.begin(), right_bound.end());
	vector<long>::iterator it = unique(right_bound.begin(), right_bound.end());
	right_bound.erase(it, right_bound.end());
	// contained
	node root_contained(0, right_bound.size() - 1, nullptr); 
	for (long i = 0; i < n; i++) {
		right = ranges[i].first.second;
		// map the right bound to the index of the leaf node in the tree
		long index = lower_bound(right_bound.begin(), right_bound.end(), right) - right_bound.begin();
		// count the number of right bounds included in the tree that are larger than the current right bound
		contained[ranges[i].second] = root_contained.sum_of_freq(index, right_bound.size() - 1);
		// include the current right bound to the tree
		root_contained.add(index);
	}
	// contains
	node root_contains(0, right_bound.size() - 1, nullptr);
	for (long i = n - 1; i >= 0; i--) {
		right = ranges[i].first.second;
		// map the right bound to the index of the leaf node in the tree
		long index = lower_bound(right_bound.begin(), right_bound.end(), right) - right_bound.begin();
		// count the number of right bounds included in the tree that are smaller than the current right bound
		contains[ranges[i].second] = root_contains.sum_of_freq(0, index);
		// include the current right bound to the tree
		root_contains.add(index);
	}
	for (long i : contains) {
		cout << i << " ";
	}
	cout << endl;
	for (long i : contained) {
		cout << i << " ";
	}
	return 0;
}