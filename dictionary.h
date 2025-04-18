#pragma once


#include <vector>

class node {
public:
	std::wstring key;
	std::wstring value;
	int relevance;
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
	void add(int n);
	void print();
};

node find(std::wstring k, node rhv);

bool comparison(node* lhv, node* rhv);