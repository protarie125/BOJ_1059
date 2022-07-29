#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	auto l = int{};
	cin >> l;

	auto v = vector<int>(l);
	for (auto i = 0; i < l; ++i) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	auto n = int{};
	cin >> n;

	auto b = int{ -1 };
	for (auto i = 0; i < l; ++i) {
		if (v[i] < n) {
			b = i;
		}
		else if (v[i] == n) {
			b = -2;
			break;
		}
		else {
			break;
		}
	}

	if (-2 == b) {
		cout << 0;
		return 0;
	}

	if (-1 == b) {
		auto left = n - 1;
		auto right = v[b + 1] - n - 1;

		cout << left + right + left * right;

		return 0;
	}

	auto left = n - v[b] - 1;
	auto right = v[b + 1] - n - 1;

	cout << left + right + left * right;

	return 0;
}