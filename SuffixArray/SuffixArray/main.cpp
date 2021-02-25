#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char str[] = "banana$";

bool compare(int a, int b)
{
	return (strcmp((str + a), (str + b)) <= 0);
}

int main()
{
	vector<int> suffix;
	vector<int> lcp;
	vector<int>::iterator iter;
	
	// fill suffix
	int str_len = strlen(str);
	for (int i = 0; i < str_len; i++)
		suffix.push_back(i);
	sort(suffix.begin(), suffix.end(), compare);
	// fill lcp
	lcp.push_back(0);
	for (int i = 0; i < suffix.size() - 1; i++)
	{
		int j;
		for (j = 0; j < str_len; j++)
		{
			if (j + suffix[i] >= str_len ||
				j + suffix[i + 1] >= str_len)
				break;
			if (str[j + suffix[i]] != str[j + suffix[i + 1]])
				break;
		}
		lcp.push_back(j);
	}
	for (int i = 0; i < suffix.size(); i++)
		cout << suffix[i] << " ";
	cout << endl;
	for (int i = 0; i < lcp.size(); i++)
		cout << lcp[i] << " ";
	cout << endl;
	return (0);
}
