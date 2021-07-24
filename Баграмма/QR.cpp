#include "QR.h"

void ::QR::QRdec(int& N, RFF A)
{
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			R[i][j] = A.get_A()[i][j];
		}

	}
	for(int i=0; i<=N-2; i++)	
	{
		for(int j=N-1; j>=i+1; j--)
		{   

			for (int k = 0; k < N; k++)
			{
				for (int t = 0; t < N; t++)
				{
					T[k][t] = E[k][t];
					
				}
			}
			cs = givensrotation(R[j - 1][i], R[j][i]);

			T[j-1][j-1] = cs[0];
			T[j-1][j] = -cs[1];
			T[j][j-1] = cs[1];
			T[j][j] = cs[0];

			MultMatrix(Q,T,QT,N);

			transp(T,N);
			MultMatrix(T,R,TR,N);

			for (int k = 0; k < N; k++)
			{
				for (int t = 0; t < N; t++)
				{
					R[k][t]  = TR[k][t];
					Q[k][t]  = QT[k][t];
					TR[k][t] = 0.0;
					QT[k][t] = 0.0;
				}
			}

		}
	}
	cout<<"Матрица R:"<<endl<<endl;
	show(R,N);
	cout<<"Матрица Q:"<<endl<<endl;
	show(Q,N);

	cout<<"Контроли вычислений:"<<endl<<endl;

	cout<<"1) Проверка для матрицы R:"<<endl<<endl
		<<"Матрица R должна быть верхнетреугольной "<<endl<<endl;
	UpperTr(R,N);
	cout<<endl;
	show(R,N);

	cout<<"2)Проверка для матрицы Q:"<<endl<<endl
		<<"Q^T * Q = E, где E - единичная матрица"<<endl<<endl
		<<"Q^T * Q = "<<endl<<endl;

	transp(Q,N);
     for (int k = 0; k < N; k++)
		for (int t = 0; t < N; t++)
			TrQ[k][t]  = Q[k][t];
			
   transp(Q,N);
   MultMatrix(TrQ,Q,TestQ,N);
   show(TestQ,N);

	cout<<"3)Проверка правильности решения:"<<endl<<endl
		<<"Q * R = A, где A - искомая матрица"<<endl<<endl
		<<"Q * R = "<<endl<<endl;	
	MultMatrix(Q,R,QRR,N);
	show(QRR,N);
	cout<<"Искомая матрица:"<<endl;
	show(A.RFF::get_A(),N);

	ofstream tfQ("Q.txt");
    ofstream tfR("R.txt");
	if(!tfQ || !tfR)
	{
		cout<<"Ошибка при записи в файл!"<<endl;
	}


	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			tfQ<<setw(15)<<Q[i][j]<<"";
			tfR<<setw(15)<<R[i][j]<<"";
		}
		tfQ<<endl;
	    tfR<<endl;
	}

	tfQ.close();
	tfR.close();
}

void ::QR::MultMatrix(std::vector<vector<double> >& A, std::vector<vector<double> >& B,
	std::vector<vector<double> >& AB, int& N)
{
	double EPS = 0.00001;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				AB[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (abs(AB[i][j]) < EPS)
				AB[i][j] = 0.0;
		}
	}

}

void ::QR::transp(std::vector<vector<double> >& A, int& N)
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			swap(A[j][i], A[i][j]);
		}
	}
}

void ::QR::inverse(std::vector<vector<double> >& A, int& N)
{
	double temp = 0.0;

	vector< vector<double> > E;
	E.resize(N);
	for (int i = 0; i < N; i++)
	{
		E[i].resize(N);
		for (int j = 0; j < N; j++)
		{
			E[i][i] = 1.0;
		}
	}


	for (int k = 0; k < N; k++)
	{
		temp = A[k][k];

		for (int j = 0; j < N; j++)
		{
			A[k][j] /= temp;
			E[k][j] /= temp;
		}

		for (int i = k + 1; i < N; i++)
		{
			temp = A[i][k];
			for (int j = 0; j < N; j++)
			{
				A[i][j] -= A[k][j] * temp;
				E[i][j] -= E[k][j] * temp;
			}

		}
	}

	for (int k = N - 1; k > 0; k--)
	{
		for (int i = k - 1; i >= 0; i--)
		{
			temp = A[i][k];
			for (int j = 0; j < N; j++)
			{
				A[i][j] -= A[k][j] * temp;
				E[i][j] -= E[k][j] * temp;
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A[i][j] = E[i][j];
}

void ::QR::UpperTr(std::vector<vector<double> > A, int N)
{
	int answer = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[i][j] != 0)
				answer = 0;
		}
	}

	if (answer == 1)
		cout << "Матрица верхнетреугольная" << endl;
	else
		cout << "Матрица не верхнетреугольная" << endl;
}

void ::QR::show(std::vector<vector<double> > A, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << setw(15) << A[i][j] << " ";
		}
		cout << endl;
	}
	cout<<endl;
}
vector<double> QR::givensrotation(double &a, double &b)
{
	double r = 0.0;
	vector<double> cs;
	cs.resize(2);

	if (b == 0)
	{
		cs[0] = 1;
		cs[1] = 0;
	}
	else if (abs(b) > abs(a))
	{
		r = a / b;
		cs[1] = 1 / sqrt(1 + r * r);
		cs[0] = cs[1] * r;
	}
	else
	{
		r = b / a;
		cs[0] = 1 / sqrt(1 + r * r);
		cs[1] = cs[0] * r;
	}
	return cs;

}
