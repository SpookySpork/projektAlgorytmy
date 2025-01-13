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
		cout<<"podaj odpowiednia liczbe(od 1 do "<<n-1<<")"<<endl;
		cin>>liczba;
		while(liczba>n-1){
			cout<<"zle podana liczba, podaj jeszcze raz: "<<endl;
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
	Tab = new int [n];
	cout<<"Losowac liczby?(tak/nie)"<<endl;
	cin>>answer;
	if(answer=="tak") Losuj(n);
	else Podaj(n);
//	for(int i=0; i<n;i++){
//		cout<<Tab[i]<<" ";
//	}
	
	
	
	delete [] Tab;
	return 0;
}