#include "file_miner.h"
#include "err_proc.h"
#include "convert.h"
#include <iostream>
#include <string>

#define DEBUG_OUTPUT

void file_miner(std::string file_name, dictionary* dict, Error* code) { //считывание, конвертация, записывание значений в словарь 
	std::wifstream fin;
	fin.open(file_name);
	if (!fin.is_open()) {
		*code = FILE_NOT_DEFINED;
		return;
	}
	std::wstring str = L"";
	int j = 0;
	while (!fin.eof()) {
		getline(fin, str);
		std::wstring key = L"", value = L"";

		int i = 0;

		for (; str[i] != L'\t'; i++) {
			key += str[i];
		}

		i++;

		for (; i < str.length(); i++) {
			value += str[i];
		}

		if (j == dict->size) {
			dict->add(1);
		}

		dict->book[j].key = convert(key, code);
		if (*code == SRING_OUT_OF_RANGE) {
			std::wcout << L"Err\n";
			return;
		}

		dict->book[j].value = convert(value, code);
		if (*code == SRING_OUT_OF_RANGE) {
			std::wcout << L"Err\n";
			return;
		}

#ifdef DEBUG_OUTPUT
		std::wcout << dict->book[j].key << L" - " << dict->book[j].value << L"\n";
#endif

		j++;
	}
	fin.close();
}