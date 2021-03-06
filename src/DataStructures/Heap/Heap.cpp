// Heap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


template<typename T>
class Heap {
	vector<T> v;
public:
	Heap() {
		v.push_back(-1);
	}
	T extractMin() {
		
		if (v.size() <= 1)
			throw "Error, no more items left in heap";
		T min = v[1];
		T toreplace = v[v.size() - 1];
		
		v.pop_back();
		if (v.size() > 1) {
			v[1] = toreplace;
			sink(1);
		}
		return min;
	}

	T min() {
		if (v.size() <= 1){
			throw "Error, no more items left in heap";
		}

		return v[1];
	}

	void swim(int index) {
		while (index > 1) {
			int parent = floor(index / 2);
			if (v[index] < v[parent]) {
				swap(v[index], v[parent]);
				index = parent;
			}
			else {
				break;
			}
		}
	}

	void sink(int index) {
		int c = 2 * index;
		while (c < v.size()) {
			if (c < (v.size() -1) && v[c] > v[c + 1]) {
				c++;
			}
			if (v[index] > v[c]) {
				swap(v[index], v[c]);
				index = c;
			}
			else {
				break;
			}
		}
	}

	void push_back(T item) {
		v.push_back(item);
		swim(v.size() - 1);
	}

	T deleteitem(int index) {
		if (index == 0 || index >= v.size())
			throw "Invalid";

		T deleted = v[index];
		T toreplace = v[v.size() - 1];
		v.pop_back();
		
		if (v.size() == 1)
			return deleted;
		
		v[index] = toreplace;
		sink(index);
		return deleted;
	}

	void print() {
		for (auto item : v) {
			cout << item << ' ';
		}
		cout << endl;
	}

	int length() {
		return v.size() - 1;
	}

	void printOrderddAndClear() {
		while (v.size() > 1) {
			cout << extractMin() << ' ';
		}
		cout << endl;
	}

};


int main()
{
	Heap<int> h;
	int c, i;
	cout << "  Enter choice and number, enter -1 to exit \r\n   1 to insert \r\n   2 to extract min \r\n   3 to just show min \r\n   4 to delete" << endl;
	cin >> c >> i;
	while (i != -1) {
		if (c == 1) {
			h.push_back(i);
			
		}
		else if (c == 2) {
			if (h.length() >= 1) {
				cout << "Extracted " << h.extractMin() << endl;
			}
		}
		else if (c == 4) {
			if (i <= h.length()) {
				h.deleteitem(i);
			}
		}
		if (h.length() >= 1) {
			cout << "Cur Min: " << h.min() << endl;
		}
		else {
			cout << "Heap empty" << endl;
		}
		cout << "  Enter choice and number, enter -1 to exit \r\n   1 to insert \r\n   2 to extract min \r\n   3 to just show min \r\n   4 to delete" << endl;
		cin >> c >> i;
	}
	h.printOrderddAndClear();
	return 0;
}

