#include "stdafx.h"
#include "20200504lib.h"

int factorial(int n) {
	if (n >= 20 || n<=0) {
		return -1;
	}
	if (n == 1) {
		return 1;
	}
	else {
		return n*factorial(n - 1);
	}
}

float FAC::convert(float deg) {
	float hudu = 3.14 / 180 * deg;
	return hudu;
}
