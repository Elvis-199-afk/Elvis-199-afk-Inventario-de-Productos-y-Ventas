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

