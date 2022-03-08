#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

void insertar(),eliminar(),buscar(),vacia(),
     inicializar(),primero(),ultimo(),anterior(),
     siguiente(),tamano(),vaciar(),mosList();


class lista{
	public:
		class animal{
			public:
				char Nombre[], Raza[];
				int ID;
				animal *siguiente;
				animal *anterior;
			
		}ani;
		
		animal *h,*t,*aux,*Posicion;
		//1
		insertar(){
			int i=1;
			if(h!=NULL){
				int men=0;
				aux = new animal();
				cout<<"Nombre"<<endl;
				cin>>aux->Nombre;
				cout<<"Raza"<<endl;
				cin>>aux->Raza;
				cout<<"Id:"<<endl;
				cin>>aux->ID;
				cout<<"\nInsertar\n1) Inicio\n2) Final\n3) Otra\n"<<endl;
				cin>>men;
				switch(men){
					case 1:
						aux->siguiente=h;
						aux->anterior=NULL;
						h->anterior=aux;
						h=aux;
						cout<<"\nGuardado"<<endl;
						break;
					case 2:
			    		aux->anterior=t;
			    		aux->siguiente=NULL;
						t->siguiente=aux;
						t=aux;
						cout<<"\nGuardado"<<endl;
						break;
					case 3:
						system("cls");
						int posicion;
						system("cls");
						cout<<"Posicion:\n"<<endl;
						cin>>posicion;
						Posicion=h;
						while(i<=posicion){
							Posicion=Posicion->siguiente;
							i++;
						}
						aux->siguiente=Posicion;
						Posicion->anterior=aux;
						Posicion=Posicion->anterior;
						Posicion->siguiente=aux;
						aux->anterior=Posicion;
						cout<<"\nGuardado"<<endl;
						break;
					default:
						cout<<"\nOpcion Invalida\n"<<endl;
						break;
						}
						
				}
			else
				cout<<"La lista no fue inicializada\n"<<endl;	
			}
		//2
		eliminar(){
			int a=0,e=1;
			aux=h;
			if(aux!=NULL){
				aux=h;
				cout<<"Elemento a borrar"<<endl;
				cin>>a;
				while(aux!=NULL){
					if(a==1){
						h=h->siguiente;
						h->anterior=NULL;
						delete aux;
						aux==NULL;
					}
					if(a==e&&aux->siguiente!=NULL&&aux->anterior!=NULL){
						aux=aux->siguiente;
						aux->anterior=aux->anterior->anterior;
						aux=aux->anterior->anterior;
						aux->siguiente=aux->siguiente->siguiente;
						aux=aux->siguiente;
						delete aux;
						aux=NULL;
					}
					if(a==e&&a!=1&&aux->siguiente==NULL){
						t=t->anterior;
						t->siguiente=NULL;
						delete aux;
						aux=NULL;
					}
					e++;
				}
				aux=h;
			}
			else{
				cout<<"La lista esta vacia"<<endl;
			}
		}
		//3
		buscar(){
			int e=0,i=1;
			aux=h;
			if(aux!=NULL){
				tamano();
				cout<<"Elemento buscado"<<endl;
				cin>>e;
				while(aux!=NULL){
					aux=aux->siguiente;
					i++;
					if(i==e){
						cout<<aux->Nombre<<endl;
    					cout<<aux->Raza<<endl;
    					cout<<aux->ID<<endl;
    					cout<<endl<<endl;
					}
				}
			}
			else
				cout<<"La lisga esta vacia"<<endl;
		}
		//4
		void vacia(){
			if(h!=NULL)
				cout<<"La lista no esta vacia"<<endl;
			else
				cout<<"La lista esta vacia"<<endl;
		}
		//5
		void inicializar(){
			if(aux==NULL){
		    	aux = new animal();
				cout<<"Nombre"<<endl;
				cin>>aux->Nombre;
				cout<<"Raza"<<endl;
				cin>>aux->Raza;
				cout<<"Id:"<<endl;
				cin>>aux->ID;
				h=aux;t=aux;Posicion=aux;}
			else
				cout<<"La lista ya fue inicializada\n"<<endl;
    	}
    	//6
    	void primero(){
    		if(h!=NULL){
			    cout<<"Primer Elemento\n"<<endl;
			    cout<<h->Nombre<<endl;
			    cout<<h->Raza<<endl;
			    cout<<h->ID<<endl;
			}
			else
				cout<<"La lista esta vacia\n"<<endl;
		}
		//7
		void ultimo(){
			if(h!=NULL){
			    cout<<"Primer Elemento\n"<<endl;
			    cout<<t->Nombre<<endl;
			    cout<<t->Raza<<endl;
			    cout<<t->ID<<endl;
			}
			else
				cout<<"La lista esta vacia\n"<<endl;
		}
    	//8
    	void anterior(){
    		int i=1;
    		if(Posicion!=h){
    			Posicion=Posicion->anterior;
    			cout<<"Posicion movida con exito\n"<<endl;
    			aux=h;
    			while(aux!=Posicion){
    				i++;
				}
				cout<<"Posicion actual:\nElemento "<<i<<endl;
    		}
	    	else{
	    		cout<<"Posicion esta en el limite"<<endl;
			}
		}
		//9
		void siguiente(){
			int i=1;
    		if(Posicion!=t){
    			Posicion=Posicion->siguiente;
    			cout<<"Posicion movida con exito\n"<<endl;
    			aux=h;
    			while(aux!=Posicion){
    				i++;
				}
				cout<<"Posicion actual:\nElemento "<<i<<endl;
    		}
	    	else{
	    		cout<<"Posicion esta en el limite"<<endl;
	    	}
		}
    	//10
		void tamano(){
			if(aux!=NULL){
				int i=1;
				aux=h;
				while(aux!=t){
					aux=aux->siguiente;
					i++;
				}
				cout<<"La lista tiene "<<i<<" elementos"<<endl;
			}
			else{
				cout<<"La lista esta vacia"<<endl;
			}
		}
		//11
		void vaciar(){
			if(aux!=NULL){
				while(aux!=NULL){
					aux=h;
					h=h->siguiente;
					delete aux;
				};
			h=NULL;aux=NULL;t=NULL;Posicion=NULL;
			}
			else{
				cout<<"La lista esta vacia"<<endl;
			}
		}
    	//12
    	void mosList(){
    		int men;
    		cout<<"Mostrar de..."<<endl;
    		cout<<"1: Inicio a Fin"<<endl;
    		cout<<"2: Fin a Inicio\n"<<endl;
    		cin>>men;
    		system("cls");
    		switch(men){
    			case 1:
    				aux=h;
    				while(aux!=NULL){
    					cout<<aux->Nombre<<endl;
    					cout<<aux->Raza<<endl;
    					cout<<aux->ID<<endl;
    					cout<<endl<<endl;
    					aux=aux->siguiente;
					}
    				break;
    			case 2:
    				aux=t;
    				while(aux!=NULL){
    					cout<<"Nombre: "<<aux->Nombre<<endl;
    					cout<<"Raza: "<<aux->Raza<<endl;
    					cout<<"ID:  "<<aux->ID<<endl;
    					cout<<endl<<endl;
    					aux=aux->anterior;
					}
    				break;
    			default:
						cout<<"\nOpcion Invalida\n"<<endl;
    				break;
			}
		}
		
}lis;


int main(){
	bool ciclo=true;
	int menu;
	do{
		cout<<"1:  Insertar"<<endl;
		cout<<"2:  Eliminar"<<endl;
		cout<<"3:  Buscar"<<endl;
		cout<<"4:  Vacia"<<endl;
		cout<<"5:  Inicializar"<<endl;
		cout<<"6:  Primero"<<endl;
		cout<<"7:  Ultimo"<<endl;
		cout<<"8:  Anterior"<<endl;
		cout<<"9:  Siguiente"<<endl;
		cout<<"10: Tamano"<<endl;
		cout<<"11: Vaciar"<<endl;
		cout<<"12: Mostrar Lista\n"<<endl;
		cin>>menu;
		system("cls");
		switch(menu){
			case 1:  lis.insertar();    break;
			case 2:  lis.eliminar();    break;
			case 3:  lis.buscar();      break;
			case 4:  lis.vacia();       break;
			case 5:  lis.inicializar(); break;
			case 6:  lis.primero();   	break;
			case 7:  lis.ultimo();      break;
			case 8:  lis.anterior();    break;
			case 9:  lis.siguiente();   break;
			case 10: lis.tamano();      break;
			case 11: lis.vaciar();      break;
			case 12: lis.mosList();     break;
			default:
			    cout<<"\nOpcion Invalida\n"<<endl;
			    break;
		}
		system("pause");
		system("cls");
	}while(ciclo);
	return 0;
}
