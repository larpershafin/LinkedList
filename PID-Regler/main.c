#include <stdio.h>
#include <windows.h>
#include "pidregler.h"

int main() {
    double soll = 21.0;
    double ist = 15.0;
    double integral = 0.0;
    double letzter_fehler = 0.0;

    printf("Sollwert: ");
    scanf("%lf", &soll);
    printf("\n");

    for (int t = 0; t < 30; t++) {
        double stellgroesse = berechne_pid(soll, ist, &integral, &letzter_fehler);

        printf("Zeit: %2d | Soll: %.1f | Ist: %.1f | Stellgr.: %.1f\n", t, soll, ist, stellgroesse);
        fflush(stdout);

        ist = simuliere_strecke_pid(ist, stellgroesse);

        Sleep(1000);
    }

    printf("\nSimulation beendet.\n");
    return 0;
}
