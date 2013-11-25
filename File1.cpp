#include <vcl.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

struct tovr //Структура
{
 string tovar; //название товара
 int kol;
 int zk;
 int zen;  //цена
};



void sorttovar(tovr *tovrC, int n);    //Сортировка по товарам
void bol10(tovr *tovrC, int n,string zadanniitovar);// вывод с заданым названием
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
 if(n<=0)  //Проверяем ошибки при открытии
 {
  cout<<" kol < 0."<<endl;
  system("pause");
  return;
 }

 tovr *tovrC;  //Указатель на структуру
 tovrC=new tovr[n];


 ifstream in;  //Поток для чтения
 in.open("tovrC.txt",ios::in);  //Открываем файл для чтения

 if(in==NULL)  //Проверяем ошибки при открытии
 {
  cout<<" Ne udalos' otkryt' fajl."<<endl;
  system("pause");
  return;
 }

 for(int i=0;i<n;i++)  //Читаем из фалйа
 {
  in>>tovrC[i].tovar;
  in>>tovrC[i].kol;
  in>>tovrC[i].zk;
  tovrC[i].zen=tovrC[i].kol*tovrC[i].zk;
 }


 in.close();  //Закрываем поток
 cout<<endl;
 cout<<" Sortirovka po Alfavitu:"<<endl;
 sorttovar(tovrC,n);
 cout<<" Vivod s zadamin nazvaniem:"<<endl;
 zadaniiitovar(tovrC,n,zadanniitovar);
 cout<<endl;

 delete[] tovrC;  //Освобождаем память

 system("pause");
}



void sorttovar(tovr *tovrC, int n)  //Сортировка по названиею
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




void bol10(tovr *tovrC, int n,string zadanniitovar) // Вывод с заданым название
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

void zadaniiitovar(tovr *tovrC, int n,string zadanniitovar) // Вывод с заданым название
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
void sortSr(tovr *tovrC, int n)  //Сортировка по среднему баллу
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





