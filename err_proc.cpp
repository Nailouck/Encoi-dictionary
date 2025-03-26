#include <iostream>

#include "err_proc.h"

void err_proc(Error* code) {
	switch (*code) {
	case OPERATION_OK:
		break;
	case FILE_NOT_DEFINED:
		std::wcout << L"Error! File is not defined!\n";
		exit(FILE_NOT_DEFINED);
	case OPERATION_FAILED:
		std::wcout << L"Error! Something's wrong. Error code 300.\n";
		break;
	case SRING_OUT_OF_RANGE:
		std::wcout << L"SRING OUT OF RANGE Error! Error code 200.\n";
		break;
	}
}