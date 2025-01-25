#include <iostream>
using namespace std;
#include <ctime>
#include <iomanip>
#include <limits>
#include <chrono>
using namespace chrono;
int *Tab;

void GetRandomNumbers(int n){//losuje elementy do tablicy
	srand(time(NULL));
	for(int i=0; i<n;i++){
		Tab[i]=rand()%(n-1)+1;//losuje liczby od 1 do n-1(rand()%(n) zaczyna losowanie od 0, stad powiekszenie wylosowanej liczby o 1
		cout<<Tab[i]<<" ";//wypisuje wylosowane elementy
	}
	cout<<endl;
}

void GetNumbersFromUser(int n){//elementy do tablicy przypisuje uzytkownik
	int liczba;
	for(int i=0; i<n; i++){
		cout<<"Podaj odpowiednia liczbe(od 1 do "<<n-1<<")"<<endl;
		cin>>liczba;
		while(liczba>=n||liczba<1){//jezeli zle podano liczbe, uzytkownik musi podac ja ponownie
			cout<<"zle podano liczbe, podaj jeszcze raz"<<endl;
			cin>>liczba;
		}
		Tab[i]=liczba;
	}
}

void BruteForce(int n){//pierwszy algorytm
	bool L[n];//tablica zawierajaca powtarzajace sie liczby
	for(int i=0; i<n-1; i++) L[i]=false;//poczatkowo wszystkie elementy tablicy L sa rowne 0
	
	for(int i=0; i<n-1; i++)//sprawdzam kazdy element z tablicy Tab(nie sprawdzam ostatniego elementu przez i, jest ono sprawdzane przez t. Jezeli i=n, j=n+1, co wychodzi poza wartosc tablicy)
	{
		for(int t=i+1; t<n; t++)//z kazdym elementem ktory wystepuje dalej w tablicy(np. element 1 z 2,3 i 4, nie ma potrzeby sprawdzania 1 z 1, czy 2 z 1(jest tym samym co 1 z 2))
		{
			if(Tab[i]==Tab[t]){// jezeli elementy sa sobie rowne
				if(L[Tab[i]]!=Tab[i])//sprawdzam czy element juz jest zapisany jako duplikat w tablicy L,
				{
					L[Tab[i]]=true;// jezeli nie, zapisuje wartosc true na pozycji o indeksie rownym wartosci elementu(pozycja 0 zostaje pusta)(jezeli powtarza sie 3, L[3]=true itp.
					//stad wiem, ze jezeli L[k]==true, oznacza to, ze w tablicy Tab istnieje wiecej niz jedna liczba o wartosci k
				}
			}
		}	
	}
	cout<<"elementy powtarzajace sie: ";
	for(int i=0; i<n; i++)
	{
		if(L[i]==true) cout<<i<<" ";
	}
	cout<<endl;
}

void BetterFunction(int n){//drugi algorytm
	int L[n-1];//tablica L ma tyle elementow, ile wartosci moga przyjmowac elementy tablicy Tab
	for(int i=0; i<n; i++) L[i]=0;//poczatkowo, kazdy element L jest rowny 0
	//L[0] zawsze bedzie rowne 0, poniewaz wartosci Tab zaczynaja sie od 1 (mozna wartosci przypisywac do indeksu o jeden mniejszy od wartosci, ale przez to kod bylby mniej przejrzysty)
	
	
	for(int i=0; i<n; i++){
		L[Tab[i]]++;//indeksy tablicy L odpowiadaja wartosciom jakie moga przyjmowac elementy Tab. Sprawdzam jakie elementy pojawiaja sie w Tab i zapisuje ich czestosc wystepywania w tablicy L
	}
	
	cout<<"elementy powtarzajace sie: ";
	for(int i=0; i<n; i++)
	{
		if(L[i]>1) cout<<i<<" ";//jezeli wartosc w L jest wieksza od jeden, to znaczy ze wartosc w Tab rowna indeksowi pojawiala sie wielokrotnie
	}
	cout<<endl;
}

int main(){
	string answer;
	int n=0;
	cout<<"Podaj n: "<<endl;
	cin>>n;
	Tab = new int [n];
	cout<<"Losowac liczby?(tak/nie)"<<endl;
	cin>>answer;
	if(answer=="tak") GetRandomNumbers(n);
	else GetNumbersFromUser(n);

	cout<<"funkcja 1:"<<endl;
	BruteForce(n);
	cout<<"funkcja 2: "<<endl;
	BetterFunction(n);

//do testow wydajnosciowych:
//
//	GetRandomNumbers(n);
//	
//	high_resolution_clock::time_point begin1 = high_resolution_clock::now();
//	BruteForce(n);
//	high_resolution_clock::time_point end1 = high_resolution_clock::now();
//	double duration1=duration_cast<microseconds>(end1 - begin1).count();
//	
//	high_resolution_clock::time_point begin2 = high_resolution_clock::now();
//	BetterFunction(n);
//	high_resolution_clock::time_point end2 = high_resolution_clock::now();
//	double duration2=duration_cast<microseconds>(end2 - begin2).count();
//	cout<<"czas wykonywania algorytmu 1: "<<duration1/1000000 << " sekund" << endl;
//	cout<<"czas wykonywania algorytmu 2: "<<duration_cast<nanoseconds>(end2 - begin2).count()<< " mikro sekund" << endl;

	
	delete [] Tab;
	
	return 0;
}