#pragma once

typedef enum {
	OPERATION_OK = 0,
	FILE_NOT_DEFINED = 100,
	SRING_OUT_OF_RANGE = 200,
	OPERATION_FAILED = 300
} Error;

void err_proc(Error* code);