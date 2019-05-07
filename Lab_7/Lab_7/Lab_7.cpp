#include "pch.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
#include <algorithm>

using namespace std;

int KMPSearch(string str, string word) {
	if (str.length() > word.length())
	{
		int i = 0;
		while (i < str.length())
		{
			cout << "| I:" << setw(2) << i << " | ";
			if (str[i] == word[0])
			{
				int j = 1;
				int firstMatchIndex = 0;

				while (str[i + j] == word[j] && j <= word.length())
				{
					cout << "J:" << setw(2) << j << " | ";

					if (j == word.length() - 1)
					{
						cout << "match" << " | " << endl;
						return i;
					}

					if (str[i + j] == word[0] && firstMatchIndex == 0)
					{
						firstMatchIndex = j;
					}

					j++;
				}

				if (firstMatchIndex != 0)
				{
					cout << "add index:" << setw(2) << firstMatchIndex << " | ";
					i += firstMatchIndex;
				}
				else
				{
					i += j + 1;
				}
			}
			else
			{
				i++;
			}
			cout << endl;
		}
	}
	return -1;
}

int BMSearch(string str, string word) {
	if (str.length() > word.length())
	{
		map<char, int> wordMap;
		cout << "Word hash : ";
		for (int i = 0; i < word.length() - 1; i++)
		{
			int index = word.length() - 2 - i;
			if (wordMap[word[index]] == NULL)
			{
				wordMap[word[index]] = i + 1;
				cout << word[index] << " : " << wordMap[word[index]] << " | ";
			}
		}
		if (wordMap[word[word.length() - 1]] == NULL)
		{
			wordMap[word[word.length() - 1]] = word.length();
			cout << word[word.length() - 1] << " : " << wordMap[word[word.length() - 1]] << " | ";
		}
		cout << endl;

		int indexToCompare = word.length() - 1;
		while (indexToCompare < str.length())
		{
			cout << "| I:" << setw(2) << indexToCompare << " | ";

			if (str[indexToCompare] == word[word.length() - 1])
			{
				int j = 1;
				while (str[indexToCompare - j] == word[word.length() - 1 - j])
				{
					cout << "J:" << setw(2) << j << " | ";
					if (j == word.length() - 1)
					{
						cout << "match" << " | " << endl;
						return indexToCompare - j;
					}
					j++;
				}
				indexToCompare += wordMap[str[indexToCompare]] + j;
			}
			else
			{
				if (wordMap[str[indexToCompare]] != NULL)
				{
					indexToCompare += wordMap[str[indexToCompare]];
				}
				else
				{
					indexToCompare += word.length();
				}
			}
			cout << endl;
		}
	}
	return -1;
}

int main()
{
	string word = "";
	cout << "Input word : ";
	getline(cin, word);
	cout << "             ";
	for (int i = 0; i < word.length(); i++)
	{
		cout << i % 10;
	}
	cout << endl << endl;

	string chars = "";
	cout << "Input chars : ";
	getline(cin, chars);
	cout << "              ";
	for (int i = 0; i < chars.length(); i++)
	{
		cout << i % 10;
	}
	cout << endl << endl;

	cout << "(KMP search) Chars found on : " << KMPSearch(word, chars) << endl << endl;
	cout << "(BM search) Chars found on : " << BMSearch(word, chars) << endl;
}
