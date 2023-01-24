#include <iostream>
#include <vector>
using namespace std;

vector<long> information; // stores the actual array with our data in
vector<long> results;

//make a segment tree that contains numbers from 1 to n
// This segment tree will be used to represent the children by their indices in the tree
struct node {
	// left child manages data from left to midpoint
	// right child manages data from midpoint + 1 to right
	long left, right, midpoint;
	node* left_child;
	node* right_child;
	node* parent;
	long count; // stores the number of elements in the subtree
	node(long left, long right, node* parent) : left(left), right(right), midpoint((left + right) / 2), parent(parent) {
		if (left != right) {
			left_child = new node(left, midpoint, this);
			right_child = new node(midpoint + 1, right, this);
			count = left_child->count + right_child->count;
		} else { 
			count = 1; 
		}
	}

	/* this function "deletes" index'th element (0-INDEXED) in the subtree 
	by deleting 1 from the count of along nodes in the path
	and returns the value of the found element */
	void del(long index) {
		if (count < index) {
			return; // when the index is out of range
		} else {
			count--;
			if (left == right) {
				results.push_back(information[left]); // this is the element we want to save in the result
			} else if (left_child->count > index) {
				left_child->del(index);
			} else {
				right_child->del(index - left_child->count);
			}
		}
	}
};

int main() {
	long n, k;
	cin >> n >> k;
	information.resize(n);
	for (long i = 0; i < n; i++) {
        information[i] = i + 1;
	}
	node root(0, n - 1, nullptr);
	long p = k % n; //When k is larger than n, skipping k children is the same as skipping k % n children
	while (n > 0) {
		root.del(p);
        n--;
        if (n > 0) {
            p = (p + k) % n;
		}
	}
	for (long i : results) {
		cout << i << " ";
	}
	return 0;
}