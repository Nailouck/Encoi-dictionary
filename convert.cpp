#include <string>
#include "convert.h"
std::string reverse(std::string s) {
	std::string res;
	for (int i = res.length() - 1; i != 0; i--) {
		res += s[i];
	}
	return res;
}
std::string bin(int n) {
	std::string res;
	while (n > 0) {
		int k = n % 2;
		if (k) res += '1';
		else res += '0';
		n = int(n / 2);
	}
	return reverse(res);
}
std::string to_six_symb(std::string s) {
	std::string res;
	for (int i = 0; i < 6 - s.length(); i++) {
		res += '0';
	}
	return res + s;
}
