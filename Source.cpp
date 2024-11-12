#include <iostream>
#include <string>
#include <fcntl.h>
#include <io.h>
#include "convert.h"
#include "dictionary.h"


int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	return 0;
}