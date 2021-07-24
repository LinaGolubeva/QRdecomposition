#include "read_from_file.h"

void ::RFF::read_from_file(int &N)
{
	ifstream ff;

	if(N==5)
		ff.open("A5.txt");
    if(N==6)
		ff.open("A6.txt");

	cout<<endl;
	cout<<"Матрица А:"<<endl;

	if(!ff)
	{
		cout<<"Ошибка при чтении файла!"<<endl;
	}

	double u=0;

	
	bool end=false;
	for(int i=0; i<N; i++)
	{
		
		for(int j=0; j<N; j++)
		{
			ff>>u;
			if(!end)
				A[i][j]=u;
			if( ff.eof() )
				end=true;
		}
	}
	ff.close();

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout<<setw(2)<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}