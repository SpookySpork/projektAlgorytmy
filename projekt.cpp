#include <iostream>
using namespace std;
#include <ctime>
#include <iomanip>
#include <limits>
#include <chrono>
using namespace std::chrono;
int *Tab;

void GetRandomNumbers(int n)
{//losuje elementy do tablicy
	srand(time(NULL));
	for(int i=0; i<n;i++){
		Tab[i]=rand()%(n-1)+1;//losuje liczby od 1 do n-2(rand()%(n) zaczyna losowanie od 0, stad powiekszenie wylosowanej liczby o 1)
		cout<<Tab[i]<<" ";//wypisuje wylosowane elementy
	}
	cout<<endl;
}

void GetNumbersFromUser(int n)
{//elementy do tablicy przypisuje uzytkownik
	int number;
	for(int i=0; i<n; i++)
	{
		cout<<"Podaj odpowiednia liczbe(od 1 do "<<n-1<<")"<<endl;
		cin>>number;
		while(number>=n||number<1){//jezeli zle podano liczbe, uzytkownik musi podac ja ponownie
			cout<<"zle podano liczbe, podaj jeszcze raz"<<endl;
			cin>>number;
		}
		Tab[i]=number;
	}
}

void BruteForce(int n)
{//pierwszy algorytm
	bool* L = new bool[n];//tablica zawierajaca wartosc na indeksie n rowna true, jesli liczba n sie powtarza 
	for(int i=0; i<n; i++)
	{
		L[i]=false;//poczatkowo wszystkie elementy tablicy L sa rowne false	
	}
	
	for(int i=0; i<n-1; i++)//sprawdzam kazdy element z tablicy Tab(nie sprawdzam ostatniego elementu przez i, jest ono sprawdzane przez t. Jezeli i=n, j=n+1, co wychodzi poza wartosc tablicy)
	{
		for(int t=i+1; t<n; t++)//z kazdym elementem ktory wystepuje dalej w tablicy(np. element 1 z 2,3 i 4, nie ma potrzeby sprawdzania 1 z 1, czy 2 z 1(jest tym samym co 1 z 2))
		{
			if(Tab[i]==Tab[t])// jezeli elementy sa sobie rowne
			{
				L[Tab[i]]=true;//zapisuje wartosc true na pozycji rownej wartosci sprawdzonego elementu
			}
		}	
	}
	cout<<"elementy powtarzajace sie: ";
	for(int i=0; i<n; i++)
	{
		if(L[i]==true) cout<<i<<" ";
	}
	cout<<endl;
	delete [] L;
}

void OptimizedFunction(int n){//drugi algorytm
	int* L = new int[n];//tablica L ma tyle elementow, ile roznych wartosci moga przyjmowac elementy tablicy Tab(od 0 do n-1)
	for(int i=0; i<n; i++) L[i]=0;//poczatkowo, kazdy element L jest rowny 0
	//L[0] zawsze bedzie rowne 0, poniewaz wartosci Tab zaczynaja sie od 1 (mozna wartosci przypisywac do indeksu o jeden mniejszy od wartosci, ale przez to kod bylby mniej przejrzysty)
	
	
	for(int i=0; i<n; i++)
	{
		L[Tab[i]]++;//indeksy tablicy L odpowiadaja wartosciom jakie moga przyjmowac elementy Tab. Sprawdzam jakie elementy pojawiaja sie w Tab i zapisuje ich czestosc wystepywania w tablicy L
	}
	
	cout<<"elementy powtarzajace sie: ";
	for(int i=0; i<n; i++)
	{
		if(L[i]>1)	cout<<i<<" ";//jezeli wartosc w L jest wieksza od jeden, to znaczy ze wartosc w Tab rowna indeksowi pojawiala sie wielokrotnie
	}
	cout<<endl;
	for(int i=0; i<n;i++) cout<<L[i]; 
	delete [] L;
} 

int main(){
	string answer;
	int n=0;
	cout<<"Podaj n: "<<endl;
	cin>>n;
	while(n<2)
	{
		cout<<"n musi byc wieksze od 1, podaj jeszcze raz"<<endl;
		cin>>n;
	}
	Tab = new int [n];
	cout<<"Losowac liczby?(tak/nie)"<<endl;
	cin>>answer;
	if(answer=="tak") GetRandomNumbers(n);
	else GetNumbersFromUser(n);

	cout<<"funkcja 1:"<<endl;
	BruteForce(n);
	cout<<"funkcja 2: "<<endl;
	OptimizedFunction(n);

//do testow wydajnosciowych:
//
//	int n=500000;
//	Tab = new int [n];
//	GetRandomNumbers(n);
//	
//	high_resolution_clock::time_point start1 = high_resolution_clock::now();
////	BruteForce(n);
//	for(int i=0; i<100;i++){
//		OptimizedFunction(n);	
//	}
//	high_resolution_clock::time_point end1 = high_resolution_clock::now();
//	double duration=duration_cast<microseconds>(end1 - start1).count();
//	
//	cout<<"czas trwania funkcji 1: "<< (duration)/1000000<<"[s]"<<endl;
//	cout<<"n= "<<n*100<<endl;


	delete [] Tab;
	return 0;
}