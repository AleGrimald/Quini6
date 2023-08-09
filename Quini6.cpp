#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

void arrRand(int arrNum[], int);
void cargarApuesta(int arrApuesta[], int);
void mostrarArr(int arrNum[], int);
int compararArr(int arrNum[], int arrApuesta[], int);
int arrVerif(int arrNum[], int, int, bool);

int main()
{   
    bool bandera = true;
    const int largo = 6;
    int arrNum[largo],arrApuesta[largo],selector,cont=0;

    while (bandera)
    {
        system("cls");
        
        //Menu
        {
            printf(" ----------- Bienvenido a Quini6 -----------\n");
            printf(" 1 - Tradicional\n");
            printf(" 2 - Tradicional + Revancha\n");
            printf(" 3 - Tradicional + Revancha + Siempre sale\n");
            printf(" 4 - Salir\n");
            scanf_s("%d", &selector);
            system("cls");
        }

        switch (selector)
        {
        case 1:
            arrRand(arrNum, largo);
            cargarApuesta(arrApuesta, largo);
            cont = compararArr(arrNum, arrApuesta, largo);
            if (cont == 6)
            {
                printf("Ganaste el Quini6!!\n Cantidad de aciertos: %d\n\n", cont);
            }
            else
            {
                printf("Segui participando!!\n Cantidad de aciertos: %d\n\n", cont);
            }
            system("pause");
            break;

        case 2:
            arrRand(arrNum, largo);
            cargarApuesta(arrApuesta, largo);
            cont = compararArr(arrNum, arrApuesta, largo);
            if (cont == 6)
            {
                printf("Ganaste el Quini6!!\n Cantidad de aciertos: %d\n\n", cont);
            }
            else
            {
                printf("Perdiste el Tradicional, vas a la Revancha!!\n Cantidad de aciertos: %d\n\n", cont);
            }

            arrRand(arrNum, largo);
            cont = compararArr(arrNum, arrApuesta, largo);
            if (cont == 6 || cont == 5 || cont == 4)
            {
                printf("Ganaste la Revancha!!\n Cantidad de aciertos: %d\n\n", cont);
            }
            else
            {
                printf("Segui participando!!\n Cantidad de aciertos: %d\n\n", cont);
            }
            system("pause");
            break;

        case 3:
            arrRand(arrNum, largo);
            cargarApuesta(arrApuesta, largo);
            cont = compararArr(arrNum, arrApuesta, largo);
            if (cont == 6)
            {
                printf("Ganaste el Quini6!!\n Cantidad de aciertos: %d\n\n", cont);
            }
            else
            {
                printf("Perdiste el Tradicional, vas a la Revancha!!\n Cantidad de aciertos: %d\n\n", cont);
            }

            arrRand(arrNum, largo);
            cont = compararArr(arrNum, arrApuesta, largo);
            if (cont == 6 || cont == 5 || cont == 4)
            {
                printf("Ganaste la Revancha!!\n Cantidad de aciertos: %d\n\n", cont);
            }
            else
            {
                printf("Perdiste la Revancha, vas al Siempre Sale!!\n Cantidad de aciertos: %d\n\n", cont);
            }

            arrRand(arrNum, largo);
            cont = compararArr(arrNum, arrApuesta, largo);
            if (cont > 0 && cont <= 6)
            {
                printf("Ganaste el Siempre Sale!!\n Cantidad de aciertos: %d\n\n", cont);
            }
            else
            {
                printf("Sos re meaoooo, ni un acierto hiciste chivo!!\n Cantidad de aciertos: %d\n\n", cont);
            }
            system("pause");
            break;

        case 4:
            bandera = false;
            break;

        default:
            printf("Error! Opcion incorrecta.\n\n\n");
            break;
        }
        fflush(stdin);
    }
}

//Funcion para generar un Array con numeros Random
void arrRand(int arrNum[], int largo)
{
    int numRand;
    bool bandera = true;
    srand(time(NULL));
    
    for (int i = 0; i < largo; i++)
    {
        numRand = rand() % (46 - 0);
        if (i > 0)
        {
            bandera = arrVerif(arrNum, largo, numRand, bandera);
            if (bandera)
            {
                arrNum[i] = numRand;
            }
            else
            {
                i--;
            }
        }
        else{arrNum[i] = numRand;}
    }
}

//Muestra el un Array
void mostrarArr(int arrNum[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        cout << arrNum[i] << " | ";
    }
}

//Carga un array por teclado
void cargarApuesta(int arrApuesta[], int largo)
{
    int numIngresado;
    bool bandera=true;
    printf("Igresa 6 numeros entre 0 y 45 (incluido esos dos numeros.) \n");
    for (int i = 0; i < largo; i++)
    {
        scanf_s("%d", &numIngresado);
        if (numIngresado >= 0 && numIngresado <= 45)
        {
            if (i > 0)
            {
                bandera = arrVerif(arrApuesta, largo, numIngresado, bandera);
                if (bandera)
                {
                    arrApuesta[i] = numIngresado;
                }
                else { i--; }
            }
            else
            {
                arrApuesta[i] = numIngresado;
            }
        }
        else
        {
            printf("Error! El numero debe estar entre 0 y 45 (incluidos estos dos numeros)\n");
            i--;
        }
    }
}

//Compara dos Arra y devuelve la cantidad de coinsidencias
int compararArr(int arrNum[], int arrApuesta[], int largo)
{
    int cont = 0;
    for (int i = 0; i < largo; i++)
    {
        for (int j = 0; j < largo; j++)
        {
            if(arrNum[i]==arrApuesta[j])
            {
                cont++;
            }
        }
    }
    return cont;
}

//Verifica si hay numeros repetidos al generar el Array de numeros Random. Si los encuentra los excluye y genera otro numero
int arrVerif(int arrNum[], int largo, int numRand, bool bandera)
{
    for (int j = 0; j < largo; j++)
    {
        if (arrNum[j] == numRand)
        {
            bandera = false;
            j = largo;
        }
        else
        {
            bandera = true;
        }
    }
    return bandera;
}