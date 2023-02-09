#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// make a segment tree whose nodes store the total frequency of the elements in the subtree
/* This segment tree will be used to store the frequency of a number in a leaf node 
whose tree index corresponds to that number.*/
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
	// this function adds the frequency of the given index in the tree by 1
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
	// this function deletes the frequency of the given index in the tree by 1
	void del(long index) {
		if (index < left || index > right) {
	        return; // when the given index is outside the range of the current subtree
	    } else {
			if (freq > 0) {
				freq--;
			} else {
				return; 
			}
			if (left == right) {
				return; // when the current subtree is a leaf node
	    	} else if (index <= midpoint) {
	        	left_child->del(index);
			} else {
				right_child->del(index);
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
	// this function returns the kth smallest element in the index range [left, right]
	long kth_smallest(long left, long right, long k) {
	    if (left > this->right || right < this->left || k > this->freq) {
			/* when the given range is outside the range of the current subtree 
			or k is greater than the total frequency of the elements in the range */
	        return 0; 
	    } else if (this->left == this->right) {
	        return this->left; // when the range of the current subtree is a single element
		} else {
	        long left_sum = left_child->sum_of_freq(left, right);
	        if (k <= left_sum) {
	            return left_child->kth_smallest(left, right, k);
	        } else {
	            return right_child->kth_smallest(left, right, k - left_sum);
	        }
	    }
	}
};

int main() {
	long n, k;
	cin >> n >> k;
	vector<long> x(n); // stores the input numbers
	vector<long> array(n); // stores input numbers and will be used to map the numbers to the indices in the tree
	for (long i = 0; i < n; i++) {
		cin >> x[i];
		array[i] = x[i];
	}
	/* map the numbers in the array to the indices in the tree
	by keeping only the unique elements in the array vector and arrange them in ascending order */
	sort(array.begin(), array.end());
	cout << endl;
	vector<long>::iterator it = unique(array.begin(), array.end());
	array.erase(it, array.end());
	node root(0, n - 1, nullptr);
	for (long i = 0; i < k; i++) {
		long index = lower_bound(array.begin(), array.end(), x[i]) - array.begin();
		root.add(index);
	}
	cout << array[root.kth_smallest(0, n - 1, (k + 1) / 2)] << " ";
	for (long i = k; i < n; i++) {
		long index1 = lower_bound(array.begin(), array.end(), x[i]) - array.begin();
		root.add(index1);
		long index2 = lower_bound(array.begin(), array.end(), x[i - k]) - array.begin();
		root.del(index2);
		cout << array[root.kth_smallest(0, n - 1, (k + 1) / 2)] << " ";
	}
	return 0;
}