#include <iostream>
#include <string>
#include "dictionary.h"

	node::node() {
		key = L" ";
		value = L" ";
	}
	dictionary::dictionary(): size(1), book(1) {}
	dictionary::dictionary(int n): size(n), book(std::vector<node>(n)) {}

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
	std::wstring dictionary::find(std::wstring k) {
		auto it = std::find_if(book.begin(), book.end(), [k](const auto& item) { return item.key == k; });
		
		return it == book.end() ? L"" : it->value; 
	}
	void dictionary::add(int n) {
		size += n;
		for (int i = 0; i < n; i++) {
			node new_node;
			book.push_back(new_node);
		}
	}