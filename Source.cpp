#include <iostream>
#include <string>
#include <fcntl.h>
#include <io.h>
#include <fstream>
#include "convert.h"
#include "dictionary.h"
#include "file_miner.h"
#include "err_proc.h"

#define FILE_NAME "D:/resourses/small_book.txt"

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	dictionary a;
	Error* code = new Error;
	*code = OPERATION_FAILED;
	file_miner(FILE_NAME, &a, code);
	delete code;
	return 0;
}