#include <iostream>
using namespace std;
#include <ctime>
#include <iomanip>


int *Tab;

void Losuj(int n){
	srand(time(NULL));
	for(int i=0; i<n;i++){
		Tab[i]=rand()%(n-1) + 1;
		cout<<Tab[i]<<" ";
	}
}

void Podaj(int n){
	int liczba;
	for(int i=0; i<n; i++){
		cout<<"Podaj odpowiednia liczbe(od 1 do "<<n-1<<")"<<endl;
		cin>>liczba;
		while(liczba>=n||cin.fail()){
			cin.clear();
			cin.ignore();
			cout<<"zle podano liczbe, podaj jeszcze raz"<<endl;
			cin>>liczba;
		}
		Tab[i]=liczba;
	}
}


int main(){
	string answer;
	int n;
	cout<<"Podaj n: "<<endl;
	cin>>n;
	while(cin.fail()){
		cin.clear();
		cin.ignore();
		cout<<"zle podano liczbe, podaj jeszcze raz";
		cin>>n;
	}
	Tab = new int [n];
	cout<<"Losowac liczby?(tak/nie)"<<endl;
	cin>>answer;
	if(answer=="tak") Losuj(n);
	else Podaj(n);
	
	
	
	delete [] Tab;
	return 0;
}