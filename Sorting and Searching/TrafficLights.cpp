#include <iostream>
#include <set>
#include <vector>
#define ll long long
using namespace std;
 
int main() {
	ll n, x, p;
	cin >> x >> n;
	vector<ll> input(n); // stores the positions of the traffic lights in the order of the input
	vector<ll> output(n); // stores the largest distance between two consecutive traffic lights in the order of the input
	set<ll> lights{0, x}; // stores the positions of the traffic lights and the ends of the road
	// insert all of the traffic lights 
	for (int i = 0; i < n; i++) {
		cin >> p;
		input[i] = p;
		lights.insert(p);
	}
	// find the largest distance between two consecutive traffic lights 
	ll max = 0;
	set<ll>::iterator it = lights.begin();
	it++;
	ll prev = 0; // stores the position of the traffic light right before the current one
	for (set<ll>::iterator i = it; i != lights.end(); i++) {
		if (max < *i - prev) 
			max = *i - prev;
		prev = *i;
	}
	// assign that value to the last element of the output array
	output[n - 1] = max; 
	/* we remove the traffic lights from the set in the reverse order compared to the input
	and update the largest distance between two consecutive traffic lights to the output array */
	for (int i = n - 1; i > 0; i--) {
		lights.erase(input[i]);
		set<ll>::iterator it = lights.upper_bound(input[i]);
		ll right_light = *it;
		it--;
		ll left_light = *it;
		if (right_light - left_light > output[i])
			output[i - 1] = right_light - left_light;
		else 
			output[i - 1] = output[i];
	}
	for (int i = 0; i < n; i++) 
		cout << output[i] << ' ';
}