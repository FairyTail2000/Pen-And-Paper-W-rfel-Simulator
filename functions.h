/*
 * funtions.h
 *  Created on: 18.12.2017
 *      Author: rafael
 */
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <stdlib.h>
#include <time.h>

void wuerfel(int wuerfel,int augenzahl) {
	srand(time(NULL));
	int wurf = 0;
	int erfolge = 0;
	int zwischen = 0;
	if(augenzahl == 4) {
		for (int i = 0; i < wuerfel; i++) {
			wurf = rand()%4 + 1;
			if (wurf == 5) {
				wurf--;
			}
			printf("Wuerfel %i = %i\n", i + 1, wurf);
			zwischen = wurf + zwischen;
			wurf = 0;
		}
		printf("Gesamt: %i\n", zwischen);
		erfolge = 0;
		zwischen = 0;
	} else if(augenzahl == 6) {
		for (int i = 0; i != wuerfel; i++) {
					wurf = rand()%6 + 1;
					if (wurf == 7) {
						wurf--;
					}
					if(wurf > 4) {
						printf("Wuerfel %i = %i\n", i + 1, wurf);
						printf("ERFOLG\n");
						erfolge++;
					} else {
						printf("Wuerfel %i = %i\n", i + 1, wurf);
					}
				}
				printf("Erfolge: %i\n", erfolge);
				wurf = 0;
				erfolge = 0;
	} else if(augenzahl == 8) {
		for (int i = 0; i < wuerfel; i++) {
						wurf = rand()%8 + 1;
						if (wurf == 9) {
							wurf--;
						}
						printf("Wuerfel %i = %i\n", i + 1, wurf);
						zwischen = wurf + zwischen;
						wurf = 0;
					}
				printf("Gesamt: %i\n", zwischen);
				zwischen = 0;
	} else if(augenzahl == 12) {
		for (int i = 0; i < wuerfel; i++) {
								wurf = rand()%12 + 1;
								if (wurf == 13) {
									wurf--;
								}
								printf("Wuerfel %i = %i\n", i + 1, wurf);
								zwischen = wurf + zwischen;
								wurf = 0;
							}
						printf("Gesamt: %i\n", zwischen);
						erfolge = 0;
						zwischen = 0;
	} else if(augenzahl == 20) {
		for (int i = 0; i < wuerfel; i++) {
							wurf = rand()%20 + 1;
							if (wurf == 21) {
								wurf--;
							}
							if(wurf == 1) {
								printf("Wuerfel %i = %i\n", i + 1, wurf);
								printf("KRITISCHER ERFOLG\n");
								erfolge++;
							} else {
								printf("Wuerfel %i = %i\n", i + 1, wurf);
							}
						}
						printf("Kritische Erfolge: %i\n", erfolge);
						wurf = 0;
						erfolge = 0;
	} else if(augenzahl == 100) {
		for (int i = 0; i < wuerfel; i++) {
							wurf = rand()%100 + 1;
							if (wurf == 101) {
								wurf--;
							}
								zwischen = zwischen + wurf;
								printf("Wuerfel %i = %i\n", i, wurf);
						}
						wurf = 0;
						erfolge = 0;
	} else {
		printf("Wie zum fick konnte das hier passieren?\n");
		printf("Das ist schlicht und einfach nicht moeglich\n");
	}

 }
#endif /* FUNCTIONS_H_ */
