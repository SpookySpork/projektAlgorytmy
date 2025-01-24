#include <iostream>
using namespace std;
#include <ctime>
#include <iomanip>
#include <limits>
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
		while(liczba>=n||cin.fail()){//jezeli zle podano liczbe, uzytkownik musi podac ja ponownie
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"zle podano liczbe, podaj jeszcze raz"<<endl;
			cin>>liczba;
		}
		Tab[i]=liczba;
	}
}

void BruteForce(int n){//pierwszy algorytm
	bool L[n];//tablica zawierajaca powtarzajace sie liczby
	for(int i=0; i<n-1; i++) L[i]=false;//poczatkowo wszystkie elementy tablicy L sa rowne 0
	
	for(int i=0; i<n; i++)//sprawdzam kazdy element z tablicy Tab
	{
		for(int t=i+1; t<n; t++)//z kazdym elementem ktory wystepuje dalej w tablicy(np. element 1 z 2,3 i 4, nie ma potrzeby sprawdzania 1 z 1, czy 2 z 1(jest tym samym co 1 z 2))
		{
			if(Tab[i]==Tab[t]){// jezeli elementy sa sobie rowne
				if(L[Tab[i]]!=Tab[i])//sprawdzam czy element juz jest zapisany jako duplikat w tablicy L,
				{
					L[Tab[i]]=true;// jezeli nie, zapisuje element na pozycji o 1 mniejszy niz jego wartosc, przez to, na indeksie 0 zapisywana jest 1, na 1 zapisywana jest 2 itd.
					//stad wiem, ze jezeli L[k]==true, oznacza to, ze w tablicy Tab istnieje wiecej niz jedna liczba o wartosci k+1
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

void BetterBruteForce(int n){//drugi algorytm
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
	int n;
	cout<<"Podaj n: "<<endl;
	cin>>n;
	while(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"zle podano liczbe, podaj jeszcze raz"<<endl;
		cin>>n;
	}
	Tab = new int [n];
	cout<<"Losowac liczby?(tak/nie)"<<endl;
	cin>>answer;
	
	int t;
	cout<<"ile testow? "<<endl;
	cin>>t;
	
	if(answer=="tak") GetRandomNumbers(n);
	else GetNumbersFromUser(n);
	
	for(int i=0; i<t; i++)
	{
		cout<<"funkcja 1"<<endl;
		BruteForce(n);
		cout<<"funkcja 2"<<endl;
		BetterBruteForce(n);
		cout<<endl;
		cin>>t;
		if(i+1<t)
		{
			if(answer=="tak") GetRandomNumbers(n);
			else GetNumbersFromUser(n);	
		}
	}	
	
	delete [] Tab;
	return 0;
}