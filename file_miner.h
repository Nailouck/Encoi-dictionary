#pragma once

#include <fstream>

#include "Dictionary.h"
#include "err_proc.h"

void file_miner(std::string file_name, dictionary* dict, Error* code);