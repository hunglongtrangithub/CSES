#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
 
//make a segment tree that contains consecutive numbers starting from 1 
struct node {
	// left child manages data from left to midpoint
	// right child manages data from midpoint+1 to right
    long left, right, midpoint;
	node* left_child;
	node* right_child;
	node* parent;
	long freq; // stores the total number of occurences of the elements in the subtree
	node(long left, long right, node* parent) : left(left), right(right), midpoint((left + right) / 2), parent(parent) {
		if (left != right) {
			left_child = new node(left, midpoint, this);
			right_child = new node(midpoint + 1, right, this);
			freq = left_child->freq + right_child->freq;
		} else {
			freq = 0;
		}
	}
	//this function updates the frequency of the given value in the tree
	void update(long value) {
		if (value < left || value > right) {
	        return; //when the given value is outside the range of the current node
	    }
	    if (left == right) {
	        freq++;
	    } else {
			if (value <= midpoint) {
	        	left_child->update(value);
			} else {
				right_child->update(value);
			}
	    	freq = left_child->freq + right_child->freq;
		}
	}
 
	//this function returns the sum of all of the elements's occurences in the range [left, right]
	int sum(long left, long right) {
	    if (left > this->right || right < this->left) {
	        return 0; //when the given range is outside the range of the current node
	    } else if (left <= this->left && right >= this->right) {
	        return freq; //when the range of the current node is inside the given range
	    } else {
	        return left_child->sum(left, right) + right_child->sum(left, right);
	    }
	}
};
 
//define a custom function to compare in the sort() function
bool compare(const pair<pair<long, long>, long> &a, const pair<pair<long, long>, long> &b) {
    if (a.first.first == b.first.first) {
        return a.first.second > b.first.second;
	}
    return a.first.first < b.first.first;
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
	/* map the right bounds to the numbers in the node 
	by keeping only the unique elements in the right_bound vector and arrange them in ascending order */
	sort(right_bound.begin(), right_bound.end());
	vector<long>::iterator it = unique(right_bound.begin(), right_bound.end());
	right_bound.erase(it, right_bound.end());
	//contained
	node root_contained(0, right_bound.size() - 1, nullptr); 
	for (long i = 0; i < n; i++) {
		right = ranges[i].first.second;
		long index = lower_bound(right_bound.begin(), right_bound.end(), right) - right_bound.begin();
		contained[ranges[i].second] = root_contained.sum(index, right_bound.size() - 1);
		root_contained.update(index);
	}
	//contains
	node root_contains(0, right_bound.size() - 1, nullptr);
	for (long i = n - 1; i >= 0; i--) {
		right = ranges[i].first.second;
		long index = lower_bound(right_bound.begin(), right_bound.end(), right) - right_bound.begin();
		contains[ranges[i].second] = root_contains.sum(0, index);
		root_contains.update(index);
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