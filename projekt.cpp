#include <iostream>
using namespace std;
#include <ctime>
#include <iomanip>


int *Tab;

int Losuj(int n)
{
	srand(time(NULL));
	for(int i=0; i<=n;i++){
		Tab[i]=rand()%(n-1) + 1;
		cout<<Tab[i]<<" ";
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
	//else Podaj();
	
	
	delete [] Tab;
	return 0;
}