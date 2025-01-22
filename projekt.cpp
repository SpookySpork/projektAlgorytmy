#include <iostream>
using namespace std;
#include <ctime>
#include <iomanip>
#include <limits>
int *Tab;

void GetRandomNumbers(int n){
	srand(time(NULL));
	for(int i=0; i<n;i++){
		Tab[i]=rand()%(n-1) + 1;
		cout<<Tab[i]<<" ";
	}
}

void GetNumbersFromUser(int n){
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
	bool powtarzanie=false;
	for(int i=0; i<n; i++) L[i]=0;
	
	for(int i=0; i<n; i++)
	{
		for(int t=i+1; t<n; t++)
		{
			if(Tab[i]==Tab[t]){
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
	cout<<endl<<"elementy powtarzajace sie: ";
	for(int i=0; i<n; i++)
	{
		if(L[i]!=0) cout<<Tab[i]<<" ";
	}
	
}

void BetterBruteForce(int n)
{
	int L[n-1];
	for(int i=0; i<n-1; i++) L[i]=0;
		
	for(int i=1; i<n-1; i++)
	{
		for(int t=0; t<n; t++){
			if(i==L[t]) L[i-1]++;
		}
	}
	cout<<endl;
	for(int i=0; i<n; i++) cout<<L[i]<<" ";
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
	
	//BruteForce(n);
	BetterBruteForce(n);	
	
	delete [] Tab;
	return 0;
}