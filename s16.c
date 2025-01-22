#include <stdio.h>

int main(int argc, char *argv[]) {
    const float sprite = 61.7, cocacola = 41, pepsi = 20.50;
    float dinero, cambio, dinerof, precio = 0.0;
    int continuar = 1, opc1;

    while (continuar == 1) {
        printf("\nMáquina Expendedora en dólares\n");
        printf("1. Sprite - $61.7\n");
        printf("2. CocaCola - $41.0\n");
        printf("3. Pepsi - $20.5\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opc1);

        if (opc1 == 1 || opc1 == 2 || opc1 == 3) {
            if (opc1 == 1) precio = sprite;
            else if (opc1 == 2) precio = cocacola;
            else if (opc1 == 3) precio = pepsi;

            printf("Ingrese su dinero: ");
            scanf("%f", &dinero);

            while (dinero < 0) {
                printf("Error: El dinero no puede ser negativo. Intente de nuevo.\n");
                printf("Ingrese su dinero: ");
                scanf("%f", &dinero);
            }

            while (dinero < precio) {
                printf("Dinero insuficiente. Faltan $%.2f\n", precio - dinero);
                printf("Ingrese el dinero que falta: ");
                scanf("%f", &dinerof);

                while (dinerof < 0) {
                    printf("Error: El dinero ingresado no puede ser negativo. Intente de nuevo.\n");
                    printf("Ingrese el dinero que falta: ");
                    scanf("%f", &dinerof);
                }

                dinero += dinerof;
            }

            cambio = dinero - precio;
            printf("Pago completado. Cambio total: $%.2f\n", cambio);
            int cambioCentavos = (int)(cambio * 100);

            int monedas10 = cambioCentavos / 1000; 
            cambioCentavos %= 1000;

            int monedas5 = cambioCentavos / 500; 
            cambioCentavos %= 500;

            int monedas1 = cambioCentavos / 100; 
            cambioCentavos %= 100;

            int monedas50 = cambioCentavos / 50; 
            cambioCentavos %= 50;

            int monedas25 = cambioCentavos / 25; 
            cambioCentavos %= 25;

            int monedas10cent = cambioCentavos / 10; 
            cambioCentavos %= 10;

            printf("Cambio en monedas:\n");
            if (monedas10 > 0) printf("Monedas de $10.00: %d\n", monedas10);
            if (monedas5 > 0) printf("Monedas de $5.00: %d\n", monedas5);
            if (monedas1 > 0) printf("Monedas de $1.00: %d\n", monedas1);
            if (monedas50 > 0) printf("Monedas de $0.50: %d\n", monedas50);
            if (monedas25 > 0) printf("Monedas de $0.25: %d\n", monedas25);
            if (monedas10cent > 0) printf("Monedas de $0.10: %d\n", monedas10cent);
        } else {
            printf("Error. Opción no válida. Intente de nuevo.\n");
        }

        printf("\n¿Desea pedir otra bebida? 1) Sí, 2) No: ");
        scanf("%d", &continuar);
    }

    return 0;
}