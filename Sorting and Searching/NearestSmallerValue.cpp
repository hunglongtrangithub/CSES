#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// make a segment tree that contain the maximum value of the numbers in the subtree
/* This segment tree will be used to store the array index of a number in a leaf node 
whose tree index corresponds to that number. */
struct node {
	// left child manages data from left to midpoint
	// right child manages data from midpoint + 1 to right
    long left, right, midpoint;
	node* left_child;
	node* right_child;
	node* parent;
	long maximum; // stores the largest value of the elements in the subtree
	node(long left, long right, node* parent) : left(left), right(right), midpoint((left + right) / 2), parent(parent) {
		if (left != right) {
			left_child = new node(left, midpoint, this);
			right_child = new node(midpoint + 1, right, this);
			maximum = max(left_child->maximum, right_child->maximum);
		} else {
			maximum = 0; // initialize to 0
		}
	}
	// this function updates the tree with the given value at the given index
	void update(long value, long index) {
		if (index < left || index > right) {
	        return; // when the given index is outside the range of the current subtree
	    }
	    if (left == right) {
	        maximum = value;
	    } else {
			if (index <= midpoint) {
	        	left_child->update(value, index);
			} else {
				right_child->update(value, index);
			}
	    	maximum = max(left_child->maximum, right_child->maximum);
		}
	}
    // this function returns the sum of all of the elements's occurences in the range [left, right]
	long max_in_range(long left, long right) {
	    if (left > this->right || right < this->left) {
	        return 0; // when the given range is outside the range of the current subtree
	    } else if (left <= this->left && right >= this->right) {
	        return maximum; // when the range of the current subtree is inside the given range
	    } else {
	        return max(left_child->max_in_range(left, right), right_child->max_in_range(left, right));
	    }
	}
};

int main() {
    long n;
    cin >> n;
    vector<long> array(n); // stores the input array and will be sorted
    vector<pair<long, long>> input(n); // stores the input array with its array indices (1-based)
    for (long i = 0; i < n; i++) {
        cin >> array[i];
        input[i] = {array[i], i + 1};
    }
    // map the numbers in the array to the indices in the tree by sorting the numbers 
    sort(array.begin(), array.end());
    node root(0, n - 1, nullptr);
    for (long i = 0; i < n; i++) {
        // find the index in the tree that corresponds to the current number
        long tree_index = lower_bound(array.begin(), array.end(), input[i].first) - array.begin();
        // update the tree with the array index of the current number
        root.update(input[i].second, tree_index); 
        // the nearest smaller value of the current number is the maximum value in the range [0, tree_index - 1]
        cout << root.max_in_range(0, tree_index - 1) << " "; 
    }
    return 0;
}