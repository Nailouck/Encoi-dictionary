#include <iostream>
#include <string>
#include "Dictionary.h"
#include "convert.h"

node::node() {
	key = L"";
	value = L"";
}
dictionary::dictionary() : size(1), book(1) {}
dictionary::dictionary(int n) : size(n), book(std::vector<node>(n)) {}

void dictionary::fill() {
	for (int i = 0; i < size; i++) {
		std::wcin >> book[i].key;
		std::wcin >> book[i].value;
	}
}
void dictionary::print() {
	for (int i = 0; i < size; i++) {
		std::wcout << book[i].key << L" - ";
		std::wcout << book[i].value;
		std::wcout << L'\n';
	}
}
node dictionary::find(std::wstring k, size_t index) {
	for (size_t i = index; i < size; i++) {
		if (book[i].key.find(k) != book[i].key.npos) return book[i];
	}
	return node::node();
}
void dictionary::add(int n) {
	size += n;
	for (int i = 0; i < n; i++) {
		node new_node;
		book.push_back(new_node);
	}
}

bool node::is_empty() {
	return key == L"" && value == L"" ? true : false;
}

bool comparison(node* lhv, node* rhv) {
	return lhv->key.compare(rhv->key) == 0 && lhv->value.compare(rhv->value) == 0 ? true : false;
}