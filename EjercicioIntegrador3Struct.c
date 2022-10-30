// Hacerlo con struct

/*
Deseamos realizar un programa que gestione las notas de una clase de 10 alumnos de los
cuales sabemos el DNI y la nota. El programa debe mostrar un menú con las siguientes
opciones a resolver:
1. Cargar Alumnos
2. Buscar un alumno
3. Modificar la nota de un alumno
4. Mostrar un listado de los 10 alumnos
5. Salir
Donde, la opción 1 permite cargar los 10 alumnos ingresando para cada uno: DNI y nota.
Validar que el DNI no sea menor que 1000000 ni mayor que 99999999. Validar que la nota sea
mayor a 0 y menor o igual que 10.
La opción 2 debe pedir el DNI de un alumno y mostrar en consola DNI y nota. Si el DNI
ingresado no existe, informar la situación con un mensaje “DNI inexistente”.
La opción 3 debe pedir el DNI del alumno al cual se desea cambiar la nota y la nueva nota. Si el
DNI ingresado no existe, informar la situación con un mensaje “DNI inexistente”, si el DNI si se
encuentra modificar la nota del alumno por la ingresada.
La opción 4 debe mostrar en la consola el listado de alumnos.
SÓLO se saldrá de la aplicación si se selecciona la opción 5.
*/

#include <stdio.h>
#include <stdlib.h>

struct alumnos
{
    int dnial;
    int notasal;
};

void main()
{
    int opc = 0, dni = 0, nota = 0, dniIngres = 0, notaNueva = 0;
    int valido1 = 0, valido2 = 0;
    int tam = 10; 
    struct alumnos alumno[tam];

    do
    {
        printf("Ingrese una de las siguientes opciones: \n");
        printf("1. Cargar Alumnos\n");
        printf("2. Buscar un alumno\n");
        printf("3. Modificar la nota de un alumno\n");
        printf("4. Mostrar un listado de los 10 alumnos\n");
        printf("5. Salir\n");
        scanf("%i", &opc);

        switch (opc)
        {
        case 1:
            printf("\n");
            for (int i = 0; i < tam; i++)
            {
                
                do
                {
                    printf("Ingrese el DNI del alumno nro %i:\n", i + 1);
                    scanf("%i", &dni);

                    if (dni >= 1000000 && dni <= 99999999)
                    {
                        alumno[i].dnial = dni;
                    }
                    else
                    {
                        printf("DNI inv%clido.\n", 160);
                    }
                } while (dni < 1000000 || dni > 99999999);

                do
                {
                    printf("Ingresa la nota del alumno nro %i: \n", i + 1);
                    scanf("%i", &nota);

                    if (nota > 0 && nota <= 10)
                    {
                        alumno[i].notasal = nota;
                    }
                    else
                    {
                        printf("Nota inv%clida.\n", 160);
                    }

                } while (nota <= 0 || nota > 10);
                printf("\n");
            }

            break;

        case 2:
            printf("\n");
            printf("Ingrese el DNI del alumno:\n");
            scanf("%i", &dniIngres);

            for (int i = 0; i < tam; i++)
            {
                if (dniIngres == alumno[i].dnial)
                {
                    ++valido1;
                    printf("DNI: %i \t Nota: %i\n", alumno[i].dnial, alumno[i].notasal);
                }
            }

            if (valido1 == 0)
            {
                printf("DNI inexistente.\n");
            }
            printf("\n");
            break;

        case 3:
            
            printf("Ingrese el DNI del alumno al cual desea cambiar la nota:\n");
            scanf("%i", &dniIngres);
            for (int i = 0; i < tam; i++)
            {
                if (dniIngres == alumno[i].dnial)
                {
                    printf("Ingrese la nueva nota: \n");
                    scanf("%i", &notaNueva);
                    alumno[i].notasal = notaNueva;
                    ++valido2;
                }
            }

            if (valido2 == 0)
            {
                printf("DNI inexistente.\n");
            }
            printf("\n");
            break;

        case 4:
            
            for (int i = 0; i < tam; i++)
            {
                printf("DNI: %i \t Nota: %i\n", alumno[i].dnial, alumno[i].notasal);
            }
            printf("\n");
            break;

        case 5:
            //Es la salida.
            break;

        default:
            printf("Opcion inv%clida.\n", 160);
            printf("\n");
            break;
        }
    } while (opc != 5);

    system("pause");
}