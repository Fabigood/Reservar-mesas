#include <stdio.h>
#include <string.h>

#define MAX_INTENTOS  3
#define MAX_RESERVAS 5
#define MAX_MESAS 10
#define MAX_PERSONAS 6
#define MESAS_2_PERSONAS 4
#define MESAS_4_PERSONAS 4
#define MESAS_6_PERSONAS 2

int main() {
    char usuario1[] = "admin1";
    char contrasena1[] = "c123";
    char usuario2[] = "admin2";
    char contrasena2[] = "cont2";
    char usuario3[] = "guest";
    char contrasena3[] = "cont3";

    int intentos = 0;
    int opcion;
    int tota_mesreser = 0;
    int tota_comen_espe = 0;
    int mesas2_dispo = MESAS_2_PERSONAS;
    int mesas4_dispo = MESAS_4_PERSONAS;
    int mesas6_dispo = MESAS_6_PERSONAS;

    while (intentos < MAX_INTENTOS) {
        char usuario[20];
        char contrasena[20];

        printf("Ingrese usuario: ");
        scanf("%s", usuario);
        printf("Ingrese su contrasena: ");
        scanf("%s", contrasena);

        if (strcmp(usuario, usuario1) == 0 && strcmp(contrasena, contrasena1) == 0) {
            printf("Inicio de sesion, con exito \n");
            break;
        } else if (strcmp(usuario, usuario2) == 0 && strcmp(contrasena, contrasena2) == 0) {
            printf("Inicio de sesion, con exito \n");
            break;
        } else if (strcmp(usuario, usuario3) == 0 && strcmp(contrasena, contrasena3) == 0) {
            printf("Inicio de sesion, con exito \n");
            break;
        } else {
            intentos++;
            if (intentos < MAX_INTENTOS) {
                printf("Usuario o contrasena incorrectos, intento #%d\n", intentos);
            } else {
                printf("Imposible ingresar\n");
                return 0;
            }
        }
    }

    while (1) {
        
        printf("\n Restaurante Menu \n");
        printf("\n Que desea hacer? \n");
        printf("1. Reservar Mesa\n");
        printf("2. Estadisticas de Reservas\n");
        printf("3. Salir\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            printf(" Reservar Mesa\n");

            if (tota_mesreser >= MAX_RESERVAS) {
                printf("YA hiciste todsa las reservas que deisponibles\n");
                continue;
            }

            int tipo_mesa;
            int num_mesas;
            int capacidad_mesa;
            int mesas_disponibles;

            printf("Tipos de mesas disponibles:\n");
            printf("1. Mesa de 2 personas (disponibles: %d)\n", mesas2_dispo);
            printf("2. Mesa de 4 personas (disponibles: %d)\n", mesas4_dispo);
            printf("3. Mesa de 6 personas (disponibles: %d)\n", mesas6_dispo);

            printf("Selecciona de cuanto quieres la mesa : ");
            scanf("%d", &tipo_mesa);

            switch (tipo_mesa) {
                case 1:
                    capacidad_mesa = 2;
                    mesas_disponibles = mesas2_dispo;
                    break;
                case 2:
                    capacidad_mesa = 4;
                    mesas_disponibles = mesas4_dispo;
                    break;
                case 3:
                    capacidad_mesa = 6;
                    mesas_disponibles = mesas6_dispo;
                    break;
                default:
                    printf("Mesa invalida.\n");
                    continue;
            }

            if (mesas_disponibles == 0) {
                printf("No tenemos ese tipo de mesa ahoraa.\n");
                continue;
            }

            printf("Cuantas mesas va a reservaar: ");
            scanf("%d", &num_mesas);

            if (num_mesas <= 0 || num_mesas > mesas_disponibles) {
                printf("Numero de mesas no valido.\n");
                continue;
            }

            int comensales = num_mesas * capacidad_mesa;

            tota_mesreser += num_mesas;
            tota_comen_espe += comensales;

            switch (tipo_mesa) {
                case 1:
                    mesas2_dispo -= num_mesas;
                    break;
                case 2:
                    mesas4_dispo -= num_mesas;
                    break;
                case 3:
                    mesas6_dispo -= num_mesas;
                    break;
            }

            printf("Se han reservado %d mesas para %d personas.\n", num_mesas, comensales);
        } else if (opcion == 2) {
            printf(" Estadisticas de Reservas\n");
            printf("Total de mesas reservadas: %d\n", tota_mesreser);
            printf("Total de comensales esperados: %d\n", tota_comen_espe);
        } else if (opcion == 3) {
            printf(" Salir\n");
            return 0;
        } else {
            printf("Opción no valida. Por favor, seleccione una opcion valida.\n");
        }
    }

    return 0;
}
