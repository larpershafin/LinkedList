#ifndef PIDREGLER_H
#define PIDREGLER_H

double berechne_pid(double sollwert, double istwert, double *integral, double *letzter_fehler);
double simuliere_strecke_pid(double istwert, double stellgroesse);

#endif
