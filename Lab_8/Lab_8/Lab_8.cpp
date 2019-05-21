#include "pch.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void insertion_sort(vector<int> &nums) {
	int comparisons = 0, rearrangements = 0;
	for (int i = 1; i < nums.size(); i++) {
		int key = nums[i], j = i - 1;
		for (; j >= 0 && nums[j] > key; j--) {
			nums[j + 1] = nums[j];
			comparisons++;
			rearrangements++;
			cout << "Replaced : " << j + 1 << " & " << j << endl;
		}
		nums[j + 1] = key;
	}
}

void shifting_sort(vector<int> &nums) {
	int comparisons = 0, swaps = 0;
	for (int i = 1; i < nums.size(); i++) {
		for (int j = i - 1; j >= 0 && nums[j] > nums[j + 1]; j--) {
			swap(nums[j], nums[j + 1]);
			cout << "Swaped : " << j + 1 << " & " << j << endl;
			comparisons++;
			swaps++;
		}
	}
	// cout << "comparisons: " << comparisons << ", swaps: " << swaps << endl;
}

void selection_sort(vector<int> &nums) {
	int comparisons = 0, swaps = 0;
	for (int i = 0; i < nums.size() - 1; i++) {
		int min = i;
		for (int j = i + 1; j < nums.size(); j++) {
			comparisons++;
			if (nums[j] < nums[min]) {
				min = j;
			}
		}
		cout << "Min : " << min << endl;
		swap(nums[i], nums[min]);
		swaps++;
	}
	// cout << "comparisons: " << comparisons << ", swaps: " << swaps << endl;
}

void counting_sort(vector<int> &nums) {
	auto counts = vector<int>();
	auto max = (unsigned long)*max_element(nums.begin(), nums.end()) + 1;
	counts.reserve(max);
	for (int i = 0; i < max; i++) {
		counts.push_back(0);
	}
	for (int num : nums) {
		counts[num]++;
	}
	for (int i = 0, j = 0; i < max; i++) {
		for (int k = 0; k < counts[i]; k++) {
			nums[j++] = i;
		}
	}
	for (int i = 0; i < counts.size(); i++)
	{
		cout << " | Num : " << i << " times : " << counts[i] << endl;
	}
}

void bubble_sort(vector<int> &nums) {
	int comparisons = 0, swaps = 0;
	int n = int(nums.size()) - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			comparisons++;
			if (nums[j] > nums[j + 1]) {
				swap(nums[j], nums[j + 1]);
				cout << " | Swaped : " << j << " & " << j + 1 << endl;
				swaps++;
			}
		}
	}
}

vector<int> vector_get_random_numbers(int size, int maxRand = 100){
	cout << endl;
	vector<int> vec;
	for (int i = 0; i < size; i++)
	{
		vec.push_back(rand() % maxRand);
		cout << vec[i] << " ";
	}
	cout << endl;
	return vec;
}

void vector_print(vector<int> &vec) {
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vec;

	vec = vector_get_random_numbers(10);
	insertion_sort(vec);
	vector_print(vec);

	vec = vector_get_random_numbers(10);
	shifting_sort(vec);
	vector_print(vec);

	vec = vector_get_random_numbers(10);
	selection_sort(vec);
	vector_print(vec);

	vec = vector_get_random_numbers(10, 10);
	counting_sort(vec);
	vector_print(vec);

	vec = vector_get_random_numbers(10);
	bubble_sort(vec);
	vector_print(vec);
}