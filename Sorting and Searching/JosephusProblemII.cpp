#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node;

vector<int> information; // stores the actual array with our data in

vector<int> results;

//make a segment tree, time complexity is O(nlogn)
struct node {
	// left child manages data from left to midpoint
	// right child manages data from midpoint+1 to right
	int left, right, midpoint;
	node* left_child;
	node* right_child;
	node* parent;
	int count; // stores the number of elements in the subtree
	node(int left, int right, node* parent) : left(left), right(right), midpoint((left+right)/2), parent(parent) {
		if (left != right) {
			left_child = new node(left, midpoint, this);
			right_child = new node(midpoint+1, right, this);
			count = left_child->count + right_child->count;
		} else {
			count = 1;
		}
	}

	// this function deletes index'th element (0-INDEXED) in the subtree and also removes
	// one from the count
	void del(int index) {
		if (count < index) {
			throw std::runtime_error("Element doesn't exist");
		} else {
			count--;
			if (left == right) {
				results.push_back(information[left]);
			} else if (left_child->count > index) {
				left_child->del(index);
			} else {
				right_child->del(index - left_child->count);
			}
		}
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	information.resize(n);
	for (int i = 0; i < n; i++) 
        information[i] = i + 1;
	node root(0, n - 1, nullptr);
	int p = k % n; //When k is larger than n, skipping k children is the same as skipping k%n children
	while (n > 0) {
		root.del(p);
        n--;
        if (n > 0) 
            p = (p + k) % n;
	}
	for (int i = 0; i < results.size(); i++) {
		cout << results[i] << " ";
	}
}