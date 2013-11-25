#include <vcl.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

struct tovr //���������
{
 string tovar; //�������� ������
 int kol;
 int zk;
 int zen;  //����
};



void sorttovar(tovr *tovrC, int n);    //���������� �� �������
void bol10(tovr *tovrC, int n,string zadanniitovar);// ����� � ������� ���������
void zadaniiitovar(tovr *tovrC, int n,string zadanniitovar);
void main()
{

 int n;
 string zadanniitovar;
 cout<<" Kol tovarov :   ";
 cin>>n;
 cout<<endl;
 cout<<" nyznii tovar : ";
 cin>>zadanniitovar;
 cout<<endl;
 if(n<=0)  //��������� ������ ��� ��������
 {
  cout<<" kol < 0."<<endl;
  system("pause");
  return;
 }

 tovr *tovrC;  //��������� �� ���������
 tovrC=new tovr[n];


 ifstream in;  //����� ��� ������
 in.open("tovrC.txt",ios::in);  //��������� ���� ��� ������

 if(in==NULL)  //��������� ������ ��� ��������
 {
  cout<<" Ne udalos' otkryt' fajl."<<endl;
  system("pause");
  return;
 }

 for(int i=0;i<n;i++)  //������ �� �����
 {
  in>>tovrC[i].tovar;
  in>>tovrC[i].kol;
  in>>tovrC[i].zk;
  tovrC[i].zen=tovrC[i].kol*tovrC[i].zk;
 }


 in.close();  //��������� �����
 cout<<endl;
 cout<<" Sortirovka po Alfavitu:"<<endl;
 sorttovar(tovrC,n);
 cout<<" Vivod s zadamin nazvaniem:"<<endl;
 zadaniiitovar(tovrC,n,zadanniitovar);
 cout<<endl;

 delete[] tovrC;  //����������� ������

 system("pause");
}



void sorttovar(tovr *tovrC, int n)  //���������� �� ���������
{
 string min;
 tovr Buf;
 int minI;

 for(int i=0;i<n;i++)
 {
  min=tovrC[i].tovar;
  minI=i;
  for(int j=i;j<n;j++)
  {
   if(strcmp(tovrC[j].tovar.c_str(),min.c_str())<0)
   {
	min=tovrC[j].tovar;
	minI=j;
   }
  }
  Buf=tovrC[i];
  tovrC[i]=tovrC[minI];
  tovrC[minI]=Buf;
 }
 cout<<"---------------------------------------------------------------------------------"<<endl;
 cout<<"    tovar   "<<"  Kol  "<<"  zen za schtuky  "<<"  obscay stoimostoimostb  "<<endl;
 cout<<"---------------------------------------------------------------------------------"<<endl;
 for(int i=0;i<n;i++)
 {
  cout<<setw(11)<<tovrC[i].tovar<<setw(11)<<tovrC[i].kol<<setw(11)<<tovrC[i].zk<<setw(11)<<tovrC[i].zen<<endl;
  }
  cout<<endl;
}




void bol10(tovr *tovrC, int n,string zadanniitovar) // ����� � ������� ��������
{
 int i;
 bool flag;
 flag=false;
 for(i=0;i<n;i++)
		 {
		   if (tovrC[i].kol >10 && (flag==false)) {
			 flag=true;
		   }
		 }
		if (flag==false) {
		 cout<<" Net tovara bolee 10"<<endl;
				}
  if (flag==true){

 cout<<"--------------------------------"<<endl;
 cout<<"    tovar   "<<endl;
 cout<<"--------------------------------"<<endl;
 for(i=0;i<n;i++){
 if (tovrC[i].kol>10){
 cout<<setw(11)<<tovrC[i].tovar<<endl;
 }
 }
										}
  }

void zadaniiitovar(tovr *tovrC, int n,string zadanniitovar) // ����� � ������� ��������
{
 int i;
 bool flag;
 flag=false;
 for(i=0;i<n;i++)
		 {
		   if (tovrC[i].tovar==zadanniitovar && (flag==false)) {
			 flag=true;
		   }
		 }
		if (flag==false) {
		 cout<<" Net tovara s dannim nazvaniem"<<endl;
				}
  if (flag==true){

 cout<<"--------------------------------"<<endl;
 cout<<"    tovar   "<<"  Kol  "<<"  zen za schtuky  "<<"  obscay stoimostoimostb  "<<endl;
 cout<<"--------------------------------"<<endl;
 for(i=0;i<n;i++){
 if (tovrC[i].tovar == zadanniitovar){
 cout<<setw(11)<<tovrC[i].tovar<<setw(11)<<tovrC[i].kol<<setw(11)<<tovrC[i].zk<<setw(11)<<tovrC[i].zen<<endl;
 }
 }
										}
  }
void sortSr(tovr *tovrC, int n)  //���������� �� �������� �����
{
 tovr Buf;
 float min,b;
 int minI;
 for(int i=0;i<n;i++)
 {
  min=tovrC[i].zk;
  minI=i;
  for(int j=i;j<n;j++)
  {
   if(tovrC[j].zk<min)
   {
	minI=j;
	min=tovrC[j].zk;
   }
  }
  b=tovrC[i].zk;
  tovrC[i].zk=tovrC[minI].zk;
  tovrC[minI].zk=b;
  Buf=tovrC[i];
  tovrC[i]=tovrC[minI];
  tovrC[minI]=Buf;
 }
 cout<<"---------------------------------------------------------------------------------"<<endl;
 cout<<"    tovar   "<<"  Kol  "<<"  zen za schtuky  "<<"  obscay stoimostoimostb  "<<endl;
 cout<<"---------------------------------------------------------------------------------"<<endl;
 for(int i=0;i<n;i++)
 {
	cout<<setw(11)<<tovrC[i].tovar<<setw(11)<<tovrC[i].kol<<setw(11)<<tovrC[i].zk<<setw(11)<<tovrC[i].zen<<endl;
  }
  cout<<endl;
}





