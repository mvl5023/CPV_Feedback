#include "zaberx.h"
#include "Arduino.h"


double p[] = { 0,  0.0235, 0.0470, 0.0705, 0.0940, 0.117,  0.141,  0.164,  0.188,  0.211,  0.235,  0.258,  0.282,  0.305,
0.329,  0.352,  0.376,  0.399,  0.423,  0.446,  0.470,  0.493,  0.517,  0.540,  0.564,  0.587,  0.611,  0.634,
0.658,  0.681,  0.705,  0.728,  0.752,  0.775,  0.799,  0.822,  0.846,  0.869,  0.893,  0.916,  0.940 };

double q[] = { 0,  0.132,  0.264,  0.397,  0.529,  0.662,  0.795,  0.928,  1.06, 1.20, 1.33, 1.46, 1.60, 1.74, 1.87, 2.01,
2.15, 2.29, 2.42, 2.57, 2.71, 2.85, 2.99, 3.14, 3.28, 3.43, 3.58, 3.73, 3.89, 4.05, 4.21, 4.37, 4.53, 4.69,
4.86, 5.04, 5.21, 5.39, 5.57, 5.76, 5.96 };


int readAnalog(int analogPin, int iterations)
{
	long volTemp = 0;
	for (int i = 0; i < iterations; i++)
	{
		volTemp += analogRead(analogPin);
	}
	int voltage = volTemp / iterations;
	return voltage;
}

long mm(float mmValue)
{
	long dataValue;
	dataValue = mmValue / mmResolution;
	return dataValue;
}

long um(float umValue)
{
	long dataValue;
	dataValue = umValue / umResolution;
	return dataValue;
}

double interp1(double input)
{
	double out;
	int i = 0;
	while (input >= p[i])
	{
		i++;
	}
	out = q[i - 1] + ((input - p[i - 1]) / (p[i] - p[i - 1])) * (q[i] - q[i - 1]);
	return out;
}