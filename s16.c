 #include <stdio.h>
int main(int argc, char *argv[]) {
    const float sprite = 61.7, cocacola = 41, pepsi = 20.50;
    float dinero, cambio, dinerof, precio = 0.0;
    int continuar = 1, opc1; 
    while (continuar == 1) { 
        printf("\nMáquina Expendedora en pesos mexicanos\n");
        printf("1. Sprite - 61.7\n");
        printf("2. CocaCola - 41\n");
        printf("3. Pepsi - 20.50\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opc1);
        if (opc1 == 1 || opc1 == 2 || opc1 == 3) {
            if (opc1 == 1) precio = sprite;
            else if (opc1 == 2) precio = cocacola;
            else if (opc1 == 3) precio = pepsi;
            printf("Ingrese su dinero: ");
            scanf("%f", &dinero);  
            while (dinero < precio) {
                printf("Dinero insuficiente. Faltan $%.2f\n", precio - dinero); 
                printf("Ingrese el dinero que falta: ");
                scanf("%f", &dinerof);  
                dinero += dinerof; 
                 if (dinero < precio) {
                    printf("El dinero ingresado sigue siendo insuficiente. Intente de nuevo.\n");
                    continue;
                }
            }
            cambio = dinero - precio;
            printf("Cambio total: $%.2f\n", cambio);
            int monedas10 = cambio / 10; 
            cambio = (int)(cambio) % 10;  
            int monedas5 = cambio / 5;   
            cambio = (int)(cambio) % 5;  
            int monedas2 = cambio / 2;   
            cambio = (int)(cambio) % 2;  
            int monedas1 = (int)cambio;  
            printf("Cambio en pesos:\n");
            printf("Monedas de 10: %d\n", monedas10);
            printf("Monedas de 5: %d\n", monedas5);
            printf("Monedas de 2: %d\n", monedas2);
            printf("Monedas de 1: %d\n", monedas1);
        } else { 
            printf("Error. Intente de nuevo.\n");
        }
       
        printf("\n¿Desea pedir otra bebida? 1) Si, 2) No: ");
        scanf("%d", &continuar);
    }
    return 0;
}