#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char str[512];

bool compare(int a, int b)
{
	return (strcmp((str + a), (str + b)) <= 0);
}

int main()
{
	vector<int> suffix;
	int C;
	int num;
	int str_len;

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C;

	for (int N = 1; N <= C; N++)
	{
		cin >> num;
		cin >> str;
		strcat(str, "$");
		// fill suffix
		str_len = strlen(str);
		for (int i = 0; i < str_len; i++)
			suffix.push_back(i);
		sort(suffix.begin(), suffix.end(), compare);
		cout << "#" << N << " ";
		for (int i = suffix[num]; str[i] != '$'; i++)
			cout << str[i];
		cout << endl;
		suffix.clear();
	}
	return (0);
}
