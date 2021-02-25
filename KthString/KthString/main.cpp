#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str;

bool compare(string a, string b)
{
	return a < b;
}

int main()
{
	vector<string> suffix;
	string a;
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
		// fill suffix
		str_len = str.size();
		for (int i = 0; i < str_len; i++)
		{
			for (int j = 1; i + j <= str_len; j++)
				suffix.push_back(str.substr(i, j));
		}
		sort(suffix.begin(), suffix.end(), compare);
		suffix.erase(unique(suffix.begin(), suffix.end()), suffix.end());
		if (num <= suffix.size())
		{
			cout << "#" << N << " " << suffix[num - 1];
			suffix.clear();
		}
		else
			cout << "#" << N << " " << "none" << endl;
	}
	return (0);
}
