#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

struct Producto{
	char nombre[30];
	float precio;
};

struct Venta{
	int idVenta;
	char producto[30];
	int cantidad;
	float precioTotal;
};

void registrarPro(Producto [], int &);
void listarPro(Producto [], int);
int buscar(Producto [], char [], int);
void buscarPro(Producto [], int);

int main(){
	int op, np=-1, nv=-1;
	Producto listproductos[20];
	Venta listventas[20];	
	do{
		system("cls");
		cout<<"===== Inventario de Productos y Ventas =====\n\n\n";
		cout<<"1. Registrar un nuevo producto\n";
		cout<<"2. Listar los productos registrados\n";
		cout<<"3. Buscar un producto por nombre\n";
		cout<<"4. Actualizar los datos de un producto\n";
		cout<<"5. Eliminar un producto\n";
		cout<<"6. Registrar una venta\n";
		cout<<"7. Listar las ventas realizadas\n";
		cout<<"8. Calcular el total de ventas realizadas\n";
		cout<<"9. S A L I R\n\n";
		cout<<"\t\t\tOPCION: ";
		cin>>op;
		switch (op){
			case 1:
				system("cls");
				if(np<=30){
					registrarPro(listproductos, np);
				}else{
					cout<<"No se puede registrar productos, el arreglo esta lleno...\n";
				}	
				system("pause");		
				break;	
			case 2:
				system("cls");
				if (np>-1){
					listarPro(listproductos, np);
				}else{
					cout<<"\nNo hay productos para listar...\n";
				}
				system("pause");
				break;
			case 3:	
				system("cls");
				if(np>-1){
					buscarPro(listproductos, np);
				}else{
					cout<<"\nNo hay productos para buscar...\n";
				}
				system("pause");
				break;
			case 9:
				cout<<"\n\n\t\tS A L I E N D O  . . . \n";
				break;
			default:
				cout<<"\nIngrese una opcion valida\n";
				system("pause");
				break;
		}
	}while(op!=9);
	return 0;
}      

void registrarPro(Producto listproductos[], int &np){
	np++;
	cout<<"Ingrese el nombre del producto: ";
	cin.ignore();
	cin.getline(listproductos[np].nombre, 30);
	cout<<"Ingrese el precio: ";
	cin>>listproductos[np].precio;
	cout<<"\nSe registro el producto...\n";
}
void listarPro(Producto listproductos[], int np){
	cout<<"\t\t===LISTA DE PRODUCTOS==="<<endl;
	cout<<left<<setw(30)<<"NOMBRE"<<setw(20)<<"PRECIO"<<endl;
	for(int i=0; i<=np; i++){
		cout<<setw(30)<<listproductos[i].nombre;
		cout<<setw(20)<<listproductos[i].precio<<endl;
	}
}
int buscar(Producto listproductos[], char nomPro[], int np){
	int i=0;
	while((strcmp(nomPro, listproductos[i].nombre)!=0)&&(i<=np)){
		i++;
	}
	if(i>np){
		return -1;
	}else{
		return i;
	}
}

void buscarPro(Producto listproductos[], int np){
	char nomPro[30];
	int i;
	cout<<"\t===BUSCAR PRODUCTO===";
	cout<<"\nIngrese el nombre que desea bucar: ";
	cin.ignore();
	cin.getline(nomPro, 30);
	i=buscar(listproductos, nomPro, np);
	if(i==-1){
		cout<<"\nEl nombre del producto no se encuentra en la lista...";
	}else{
		cout<<"\n"<<listproductos[i].nombre<<endl;
		cout<<listproductos[i].precio<<endl;
	}
	
}
