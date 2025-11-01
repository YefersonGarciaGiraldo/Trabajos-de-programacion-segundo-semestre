#include <iostream>
#include <cstring> 
#include <cstdlib>
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
};


void leer_arreglo(int *a, size_t n){
    int falta = n;
    for(size_t i =0 ; i<n ; i++){
        cout << "Faltan " << falta << "numeros por ingresar. Ingrese el proximo"<<endl;
        cin >> *(a+i);
        falta -= 1;
    }
}

void min_max_prom(const int *a, size_t n, int *minv, int *maxv, double *prom){
    const int *ptr = a;
    *minv = *maxv = *ptr;
    long long suma =0;

    for(size_t i=0; i<n; i++ , ptr++ ){   
        if (*ptr < *minv) *minv = *ptr;
        if (*ptr > *maxv) *maxv = *ptr;
        suma += *ptr;
    }

    *prom = static_cast<double>(suma) / n;
}

void Ejercicio1(){
    size_t cantidad = 0;
    cout<< "Ingrese la cantidad de numeros que desea ingresar: "<<endl;
    cin>> cantidad;
    if(cantidad < 1 || cantidad > 100.000){
        cout << "Error: Cantidad fuera de rango (1-100.000)";
    }else{
        int *array =new int[cantidad];
        int minv, maxv;
        double prom;
        leer_arreglo(array,cantidad);
        min_max_prom(array, cantidad, &minv, &maxv, &prom);
        cout << "Minimo: " << minv << endl << "Maximo: " << maxv << endl << "Promedio: " << prom << endl;
        delete[] array;
    }
}

// Ejercicio 2
void reverse(int *a, size_t i, size_t j){
    while (i < j) {
        int temp = *(a + i);
        *(a + i) = *(a + j);
        *(a + j) = temp;
        i++;
        j--;
    }
}

void rotar_derecha(int *a, size_t n, size_t k){
    if (n == 0) return;
    k = k % n;
    if (k == 0) return;

    reverse(a, 0, n - 1);
    reverse(a, 0, k - 1);
    reverse(a, k, n - 1);
}


void Ejercicio2(){
    size_t n, k;
    cout << "Ingrese la cantidad de elementos del arreglo: ";
    cin >> n;
    int *a = new int[n];
    leer_arreglo(a, n);
    cout << "Ingrese el numero de posiciones a rotar: ";
    cin >> k;
    rotar_derecha(a, n, k);
    cout << "Arreglo rotado: ";
    for (size_t i = 0; i < n; i++) {
        cout << *(a + i) << " ";
    }
    cout << endl;
    delete[] a;
}


// Ejercicio 3
size_t normalizar_espacios(const char *in, char *out, size_t outcap) {
    const char *src = in;
    char *dst = out;
    bool en_espacio = true; 
    size_t count = 0;
    while (*src && count + 1 < outcap) {
        if (*src != ' ') {
            *dst++ = *src;
            en_espacio = false;
            count++;
        } else if (!en_espacio) {
            *dst++ = ' ';
            count++;
            en_espacio = true;
        }
        src++;
    }
    if (count > 0 && *(dst - 1) == ' ') {
        dst--;
        count--;
    }
    *dst = '\0';
    return count;
}


void Ejercicio3(){
    const size_t MAX = 1000;
    char entrada[MAX];
    char salida[MAX];
    cout << "Ingrese una linea (max 1000 caracteres): ";
    cin.getline(entrada, MAX);
    size_t len = normalizar_espacios(entrada, salida, MAX);
    cout << "Cadena normalizada: \"" << salida << "\"" << endl;
    cout << "Longitud: " << len << endl;

}



int **mat_crear(size_t m, size_t n) {
    int **A = new int*[m];
    for (size_t i = 0; i < m; i++) {
        A[i] = new int[n];
    }
    return A;
}

void mat_destruir(int **A, size_t m) {
    for (size_t i = 0; i < m; i++) {
        delete[] A[i];
    }
    delete[] A;
}

void mat_sumas(int **A, size_t m, size_t n, int *sumF, int *sumC) {
    for (size_t j = 0; j < n; j++)
        sumC[j] = 0;

    for (size_t i = 0; i < m; i++) {
        sumF[i] = 0; 
        for (size_t j = 0; j < n; j++) {
            int val = *(*(A + i) + j);
            sumF[i] += val;
            sumC[j] += val;
        }
    }
}


void Ejercicio4(){ 
        size_t m, n;
    cout << "Ingrese el numero de filas: ";
    cin >> m;
    cout << "Ingrese el numero de columnas: ";
    cin >> n;
    if (m < 1 || n < 1 || m > 1000 || n > 1000) {
        cout << "Error: dimensiones fuera de rango." << endl;
    }
    int **mat = mat_crear(m, n);
    cout << "Ingrese los elementos de la matriz (" << m << "x" << n << "):" << endl;
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            cin >> *(*(mat + i) + j);
        }
    }
    int *sumF = new int[m];
    int *sumC = new int[n];
    mat_sumas(mat, m, n, sumF, sumC);
    cout << "sumF: [";
    for (size_t i = 0; i < m; i++) {
        cout << sumF[i];
        if (i < m - 1) cout << ",";
    }
    cout << "]" << endl;

    cout << "sumC: [";
    for (size_t j = 0; j < n; j++) {
        cout << sumC[j];
        if (j < n - 1) cout << ",";
    }
    cout << "]" << endl;

    delete[] sumF;
    delete[] sumC;
    mat_destruir(mat, m);
}

typedef struct {
    char nombre[40];
    int edad;
    double promedio;
} Estudiante;

int cmp_prom_desc(const void *a, const void *b) {
    const Estudiante *e1 = (const Estudiante*)a;
    const Estudiante *e2 = (const Estudiante*)b;
    if (e1->promedio < e2->promedio) return 1;
    if (e1->promedio > e2->promedio) return -1;
    return 0;
}

int buscar_nombre(Estudiante *v, size_t n, const char *clave) {
    for (size_t i = 0; i < n; i++) {
        if (strcmp(v[i].nombre, clave) == 0) {
            return static_cast<int>(i);
        }
    }
    return -1; 
}

void Ejercicio5(){
     size_t n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;
    cin.ignore(); 

    if (n < 1 || n > 1000) {
        cout << "Error: cantidad fuera de rango (1-1000)." << endl;
    }
    Estudiante *v = new Estudiante[n];
    cout << "Ingrese los datos de los estudiantes:" << endl;
    for (size_t i = 0; i < n; i++) {
        cout << "\nEstudiante " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin.getline(v[i].nombre, 40);
        cout << "Edad: ";
        cin >> v[i].edad;
        cout << "Promedio: ";
        cin >> v[i].promedio;
        cin.ignore();
    }

    qsort(v, n, sizeof(Estudiante), cmp_prom_desc);

    cout << "\n=== Estudiantes ordenados por promedio (descendente) ===" << endl;
    for (size_t i = 0; i < n; i++) {
        cout << i + 1 << ". " << v[i].nombre 
             << " | Edad: " << v[i].edad
             << " | Promedio: " << v[i].promedio << endl;
    }

    cout << "\n=== TOP 3 ===" << endl;
    for (size_t i = 0; i < n && i < 3; i++) {
        cout << v[i].nombre << " (" << v[i].promedio << ")" << endl;
    }

    char clave[40];
    cout << "\nIngrese un nombre a buscar: ";
    cin.getline(clave, 40);

    int pos = buscar_nombre(v, n, clave);
    if (pos != -1) {
        cout << "\nEncontrado en la posición " << pos 
             << ": " << v[pos].nombre
             << ", Edad: " << v[pos].edad
             << ", Promedio: " << v[pos].promedio << endl;
    } else {
        cout << "\nEstudiante no encontrado." << endl;
    }

    delete[] v;
}

typedef struct Nodo {
    int x;
    struct Nodo *sig;
} Nodo;

void push_front(Nodo **head, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo) return;
    nuevo->x = valor;
    nuevo->sig = *head;
    *head = nuevo;
}

void push_back(Nodo **head, int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo) return;
    nuevo->x = valor;
    nuevo->sig = NULL;

    if (*head == NULL) {
        *head = nuevo;
        return;
    }

        Nodo *actual = *head;
    while (actual->sig != NULL) {
        actual = actual->sig;
    }
    actual->sig = nuevo;
}

void pop_front(Nodo **head) {
    if (*head == NULL) return;
    Nodo *temp = *head;
    *head = (*head)->sig;
    free(temp);
}

int size(Nodo *head) {
    int c = 0;
    while (head != NULL) {
        c++;
        head = head->sig;
    }
    return c;
}

void clear(Nodo **head) {
    while (*head != NULL) {
        pop_front(head);
    }
}

void print_list(Nodo *head) {
    Nodo *actual = head;
    while (actual != NULL) {
        printf("%d ", actual->x);
        actual = actual->sig;
    }
    printf("\n");
}

void Ejercicio6() {
    Nodo *lista = NULL;
    char cmd[10];
    int val;

    while (1) {
        if (scanf("%s", cmd) != 1) break;

        if (strcmp(cmd, "pf") == 0) {      // push_front
            scanf("%d", &val);
            push_front(&lista, val);
        } 
        else if (strcmp(cmd, "pb") == 0) { // push_back
            scanf("%d", &val);
            push_back(&lista, val);
        } 
        else if (strcmp(cmd, "pop") == 0) { // pop_front
            pop_front(&lista);
        } 
        else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", size(lista));
        } 
        else if (strcmp(cmd, "clear") == 0) {
            clear(&lista);
        } 
        else if (strcmp(cmd, "fin") == 0) {
            break;
        }
    }

    print_list(lista);
    clear(&lista);
}


int doble(int x) {
    return 2 * x;
}

int cuadrado(int x) {
    return x * x;
}

void aplicar(int *a, size_t n, int (*op)(int)) {
    for (size_t i = 0; i < n; i++) {
        a[i] = op(a[i]);
    }
}

void Ejercicio7() {
    size_t n;
    printf("Ingrese cantidad de elementos: ");
    scanf("%zu", &n);

    int *a = (int*)malloc(n * sizeof(int));
    if (!a) {
        printf("Error de memoria\n");
    }

    printf("Ingrese los %zu numeros:\n", n);
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int opcion;
    printf("\nSeleccione operacion:\n");
    printf("1. Doble\n");
    printf("2. Cuadrado\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        aplicar(a, n, doble);
    } else if (opcion == 2) {
        aplicar(a, n, cuadrado);
    } else {
        printf("Opcion invalida\n");
        free(a);
    }

    printf("\nResultado:\n");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);
}


typedef struct {
    char prod[32];
    int unidades;
    double precio;
} Venta;

size_t contar_lineas(FILE *f) {
    size_t count = 0;
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), f)) count++;
    rewind(f);
    return count;
}

Venta* leer_csv(const char *nombre, size_t *n) {
    FILE *f = fopen(nombre, "r");
    if (!f) {
        printf("Error al abrir el archivo: %s\n", nombre);
        return NULL;
    }

    *n = contar_lineas(f);
    if (*n == 0) {
        printf("Archivo vacío.\n");
        fclose(f);
        return NULL;
    }

    Venta *ventas = (Venta*)malloc(*n * sizeof(Venta));
    if (!ventas) {
        printf("Error de memoria.\n");
        fclose(f);
        return NULL;
    }

    size_t i = 0;
    char linea[128];
    while (fgets(linea, sizeof(linea), f)) {
        linea[strcspn(linea, "\n")] = 0;
        sscanf(linea, "%31[^,],%d,%lf", ventas[i].prod, &ventas[i].unidades, &ventas[i].precio);
        i++;
    }

    fclose(f);
    return ventas;
}

void estadisticas(Venta *v, size_t n) {
    if (n == 0) return;

    double total_vendido = 0;
    int max_unidades = v[0].unidades;
    size_t idx_top = 0;

    for (size_t i = 0; i < n; i++) {
        total_vendido += v[i].unidades * v[i].precio;
        if (v[i].unidades > max_unidades) {
            max_unidades = v[i].unidades;
            idx_top = i;
        }
    }

    double ticket_promedio = total_vendido / n;

    printf("\n=== Estadísticas ===\n");
    printf("Total vendido: %.2f\n", total_vendido);
    printf("Producto más vendido: %s (%d unidades)\n", v[idx_top].prod, v[idx_top].unidades);
    printf("Ticket promedio: %.2f\n", ticket_promedio);
}

void Ejercicio8() {
    char archivo[64];
    printf("Ingrese el nombre del archivo CSV: ");
    scanf("%63s", archivo);

    size_t n = 0;
    Venta *ventas = leer_csv(archivo, &n);

    printf("\nVentas cargadas (%zu registros):\n", n);
    for (size_t i = 0; i < n; i++) {
        printf("%-10s | unidades=%d | precio=%.2f\n",
               ventas[i].prod, ventas[i].unidades, ventas[i].precio);
    }

    estadisticas(ventas, n);

    free(ventas);
}

int main() {
    int opcion=0;
    Funcionseparar();
    do {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1. Ejercicio 1 - Minimo, Maximo y Promedio\n";
        cout << "2. Ejercicio 2 - Rotar arreglo a la derecha\n";
        cout << "3. Ejercicio 3 - Normalizar espacios en cadena\n";
        cout << "4. Ejercicio 4 - Suma de filas y columnas de matriz\n";
        cout << "5. Ejercicio 5 - Ordenar y buscar estudiantes\n";
        cout << "6. Ejercicio 6 - Lista enlazada con comandos\n";
        cout << "7. Ejercicio 7 - Aplicar funcion (doble/cuadrado)\n";
        cout << "8. Ejercicio 8 - Leer CSV y mostrar estadisticas\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // limpia buffer por si hay saltos de línea

        switch (opcion) {
            case 1:
                Ejercicio1();
                break;
            case 2:
                Ejercicio2();
                break;
            case 3:
                Ejercicio3();
                break;
            case 4:
                Ejercicio4();
                break;
            case 5:
                Ejercicio5();
                break;
            case 6:
                Ejercicio6();
                break;
            case 7:
                Ejercicio7();
                break;
            case 8:
                Ejercicio8();
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida, intente nuevamente." << endl;
                break;
        }

        cout << "\nPresione Enter para continuar...";
        cin.get();

    } while (opcion != 0);

    return 0;
}