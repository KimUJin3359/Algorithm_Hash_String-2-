#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int hash_max = 1;
map<int, vector<int>> hash_table;

int make_hash(char str[], int len, int before_hash = 0)
{
	int hash_v = 0;

	if (before_hash == 0)
	{
		for (int i = 0; i < len; i++)
		{
			hash_v *= 2;
			hash_v += str[i];
		}
	}
	else
	{
		hash_v = before_hash - str[-1] * hash_max;
		hash_v *= 2;
		hash_v += str[len - 1];
	}
	return (hash_v % 65521);
}

int main()
{
	char str[] = "ABC ABCDAB ABCDABCDABDE";
	char find[] = "ABCDABD";
	int str_len = strlen(str);
	int f_len = strlen(find);
	string sub;
	int find_hash;
	int before_hash = 0;
	
	for (int i = 0; i < f_len - 1; i++)
		hash_max *= 2;
	
	//find hash
	find_hash = make_hash(find, f_len, 0);
	for (int i = 0; i <= str_len - f_len; i++)
	{
		before_hash = make_hash(str + i, f_len, before_hash);
		hash_table[before_hash].push_back(i);
	}

	//match hash
	if (hash_table[find_hash].size() == 0)
		cout << "find : -1" << endl;
	//only one
	else if (hash_table[find_hash].size() == 1)
		cout << "find : " << hash_table[find_hash][0] << endl;
	//duplicate
	else
	{
		for (int i = 0; i < hash_table[find_hash].size(); i++)
		{
			int j;

			for (j = 0; j < f_len; j++)
			{
				if (str[hash_table[find_hash][i] + j] != find[j])
					break;
			}
			if (j == f_len)
			{
				cout << "find : " << hash_table[find_hash][j] << endl;
				break;
			}
		}
	}
	return (0);
}