#include<iostream>
#include<string.h>
#include <math.h>
using namespace std;

void CalcularMasK(int Mask);
void CalcularHost(int Host);
void MostrarIps(int num1,int num2, int num3,int num4);

int Salto;
float Subred;
float Host;
int Ms1, Ms2, Ms3, Ms4;

int main(){
	int num1, num2, num3, num4;
	
	char TieneHost;
	
	cout<<"Digite su IP: ";
	cin>>num1>>num2>>num3>>num4;
	
	cout<<"Tienes el hots (s/n): ";
	cin>>TieneHost;
	
	if(TieneHost == 's' || TieneHost == 'S'){
		cout<<"Digite el Host: ";
		cin>>Host;
		CalcularHost(Host);
	}
	else{
		cout<<"Digite la Mascara: ";
		cin>>Ms1>>Ms2>>Ms3>>Ms4;
		CalcularMasK(Ms4);
	}
	cout<<endl;
	cout<<num1<<"."<<num2<<"."<<num3<<"."<<num4<<endl;
	cout<<Ms1<<"."<<Ms2<<"."<<Ms3<<"."<<Ms4<<endl;
	cout<<"Salto: "<<Salto<<endl;
	cout<<"#SubRed: "<<Subred<<endl;
	cout<<"#Host: "<<Host<<endl<<endl;
	
	MostrarIps(num1,num2, num3,num4);
	return 0;
}
void CalcularHost(int Host){
	int tabla[] = {128, 64, 32, 16, 8, 4, 2, 1};
	int sumaMask = 0;
	int cont = 0;
	int nSaltos = 0;
	for(int i = 0; i < 8; i++){
		if(tabla[i] >= Host){
			sumaMask += tabla[i]; 
			cont++;
		}
	}
	Ms1 = 255;
	Ms2 = 255;
	Ms3 = 255;
	Ms4 = sumaMask;
	
	Salto = pow(2,(8-cont));
	Subred = (pow (2,(cont)))- 2;
}

void CalcularMasK(int Mask){
	int tabla[] = {128, 64, 32, 16, 8, 4, 2, 1};
	int sumaMask = 0;
	int cont = 0;
	int nSaltos = 0;
	for(int i = 0; i < 8; i++){
		sumaMask += tabla[i]; 
		if(sumaMask == Mask){
			nSaltos = cont;
		}
		cont ++;
	}
	Subred = (pow (2,(nSaltos+1)))- 2;
	Salto = tabla[nSaltos];
	Host = (pow (2,(8-(nSaltos+1)) ))- 2;
}
void MostrarIps(int num1,int num2, int num3,int num4){
	cout<<"ID\t\tIP valida\tUltima IP Valida\tBroadcast"<<endl;
	for(int i = 1; i <= 5; i++){
		cout<<num1<<"."<<num2<<"."<<num3<<"."<<num4<<"\t"<<num1<<"."<<num2<<"."<<num3<<"."<<num4+1<<"\t"<<num1<<"."<<num2<<"."<<num3<<"."<<(num4 + Salto)-2<<"\t\t"<<num1<<"."<<num2<<"."<<num3<<"."<<((num4 + Salto)-2)+1<<endl;
		num4 += Salto;
	}
	cout<<endl;
	cout<<num1<<"."<<num2<<"."<<num3<<"."<<Ms4<<"\t"<<num1<<"."<<num2<<"."<<num3<<"."<<Ms4+1<<"\t"<<num1<<"."<<num2<<"."<<num3<<"."<<(Ms4 + Salto)-2<<"\t\t"<<num1<<"."<<num2<<"."<<num3<<"."<<((Ms4 + Salto)-2)+1<<endl;
}


