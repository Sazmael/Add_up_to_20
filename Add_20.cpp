#include <iostream>
#include <time.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void limpiar();
void titulo();
void puntos(char j1[], char j2[], int &, int &);
void condicionfila(int &, int &, int &, int &, char j1[], char j2[]);
void condicioncolumna(int &,int &, int &, int &, char j1[], char j2[]);
void ganador(int &, int &, char j1[], char j2[]);
void salir(int &, int &, int &, char j1[], char j2[]);
void no_repetir(int tablero1[][8],int tablero2[][8],int &, int &, int *, int *,int &,int &,int &,char j1[],char j2[]);
void inhabilitadas_j1(int tablero1[][8], int tablero2[][8], int &, int &, int *, int *,int &, int &,int &,char j1[],char j2[]);
void inhabilitadas_j2(int tablero1[][8], int tablero2[][8], int &, int &, int *, int *,int &, int &,int &,char j1[],char j2[]);

int main()
{
   int jugador = 1;
   int puntos1 = 0, puntos2 = 0;
   int contador1 = 0,contador2 = 64;
   int casillas_j1 = 0, casillas_j2 = 0;
   char j1[15], j2[15];
   int i,j;
   int *p1,*p2,*p3;
   int numero1[3] = {0,0,0};
   int tablero1[8][8];
   int tablero2[8][8];
   int total = 0, total1 = 1;
   int n11, n12, n13, n14;
   int n21, n22, n23, n24;
   char respuesta = 'S';
   int salida = 1;
   int juego;
   int validar_num;
   char validar_letra;

   srand(time(NULL));

   system("title JUEGO DE SUMAR 20 by Olman Davila Solano");
   system("color 7d");

   while( salida == 1){

   //Funcion de titulo del menú y las opciones
   titulo();
   cout << right << setw(40) << "Digite 1: Para Jugar" << endl;
   cout << right << setw(40) << "Digite 2: Para Salir" << endl;
   cout << right << setw(31) << "Seleccion: ";
   cin >> juego;validar_num = juego;

   //Funcion para detener y limpiar pantalla
   limpiar();

   //switch de dos case, para el juego y la salida
   switch(juego){

    case 1:

     //Pasar numeros aleatorios a las matrices
    for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){

    tablero1[i][j] = 1 + rand() % (19);
    tablero2[i][j] = 1 + rand() % (19);

        }
    }

    //Guardar los nombres de los jugadores
   titulo();
   cout << right << setw(53) << "Digita el nombre del jugador #1: ";
   cin >> j1;
   cout << right << setw(53) << "Digita el nombre del jugador #2: ";
   cin >> j2;

   limpiar();

     do{

   ///////////////////////////////////JUGADOR1///////////////////////////////////////////////////////
    if(jugador == 1){

    //resetear puntajes
    contador1 = 0;
    p1 = 0; p2 = 0; p3 = 0;
    i = 0; j= 0;

    //Función de imprimir puntos de ambos jugadores
    puntos(j1,j2,puntos1,puntos2);

    //Imprimir matriz aleatoria
     cout << right << setw(60) << "Tablero de " << j1 << endl << endl;

     for(i = 0; i < 8; i++){ //enumerar columnas
        cout << right << setw(13) << i + 1 << " ";
     }
     cout << "\n";
    cout << right << setw(113) << "-------------------------------------------------------------------------------------------------------";
     cout << "\n";
     for(i = 0; i < 8; i++){
             cout << right << setw(9) << i + 1 << "|" ; //enumerar filas
        for(j = 0; j < 8; j++){

            cout << right << setw(11) << tablero1[i][j] <<" |";

           //Contar las casillas disponibles y las casillas usadas
            if(tablero1[i][j] > 0){

              contador1++;
            }
            if(tablero1[i][j] == 0){

             casillas_j1++;

            }

        }
            cout << endl;
            cout << right << setw(113) << "-------------------------------------------------------------------------------------------------------";
            cout << endl;

    }

    cout << endl;
    cout << right << setw(80) << "Seleccione una pareja o trio de la matriz que sume 20" << endl;
    cout << right << setw(105) << "Casillas disponibles de " << j1 << ": " << contador1 << endl;
    cout << right << setw(100) << "Casillas usadas de " << j1 << ": " << casillas_j1;

    //Escoger y guardar los numeros a punteros
    cout << "\n";


    //numero1
    cout << right << setw(74) << "Seleccione la fila y columna del primer numero o (0) para salir: " << endl;
    cout << right << setw(15) << "Fila: "; cin >> i; salida = i;

    //Salir al digitar 0
    salir(salida,contador1,contador2,j1,j2);

    //Condicional de digitar del 1 al 8 en la matriz
    condicionfila(i,salida,contador1,contador2,j1,j2);

    cout << right << setw(18) << "Columna: "; cin >> j; salida = j;


    salir(salida,contador1,contador2,j1,j2);

    condicioncolumna(j,salida,contador1,contador2,j1,j2);

    //Condicional de inhabilitar las casillas con 0
     inhabilitadas_j1(tablero1,tablero2,i,j,p1,p2,salida,contador1,contador2,j1,j2);

    p1 = &tablero1[i-1][j-1]; //guardar la ubicacion del primer numero

    //Guardar el primer numero a un vector de 3 espacios
    numero1[0] = tablero1[i-1][j-1];
    cout << right << setw(72) << "Primer numero escogido = " << "["<<numero1[0]<<"]" << endl;

    //numero 2
    cout << right << setw(73) << "Seleccione la fila y columna del segundo numero o (0) para salir" << endl;
    cout << right << setw(15) << "Fila: "; cin >> i; salida = i;

    salir(salida,contador1,contador2,j1,j2);

    condicionfila(i,salida,contador1,contador2,j1,j2);

    cout << right << setw(18) << "Columna: "; cin >> j; salida = j;

    salir(salida,contador1,contador2,j1,j2);

    condicioncolumna(j,salida,contador1,contador2,j1,j2);

    //Condicional de no repetir la misma casilla

     no_repetir(tablero1,tablero2,i,j,p1,p2,salida,contador1,contador2,j1,j2);

    //Condicional de inhabilitar las casillas con 0

     inhabilitadas_j1(tablero1,tablero2,i,j,p1,p2,salida,contador1,contador2,j1,j2);

    p2 = &tablero1[i-1][j-1]; //guardar la ubicacion del segundo numero

    //Guardar el segundo numero escogido a la segunda posicion del vector
    numero1[1] = tablero1[i-1][j-1];

    cout << right << setw(72) << "Segundo numero escogido = " << "["<<numero1[1]<<"]" << endl;

    //Validación para escoger o no un tercer numero
    cout << right << setw(42) << "Desea habilitar un tercer numero?" << endl;
    cout << right << setw(70) << "Digite (S) para habilitarlo, o (N) para sumar los escogidos: " ;
    cin >> respuesta;
    respuesta = toupper(respuesta);

    if(respuesta == 'S'){

    //numero 3
    cout << right << setw(73) << "Seleccione la fila y columna del tercer numero o (0) para salir" << endl;
    cout << right << setw(15) << "Fila: "; cin >> i; salida = i;

    salir(salida,contador1,contador2,j1,j2);

    condicionfila(i,salida,contador1,contador2,j1,j2);

    cout << right << setw(18) << "Columna: "; cin >> j; salida = j;

    salir(salida,contador1,contador2,j1,j2);

    condicioncolumna(j,salida,contador1,contador2,j1,j2);

    no_repetir(tablero1,tablero2,i,j,p1,p2,salida,contador1,contador2,j1,j2);

     inhabilitadas_j1(tablero1,tablero2,i,j,p1,p2,salida,contador1,contador2,j1,j2);

    p3 = &tablero1[i-1][j-1]; //guardar la ubicacion del tercer numero

    //Guardar el tercer numero a un vector
    numero1[2] = tablero1[i-1][j-1];

    cout << right << setw(72) << "Tercer numero escogido = " << "["<<numero1[2]<<"]" << endl;

    //Tres numeros escogidos
    if(numero1[0] + numero1[1] + numero1[2] != 20){

    //Sumar los 3 vectores
    total = numero1[0] + numero1[1] + numero1[2];

    //Mensaje cuando el resultado no es 20
    cout << right << setw(21) << "Fallaste!!! " << numero1[0] << " + " << numero1[1] <<" + "<< numero1[2] << " = " << total << "..." << endl;

    limpiar();

    //Cambiar turno al jugador 2
    jugador = 2;

     }else{
    //Colocar 0 los que dieron 20
    *p1 = 0;
    *p2 = 0;
    *p3 = 0;

    total = numero1[0] + numero1[1] + numero1[2];

    //Ganar un punto cuando se suma 20
    puntos1++;

    //Mensaje de validación cuando se acierta 20
    cout << right << setw(22) << "Acertaste!!! " << numero1[0] << " + " << numero1[1] << " = " << total << "!!!" << endl;

    limpiar();
    jugador = 2;

     }

    //dos numeros
    }else{

    if(numero1[0] + numero1[1] != 20){

    total = numero1[0] + numero1[1];

    cout << right << setw(21) << "Fallaste!!! " << numero1[0] << " + " << numero1[1] << " = " << total << "..." << endl;

    limpiar();
    jugador = 2;

     }else{

    *p1 = 0;
    *p2 = 0;

    total = numero1[0] + numero1[1];
    puntos1++;

    cout << right << setw(20) << "Acertaste!!! " << numero1[0] << " + " << numero1[1] << " = " << total << "!!!" << endl;

    limpiar();
    jugador = 2;

     }
    }

        }

    //////////////////////JUGADOR 2//////////////////////////////////////////////////////////////7
    if(jugador = 2){

    contador2 = 0;
    p1 = 0; p2 = 0; p3 = 0;
    i = 0; j = 0;

    puntos(j1,j2,puntos1,puntos2);

    //Imprimir matriz aleatoria
     //Imprimir matriz aleatoria
     cout << right << setw(60) << "Tablero de " << j2 << endl << endl;

     for(i = 0; i < 8; i++){ //enumerar columnas
        cout << right << setw(13) << i + 1 << " ";
     }
     cout << "\n";
    cout << right << setw(113) << "-------------------------------------------------------------------------------------------------------";
     cout << "\n";
     for(i = 0; i < 8; i++){
             cout << right << setw(9) << i + 1 << "|" ; //enumerar filas
        for(j = 0; j < 8; j++){

            cout << right << setw(11) << tablero2[i][j] <<" |";

            if(tablero2[i][j] > 0){

              contador2++;
            }

            if(tablero2[i][j] == 0){

             casillas_j2++;

            }

            }
            cout << endl;
            cout << right << setw(113) << "-------------------------------------------------------------------------------------------------------";
            cout << endl;

    }

    cout << endl;
    cout << right << setw(80) << "Seleccione una pareja o trio de la matriz que sume 20" << endl;
    cout << right << setw(105) << "Casillas disponibles de " << j2 << ": " << contador2 << endl;
    cout << right << setw(100) << "Casillas usadas de " << j2 << ": " << casillas_j2;

    //escoger y guardar los numeros a punteros
    cout << "\n";

    //numero1
    cout << right << setw(74) << "Seleccione la fila y columna del primer numero o (0) para salir: " << endl;
    cout << right << setw(15) << "Fila: "; cin >> i; salida = i;

    //salir al digitar 0
    salir(salida,contador1,contador2,j1,j2);

    //condicional de digitar del 1 al 8 en la matriz
    condicionfila(i,salida,contador1,contador2,j1,j2);

    cout << right << setw(18) << "Columna: "; cin >> j; salida = j;
    //salir al digitar 0
    salir(salida,contador1,contador2,j1,j2);

    //condicional de digitar del 1 al 8 en la matriz
    condicioncolumna(j,salida,contador1,contador2,j1,j2);

    //condicional de inhabilitar las casillas con 0
     inhabilitadas_j2(tablero2,tablero1,i,j,p1,p2,salida,contador1,contador2,j1,j2);

    p1 = &tablero2[i-1][j-1]; //guardar la ubicacion del primer numero

    numero1[0] = tablero2[i-1][j-1];
    cout << right << setw(72) << "Primer numero escogido = " << "["<<numero1[0]<<"]" << endl;

    //numero 2
    cout << right << setw(73) << "Seleccione la fila y columna del segundo numero o (0) para salir" << endl;
    cout << right << setw(15) << "Fila: "; cin >> i; salida = i;

    //salir al digitar 0
    salir(salida,contador1,contador2,j1,j2);

    //condicional de digitar del 1 al 8 en la matriz
    condicionfila(i,salida,contador1,contador2,j1,j2);

    cout << right << setw(18) << "Columna: "; cin >> j; salida = j;

    //salir al digitar 0
    salir(salida,contador1,contador2,j1,j2);

    //condicional de digitar del 1 al 8 en la matriz
    condicioncolumna(j,salida,contador1,contador2,j1,j2);

    //condicional de no repetir la misma casilla

     no_repetir(tablero1,tablero2,i,j,p1,p2,salida,contador1,contador2,j1,j2);

    //condicional de inhabilitar las casillas con 0

     inhabilitadas_j2(tablero2,tablero1,i,j,p1,p2,salida,contador1,contador2,j1,j2);

    p2 = &tablero2[i-1][j-1]; //guardar la ubicacion del segundo numero

    numero1[1] = tablero2[i-1][j-1];

    cout << right << setw(72) << "Segundo numero escogido = " << "["<<numero1[1]<<"]" << endl;

    //escoger un tercer numero
    cout << right << setw(42) << "Desea habilitar un tercer numero?" << endl;
    cout << right << setw(70) << "Digite (S) para habilitarlo, o (N) para sumar los escogidos: " ;
    cin >> respuesta;
    respuesta = toupper(respuesta);

    if(respuesta == 'S'){

    //numero 3
    cout << right << setw(73) << "Seleccione la fila y columna del tercer numero o (0) para salir" << endl;
    cout << right << setw(15) << "Fila: "; cin >> i; salida = i;

    //salir al digitar 0
    salir(salida,contador1,contador2,j1,j2);

    //condicional de digitar del 1 al 8 en la matriz
    condicionfila(i,salida,contador1,contador2,j1,j2);

    cout << right << setw(18) << "Columna: "; cin >> j; salida = j;

    //salir al digitar 0
    salir(salida,contador1,contador2,j1,j2);

    //condicional de digitar del 1 al 8 en la matriz
    condicioncolumna(j,salida,contador1,contador2,j1,j2);

    //condicional de no repetir la misma casilla

    no_repetir(tablero1,tablero2,i,j,p1,p2,salida,contador1,contador2,j1,j2);

    //condicional de inhabilitar las casillas con 0

     inhabilitadas_j2(tablero2,tablero1,i,j,p1,p2,salida,contador1,contador2,j1,j2);

    p3 = &tablero2[i-1][j-1]; //guardar la ubicacion del tercer numero

    numero1[2] = tablero2[i-1][j-1];

    cout << right << setw(72) << "Tercer numero escogido = " << "["<<numero1[2]<<"]" << endl;

    //tres numeros escogidos
    //poner 0 los que dieron 20
    if(numero1[0] + numero1[1] + numero1[2] != 20){

    total = numero1[0] + numero1[1] + numero1[2];

    cout << right << setw(21) << "Fallaste!!! " << numero1[0] << " + " << numero1[1] <<" + "<< numero1[2] << " = " << total << "..." << endl;

    limpiar();
    jugador = 1;

     }else{

    *p1 = 0;
    *p2 = 0;
    *p3 = 0;

    total = numero1[0] + numero1[1] + numero1[2];
    puntos1++;

    cout << right << setw(22) << "Acertaste!!! " << numero1[0] << " + " << numero1[1] << " = " << total << "!!!" << endl;

    limpiar();
    jugador = 1;

     }

    //dos numeros
    }else{

    if(numero1[0] + numero1[1] != 20){

    total = numero1[0] + numero1[1];

    cout << right << setw(21) << "Fallaste!!! " << numero1[0] << " + " << numero1[1] << " = " << total << "..." << endl;

    limpiar();
    jugador = 1;

     }else{

    *p1 = 0;
    *p2 = 0;

    total = numero1[0] + numero1[1];
    puntos1++;

    cout << right << setw(20) << "Acertaste!!! " << numero1[0] << " + " << numero1[1] << " = " << total << "!!!" << endl;

    limpiar();
    jugador = 1;

     }
    }

    //cerrar juego si no hay combinaciones
    if(contador1 <= 18 || contador2 <= 18 ){

     for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
           n11 = tablero1[i][j];
            n13 = tablero1[i][j];

                n21 = tablero2[i][j];
                 n23 = tablero2[i][j];

        for(int k = 0; k < 8; k++){
            for(int m = 0; m < 8; m++){

             n12 = tablero1[k][m];

                n22 = tablero2[k][m];

                    if(n11 + n12 == 20 || n21 + n22 == 20 || n11 + n12 + n13 == 20 || n21 + n22 + n23 == 20){

                      total1 = 1;

                        }

                    if(total1 != 1){

                    cout << "Ya no quedan parejas o trios de 20" << endl;
                    //poner condicional de cierre de juego
                    salir(salida,contador1,contador2,j1,j2);

            }



        }

            }

                }

            }


        }
    }



   }while(jugador >= 1);


     break;//break del juego


    case 2:

    titulo();
    cout << right <<  "Desea salir? \nDigite S Salir o N para volver al menú: " ;
        cin >> respuesta;

        if(respuesta == 'n'){
           limpiar();
           return main();

        }else{

            return 0;

        }

        break;

    default:
        cout << "Digite un numero del menú valido" << endl; break;  //Default nos da el mensaje si se digita un numero que no esta en el case

    }

   }

    return 0;
}

///////////////////////////////////////Funciones///////////////////////////////////

void limpiar(){
system("PAUSE");
system("CLS");
}

void condicionfila(int &i,int &salida, int &contador1, int &contador2, char j1[], char j2[]){

    if(i <= -1 || i >= 9){
    do{
     cout << right << setw(50) << "(ERROR): Debe digitar una fila del 1 al 8" << endl;
        cout << right << setw(15) << "Fila: "; cin >> i; salida = i;
        salir(salida,contador1,contador2,j1,j2);

    }while(i <= -1 || i >= 9);

        }
    }


void condicioncolumna(int &j,int &salida, int &contador1, int &contador2, char j1[], char j2[]){

if(j <= -1 || j >= 9){
    do{
      cout << right << setw(50) << "(ERROR) Debe digitar una columna del 1 al 8" << endl;
        cout << right << setw(18) << "Columna: "; cin >> j; salida = j;
        salir(salida,contador1,contador2,j1,j2);

    }while(j <= -1 || j >= 9);
            }
}

void ganador(int &contador1, int &contador2, char j1[], char j2[]){

if(contador1 > contador2){
      cout << right << setw(30) << j1 << " ha ganado con menos casillas usadas!!!" << endl;

    }
    if(contador1 < contador2){
    cout << right << setw(30) << j2 << " ha ganado con menos casillas usadas!!!" << endl;

    }

    if(contador1 == contador2){
     cout << right << setw(30) << j1 << " y " << j2 << " han empatado con las mismas casillas usadas!!!" <<endl;

    }


}

void salir(int &salida, int &contador1, int &contador2, char j1[], char j2[]){

char respuesta;

 if(salida == 0){
    ganador(contador1,contador2,j1,j2);

    cout << right << setw(63) << "Desea salir? Digite S Salir o N para volver al menú: " ;
        cin >> respuesta;
        respuesta = toupper(respuesta);

         if(respuesta == 'S'){
            exit(NULL);

        }else{

        limpiar();
        main();

        }
    }

}

void no_repetir(int tablero1[][8],int tablero2[][8], int &i,int &j,int *p1,int *p2,int &salida,int &contador1,int &contador2,char j1[],char j2[]){

 //tablero1
    if(&tablero1[i-1][j-1] == p1 || &tablero1[i-1][j-1] == p2){

    do{

    cout << right << setw(54) << "(Error): No debe seleccionar la misma casilla" << endl;
     cout << right << setw(15) << "Fila: "; cin >> i; salida = i;
     condicionfila(i,salida,contador1,contador2,j1,j2);
     salir(salida,contador1,contador2,j1,j2);
     cout << right << setw(18) << "Columna: "; cin >> j; salida = j;
     condicioncolumna(j,salida,contador1,contador2,j1,j2);
     salir(salida,contador1,contador2,j1,j2);

    }while(&tablero1[i-1][j-1] == p1 || &tablero1[i-1][j-1] == p2);

        }

    //tablero2
    if(&tablero2[i-1][j-1] == p1 || &tablero2[i-1][j-1] == p2){

    do{

     cout << right << setw(54) << "(Error): No debe seleccionar la misma casilla" << endl;
     cout << right << setw(15) << "Fila: "; cin >> i;
     condicionfila(i,salida,contador1,contador2,j1,j2);
     cout << right << setw(18) << "Columna: "; cin >> j;
     condicioncolumna(j,salida,contador1,contador2,j1,j2);

    }while(&tablero2[i-1][j-1] == p1 || &tablero2[i-1][j-1] == p2);

        }

}

void inhabilitadas_j1(int tablero1[][8],int tablero2[][8],int &i,int &j,int *p1,int *p2,int &salida,int &contador1,int &contador2,char j1[],char j2[]){

if(tablero1[i-1][j-1] == 0){
    do{

cout << right << setw(68) << "(Error):Casilla inhabilitada, vuelva a escoger una casilla " << endl;
cout << right << setw(15) <<"Fila: "; cin >> i; salida = i;
condicionfila(i,salida,contador1,contador2,j1,j2);
salir(salida,contador1,contador2,j1,j2);
cout << right << setw(18) << "Columna: "; cin >> j; salida = j;
condicioncolumna(j,salida,contador1,contador2,j1,j2);
salir(salida,contador1,contador2,j1,j2);

no_repetir(tablero1,tablero2,i,j,p1,p2,salida,contador1,contador2,j1,j2);

    }while(tablero1[i-1][j-1] == 0);
        }

}

void inhabilitadas_j2(int tablero2[][8],int tablero1[][8],int &i,int &j,int *p1,int *p2,int &salida,int &contador1,int &contador2,char j1[],char j2[]){

if(tablero2[i-1][j-1] == 0){
    do{

cout << right << setw(68) << "(Error):Casilla inhabilitada, vuelva a escoger una casilla " << endl;
cout << right << setw(15) <<"Fila: "; cin >> i; salida = i;
condicionfila(i,salida,contador1,contador2,j1,j2);
salir(salida,contador1,contador2,j1,j2);

cout << right << setw(18) << "Columna: "; cin >> j;salida = j;
condicioncolumna(j,salida,contador1,contador2,j1,j2);
salir(salida,contador1,contador2,j1,j2);
no_repetir(tablero1,tablero2,i,j,p1,p2,salida,contador1,contador2,j1,j2);

    }while(tablero2[i-1][j-1] == 0);
        }

}

void titulo(){

cout << right << setw(100) << "--------------------------------------------------------------------------------" << endl;
cout << right << setw(100) << "--------------------------------------------------------------------------------" << endl;
cout << right << setw(101) << "----------------- Bienvenido a: Parejas y tríos: Suma a 20 ---------------------" << endl;
cout << right << setw(100) << "--------------------------------------------------------------------------------" << endl;
cout << right << setw(100) << "--------------------------------------------------------------------------------" << endl;
}

void puntos(char j1[], char j2[], int &puntos1, int &puntos2){

cout << right << setw(20) << "Puntos de " << j1 << " " << puntos1 << endl;
cout << right << setw(20) << "Puntos de " << j2 << " " << puntos2 << endl;

}
