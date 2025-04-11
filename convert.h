#pragma once

#include "err_proc.h"
#include <string>

std::wstring get_six_symb(std::wstring str, int shift, Error* code);
bool is_latin(wchar_t symb);
std::wstring convert(std::wstring str, Error* code);
std::wstring decryption(std::wstring str, Error* code);