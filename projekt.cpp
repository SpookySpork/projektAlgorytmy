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
	int L[n];//tablica zawierajaca powtarzajace sie liczby
	bool powtarzanie=false;
	for(int i=0; i<n-1; i++) L[i]=0;//poczatkowo wszystkie elementy tablicy L sa rowne 0
	
	for(int i=0; i<n; i++)//sprawdzam kazdy element z tablicy Tab
	{
		for(int t=i+1; t<n; t++)//z kazdym elementem ktory wystepuje dalej w tablicy(np. element 1 z 2,3 i 4, nie ma potrzeby sprawdzania 1 z 1, czy 2 z 1(jest tym samym co 1 z 2))
		{
			if(Tab[i]==Tab[t]){// jezeli elementy sa sobie rowne
				if(L[Tab[i]-1]!=Tab[i])//sprawdzam czy element juz jest zapisany jako duplikat
				{
					L[Tab[i]-1]=1;	
				}
//			
//			
//			
//			
//				for(int z=0; z<i; z++){//sprawdzam czy dana liczba juz nie zostala oznaczona jako duplikat
//					if(L[z]==Tab[i]) powtarzanie=true;//
//				}
//				if(powtarzanie==false){
//					L[i]=Tab[i];	
//				}
//				else powtarzanie=false;
			}	
		}
	}
	cout<<endl<<"elementy powtarzajace sie: ";
	for(int i=0; i<n; i++)
	{
		if(L[i]!=0) cout<<i+1<<" ";
	}
	
}

void BetterBruteForce(int n)
{
	int L[n-1];
	for(int i=0; i<n-1; i++) L[i]=0;
		
	for(int i=1; i<n-1; i++)
	{
		for(int t=0; t<n; t++){
			if(i==Tab[t]) L[i-1]++;
		}
	}
	
	for(int i=0; i<n; i++)
	{
		if(L[i]>1) cout<<"liczba "<<i+1<<" pojawila sie "<<L[i]<<" razy"<<endl;
	}
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
	if(answer=="tak") GetRandomNumbers(n);
	else GetNumbersFromUser(n);
	
	BruteForce(n);
	//BetterBruteForce(n);	
	
	delete [] Tab;
	return 0;
}