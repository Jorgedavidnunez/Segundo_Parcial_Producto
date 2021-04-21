
#include <mysql.h>
#include <iostream>
#include "Marca.h"
#include "Producto.h"
using namespace std;
void create_marca();
void read_marca();
void update_marca();
void delete_marca();
void create_producto();
void read_producto();
void update_producto();
void delete_producto();
int main()
{
    int op1, op2;
    do {
        system("cls");
        cout << "Ingrese el numero de la tabal en la que desea trabajar\n";
        cout << "1. -----MARCAS-----\n";
        cout << "2. -----PRODUCTOS--\n";
        cout << "3. -----SALIR------\n";
        cin >> op1;
        cin.ignore();
        switch (op1)
        {
        case 1:
            system("cls");
            cout << "Ingrese el numero de la opcion a realizar\n";
            cout << "--------MARCAS--------\n";
            cout << "1. Ingresar en marcas\n";
            cout << "2. Ver en marcas\n";
            cout << "3. Modificar en marcas\n";
            cout << "4. Eliminar en marcas\n";
            cin >> op2;
            cin.ignore();
            switch (op2)
            {
            case 1:
                create_marca();
                break;
            case 2:
                read_marca();
                break;
            case 3:
                update_marca();
                break;
            case 4:
                delete_marca();
                break;
            default:
                break;
            }
            break;
        case 2:
            system("cls");
            cout << "Ingrese el numero de la opcion a realizar\n";
            cout << "--------PRODUCTOS--------\n";
            cout << "1. Ingresar en productos\n";
            cout << "2. Ver en productos\n";
            cout << "3. Modificar en productos\n";
            cout << "4. Eliminar en productos\n";
            cin >> op2;
            cin.ignore();
            switch (op2)
            {
            case 1:
                create_producto();
                break;
            case 2:
                read_producto();
                break;
            case 3:
                update_producto();
                break;
            case 4:
                delete_producto();
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    } while (op1 != 3);
    return 0;
}
void create_marca() {
    string marca;
    system("cls");
    cout << "Ingrese el nombre de la marca: ";
    getline(cin, marca);
    Marca m = Marca(marca);
    m.crear();
    system("pause");
}

void read_marca() {
    system("cls");
    Marca m = Marca();
    m.leer();
    system("pause");
}

void update_marca() {
    string marca;
    int idmarca;
    system("cls");
    cout << "Ingrese el id a modificar: ";
    cin >> idmarca;
    cin.ignore();
    cout << "Ingrese el nuevo nombre de la marca: ";
    getline(cin, marca);
    Marca m = Marca(marca);
    m.modificar(idmarca);
    system("pause");
}

void delete_marca() {
    int idmarca;
    system("cls");
    cout << "Ingrese el id de la marca a eliminar: ";
    cin >> idmarca;
    cin.ignore();
    Marca m = Marca();
    m.eliminar(idmarca);
    system("pause");
}

void create_producto() {
    string producto, descripcion, imagen, fecha_ingreso;
    int idmarca = 0, existencia = 0;
    double precio_costo = 0, precio_venta = 0;
    system("cls");
    cout << "Ingrese el nombre del producto: ";
    getline(cin, producto);
    cout << "Ingrese el idmarca del producto: ";
    cin >> idmarca;
    cin.ignore();
    cout << "Ingrese la descripcion del producto: ";
    getline(cin, descripcion);
    cout << "Ingrese la imagen del producto: ";
    getline(cin, imagen);
    cout << "Ingrese el precio de costo del producto: ";
    cin >> precio_costo;
    cin.ignore();
    cout << "Ingrese el precio de venta del producto: ";
    cin >> precio_venta;
    cin.ignore();
    cout << "Ingrese la cantindad de existencias del producto: ";
    cin >> existencia;
    cin.ignore();
    cout << "Ingrese la fecha y hora de ingreso del producto: ";
    getline(cin, fecha_ingreso);
    Producto p = Producto(producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso);
    p.crear();
    system("pause");
}

void read_producto() {
    system("cls");
    Producto p = Producto();
    p.leer();
    system("pause");
}

void update_producto() {
    string producto, descripcion, imagen, fecha_ingreso;
    int idproducto = 0, idmarca = 0, existencia = 0;
    double precio_costo = 0, precio_venta = 0;
    system("cls");
    cout << "Ingrese el id del producto a modificar: ";
    cin >> idproducto;
    cin.ignore();
    cout << "Ingrese el nuevo nombre del producto: ";
    getline(cin, producto);
    cout << "Ingrese el nuevo idmarca del producto: ";
    cin >> idmarca;
    cin.ignore();
    cout << "Ingrese la nueva descripcion del producto: ";
    getline(cin, descripcion);
    cout << "Ingrese la nueva imagen del producto: ";
    getline(cin, imagen);
    cout << "Ingrese el nuevo precio de costo del producto: ";
    cin >> precio_costo;
    cin.ignore();
    cout << "Ingrese el nuevo precio de venta del producto: ";
    cin >> precio_venta;
    cin.ignore();
    cout << "Ingrese la nueva cantindad de existencias del producto: ";
    cin >> existencia;
    cin.ignore();
    cout << "Ingrese la nueva fecha y hora de ingreso del producto: ";
    getline(cin, fecha_ingreso);
    Producto p = Producto(producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso);
    p.modificar(idproducto);
    system("pause");
}

void delete_producto() {
   int idproducto;
   system("cls");
   cout << "Ingrese el id del producto a eliminar: ";
   cin >> idproducto;
   cin.ignore();
   Producto p = Producto();
   p.eliminar(idproducto);
   system("pause");
}