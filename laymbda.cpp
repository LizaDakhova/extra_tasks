#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v1, v2;
	for (int i = 0; i < 14; ++i)
		v1.push_back(int(i));
	for_each(v1.begin(), v1.end(), [& v2](const auto k) { v2.push_back(k); });
	for (int i = 0; i < v1.size(); ++i)
		cout << v1[i] << ' ';
	cout << endl;
	for (int i = 0; i < v2.size(); ++i) 
		cout << v2[i] << ' ';
	cout << endl;
	system("pause");
	return 0;
}