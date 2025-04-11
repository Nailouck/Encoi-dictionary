#pragma once


#include <vector>

class node {
public:
	std::wstring key;
	std::wstring value;
	node();

	bool is_empty();
};
class dictionary {
public:
	std::vector<node> book;
	int size;

	dictionary();
	dictionary(int n);

	void fill();
	node find(std::wstring k, size_t index);
	void add(int n);
	void print();
};

bool comparison(node* lhv, node* rhv);