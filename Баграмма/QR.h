#ifndef _QR_H
#define _QR_H

#include "read_from_file.h"
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

class QR
{
private:
	vector<double> cs;
	vector< vector<double> > E;
	vector< vector<double> > R;
	vector< vector<double> > Q;
	vector< vector<double> > T;
	vector< vector<double> > TR;
	vector< vector<double> > QT;
	vector< vector<double> > QRR;
	vector< vector<double> > TrQ;
	vector< vector<double> > TestQ;
	void MultMatrix(vector<vector<double>>& A, vector<vector<double>>& B,
		vector<vector<double>>& AB, int& N);
	void transp(vector<vector<double>>& A, int& N);
	void inverse(vector<vector<double>>& A, int& N);
	void UpperTr(vector<vector<double>> A, int N);
	void show(vector<vector<double>> A, int N);
	vector<double> givensrotation(double& a, double& b);

public:	
	QR(int N)
	{
		cs.resize(2);
		E.resize(N);
		R.resize(N);
		Q.resize(N);
		T.resize(N);
		TR.resize(N);
		QT.resize(N);
		QRR.resize(N);
		TrQ.resize(N);
		TestQ.resize(N);
		for (int i = 0; i < N; i++)
		{
			E[i].resize(N);
			R[i].resize(N);
			Q[i].resize(N);
			T[i].resize(N);
			TR[i].resize(N);
			QT[i].resize(N);
			QRR[i].resize(N);
			TrQ[i].resize(N);
			TestQ[i].resize(N);

			for (int j = 0; j < N; j++)
			{
				E[i][i] = 1.0;
				Q[i][i] = 1.0;
				

			}
		}

	}
	void QRdec(int &N, RFF A);
	

};

#endif