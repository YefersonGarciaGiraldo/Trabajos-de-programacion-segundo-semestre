#include <iostream> 
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;

//estructura para manejar los datos del primer ejercicio 
struct Persona{
  string nombre,apellido;
  int edad;
  double estatura;
  char inicialApellido;
  bool esEstudiante;
};

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

// funcion que obtiene el año actual desde local
int ObtenerAnioActual(void){
  time_t actual = time(0);
  tm *ltm = localtime(&actual);
  return 1900 + ltm->tm_year; 
};

// funcion que calcula el año segun edad
int CalcularAnioNacimiento(int edad){
    int anioActual = ObtenerAnioActual();
  return anioActual - edad;
};
// funcion factorial
int Funcionfactorial(int a){
  if(a<0) return -1;
  int resultado =1 ;
  for(int n = 1; n <= a; n++){
    resultado *= n;
  }
  return resultado;
};
// funcion suma de digitos
int FuncionSumaDigitos(string numero){
  int suma = 0;
  for(char c : numero ){
    if(c < '0' || c > '9'){
      cout<< "Ingreso un digito no numerico"<<endl;
      return -1;
    }
    suma += c - '0';
  }
  return suma;
}

// funcion principal
int main(void){

Funcionseparar(1);
// Nivel 1: Conceptos Básicos
  Persona p1;
  // nombre
  cout<< "Nombre: "<<endl;
  cin>>p1.nombre;
  // apellido
  cout<< "Apellido: "<<endl;
  cin>>p1.apellido;
  // edad
  do{
    cout<< "Edad: "<<endl;
    cin>>p1.edad;
  }while(p1.edad <= 0);
  // estatura en metros
  do{
    cout<< "Estatura (2.71): "<<endl;
    cin>>p1.estatura;
  }while(p1.estatura<=0);
  // es estudiante?
  string comprobarEstudiante;
  do{
  cout<< "Es estudiante? (si/no): "<<endl;
  cin>>comprobarEstudiante;
  for (char &c : comprobarEstudiante) c = toupper(c);
  if(comprobarEstudiante == "SI"){p1.esEstudiante = true;}
  else if(comprobarEstudiante == "NO"){p1.esEstudiante = false;}
  else{cout<<"\n\nERROR: ingreso invalido, ingresa si/no"<<endl;}
  }while(comprobarEstudiante != "SI" && comprobarEstudiante != "NO");

  // año de nacimiento
  int anioNacimiento = CalcularAnioNacimiento(p1.edad);
  // conversion estatura m a cm
  int estaturaCM = static_cast<int>(p1.estatura*100);
  // primer letra del apellido en mayuscula
  char apellido1Letra = toupper(p1.apellido[0]);

  // Salidas y confirmaciones de lectura 
  Funcionseparar();
  cout<<"Nombre: " << p1.nombre + " " + p1.apellido <<endl;
  cout<< "Primer letra del apellido: " << "\"" << apellido1Letra << "\"" <<endl;
  cout<<"Anio de nacimiento: " << anioNacimiento<<endl;
  cout<<"Edad: " << p1.edad << endl;
  cout<<"Estatura en cm: " << estaturaCM << endl;
  cout<< comprobarEstudiante << " " << "es estudiante!"<<endl;
  Funcionseparar();

  Funcionseparar(2);
// 02_operadores.cpp — Aritméticos, comparación y lógicos
  int a,b;
  // ingreso de valores
  cout<<"Ingrese el primer numero: ";
  cin>>a;
  cout<<"Ingrese el segundo numero: ";
  cin>>b;
  // Operaciones aritmeticas
  double suma,resta,multiplicacion,division;
  int residuo;
  suma = a+b;
  resta = a-b;
  multiplicacion = a*b;
  division = (b!=0) ? a/b : 0;
  residuo = (b!=0) ? a%b : 0;
  // operaciones de comparacion
  bool esIgual,esDiferente,mayorQue,menorQue,mayorIgual,menorIgual;
  esIgual = (a==b);
  esDiferente = (a!=b);
  mayorQue = (a>b);
  menorQue = (a<b);
  mayorIgual = (a>=b);
  menorIgual = (a<=b);
  // intervalo
  bool enIntervalo = (a >= 0 && a <= 10);
  //pariedad
  bool esparAA,esparBB;
  bool aEsPar = (a % 2 == 0);
  bool bEsPar = (b % 2 == 0);
  // salida de datos
  // salida operaciones aritmeticas
  Funcionseparar();
  cout<< "SUMA: "<< a <<" + "<< b << " = " << suma<<endl;
  cout<< "RESTA: "<< a <<" - "<< b << " = " << resta<<endl;
  cout<< "Multiplicacion: "<< a <<" * "<< b << " = " << multiplicacion<<endl;
  (b != 0) ? cout<< "Division: "<< a <<" / "<< b << " = " << division << endl : cout << "Division por cero no definida." <<endl;
  cout<< "Residuo: "<< a <<" % "<< b << " = " << residuo<<endl;
  // Operaciones de comparación
  Funcionseparar();
  cout << "El numero " << a << " == " << b << "? " << (esIgual ? "Si" : "No") << endl;
  cout << "El numero " << a << " != " << b << "? " << (esDiferente ? "Si" : "No") << endl;
  cout << "El numero " << a << " > " << b << "? " << (mayorQue ? "Si" : "No") << endl;
  cout << "El numero " << a << " < " << b << "? " << (menorQue ? "Si" : "No") << endl;
  cout << "El numero " << a << " >= " << b << "? " << (mayorIgual ? "Si" : "No") << endl;
  cout << "El numero " << a << " <= " << b << "? " << (menorIgual ? "Si" : "No") << endl;
  // Intervalo
  Funcionseparar();
  cout << "El numero " << a << " esta entre 0 y 10? " << (enIntervalo ? "Si" : "No") << endl;
  // Paridad
  cout << "El numero " << a << " es " << (aEsPar ? "par" : "impar") << endl;
  cout << "El numero " << b << " es " << (bEsPar ? "par" : "impar") << endl;

  Funcionseparar(3);
//03_condicionales.cpp — if, else if, else

// Signo de un número (positivo/negativo/cero)
  int numero;
  cout<< "Ingrese un numero: ";
  cin>>numero;
  cout<<"\nNumero ingresado: " << numero <<endl;
  if(numero < 0 ){cout<<"El numero ingresado es negativo"<<endl;}
  else if(numero == 0){cout<<"El numero ingresado es cero"<<endl;}
  else{cout<<"El numero ingresado es positivo"<<endl;}
  cout<< "\n\n==================================="<<endl;

  Funcionseparar();
// Máximo de tres enteros (indicando si hay empate).
  // ingreso de datos
  int e,f,g;
  cout<< "Ingrese el primer numero: "<<endl;
  cin>>e;
  cout<< "Ingrese el segundo numero: "<<endl;
  cin>>f;
    cout<< "Ingrese el tercer numero: "<<endl;
  cin>>g;
  // hallando el maximo 
  int maximo = e;
  if(maximo < f){ maximo = f;}
  if(maximo < g){maximo = g;}
  bool hayEmpate = false;
  if( e==maximo && f == maximo && g == maximo ){
    hayEmpate = true;
  }
  // salida de datos
  cout<< "El numero mayor ingresado es: " <<maximo<<endl;
  hayEmpate ? cout<< "Empate!! " <<endl  :  cout<< "No hay empate"<<endl; 
  cout<< "\n\n==================================="<<endl;

  Funcionseparar();
  // convertir nota numerica a alfabeto
  double nota;
  cout<<"Ingrese su nota: "<<endl;
  cin>>nota;

  if(nota >= 0 && nota <= 49){
      cout << "Su nota es: \"F\"" << endl;
  }else if(nota > 49 && nota <= 59){
      cout << "Su nota es: \"E\"" << endl;
  }else if(nota > 59 && nota <= 69){
      cout << "Su nota es: \"D\"" << endl;
  }else if(nota > 69 && nota <= 79){
      cout << "Su nota es: \"C\"" << endl;
  }else if(nota > 79 && nota <= 89){
      cout << "Su nota es: \"B\"" << endl;
  }else if(nota > 89 && nota <= 100){
      cout << "Su nota es: \"A\"" << endl;
  }else{
      cout << "Nota inválida" << endl;
  }
  Funcionseparar();
  // año bisiesto
  int aniobisiesto;
  bool esbisiesto = false;
  cout<<"Ingrese un anio"<< endl;
  cin>>aniobisiesto;

  if(aniobisiesto % 4 == 0 && aniobisiesto % 100 != 0 || aniobisiesto % 400 == 0){
    esbisiesto = true;
  }else{ esbisiesto = false; }

  cout << aniobisiesto << " Es bisiesto?: " << (esbisiesto ? "Si" : "No" ) << endl;

  Funcionseparar(4);
// 04_bucles.cpp — for, while, do-while
  // tablas de n hasta k
  int n,k;
  for(int i=0;i<k;i++){
    int tablas = n * i;
    cout<< n << "*" << i << " = " << tablas<<endl;
  }

  Funcionseparar();
  // sumar numeros hasta leer 0
  int m,q=0;
  cout<< "Ingrese un numero. ( 0 para salir )"<<endl;
  cin>>m;
  while(m!=0){
    q += m;
    cout<< "Ingrese un numero. ( 0 para salir )"<<endl;
    cin>>m;
  }
  cout<< "Total: "<< q <<endl;
  
  Funcionseparar();
  //factorial y suma de digitos
  int opcion;
  
  do{
  cout<< R"(
  Menu (1/2): 
  1. Factorial
  2. Suma de digitos
  0.salir
  )"<<endl;
  cin>>opcion;
  
  switch(opcion){
    case 1:{
      int factorial;
      cout<< "Factorial/ ingrese un numero entero positivo: "<<endl;
      cin>>factorial;
      cout<< "Resultado: " << Funcionfactorial(factorial) <<endl;
      break;
    }
    case 2:{
      string dgto;
      cout<< "Suma de digitos/ ingrese digitos numericos sin espacios: "<<endl;
      cin>>dgto;
      cout<<"Resultado: " << FuncionSumaDigitos(dgto)<<endl;
      break;
    }
    case 0:
      cout<<"saliendo.."<<endl;
      break;
    default:
      cout<< "opcion invalida"<<endl;
  }
  }while(opcion != 0 );


  Funcionseparar(5);
  // 05_arrays.cpp — Arrays 1D y 2D

  // 1D

  // posiciones a ingresar
  int posiciones;
  cout<< "Cuantos numeros desea ingresar? (1...100): "<<endl;
  cin>>posiciones;

  int *array = new int[posiciones];

  // validacion de rango
  if(posiciones >= 1 && posiciones <= 100 ){
    int numerosArray;
    // pedir numeros
    for(int i=0;i<posiciones;i++){
      cout<<"Ingrese el numero #" << i+1 << ":"<<endl;
      cin>> array[i];
    }
    // promedio
    double promedio=0;
    for(int i=0;i<posiciones;i++){
      promedio += array[i];
    }
    promedio = promedio/posiciones;
  // minimmo y maximo
  sort(array, array + posiciones);
  int minimo = array[0];
  int maximo = array[posiciones-1];
  cout<< "Promedio: "<< promedio<<endl;
  cout<< "Minimo: " << minimo<<endl;
  cout<< "Maximo: "<< maximo<<endl;
  }else{
    cout<<"Error: el numero debe estar entre 1 y 100."<<endl;
  }
  Funcionseparar();

  //2D
  int r,c;
  cout<< "Numero de filas: "<<endl;
  cin>> r;
  cout<< "Numero de columnas: "<<endl;
  cin>> c;

  if(r > 0 && r <=10 && c > 0 && c <= 10 ){
    int matriz[r][c];
    // llenar matriz
    for(int i =0; i < r; i++){
      for(int j =0 ; j < c ; j++){
        cout<< "Ingrese los numeros de la matriz: "<<endl;
        cin>> matriz[i][j];
      }
    }
  }
}