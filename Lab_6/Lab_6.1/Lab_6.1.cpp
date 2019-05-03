#include "pch.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

vector<int> GetVectorWithRandomNums(int elemsCount) {
	vector<int> v;
	for (int i = 0; i < elemsCount; i++)
	{
		v.push_back(rand() % 100);
	}
	return v;
}

void PrintVector(vector<int> v) {
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int LinearSearch(vector<int> v, int num) {
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == num)
		{
			return i;
		}
	}
	return -1;
}

int BinarySearch(vector<int> vec, int num) {
	int min = 0;
	int max = vec.size() - 1;

	while (min <= max)
	{
		int mid = (min + max) / 2;

		if (vec[mid] > num)
		{
			max = mid - 1;
		}
		else if (vec[mid] < num)
		{
			min = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int CahrsSearch(string word, string chars) {
	int wordLength = int(word.length());
	int charsLength = int(chars.length());

	for (int i = 0; i <= wordLength - charsLength; i++)
	{
		for (int j = 0; j < charsLength && word[i + j] == chars[j]; j++)
		{
			if (j + 1 == charsLength)
			{
				return i;
			}
		}
	}
	return -1;
};

int GetShift(string chars, int i) {
	int shift = 0, j;
	for (j = 1; j < i && chars[j] != chars[0]; j++);
	if (j < i)
	{
		int k = j;
		for (; k < i && chars[k] == chars[k - j]; k++);
		if (k == i)
		{
			shift = i - j;
		}
	}
	return shift;
};

vector<int> *GetKPMShift(string &img) {
	auto *shifts = new vector<int>();
	shifts->reserve(img.length());
	for (int i = 0; i < img.length(); i++) 
	{
		shifts->push_back((img[i] == img[0]) ? -1 : GetShift(img, i));
	}
	return shifts;
};

int kmp_search(string &str, string &img) {
	auto *shifts = GetKPMShift(img);
	int str_length = int(str.length()), img_length = int(img.length()), i = 0;
	while (i <= str_length - img_length) {
		int j = 0;
		for (; j < img_length && str[i + j] == img[j]; j++) {
			if (j + 1 == img_length) {
				return i;
			}
		}
		i += j - (*shifts)[j];
	}
	delete shifts;
	return -1;
};

map<char, int> *calculate_bm_shifts(string &img) {
	int img_length = int(img.length());
	auto *shifts = new map<char, int>();
	for (int i = 0; i < 256; i++) {
		shifts->insert(pair<char, int>(char(i), img_length));
	}
	for (int i = 0; i < img_length - 1; i++) {
		(*shifts)[img[i]] = img_length - i - 1;
	}
	return shifts;
};

int bm_search(string &str, string &img) {
	int str_length = int(str.length()), img_length = int(img.length());
	if (str_length < img_length) {
		return -1;
	}
	auto *shifts = calculate_bm_shifts(img);
	int i = img_length - 1, j = i, k = i;
	while (j >= 0 && i < str_length) {
		for (j = img_length - 1, k = i; j >= 0 && str[k] == img[j]; k--, j--);
		i += (*shifts)[str[i]];
	}
	delete shifts;
	return (k >= str_length - img_length) ? -1 : k + 1;
};

int main() {
	vector<int> vec = GetVectorWithRandomNums(30);
	PrintVector(vec);

	int num = 0;
	cout << "Search for : ";
	cin >> num;

	cout << "(linear search) Found on index : " << LinearSearch(vec, num) << endl;

	sort(vec.begin(), vec.end());
	PrintVector(vec);
	cout << "(binary search) Found on index : " << BinarySearch(vec, num) << endl;

	string word = "";
	cout << "Input word : ";
	cin >> word;

	string chars = "";
	cout << "Input chars : ";
	cin >> chars;

	cout << "(linear search) Chars found on : " << CahrsSearch(word, chars) << endl;

	cout << "(KMP search) Chars found on : " << kmp_search(word, chars) << endl;

	cout << "(BM search) Chars found on : " << bm_search(word, chars) << endl;
}