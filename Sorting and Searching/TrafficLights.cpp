#include <iostream>
#include <set>
#include <vector>
#define ll long long

using namespace std;

int main() {
	ll n, x, p;
	cin >> x >> n;
	vector<ll> input(n);
	set<ll> s;
	s.insert(0);
	s.insert(x);
	for (int i = 0; i < n; i++) {
		cin >> p;
		input[i] = p;
		s.insert(p);
	}
	ll max = 0, prev = 0;
	set<ll>::iterator it = s.begin();
	it++;
	for (set<ll>::iterator i = it; i != s.end(); i++) {
		if (max < *i - prev) 
			max = *i - prev;
		prev = *i;
	}
	vector<ll> output(n);
	output[n - 1] = max;
	for (int i = n - 1; i > 0; i--) {
		s.erase(input[i]);
		set<ll>::iterator it = s.upper_bound(input[i]);
		ll a = *it;
		it--;
		ll b = *it;
		if (a - b > output[i])
			output[i - 1] = a - b;
		else 
			output[i - 1] = output[i];
	}
	for (int i = 0; i < n; i++) 
		cout << output[i] << ' ';
}