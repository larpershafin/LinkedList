#include <stdio.h>
#include <windows.h>
#include "2punktregler.h"

int main() {
    double soll = 21.0;
    double ist = 15.0;


    printf("Sollwert: ");
    scanf("%lf", &soll);
    printf("\n");

    for (int t = 0; t < 30; t++) {
        int an = berechne_2punkt(soll, ist);
        printf("Zeit: %2d | Soll: %.1f | Ist: %.1f | Heizung: %d\n", t, soll, ist, an);
        fflush(stdout);
        ist = simuliere_strecke(ist, an);
        Sleep(1000); //1 Sekunde warten bevor man den nächsten Temperaturwert ausgibt
    }

    printf("\nSimulation beendet.\n");
    return 0;
}
