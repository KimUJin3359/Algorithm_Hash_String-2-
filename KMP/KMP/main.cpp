#include <iostream>
#include <string>
using namespace std;

int main()
{
	char str[] = "ABC ABCDAB ABCDABCDABDE";
	char find[] = "ABCDABD";
	int str_len = strlen(str);
	int find_len = strlen(find);
	int *pi_table;
	int pi_i = 0, pi_j = 1;

	//make_pi table
	pi_table = new int[find_len];
	pi_table[0] = -1;
	pi_table[1] = 0;
	while (pi_j < find_len - 1)
	{
		if (pi_table[pi_j])
		{
			if (find[pi_i + pi_table[pi_j]] == find[pi_j])
			{
				pi_table[pi_j + 1] = pi_table[pi_j] + 1;
				pi_j++;
			}
			else
			{
				if (find[pi_i] == find[pi_j])
					pi_table[++pi_j] = 1;
				else
					pi_table[++pi_j] = 0;
			}
		}
		else
		{
			if (find[pi_i] == find[pi_j])
				pi_table[++pi_j] = 1;
			else
				pi_table[++pi_j] = 0;
		}
	}
	
	//find word
	int i = 0;
	int flag = 0;

	while (i <= str_len - find_len)
	{
		int j;

		for (j = 0; j < find_len; j++)
		{
			if (str[i + j] != find[j])
				break;
		}
		if (j == find_len)
		{
			flag = 1;
			break;
		}
		i += j - pi_table[j];
	}
	if (flag)
		cout << "find : " << i << endl;
	else
		cout << "find : -1" << endl;
	return (0);
}