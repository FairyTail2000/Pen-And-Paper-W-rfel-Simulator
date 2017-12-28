/*
 * main.c
 *
 *  Created on: 18.12.2017
 *      Author: rafael
 */

#include <stdio.h>
#include "functions.h"

void wuerfel(int wuerfel,int augenzahl);

int main () {
	int anzahl = 0, Wuerfel = 0;
	printf("Die Wuerfelanzahl eingeben:\n");
	scanf("%i", &anzahl);
	printf("Bitte die Wuerfel angeben:\n");
	printf("Moeglich ist: 4 6 8 12 20 100\n");
	scanf("%i", &Wuerfel);
	if(Wuerfel == 4 || Wuerfel == 6 || Wuerfel == 8 || Wuerfel == 12 || Wuerfel == 20 || Wuerfel == 100) {
		wuerfel(anzahl, Wuerfel);
	} else {
		printf("Ungueltige Zahl: %i\n", Wuerfel);
		return -1;

	}
	return 0;
}
