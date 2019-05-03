#include "pch.h"
#include <iostream>

using namespace std;

class ListElement {
private:
	int data = 0;

public:
	ListElement *prevoius = nullptr;
	ListElement *next = nullptr;

	ListElement(int newData) {
		this->data = newData;
	}

	int GetData() {
		return this->data;
	}

	void SetData(int newData) {
		this->data = newData;
	}
};

class List
{
private:
	ListElement *firstElement = nullptr;
	ListElement *lastElement = nullptr;

public:
	void PushElement(int data) {
		ListElement *elem = new ListElement(data);

		if (IsEmpty()) {
			firstElement = elem;
			lastElement = elem;
		}
		else
		{
			elem->prevoius = lastElement;
			lastElement->next = elem;
			lastElement = elem;
		}

		// cout << "Pushed element, data : " << elem->data << endl;
	}

	void PrintAllElements() {
		if (!IsEmpty()) {
			ListElement *elem = firstElement;
			int elemId = 0;

			while (elem->next != nullptr)
			{
				cout << "Turn element data [" << elemId << "] : " << elem->GetData() << endl;
				elemId++;
				elem = elem->next;
			}
			cout << "Turn element data [" << elemId << "] : " << elem->GetData() << endl;
		}
		else
		{
			cout << "No elements in turn" << endl;
		}
	}

	int DeleteElement(int id) {
		if (!IsEmpty()) {
			ListElement *elem = firstElement;
			int elemId = 0;

			if (elemId == id) {
				if (firstElement->next == nullptr) {
					firstElement = nullptr;
				}
				else {
					firstElement = elem->next;
				}

				return elem->GetData();
			}

			while (elem->next != nullptr)
			{
				if (elemId == id) {
					ListElement *elemPrevious = elem->prevoius;
					ListElement *elemNext = elem->next;
					elemPrevious->next = elemNext;
					elemNext->prevoius = elemPrevious;

					return elem->GetData();
				}

				elemId++;
				elem = elem->next;
			}

			if (elemId == id) {
				elem->prevoius->next = nullptr;

				return elem->GetData();
			}

			cout << "No element with this index  |  ";
		}
		else
		{
			cout << "No elements in turn" << endl;
		}

		return NULL;
	}

	int GetElementData(int id) {
		if (!IsEmpty()) {
			ListElement *elem = firstElement;
			int elemId = 0;

			while (elem->next != nullptr)
			{
				if (elemId == id) {
					return elem->GetData();
				}

				elemId++;
				elem = elem->next;
			}

			if (elemId == id) {
				return elem->GetData();
			}

			cout << "No element with this index  |  ";
		}
		else
		{
			cout << "No elements in turn" << endl;
		}

		return NULL;
	}

	void SetElementData(int id, int data) {
		if (!IsEmpty()) {
			ListElement *elem = firstElement;
			int elemId = 0;

			while (elem->next != nullptr)
			{
				if (elemId == id) {
					elem->SetData(data);
				}

				elemId++;
				elem = elem->next;
			}

			if (elemId == id) {
				elem->SetData(data);
			}
		}
	}

	int ListSize() {
		if (!IsEmpty()) {
			ListElement *elem = firstElement;
			int elemCount = 0;

			if (elem->next != nullptr) {
				elemCount++;
			}

			while (elem->next != nullptr)
			{
				elemCount++;
				elem = elem->next;
			}

			return elemCount;
		}
		else {
			return 0;
		}
	}

	bool IsEmpty() {
		if (firstElement == nullptr) {
			return true;
		}
		else
		{
			return false;
		}
	}
};

class OneDirListElement {
public:
	OneDirListElement *next = nullptr;
	int data = 0;

	OneDirListElement(int newData) {
		this->data = newData;
	}
};

class OneDirList {
private:
	OneDirListElement *firstElement = nullptr;

public:
	void PushElement(int data) {
		OneDirListElement *elem = new OneDirListElement(data);

		if (IsEmpty()) {
			firstElement = elem;
		}
		else
		{
			OneDirListElement *lastElem = firstElement;
			while (lastElem->next != nullptr)
			{
				lastElem = lastElem->next;
			}

			lastElem->next = elem;
		}

		// cout << "Pushed element, data : " << elem->data << endl;
	}

	void PrintAllElements() {
		if (!IsEmpty()) {
			OneDirListElement *elem = firstElement;
			int elemId = 0;

			while (elem->next != nullptr)
			{
				cout << "Turn element data [" << elemId << "] : " << elem->data << endl;
				elemId++;
				elem = elem->next;
			}
			cout << "Turn element data [" << elemId << "] : " << elem->data << endl;
		}
		else
		{
			cout << "No elements in turn" << endl;
		}
	}

	int DeleteElement(int id) {
		if (!IsEmpty()) {
			OneDirListElement *elem = firstElement;
			int elemId = 0;

			if (elemId == id) {
				if (firstElement->next == nullptr) {
					firstElement = nullptr;
				}
				else {
					firstElement = elem->next;
				}

				return elem->data;
			}

			while (elem->next != nullptr)
			{
				if (elemId-1 == id) {
					
					OneDirListElement *deletedElement = elem->next;
					int deletedData = deletedElement->data;
					elem->next = elem->next->next;
					delete(deletedElement);
					return deletedElement->data;
				}

				elemId++;
				elem = elem->next;
			}

			cout << "No element with this index  |  ";
		}
		else
		{
			cout << "No elements in turn" << endl;
		}

		return NULL;
	}

	int GetElementData(int id) {
		if (!IsEmpty()) {
			OneDirListElement *elem = firstElement;
			int elemId = 0;

			while (elem->next != nullptr)
			{
				if (elemId == id) {
					return elem->data;
				}

				elemId++;
				elem = elem->next;
			}

			if (elemId == id) {
				return elem->data;
			}

			cout << "No element with this index  |  ";
		}
		else
		{
			cout << "No elements in turn" << endl;
		}

		return NULL;
	}

	void SetElementData(int id, int data) {
		if (!IsEmpty()) {
			OneDirListElement *elem = firstElement;
			int elemId = 0;

			while (elem->next != nullptr)
			{
				if (elemId == id) {
					elem->data = data;
				}

				elemId++;
				elem = elem->next;
			}

			if (elemId == id) {
				elem->data = data;
			}
		}
	}

	int ListSize() {
		if (!IsEmpty()) {
			OneDirListElement *elem = firstElement;
			int elemCount = 0;

			if (elem->next != nullptr) {
				elemCount++;
			}

			while (elem->next != nullptr)
			{
				elemCount++;
				elem = elem->next;
			}

			return elemCount;
		}
		else {
			return 0;
		}
	}

	bool IsEmpty() {
		if (firstElement == nullptr) {
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	List *turn1 = new List();
	OneDirList *turn2 = new OneDirList();

	int listLength = 0;
	cout << "Input list length : ";
	cin >> listLength;

	for (int i = 0; i < listLength; i++)
	{
		int elemData = 0;
		cout << "Input list [" << i << "] : ";
		cin >> elemData;

		turn1->PushElement(elemData);

		int num = turn1->GetElementData(i);
		if (num % 2 == 0 && num != 0) {
			turn2->PushElement(num);
		}
	}

	turn1->PrintAllElements();
	cout << endl;
	turn2->PrintAllElements();

	int tmp;
	for (int i = 0; i < turn2->ListSize() - 1; ++i)
	{
		for (int j = 0; j < turn2->ListSize() - 1; ++j)
		{
			if (turn2->GetElementData(j + 1) < turn2->GetElementData(j))
			{
				tmp = turn2->GetElementData(j + 1);
				turn2->SetElementData(j + 1, turn2->GetElementData(j));
				turn2->SetElementData(j, tmp);
			}
		}
	}

	cout << endl;
	turn2->PrintAllElements();
}