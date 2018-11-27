#include <math.h>

int relu(int x)
{
	return fmax(0, x);
}

int sigmoid(int x)
{
	return (1 / (1 + pow(M_E, x)));
}

int softplus(int x)
{
	return log(1 + pow(M_E, x));
}
