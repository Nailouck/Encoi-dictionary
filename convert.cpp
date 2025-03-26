#include <string>
#include "convert.h"
#include <stdlib.h>
#include <cmath>

const std::wstring symb = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюяçђēīȳčћš";

int decima(int number) {
	int result = 0;
	for (int i = 0; number != 0; i++) {
		int digit = number % 10;
		number = (int)(number / 10);
		result += digit * (int)pow(2, i);
	}
	return result;
}


std::wstring get_six_symb(std::wstring str, int shift, Error* code) {
	std::wstring result = L"";
	if (str.length() < shift + 6) {
		*code = SRING_OUT_OF_RANGE;
		return L"";
	}
	for (int i = shift; i < shift + 6; i++) {
		result += str[i];
	}
	return result;
}

bool is_latin(wchar_t symb) {
	const std::wstring latin = L"abcdefghijklmnopqrstuvwxyz,';-(): ";

	for (int i = 0; i < latin.length(); i++) {
		if (symb == latin[i]) return true;
	}
	return false;
}

std::wstring decryption(std::wstring str, Error* code) {
	std::wstring result = L"";
	for (int i = 0; i < str.length(); i++) {
		if (is_latin(str[i])) {
			result += str[i];
		}
		else {
			std::wstring sextada = get_six_symb(str, i, code);
			if (*code == SRING_OUT_OF_RANGE) {
				return L"";
			}
			result += symb[decima(std::stoi(sextada))];
			i += 5;
		}
	}
	return result;
}

std::wstring convert(std::wstring str, Error* code) {
	str = decryption(str, code);
	if (*code == SRING_OUT_OF_RANGE) {
		return L"";
	}
	
	return str;
 }