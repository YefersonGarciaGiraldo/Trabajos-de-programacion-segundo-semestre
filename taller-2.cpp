#include <iostream>
#include <algorithm>
using namespace std;

// ================ FUNCIONES PARA EL EJERCICIO 4 ================

// Función para buscar un producto, devuelve la posición o -1 si no lo encuentra
int funcionBuscarProducto(string productos[], int tamanioArray, string nombreProducto) {
    for (int i = 0; i < tamanioArray; i++) {
        if (productos[i] == nombreProducto) {
            return i;
        }
    }
    return -1;
}
// Función para modificar la cantidad de un producto
void modificarCantidad(string productos[], int cantidades[], int tamanioArray, string nombreProducto, int nuevaCantidad) {
    int posicion = funcionBuscarProducto(productos, tamanioArray, nombreProducto);
    if (posicion != -1) {
        cantidades[posicion] = nuevaCantidad;
        cout << "\nCantidad actualizada.\n";
        cout<< "Producto: " << productos[posicion] << "\nNueva cantidad: " << cantidades[posicion] << " unidades\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}
// Función para eliminar un producto
void eliminarProducto(string productos[], int cantidades[], int &tamanioArray, string nombreProducto) {
    int posicion = funcionBuscarProducto(productos, tamanioArray, nombreProducto);
    if (posicion != -1) {
        for (int i = posicion; i < tamanioArray - 1; i++) {
            productos[i] = productos[i + 1];
            cantidades[i] = cantidades[i + 1];
        }
        tamanioArray--;
        cout << "\nProducto "<< nombreProducto << " eliminado.\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}
// Función para agregar un producto
void agregarProducto(string productos[], int cantidades[], int &tamanioArray, string nuevoProducto, int cantidad) {
    productos[tamanioArray] = nuevoProducto;
    cantidades[tamanioArray] = cantidad;
    tamanioArray++;
    cout << "Producto agregado.\n";
    cout<< "Producto: " << nuevoProducto << "\nCantidad: " << cantidad << " unidades\n";
}
// Función para mostrar el inventario
void mostrarInventario(string productos[], int cantidades[], int tamanioArray) {
    cout << "\nInventario:\n";
    for (int i = 0; i < tamanioArray; i++) {
        cout << productos[i] << ": " << cantidades[i] << " unidades\n";
    }
}

// ================== FUNCIONES PARA EL EJERCICIO 7 ================
// Función para verificar si hay un ganador
bool verificarGanador(char tablero[3][3], char jugador) {
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador)
            return true;
        if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)
            return true;
    }
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador)
        return true;
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)
        return true;
    return false;
}

// ================ FUNCION PRINCIPAL, INICIO TALLER ================
int main(){
    cout << "\n===== Taller 2 =====\n\n";
    // se define un array de trabajo para el documento
    int arreglo[20] = {34, 7, 23, 32, 5, 62, 32, 7, 78, 90, 12, 45, 67, 89, 21, 43, 56, 78, 90, 11};
    // se muestra en consola el array inicial
    cout << "Array inicial de trabajo: \n";
    for(int i =0; i < 20 ; i++){
        cout<< arreglo[i] << " ";
    }
    cout<<"\n";

// ================== EJERCICIO #1 ==================

    cout<< "\n=============== \n";
    cout << "1. Crea un programa que encuentre la mediana de un array:\n";
    cout<< "=============== \n\n";
    // se hace una copia para no modificar el array original
    int arrayOrdenado[20];
    for(int i=0; i<20; i++) {
        arrayOrdenado[i] = arreglo[i];
    }
    // se ordena el array con la funcion sort de la libreria algorithm
    sort(arrayOrdenado, arrayOrdenado + 20);
    // se muestra el array ordenado en consola
    cout << "Array ordenado: \n";
    for(int i =0; i < 20 ; i++){
        cout<< arrayOrdenado[i] << " ";
    }
    // se cuenta el numero de elementos y se calcula la mediana segun sea par o impar
    int cantidadElementos = sizeof(arrayOrdenado) / sizeof(arrayOrdenado[0]);
    if(cantidadElementos %2 ==0 ){
        int elemento1 = arrayOrdenado[cantidadElementos/2 -1];
        int elemento2 = arrayOrdenado[cantidadElementos/2];
        double mediana = (elemento1 + elemento2) / 2.0;
        cout << "\n\nMediana: \n" << mediana << "\n\n";
    } else{
        double mediana =arrayOrdenado[cantidadElementos/2];
        cout << "\n\nLa mediana de el arreglo es: " << mediana << "\n\n";
    }

// ================== EJERCICIO #2 ==================

    cout<< "\n=============== \n";
    cout << "2. Implementa la búsqueda binaria en un array ordenado\n";
    cout<< "=============== \n\n";

    // se reutiliza el array del ejercicio anterior
    // se declara el elemento a buscar y se le pide al usuario el dato de entrada del elemento
    int elementoBuscar;
    cout<< "ingrese el numero a buscar en el array: ";
    cin>> elementoBuscar;
    bool encontrado = false;
    int posicion = -1;
    // se inicia un ciclo for para recorrer el array y buscar el elemento
    // y se condiciona en caso de que lo encuentre o no
    for ( int i=0 ; i<20 ; i++){ 
        if(arreglo[i] == elementoBuscar){
            encontrado = true;
            posicion = i;
            break;
        }
    }
    if(encontrado){
        cout<<"El elemento " << elementoBuscar << " " << "se encuentra en la posicion " << posicion <<"\n\n";
    }else{
        cout << " El elemento " << elementoBuscar << " " << "no se encontro en el array \n";
    }
    cout << "\n";

// ================== EJERCICIO #3 ==================
    cout<< "\n=============== \n";
    cout << "3. Desarrolla un programa que calcule la transpuesta de una matriz\n";
    cout<< "=============== \n\n";
    // se define una matriz de 3x3
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    // se muestra en consola la matriz
    cout << "Matriz original: \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
    
    // se asigna una variable para almacenar la traspuesta
    int transpuesta[3][3];
    // se recorre la matriz y se intercambian los valores almacenandolos en la variable traspuesta
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            transpuesta[j][i] = matriz[i][j];
        }
    }
    // se muestra la traspuesta en consola
    cout << "\n\nMatriz transpuesta: \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << transpuesta[i][j] << " ";
        }
        cout << "\n";
    }

// ================= EJERCICIO 4 ==================
    cout << "\n===== EJERCICIO 4 =====\n\n";
    cout << "4. Crea un sistema de inventario simple con arrays\n";
    cout << "=======================\n\n";
    // se define un array para los nombres de los productos y otro para las cantidades
    int tamanioInventario = 5;
    string productos[tamanioInventario] = {"Manzana", "Naranja", "Platano", "Uva", "Pera"};
    int cantidades[tamanioInventario] = {50, 30, 20, 15, 25};
    // se muestra el inventario en consola
    cout << "Inventario:\n";
    for(int i = 0 ; i < tamanioInventario; i++){
        cout<< productos[i] << ": " << cantidades[i] << " " << "unidades\n";
    }
    // se inicializa un bucle while para el menu de opciones, que se repetira hasta que el usuario decida salir
    while (true){  
cout << R"(
Bienvenido al sistema de inventario simple
Ingrese una opcion (numero):
1. Buscar producto
2. Modificar cantidad de producto
3. Eliminar producto
4. Agregar producto
5. mostrar inventario
6. Salir y continuar con el taller
)";  
        // se captura la opcion del usuario en la variable "opcion"
        int opcion;
        // se usan condicionales para ejecutar la funcion correspondiente a la opcion seleccionada
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada inválida, ingrese un número.\n";
            continue;
        }else if (opcion == 1) {
            string buscar;
            cout << "Ingrese el nombre del producto a buscar: ";
            cin >> buscar;
            int posicion = funcionBuscarProducto(productos, tamanioInventario, buscar);
            if (posicion != -1)
                cout << "Producto encontrado: " << productos[posicion] << " - Cantidad: " << cantidades[posicion] << " unidades\n";
            else
                cout << "Producto no encontrado.\n";

        } else if (opcion == 2) {
            string nombre;
            int cantidad;
            cout << "Ingrese el nombre del producto a modificar: ";
            cin >> nombre;
            cout << "Ingrese la nueva cantidad: ";
            cin >> cantidad;
            modificarCantidad(productos, cantidades, tamanioInventario, nombre, cantidad);

        } else if (opcion == 3) {
            string nombre;
            cout << "Ingrese el nombre del producto a eliminar: ";
            cin >> nombre;
            eliminarProducto(productos, cantidades, tamanioInventario, nombre);

        } else if (opcion == 4) {
            string nombre;
            int cantidad;
            cout << "Ingrese el nombre del producto a agregar: ";
            cin >> nombre;
            cout << "Ingrese la cantidad: ";
            cin >> cantidad;
            agregarProducto(productos, cantidades, tamanioInventario, nombre, cantidad);

        } else if (opcion == 5) {
            mostrarInventario(productos, cantidades, tamanioInventario);

        }else if (opcion == 6) {
            cout << "Saliendo del sistema...\n";
            break;

        } else {
            cout << "Opcion no valida, intente de nuevo.\n";
        }
    }

// ================= EJERCICIO 5==================
    cout << "\n=============== \n";
    cout << "5. Implementa el algoritmo de ordenamiento por selección\n";
    cout << "=============== \n\n";
    // se reutiliza el array inicial
    int arrayOrdenadoSelect[20];
    for(int i=0; i<20; i++) {
        arrayOrdenadoSelect[i] = arreglo[i];
    }
    // se muestra el array inicial en consola
    cout << "\nArray inicial: \n";
    for(int i =0; i < 20 ; i++){
        cout<< arrayOrdenadoSelect[i] << " ";
    }
    // se implementa el algoritmo de ordenamiento por seleccion
    for (int i = 0; i < 20 - 1; i++){
        int indiceMinimo = i;
        for(int j = i + 1; j < 20; j++){ 
            if (arrayOrdenadoSelect[j] < arrayOrdenadoSelect[indiceMinimo]){
                indiceMinimo = j;
            }
        } 
        int temporal = arrayOrdenadoSelect[i];
        arrayOrdenadoSelect[i] = arrayOrdenadoSelect[indiceMinimo];
        arrayOrdenadoSelect[indiceMinimo] = temporal;
    } 
    // se muestra el array ordenado por seleccion en consola
    cout << "\nArray ordenado por seleccion: \n";
    for(int i =0; i < 20 ; i++){
        cout<< arrayOrdenadoSelect[i] << " ";
    }

// ================ EJERCICIO 6==================
    cout << "\n\n=======================\n";
    cout << "6. Desarrolla un programa que encuentre elementos duplicados\n";
    cout << "=======================\n\n";
    // se reutiliza el array inicial
    int arrayDuplicados[20];
    for(int i=0; i<20; i++) {
        arrayDuplicados[i] = arreglo[i];
    }
    // se muestra el array inicial en consola
    cout << "Buscando elementos duplicados en: \n";
    for(int i =0; i < 20 ; i++){
        cout<< arrayDuplicados[i] << " ";
    } 

    cout << "\nElementos duplicados encontrados: \n";
    // se usa un array booleano para marcar los elementos ya mostrados
    bool mostrados[20] = {false};
    // se usa una variable como bandera para indicar si se encontraron duplicados
    bool hayDuplicados = false;
    // se recorre el array y se comparan los elementos
    for(int i = 0; i < 20 -1; i++){
        if (mostrados[i]) continue;
        bool repetido = false;
        for(int j = i + 1; j < 20; j++){
            if(arrayDuplicados[i] == arrayDuplicados[j]){
                repetido = true;
                mostrados[j] = true;
            }
        }
        // si se encontro un duplicado, se muestra en consola
        if (repetido){
            cout << arrayDuplicados[i] << " ";
            mostrados[i] = true;
            hayDuplicados = true; 
        }
    }
    if (!hayDuplicados){
        cout << "\nNo se encontraron elementos duplicados.\n";
    }

    // ================ EJERCICIO 7==================
    cout << "\n\n=======================\n";
    cout << "7. Crea un juego de tres en raya usando arrays bidimensionales\n";
    cout << "=======================\n\n";
    // se define la matriz de juego
    char tablero[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    // se asignan variables para el juego
    char jugadorActual = 'X';
    int movimientos = 0;
    bool ganador = false;
    // se muestra el estado inicial del tablero
    cout << "Estado inicial del tablero:\n\n";
    for(int f = 0; f < 3; f++){
        for(int c = 0; c < 3; c++){
            cout << "[" << tablero[f][c] << "]";
        }
        cout << "\n";
    }
    // se inicia un ciclo for para el juego, que se repetira hasta que haya un ganador o se llenen las casillas max 9
    for(int i = 0; i < 9; i++){
        int fila, columna;
        // el jugador ingresa la fila y columna donde quiere colocar su ficha y se valida la entrada
        cout << "Turno del jugador " << jugadorActual << ". Ingrese fila y columna (0, 1, o 2) separada por espacio: ";
        if (!(cin >> fila >> columna)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada inválida, ingrese números.\n";
            continue;
        }
        // se valida que la posicion este dentro del rango y que la casilla no este ocupada
        if (fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != ' ') {
            cout << "Movimiento inválido, intente de nuevo.\n";
            continue;
        }else{
            tablero[fila][columna] = jugadorActual;
            movimientos++;
        }
        // se muestra el estado actual del tablero
        cout << "\nEstado actual del tablero:\n";
        for(int f = 0; f < 3; f++){
            for(int c = 0; c < 3; c++){
                cout << "[" << tablero[f][c] << "]";
            }
            cout << "\n";
        }
        // se verifica si hay un ganador o si el juego termina en empate
        if (verificarGanador(tablero, jugadorActual)) {
            cout<< "\n================\n";
            cout << "Jugador " << jugadorActual << " gana!\n";
            cout<< "================\n";
            ganador = true;
            break;
        }else if (movimientos == 9) {
            cout << "\n================\n";
            cout << "El juego termina en empate.\n";
            cout << "================\n";
            break;
        }
        // se cambia de jugador
        jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
    }
    return 0;
}