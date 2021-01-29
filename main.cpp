#include <iostream>
#include <random>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//metodo del ejercicio#3
void funcion(int n,int k,float d) {
	//se va a repetir hasta que k=n y n es el numero ingresado
	if (k<=n) {
		//cout <<"k= "<< k<<endl;
		float top = 0 , inferior = 0;
		float division=0;
		top = (2*k)-1;
		inferior=k*(k+1);
		division = (top) / (inferior);
		d = d+division;
		k++;
		//recursiba
		funcion(n,k,d);
	} else if(k=n) {
		//termina e imprime la respuesta
		cout<<"S( "<< n <<" )= "<<d<<endl;
	}
}

//metodo del 2do ejercicio
void ordenamientoRBB(int arr[],bool bandera,int n) {
	//mientras la bandera sea verdadera va a entrar
	if( bandera==true ) {
		//se define la variable auxiliar que sirve para almacenar y sustituir
		int aux=0;
		bandera = false;
		for(int i=0; i<n-1; i++) {
			if(arr[i] > arr[i+1]) {
				aux = arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=aux;
				bandera = true;
			}
		}
		//recursiva
		ordenamientoRBB(arr,bandera,n);
	} else {
		//si es falso entra e imprime la matriz ordenada
		for(int i=0; i<n; i++) {
			cout<<"["<<arr[i]<<"] ";
		}
	}
}

int main(int argc, char** argv) {
	bool res;
	res=true;
	//repite hasta que la respuesta de usuario sea para salir
	while(res==true) {
		int opcion;
		cout<<"1) Ejercicio1"<<endl;
		cout<<"2) Ejercicio2"<<endl;
		cout<<"3) Ejercicio3"<<endl;
		cout<<"4) Salida"<<endl;
		cout<<"Ingrese su opcion:"<<endl;
		cin>>opcion;
		//imgresa la opcion que desea
		switch(opcion) {
			case 1: {

				string palabra;

				cout << "Ingrese la cadena a evaluar: ";
				cin >> palabra;
				int valor = 0;

				for (int i = 0; i < palabra.length(); i++) {
					if ((palabra[i] == 'A' && i == 1) || (palabra[i] == 'a' && i == 1)) {
						if ((palabra[i - 1] == '1' && palabra[i + 3] == '0') || (palabra[i - 1] == '0' && palabra[i + 3] == '1') || (palabra[i - 1] == '0' && palabra[i + 3] == '0')) {
							valor = 0;
						} else {
							valor = 1;
						}
					} else if ((palabra[i] == 'O' && i == 1) || (palabra[i] == 'o' && i == 1)){
						if (valor == '0' && palabra[i + 2] == '0') {
							valor = 0;
						} else {
							valor = 1;
						}
					} else if (palabra[i] == 'A' || (palabra[i] == 'a')) {
						if ((valor == 1 && palabra[i + 3] == '0') || (valor == 0 && palabra[i + 3] == '1') || (valor == 0 && palabra[i + 3] == '0')) {
							valor = 0;
						} else {
							valor = 1;
						}
					} else if ((palabra[i] == 'O') || (palabra[i] == 'o')) {
						if (valor == 0 && palabra[i + 2] == '0') {
							valor = 0;
						} else {
							valor = 1;
						}
					}
				}//fin del for que recorre el length de la cadena

				if (valor != 1) {
					cout << "Falso " << endl;
				} else {
					cout << "Verdadero" << endl;
				}//fin que valida resultados


			}
			break;
			case 2: {
				int n=20;
				int b[n];
				//crea el arreglo y lo llena de numeros random hasta 99
				for(int i = 0; i < n; i++) {
					b[i] = 1 + (rand() % 9);
				}
				//imprime el arreglo original
				cout<<"Arreglo original="<<endl;
				for(int i = 0; i < 20; i++) {
					cout<< "["<<b[i] <<"] ";
				}
				//llama el recursivo e imprime el arreglo ordenado
				cout<<endl<<"Arreglo ordenado="<<endl;
				ordenamientoRBB(b,true,n);
				cout<<endl<<endl;
			}
			break;
			case 3: {
				int n=0,k=1;
				//pide el valor de la sumatoria
				cout<<"Ingrese el valor de x:";
				cin>>n;
				//validacion de que no acepte numeros inferiores a 1
				while(n < 1) {
					cout<<"Valor no valido ingrese nuevamente:";
					cin>>n;
				}
				//llama la recursiva e imprime la respuesta
				float d=0;
				funcion(n,k,d);
				cout<<endl;
			}
			break;
			case 4 :
				//salida
				res=false;
				cout<<"Gracias por usar lel programa!!"<<endl;
				break;
		}
	}

	return 0;
}
