#include <stdio.h>

void convertirMoneda(float cantidad, int origen, int destino) {
    float tasa[3][3] = {
        {1.0, 0.13, 0.12},  // 1 Quetzal (GTQ) -> GTQ, USD, EUR
        {7.85, 1.0, 0.92},  // 1 Dólar (USD) -> GTQ, USD, EUR
        {8.50, 1.09, 1.0}   // 1 Euro (EUR) -> GTQ, USD, EUR
    };

    if (origen < 1 || origen > 3 || destino < 1 || destino > 3) {
        printf("Opción inválida.\n");
        return;
    }

    float resultado = cantidad * tasa[origen - 1][destino - 1];
    printf("Resultado: %.2f\n", resultado);
}

int main() {
    int opcion_origen, opcion_destino;
    float cantidad;

    while (1) {
        printf("\nConversor de Monedas\n");
        printf("1. Quetzales (GTQ)\n");
        printf("2. Dólares (USD)\n");
        printf("3. Euros (EUR)\n");
        printf("4. Salir\n");
        printf("Seleccione la moneda de origen: ");
        scanf("%d", &opcion_origen);

        if (opcion_origen == 4) break;

        printf("Seleccione la moneda de destino: ");
        scanf("%d", &opcion_destino);

        if (opcion_destino == 4) break;

        printf("Ingrese la cantidad a convertir: ");
        scanf("%f", &cantidad);

        convertirMoneda(cantidad, opcion_origen, opcion_destino);
    }

    printf("Gracias por usar el conversor.\n");
    return 0;
}
