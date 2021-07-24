#ifndef READ_FROM_FILE_H
#define READ_FROM_FILE_H

#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class RFF
{
	vector< vector<double> > A;
public:
	RFF(int N)
	{
		A.resize(N);
		for (int i = 0; i < N; i++)
		{
			A[i].resize(N);
		}
	}
	void read_from_file(int &N);
	vector< vector<double>> get_A()
	{
		return A;
	}

};

#endif