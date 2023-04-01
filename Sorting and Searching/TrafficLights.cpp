#include <iostream>
#include <set>
#include <vector>
using namespace std;
 
int main() {
	long n, x, p;
	cin >> x >> n;
	vector<long> input(n); // stores the positions of the traffic lights in the order of the input
	vector<long> output(n); // stores the largest distance between two consecutive traffic lights in the order of the input
	set<long> lights{0, x}; // stores the positions of the traffic lights and the ends of the road
	// insert along of the traffic lights 
	for (long i = 0; i < n; i++) {
		cin >> p;
		input[i] = p;
		lights.insert(p);
	}
	// find the largest distance between two consecutive traffic lights 
	long max = 0;
	set<long>::iterator it = lights.begin();
	it++;
	long prev = 0; // stores the position of the traffic light right before the current one
	for (set<long>::iterator i = it; i != lights.end(); i++) {
		if (max < *i - prev) 
			max = *i - prev;
		prev = *i;
	}
	// assign that value to the last element of the output array
	output[n - 1] = max; 
	/* 
	We remove the traffic lights from the set in the reverse order compared to the input
	and update the largest distance between two consecutive traffic lights to the output array 
	*/
	for (long i = n - 1; i > 0; i--) {
		lights.erase(input[i]);
		set<long>::iterator it = lights.upper_bound(input[i]);
		long right_light = *it;
		it--;
		long left_light = *it;
		if (right_light - left_light > output[i])
			output[i - 1] = right_light - left_light;
		else 
			output[i - 1] = output[i];
	}
	for (long i : output) {
		cout << i << ' ';
	}
	return 0;
}