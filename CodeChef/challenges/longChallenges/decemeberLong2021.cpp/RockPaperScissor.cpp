problem link:- https://www.codechef.com/problems/ROPASCI/

solution:-
#include <bits/stdc++.h>
using namespace std;

map<char, char> who_beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};

int main() {
	int t;
	cin >> t;
	while (t--) {

		int n;
		string s;
		cin >> n >> s;

		map<char, int> ind = {{'R', -1}, {'P', -1}, {'S', -1}};
		string ans(n, '?');

		for (int i = n - 1; i >= 0; i--) {
			int indwb = ind[who_beats[s[i]]];
			if (indwb == -1) ans[i] = s[i];
			else ans[i] = ans[indwb];
			ind[s[i]] = i;
		}

		cout << ans << '\n';
	}
}
