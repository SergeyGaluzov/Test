#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream input;
	ofstream output;
	input.open("Input.txt");
	output.open("Output.txt");
	if (!input.is_open())
	{
		cout << "the input file can not be opened!";
	}
	else
	{
		string str;
		int index = 0;
		int num_str = 0;
		bool flag = false;
		while (!input.eof())
		{
			getline(input, str);
			char *temp = new char[str.length()];
			int *count_of_elements = new int[str.length()];
			for (int k = 0; k < str.length(); k++)
			{
				count_of_elements[k] = 0;
			}
			for (int i = 0; i < str.length(); i++)
			{
				if (isalpha(str[i]))
				{
					int j = 0;
					while (j != index)
					{
						if (temp[j] == str[i])
						{
							flag = true;
							break;
						}
						j++;
					}
					if (!flag)
					{
						temp[index] = str[i];
						count_of_elements[index]++;
						index++;
					}
					else
					{
						count_of_elements[j]++;
					}
				}
				else
				{
					if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
					{
						count_of_elements[index-1] += (str[i] - '0' - 1);
					}
				}
				flag = false;
			}
			for (int p = 0; p < index; p++)
			{
				output << temp[p] << ": " << count_of_elements[p] << ',' << " ";
				cout << temp[p] << ": " << count_of_elements[p] << ',' <<" ";
			}
			cout << endl;
			output << endl;
			index = 0;
		}
	}
	input.close();
	output.close();
}
