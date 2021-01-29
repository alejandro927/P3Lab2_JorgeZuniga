#include <iostream>
#include <random>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void funcion(int n,int k,float d) {
	if (k<=n) {
		//cout <<"k= "<< k<<endl;
		float top = 0 , inferior = 0;
		float division=0;
		top = (2*k)-1;
		inferior=k*(k+1);
		division = (top) / (inferior);
		d = d+division;
		k++;
		funcion(n,k,d);
	} else if(k=n) {
		cout<<"S( "<< n <<" )= "<<d<<endl;
	}
}

void ordenamientoRBB(int arr[],bool bandera){
	if( bandera==true ){
		int aux=0;
		bandera = false;
		for(int i=0;i<19;i++){
			if(arr[i] > arr[i+1]){
				aux = arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=aux;
				bandera = true;
			}
		}
		ordenamientoRBB(arr,bandera);
	}else{
		for(int i=0;i<20;i++){
			cout<<"["<<arr[i]<<"] ";
		}
	}
}

int main(int argc, char** argv) {
	bool res;
	res=true;
	while(res==true) {
		int opcion;
		cout<<"1) Ejercicio1"<<endl;
		cout<<"2) Ejercicio2"<<endl;
		cout<<"3) Ejercicio3"<<endl;
		cout<<"4) Salida"<<endl;
		cout<<"Ingrese su opcion:"<<endl;
		cin>>opcion;
		switch(opcion) {
			case 1: {
				cout<<"Ejercicio 1"<<endl;
			}
			break;
			case 2: {
				int b[20];
				for(int i = 0; i < 20; i++) {
					b[i] = 1 + (rand() % 10);
				}
				cout<<"Arreglo original="<<endl;
				for(int i = 0; i < 20; i++) {
					cout<< "["<<b[i] <<"] ";
				}
				cout<<endl<<"Arreglo ordenado="<<endl;
				ordenamientoRBB(b,true);
				cout<<endl<<endl;
			}
			break;
			case 3: {
				int n=0,k=1;
				cout<<"Ingrese el valor de x:";
				cin>>n;
				float d=0;
				funcion(n,k,d);
				cout<<endl;
			}
			break;
			case 4 :
				res=false;
				cout<<"Gracias por usar la app"<<endl;
				break;
		}
	}

	return 0;
}
