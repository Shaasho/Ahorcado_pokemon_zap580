#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    //Se crean 5 palabras en un arreglo de strings que se usaran paa elegir una palabra para el juego
    string palabras[5] = { "pikachu", "squirtle", "charmander", "bulbasur", "torchic" };

    //Se elegira una palabra al azar

    //Se inicializa el generador aleatorio en base a la hora para generar instancias diferentes
    srand(time(0));

    //Se eelige una palabra aleatoria de acuerdo a un valor numerico del 1 al 5
    int palabraElegida = rand() % 5;

    //Se elegira una letra para ser revelada al jugador a forma depista, primero se elige la letra
    int letraRevelada = rand() % palabras[palabraElegida].length();
    int letraRevelada2 = rand() % palabras[palabraElegida].length();

    //Se generan vidas para el jugador
    int vidas = 3;

    //Se inicializa variable donde se guardara el progreso del jugador
    string palabraAdivinada = "";

    //Se crea una variable que se usara para controlar los aciertos del jugador
    //Cuando toda la palabra se convierta en simbolos de '-', el jugador habra ganado
    string palabraObjetivo = palabras[palabraElegida];

    //Se imprime la pista y las instrucciones
    cout << "Juego del Ahorcado" << endl << "Tienes " << vidas << " vidas disponibles para intentar adivinar al pokemon!" << endl;
    cout << "Estas son las pistas!" << endl << endl << endl << " ";

    //Guarda los espacios en blanco y la pista
    for (int i = 0; i < palabras[palabraElegida].length(); i++)
    {   
        //Imprime la letra revelada al jugador
        if (i == letraRevelada) {
            palabraAdivinada += palabras[palabraElegida][letraRevelada];
            palabraObjetivo[i] = '-';
        }
        if (i == letraRevelada2) {
            palabraAdivinada += palabras[palabraElegida][letraRevelada2];
            palabraObjetivo[i] = '-';
        }
        if (i != letraRevelada && i != letraRevelada2) {
            palabraAdivinada += "_";
        }
    }

    cout << palabraAdivinada << endl << endl << endl;

    //Se genera una variable boleana de control que servira para controlar el flujo del juego
    bool enPartida = true;

    //Se genera una variable boleana para determinar si el jugador acerto o perdio una vida
    bool acertando = false;

    //Se genera una variable boleana que podra determinar si el jugaro ha conseguido la victoria final
    bool victoria = false;

    //Se crea una variable que contara los aciertos
    int aciertos = 0;

    //Se crea una variable que recibira la informacion del jugador
    char letra;

    //Comienza el Juego
    while (enPartida) {

        //Se vuelve a inicializar la variable de control de aciertos
        acertando = false;
        //Se inicializa la variable de aciertos
        aciertos = 0;

        cout << "Tienes " << vidas << " vidas, la palabra es:" << endl << palabraAdivinada << endl << "Ingresa una letra para adivinar la palabra:" << endl;
        cin >> letra;

        //Busca la letra en la palabra
        for (int i = 0; i < palabraObjetivo.length(); i++)
        {
            if (palabraObjetivo[i] != '-' && palabraObjetivo[i] == letra) {
                palabraObjetivo[i] = '-';
                palabraAdivinada[i] = letra;
                acertando = true;
            }
        }

        if (acertando) {
            cout << "Correcto!" << endl << endl;
        }
        else {
            cout << "Has Perdido una vida!" << endl << endl;
            vidas--;
        }

        //Compara si la palabra ya se ha terminado de adivinar
        for (int i = 0; i < palabraObjetivo.length(); i++)
        {
            if (palabraObjetivo[i] == '-'){
                aciertos++;
            }
        }

        //Se determina si se han perdido las vidas
        if (vidas == 0) {
            cout << "Se te han acabado las vidas! Has perdido" << endl;
        }

        //Se determina si se ha logrado la victoria
        if (aciertos == palabraObjetivo.length()) {
            cout << "Has adivinado el nombre del pokemon! Era " << palabras[palabraElegida] << endl;
            enPartida = false;
        }

        //Determina si el juego ha terminado
        if (vidas == 0 || victoria) {
            enPartida = false;
        }
    }

    cout << "Juego terminado." << endl;

}
