#include <iostream>
#include <conio.h>
#include <stdlib.h> //utiliza para new
using namespace std;



//----------------------------------------estructrura---------------------------------
struct nodo{
	int dato;
	nodo *siguiente;
};




//------------------------------------declarar funcion-----------------------------------
void agregarpila(nodo *&pila, int n);
void sacarpila(nodo *&pila, int n);

//-------------------------------------main---------------------------------------------
int main(){
	nodo *pila=NULL;
	char res;
	int dato;
	int opc;
do{
	system("cls");
	cout<<"1) insertar datos"<<endl;
	cout<<"2) eliminar datos"<<endl;
	cout<<"seleccione una opcion"<<endl;
	cin>>opc;
	switch(opc){
		case 1:
			do{
	            cout<<"teclee un elemento ";
	            cin>>dato;
	            agregarpila(pila,dato);	            
  	            cout<<endl<<"Desea otro elemento? s/n: "<<endl;
	            cin>>res;
	          }while(res!='n');	
	    break;
	    case 2:
	    	cout<<"sacar elemento de la PILA"<<endl;
	    	while(pila!=NULL){
	    		sacarpila(pila,dato);
	    		if (pila!=NULL){
	    			cout<<dato<<","; 
	    			getch();
				}
			    else{
				cout<<dato<<".";
			    }
		    }   
		break;	        
    }    
    cout <<endl<<"Regresar al menu s/n";
    cin>>res;
}while(res!='n');
getch();
}




//------------------------------------funcion1-----------------------------------
void agregarpila(nodo *&pila, int n){//& direcccion del nodo
    nodo *nvo_nodo=new nodo();//crea un espacio en la memoria para guardar el elemento
    nvo_nodo -> dato=n;//para el valor de nvo es le asigne a n
    nvo_nodo->siguiente=pila;//asignar direccion
    pila = nvo_nodo;
    cout<<"\nElemento "<<n<<" agregando a Pila correctamente "<<endl;
}
//------------------------------------funcion2-----------------------------------
void sacarpila(nodo *&pila, int n){
	nodo *aux = pila;
	pila=aux->siguiente;
	delete aux;
}
