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
void actualizarPro(Producto [], int);
void eliminarPro(Producto [], int &);

void registrarVen(Venta [], int &);
void listarVen(Venta [], int);
void totalVen(Venta [], int);

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
			case 4:
				system("cls");
				if(np>-1){
					actualizarPro(listproductos, np);
				}else{
					cout<<"\nNo hay productos para actualizar...\n";
				}
				system("pause");
				break;
			case 5:
				system("cls");
				if(np>-1){
					eliminarPro(listproductos, np);
				}else{
					cout<<"\nNo hay productos para eliminar...\n";
				}
				system("pause");
				break;
			case  6:
				system("cls");
				if(nv<=30){
					registrarVen(listventas, nv);
				}else{
					cout<<"No se puede registrar mas ventas, el arreglo esta lleno...\n";
				}	
				system("pause");		
				break;	
			case 7:
				system("cls");
				if (nv>-1){
					listarVen(listventas, nv);
				}else{
					cout<<"\nNo hay ventas para listar...\n";
				}
				system("pause");
				break;
			case 8:
				system("cls");
				if(nv>-1){
					totalVen(listventas, nv);
				}else{
					cout<<"\nNo existen ventas...\n";
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
void actualizarPro(Producto listproductos[], int np){
	listarPro(listproductos, np);
	char actPro[30], aux[30];
	int i;
	cout<<"\n\t===ACTUALIZAR PRODUCTO===\n";
	cout<<"Ingrese el nombre del producto a actualizar: ";
	cin.ignore();
	cin.getline(actPro, 30);
	i=buscar(listproductos, actPro, np);
	if(i!=-1){
		cout<<"\nIngrese el nuevo nombre: ";
		cin.ignore();
		cin.getline(aux, 30);
		strcpy(listproductos[i].nombre,aux);
		cout<<"\nIngrese el nuevo precio: ";
		cin>>listproductos[i].precio;
		cout<<"\n\nSe actualizo el producto correctamente..."<<endl;
	}else{
		cout<<"\nEl producto a actualizar no existe..."<<endl;
	}
}
void eliminarPro(Producto listproductos[], int &np){
	char elimPro[30];
	int i;
	cout<<"\nIngrese el nombre del producto que desea eliminar: ";
	cin.ignore();
	cin.getline(elimPro, 30);
	i=buscar(listproductos, elimPro, np);
	if(i!=-1){
		for(int j=i; j<=np-1; j++){
			listproductos[j]=listproductos[j+1];
		}
		np--;
		cout<<"\nSe elimino el producto correctamente..."<<endl;
	}else{
		cout<<"\nEl producto a eliminar no existe..."<<endl;
	}
}
void registrarVen(Venta listventas[], int &nv){
	nv++;
	cout<<"\n\t===REGISTRAR VENTAS==="<<endl;
	cout<<"Ingrese el ID de la venta: ";
	cin>>listventas[nv].idVenta;
	cout<<"\nIngrese el nombre del producto: ";
	cin.ignore();
	cin.getline(listventas[nv].producto, 30);
	cout<<"\nIngrese la cantidad: ";
	cin>>listventas[nv].cantidad;
	cout<<"\nIngrese el precio total: ";
	cin>>listventas[nv].precioTotal;
	cout<<"\n\nSe registro la venta correctamente..."<<endl;
}
void listarVen(Venta listventas[], int nv){
	cout<<"\t===LISTA DE VENTAS==="<<endl;
	cout<<left<<setw(10)<<"\nID"<<setw(20)<<"PRODUCTO"<<setw(20)<<"CANTIDAD"<<setw(20)<<"PRECIO TOTAL"<<endl;
	for(int i=0; i<=nv; i++){
		cout<<setw(10)<<listventas[i].idVenta;
		cout<<setw(20)<<listventas[i].producto;
		cout<<setw(20)<<listventas[i].cantidad;
		cout<<setw(20)<<listventas[i].precioTotal<<endl;
	}
}
void totalVen(Venta listventas[], int nv){
	float total=0;
	cout<<"===\tTOTAL DE VENTA==="<<endl;
	for(int i=0; i<=nv; i++){
		total+=listventas[i].precioTotal;
	}
	cout<<"\nEl tota de venta es: S/. "<<total<<endl;
}