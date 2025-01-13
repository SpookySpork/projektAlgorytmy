#include <iostream>
using namespace std;
#include <ctime>
#include <iomanip>
#include <limits>
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
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"zle podano liczbe, podaj jeszcze raz"<<endl;
			cin>>liczba;
		}
		Tab[i]=liczba;
	}
}

void BruteForce(int n){
	int L[n];
	int l;
	bool powtarzanie=false;
	for(int i=0; i<n; i++) L[i]=0;
	
	for(int i=0; i<n; i++)
	{
		for(int t=i+1; t<n; t++)
		{
			if(Tab[i]==Tab[t]){
//				L[i]=Tab[i];
//				break;
				for(int z=0; z<i; z++){
					if(L[z]==Tab[i]) powtarzanie=true;
				}
				if(powtarzanie==false){
					L[i]=Tab[i];	
				}
				else powtarzanie=false;
			}	
		}
	}
	cout<<endl<<"elementy powtarzajace sie:\t";
	for(int i=0; i<n; i++)
	{
		if(L[i]!=0) cout<<Tab[i]<<" ";
		//cout<<L[i]<<" ";
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
	if(answer=="tak") Losuj(n);
	else Podaj(n);
	
	BruteForce(n);	
	
	delete [] Tab;
	return 0;
}