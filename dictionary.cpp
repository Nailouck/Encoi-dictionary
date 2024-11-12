#include <iostream>
#include <string>
#include <vector>
#include "dictionary.h"
#include "convert.h"
const std::wstring symb = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюяabçђmntropeēiīzyjȳgdkhčћsš'";
struct node {
	std::string key;
	std::wstring value;
	node() {
		key = " ";
		value = L" ";
	}
};
struct dictionary {
	std::vector<node> book;
	int size;
	dictionary() {
		size = 1;
		book = std::vector<node>(size);
		for (int i = 0; i < size; i++) {
			book[i].key = " ";
			book[i].value = L" ";
		}
	}
	dictionary(int n) {
		size = n;
		book = std::vector<node>(size);
		for (int i = 0; i < size; i++) {
			book[i].key = " ";
			book[i].value = L" ";
		}
	}
	void fill() {
		for (int i = 0; i < size; i++) {
			std::cin >> this->book[i].key;
			std::wcin >> this->book[i].value;
		}
	}
	void pop() {
		for (int i = 0; i < size; i++) {
			std::cout << this->book[i].key << " - ";
			std::wcout << this->book[i].value;
		}
	}
	std::wstring find(std::string k) {
		for (int i = 0; i < size; i++) {
			if (this->book[i].key == k)
				return this->book[i].value;
		}
	}
	void add(int n) {
		size += n;
		for (int i = 0; i < n; i++) {
			node new_node;
			book.push_back(new_node);
		}
	}
};
//переписать под вектор
//void book_init(dictionary *con) {
//	for (int i = 0; i < symb.length(); i++) {
//		con->book[i].key = to_six_symb(bin(i));
//		con->book[i].value = symb[i];
//	}
//}