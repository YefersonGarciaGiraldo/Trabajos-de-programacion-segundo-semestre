#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>

using namespace std;


// funcion para separar ejercicios en consola
void Funcionseparar(int numeroEjercicio = 0 ){
  int cant = 20;
  cout<<"\n";
  if(numeroEjercicio != 0){
    cant = 10;
  for(int z=0 ; z<cant; z++){ cout<< "="; }
  cout<< " " << numeroEjercicio << " ";
  for(int z=0 ; z<cant; z++){ cout<< "="; }
  }else{ 
  for(int z=0; z<cant ; z++){cout << "=";}
  }
  cout<<"\n";
}

// ======================================== TALLER STRUCT =========================================

// 1. Struct con constructores y valores por defecto:
struct Producto{
    string nombre;
    double precio = 0.0;
    int stock = 0 ;

    // constructor por defecto
    Producto(string n, double p = 0.0, int s = 0) : nombre(n), precio(p),stock(s){}

    //2. Métodos const y validación:
    bool disponible() const { return stock > 0;}

    bool esValido() const {return precio >= 0 && !nombre.empty();}

    // Comparar ignorando mayusculas/minusculas
    bool operator==(const Producto& other) const {
        string n1 = nombre;
        string n2 = other.nombre;
        // conversion mayusculas
        transform(n1.begin(), n1.end(), n1.begin(),[](unsigned char c){ return tolower(c); });
        transform(n2.begin(), n2.end(), n2.begin(),[](unsigned char c){ return tolower(c); });
        // comparación
        return n1 == n2;
    } 

    // ordenar por precio ascendente
    bool operator <(const Producto& other) const{
        if(precio < other.precio)return true;
        if(precio > other.precio)return false;
        return nombre < other.nombre;
    };
}
    // Productos construidos de distintas formas
    producto1{"Laptop", 2000000, 5},
    producto2{"Iphone", 1200000},
    producto3{"Airpoods"}
;

// 4. Crea una estructura para representar un polinomio
struct Polinomio{
    double coeficiente = 0.0;
    int exponente = 0;    
};

struct Termino{
    Polinomio terminos[100];
    int cantidad;
};

// 5. Implementa un sistema de inventario más complejo
struct InventarioComplejo{
    vector<Producto> mainInventario;
};

void FuncionAgregarProducto(InventarioComplejo &inv, const string &nombre, double precio, int stock){
    inv.mainInventario.push_back({nombre,precio,stock});
}

void FuncionVerInventario(const InventarioComplejo &inv){
    cout<< "Inventario: "<<endl;
    if(inv.mainInventario.empty()){
        cout << "Inventario vacio"<<endl;
        return; 
    }
    for(const auto &p : inv.mainInventario){
        cout<< "Nombre: " << p.nombre << " | Precio: "<< p.precio << " | Stock: " << p.stock << endl;
    }
}

int FuncionBuscarProducto(const InventarioComplejo &inv, const string &nombre){
    for(size_t i =0;i < inv.mainInventario.size(); i++){
        if(inv.mainInventario[i].nombre == nombre){
            return i;
        }
    }
    return -1;
}

bool eliminarProducto(InventarioComplejo &inv, const string &nombre) {
    int id = FuncionBuscarProducto(inv, nombre);
    if(id != -1) {
        inv.mainInventario.erase(inv.mainInventario.begin() + id);
        return true;
    }
    return false;
}

// 6. Desarrolla una estructura para representar una fracción
struct Fraccion {
    int numerador;
    int denominador;
};

// 7. Crea un sistema de gestión de contactos
struct Contacto {
    string nombre;
    string telefono;
    string correo;
};

int main(){
    
    Funcionseparar(1);

    // 1. Struct con constructores y valores por defecto:
    cout<< fixed <<setprecision(0);
    // Imprimir productos
    cout<< "Productos disponibles: " <<endl;
    cout<< "Nombre: "<< producto1.nombre << " | Precio: " << producto1.precio << " | Stock: " << producto1.stock <<endl;
    cout<< "Nombre: "<< producto2.nombre << " | Precio: " << producto2.precio << " | Stock: " << producto2.stock <<endl;
    cout<< "Nombre: "<< producto3.nombre << " | Precio: " << producto3.precio << " | Stock: " << producto3.stock <<endl;

    Funcionseparar(2);

    // 2. Métodos const y validación:
    vector<Producto> productos = {
        {"Antena", 600000, 40},
        {"Laptop", 2000000, 5},
        {"Celular", 600000, 4},
        {"Iphone", 1200000, 60},
        {"Bafle"},
        {"", 50, 10},
        {"Tablet", 800000, 0},
        {"Audifonos", -100, 15},
        {"Base TV", 600000, 8}
    };

    // filtrar y eliminar productos no validos
    productos.erase(
        remove_if(productos.begin(), productos.end(),
            [](const Producto& p){ return !p.esValido(); }),
        productos.end()
    );

    // imprimir validos
    cout<< "productos validos"<<endl;
    for (const auto& p : productos) {
    cout << "Nombre: " <<  p.nombre << " | Precio:  " << p.precio << " | Stock: " << p.stock << "\n";
    }

    Funcionseparar(3);

    // 3. Operadores == y < para ordenar y buscar:
    sort(productos.begin(), productos.end());

    // productos ordenados
    cout<< "Productos ordenados: "<<endl;
        for (const auto& p : productos) {
    cout << "Nombre: " <<  p.nombre << " | Precio:  " << p.precio << " | Stock: " << p.stock << "\n";
    }

    Funcionseparar();

    // buscar productos validos con find ==
    Producto buscado{"IPHONE"}; 
    auto it = find(productos.begin(), productos.end(), buscado);

    if (it != productos.end()){
        cout << "Encontrado: "<< endl << "Nombre: " << it->nombre << endl << "Precio: " << it->precio
        << endl << "Stock: "<< it ->stock << endl;

    }else{cout << "No encontrado" << endl;}

    Funcionseparar(4);
    // 4. Crea una estructura para representar un polinomio

    Termino prueba;
    prueba.cantidad = 5;

    for(int i = 0 ; i < prueba.cantidad; i++){
        double al = i*3-5;
        prueba.terminos[i] = {al , i};
    }

    // Imprimir en consola
    cout<< "Polinomio: " <<endl;
    bool primerTermino =true;

    for(int i = prueba.cantidad -1 ; i >= 0; i--){
        double coef = abs(prueba.terminos[i].coeficiente);
        if(coef == 0)continue;

        if(primerTermino){
            if(prueba.terminos[i].coeficiente < 0){
                cout<< "-";
            }
            primerTermino = false;
        }else{
            cout <<(prueba.terminos[i].coeficiente < 0 ? " - " : " + "); 
        }
        if(prueba.terminos[i].exponente == 0){
            cout<< coef;
        }else{
            cout << coef <<"X^" << prueba.terminos[i].exponente;
        }
    }
    cout << endl;

    Funcionseparar(5);
    // 5. Implementa un sistema de inventario más complejo
    InventarioComplejo inv;
    // Agregando productos
    cout<<"Agregando productos....."<<endl;
    FuncionAgregarProducto(inv, "Laptop", 2500000, 5);
    FuncionAgregarProducto(inv, "Iphone", 1200000, 60);
    FuncionAgregarProducto(inv, "Bafle", 350000, 10);
    FuncionAgregarProducto(inv, "Monitor", 800000, 15);

    Funcionseparar();

    // Mostrar inventario
    cout<< "Productos agregados con exito!"<<endl;
    FuncionVerInventario(inv);

    Funcionseparar();

    cout<< "Eliminando \"bafle\"......."<<endl;
    // eliminar productos
        if(eliminarProducto(inv, "Bafle"))
        cout << "Producto \" bafle \" eliminado.\n";
    else
        cout << "No se encontro el producto.\n";

    Funcionseparar();

    // inventario actualizado
    cout<<"Nuevo inventario: "<<endl;
    FuncionVerInventario(inv);

    Funcionseparar(6);

    // 6. Desarrolla una estructura para representar una fracción
    Fraccion f1;

    f1.numerador = 3;
    f1.denominador = 5;

    cout << "La fraccion es: " << f1.numerador << "/" << f1.denominador << endl;

    Funcionseparar(7);

    const int MAX_CONTACTOS = 3;
    Contacto contactos[MAX_CONTACTOS];

    cout<< "Ingrese los contactos: "<<endl;

    // Registrar contactos
    for(int i = 0; i < MAX_CONTACTOS; i++) {
        cout << "Contacto " << i+1 << endl;
        cout << "Nombre: ";
        getline(cin, contactos[i].nombre);
        cout << "Telefono: ";
        getline(cin, contactos[i].telefono);
        cout << "Correo: ";
        getline(cin, contactos[i].correo);
        cout << endl;
    }

    Funcionseparar();

    // Mostrar todos los contactos
    cout << "Lista de contactos:"<<endl;

    Funcionseparar();

    for(int i = 0; i < MAX_CONTACTOS; i++) {
        cout << "Nombre: " << contactos[i].nombre << endl;
        cout << "Telefono: " << contactos[i].telefono << endl;
        cout << "Correo: " << contactos[i].correo << endl;
        Funcionseparar();
    }
    return 0;
}