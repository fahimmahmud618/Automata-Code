#include<iostream>
#include<string>
#include<fstream>
#include<set>
#include<algorithm>
#include<cctype>
using namespace std;

#define MAX 100

string grammer[MAX][MAX];
int num_of_production;


string concat_two_string(string a, string b)
{
	string temp_string = a;
	for (int i = 0; i < b.length(); i++)
		if (temp_string.find(b[i]) > temp_string.length())
			temp_string += b[i];
	return temp_string;
}


string ret_combination_two_string(string a, string b)
{
	string pri, ret_string = "";
	for (int i = 0; i < a.length(); i++)
		for (int j = 0; j < b.length(); j++)
		{
			pri = "";
			pri = pri + a[i] + b[j];

			for (int j = 0; j < num_of_production; j++)
			{
				for (int k = 1; grammer[j][k] != ""; k++)
				{
					if (grammer[j][k] == pri)
					{
						ret_string = concat_two_string(ret_string, grammer[j][0]);
					}
				}
			}
		}
	return ret_string;
}

int main()
{
	int i, pt, j, l, k;
	string a, str, r, pr, start = "S";
	char buff[100];
	num_of_production = 0;
	bool prod_found=false;


	ifstream ifile("c1.txt");


	while (ifile.getline(buff, 99))
	{
		a = buff;
		if (a.find("PRODUCTIONS:") < a.length())
		{
			prod_found=true;
			break;
		}
	}

	if(!prod_found)
	{
		cout<<"Unable to read production rules! Terminating the program\n";
		ifile.close();
		system("pause");
		return 1;
	}

	while (ifile.getline(buff, 99)) {
		a = buff;
		a.erase(remove_if(a.begin(), a.end(), ::isspace), a.end());
		a.erase(remove(a.begin(), a.end(), ';'), a.end());
		pt = a.find("->");

		//left side of production
		grammer[num_of_production][0] = a.substr(0, pt);
		a = a.substr(pt + 2, a.length());
		//right side of production
		for (j = 0; a.length()!=0; j++)
		{
			int i = a.find("|");
			if (i > a.length())
			{
				grammer[num_of_production][j + 1] = a;
				a = "";
			}
			else
			{
				grammer[num_of_production][j + 1] = a.substr(0, i);
				a = a.substr(i + 1, a.length());
			}
		}

		num_of_production++;
	}
	ifile.close();

	string table[MAX][MAX], st;
	set<string> strings;

	ifstream ifile1("c2.txt");

	while (ifile1.getline(buff, 999)) {
		str = buff;
		strings.insert(str);
	}
	ifile1.close();

	//For each string read from strings file
	for (set<string>::iterator it = strings.begin(); it != strings.end(); ++it) {
		str = *it;

		//Assigns values to principal diagonal of matrix
		for (i = 0; i < str.length(); i++)
		{
			r = "";
			st = "";
			st += str[i];

			for (j = 0; j < num_of_production; j++)
			{
				for (k = 1; grammer[j][k] != ""; k++)
				{
					if (grammer[j][k] == st)
					{
						r = concat_two_string(r, grammer[j][0]);
					}
				}
			}
			table[i][i] = r;
		}

		//Assigns values to upper half of the matrix
		for (k = 1; k < str.length(); k++)
		{
			for (j = k; j < str.length(); j++)
			{
				r = "";
				for (l = j - k; l < j; l++)
				{
					pr = ret_combination_two_string(table[j - k][l], table[l + 1][j]);
					r = concat_two_string(r, pr);
				}
				table[j - k][j] = r;
			}
		}


		//Prints the matrix
		for (i = 0; i < str.length(); i++)
		{
			k = 0;
			l = str.length() - i - 1;
			for (j=l; j<str.length(); j++)
			{
				cout << "     " << table[k++][j] << " ";
			}
			cout << endl;
		}


		//Checks if last element of first row contains a Start variable
		if (table[0][str.length() - 1].find(start) <= table[0][str.length() - 1].length())
			cout << "The string is a part of the Language\n";
		else
			cout << "The string is not a part of the Language\n";
	}

	system("pause");
	return 0;
}
