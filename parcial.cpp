#include <iostream>
#include <algorithm>
using namespace std;
// ############# quiz 1 #####################
int main(){
    // Pregunta 1.1
    int variableEntera = 20;
    float variableDecimal = 5.5;
    string variableCadena = "Hola"; 

    cout << "Variable entera: " << variableEntera << "\n";
    cout << "Variable decimal: " << variableDecimal << "\n";
    cout << "Variable cadena: " << variableCadena << "\n";

    /* Pregunta 1.2  
    DIFERENCIA ENTRE TIPOS DE DATOS INT, FLOAT, CHAR
    INT: el tipo de dato int, almacena numeros enteros, es decir sin decimales.
    FLOAT: el tipo de dato float, almacena numeros con decimales.
    CHAR:  el tipo de datos char o cadena de texto almacena caracteres, letras o palabras entre comillas.

    Diferencia entre los tres tipos de datos:
    la diferencia es el tipo de datos que puede almacenar sin dar un error de tipo "Type",
    es recomendable usar el tipo de dato adecuado para cada variable para no tener errores en la ejecución.
    */

    // ########### OPERADORES #########

    // Pregunta 2.1
    int a,b;
    cout<< "\n\nIngrese el primer valor: ";
    cin>> a;
    cout<< "\ningrese el segundo valor:";
    cin>> b;

    int suma = a + b;
    int resta = a - b;
    int multiplicacion = a * b;


    cout << "Las operaciones entre " << a  << " " << "y" << " " <<  b << " son: \n";
    cout << "Suma: " << suma << "\n";
    cout << "Resta: " << resta << "\n";
    cout << "Multiplicacion: " << multiplicacion << "\n";

    if (b != 0){
        float division = static_cast<float>(a) / b;
        cout << "Division: " << division << "\n";
    }else{
        cout << "Error: DIVISION por cero no definida.\n";
    }

    /* 
    Pregunta 2.2
    La diferencia entre los comparadores "==" y "!=" es que
    el "==" compara si dos valores son iguales y devuelve true si se cumple
    y false si no se cumple, y el "!=" compara si dos valores son diferentes
    y devuelve true si lo son y false si no lo son.
    */

    /*
    Pregunta 2.3
    Los operadores logicos se usan de la siguiente manera: 
    AND (&&): devuelve true si ambas condiciones son true.
    OR (||): devuelve true si al menos una de las condiciones es true.
    NOT (!): invierte el valor de la condicion, si es true devuelve false y viceversa.
    */

    // ########### CONDICIONALES #########
    // Pregunta 3.1

    int edad;
    cout << "\n\n Ingrese su edad: ";
    cin >> edad;
    if(edad >= 18){
        cout<< "Usted es mayor de edad. \n";
    }else if (edad <= 17){
        cout<< "Usted es menor de edad. \n";
    }else{
        cout<< "Ingrese una edad valida. \n";
    }


    /* 
    pregunta 3.2 
    la estructura if en c++ funciona como una condicion o toma de decisiones,
    donde si se cumple la condicion se ejecutara el bloque de codigo dentro del if,
    esta estructura se puede complementar con el else if que tambien lleva una condicion dentro
    en caso de que la condicion del if o de un anterior else if no se cumpla, y por ultimo tambien se 
    puede acompañar de un else, que no lleva condicion y solo se ejecutara en caso de que 
    ninguna de las condiciones antriores se cumplan.

    un ejemplo donde se puede usar if, else if o else, es en la toma de decisiones,
    por ejemplo en el acceso de usuarios a una plataforma, donde si el usuario es
    mayor de edad se le permite el acceso, si es menor de edad se le niega el acceso,
    y si no ingresa una edad valida se le pide que ingrese una edad valida.
    */

    // ########### BUCLES #########
    // Pregunta 4.1
    for (int i = 1; i <= 10; i++){
        cout << i << " ";
    }

    // Pregunta 4.2
    int j = 10;
    cout << "\n\n";
    while (j >= 1){
        cout << j << " ";
        j--;
    }
    
    // Pregunta 4.3
    int h = 1;
    cout << "\n\n";
    do {
        if (h % 2 == 0){
            cout << h << " ";
        }
        h++;
    } while (h <= 20);
    cout << "\n";

    // ARRAYS
    //Pregunta 5.1
    int numeros[5];
    cout << "\nIngrese 5 numeros enteros: \n";
    for (int i = 0; i < 5; i++){
        cout << "Numero " << i + 1 << ": ";
        cin >> numeros[i];
    }
    cout << "Los numeros ingresados son: \n";
    for (int i = 0; i < 5; i++){
        cout << numeros[i] << " ";
    }
    cout << "\n";

    /*
    Pregunta 5.2
    Un array bidimensional consta de dos dimensiones, filas y columnas,
    y se accede a sus elementos por medio de dos indices, uno para las filas y otro
    para las columnas.
    */
    //Da un ejemplo en C++ de cómo declarar y acceder a un array bidimensional de tamaño 2x3.
    int matriz[2][3] = { {1, 2, 3}, {4, 5, 6} };
    cout << "\nAccediendo a un array bidimensional 2x3:\n";
    
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }

    // Pregnta 5.3
    int matriz3x3[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int sumaMatriz = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            sumaMatriz += matriz3x3[i][j];
        }
    }
    cout << "\nLa suma de todos los elementos de la matriz 3x3 es: " << sumaMatriz << "\n";

    return 0;

}