#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> arr;
map<string, int> match;

bool compare(string a, string b)
{
	return match[a] < match[b];
}
int main()
{
	int C;
	int num;
	string input;
	match["ZRO"] = 0; match["ONE"] = 1; match["TWO"] = 2; match["THR"] = 3; match["FOR"] = 4;
	match["FIV"] = 5; match["SIX"] = 6; match["SVN"] = 7; match["EGT"] = 8; match["NIN"] = 9;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C;
	for (int N = 1; N <= C; N++)
	{
		cin >> input;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			cin >> input;
			arr.push_back(input);
		}
		sort(arr.begin(), arr.end(), compare);
		cout << "#" << N << endl;
		for (int i = 0; i < arr.size(); i++)
			cout << arr[i] << " ";
		cout << endl;
		arr.clear();
	}
	return (0);
}