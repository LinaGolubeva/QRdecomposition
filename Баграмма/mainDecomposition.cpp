#include "read_from_file.h"
#include "QR.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	system("cls");
    
	int N=0;
A: 	
	cout<<"������� ������ �������: ";
	cin>>N;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(32767,'\n');
		cout<<endl<<"������! ��������� ���� �����:"<<endl<<endl;
		goto A;
	}
	
	else if(N!=5 && N!=6)
	{
		cout<<endl<<"������ ������������ ������ �������!"<<endl<<endl;
		goto A;
	}
	else
	{

	RFF A(N);
	A.read_from_file(N);
	QR B(N);
	B.QRdec(N, A);
	
	}

system("pause");
cin.get();
return 0;
}