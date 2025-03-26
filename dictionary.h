#pragma once

#include <vector>

class node {
public:
	std::wstring key;
	std::wstring value;
	node();
};
class dictionary {
public:
	std::vector<node> book;
	int size;

	dictionary();
	dictionary(int n);

	void fill();
	std::wstring find(std::wstring k);
	void add(int n);
	void print();
};