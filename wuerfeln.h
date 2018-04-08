/*
 * wuerfeln.h
 *
 *  Created on: 05.01.2018
 *      Author: rafael
 */

#ifndef WUERFELN_H_
#define WUERFELN_H_

#include <stdio.h>
#include <stdlib.h>
#include  "settings.h"

void wuerfel(int wuerfel, int augenzahl) {
	srand(time(NULL));
	int wurf = 0;
	int erfolge = 0;
	int zwischen = 0;
	int misserfolge = 0;
	int kritische_misserfolge = 0;
	if (configuration.ultimate == true) {
		printf("Ultimativer Modus aktiv\n");
		for (int i = 0; i < wuerfel; i++) {
			switch (augenzahl) {
			case 4:
				wurf = 4;
				zwischen += wurf;
				break;
			case 6:
				wurf = 6;
				zwischen += wurf;
				break;
			case 8:
				wurf = 8;
				zwischen += wurf;
				break;
			case 12:
				wurf = 8;
				zwischen += wurf;
				break;
			case 20:
				wurf = 1;
				zwischen += wurf;
				break;
			case 100:
				wurf = 2;
				zwischen += wurf;
			}
			printf("Wuerfel %i = %i\n", i + 1, wurf);
		}
		printf("Gesamt: %i\n", zwischen);
	} else if (configuration.ultimate == null) {
		printf("NullpointerException: wuerfeln.h\n");
		printf("Sind die Einstellungen geladen?");
		return;
	} else {
		switch (augenzahl) {
		case 4:
			for (int i = 0; i < wuerfel; i++) {
				wurf = rand() % 4 + 1;
				if (wurf == 5) {
					wurf--;
				}
				printf("Wuerfel %i = %i\n", i + 1, wurf);
				zwischen += wurf;
			}
			printf("Gesamt: %i\n", zwischen);
			break;
		case 6:
			for (int i = 0; i != wuerfel; i++) {
				wurf = rand() % 6 + 1;
				if (wurf == 7) {
					wurf--;
				}
				if (configuration.tollpatsch == true && wurf == 2) {
					printf("Wuerfel %i = %i\n", i + 1, wurf);
					printf("Tollpatsch\n");
					misserfolge++;
					continue;
				} else if (configuration.BesseresGlueck == true && wurf >= 3) {
					printf("Wuerfel %i = %i\n", i + 1, wurf);
					printf("ERFOLG\n");
					erfolge++;
					continue;
				} else if (configuration.glueck == true && wurf >= 4) {
					printf("Wuerfel %i = %i\n", i + 1, wurf);
					printf("ERFOLG\n");
					erfolge++;
					continue;
				}
				if (wurf > 4) {
					printf("Wuerfel %i = %i\n", i + 1, wurf);
					printf("ERFOLG\n");
					erfolge++;
				} else {
					printf("Wuerfel %i = %i\n", i + 1, wurf);
				}
				if (wurf == 1) {
					misserfolge++;
				}
			}
			printf("Erfolge: %i\n", erfolge);
			printf("Misserfolge: %i\n", misserfolge);
			if (wuerfel / 2 <= misserfolge) {
				printf("Patzer\n");
			} else if (wuerfel / 2 <= misserfolge && erfolge == 0) {
				kritische_misserfolge++;
				printf("KRITISCHER PATZER");
			}
			break;
		case 8:
			for (int i = 0; i < wuerfel; i++) {
				wurf = rand() % 8 + 1;
				if (wurf == 9) {
					wurf--;
				}
				printf("Wuerfel %i = %i\n", i + 1, wurf);
				zwischen += wurf;
				wurf = 0;
			}
			printf("Gesamt: %i\n", zwischen);
			break;
		case 12:
			for (int i = 0; i < wuerfel; i++) {
				wurf = rand() % 12 + 1;
				if (wurf == 13) {
					wurf--;
				}
				printf("Wuerfel %i = %i\n", i + 1, wurf);
				zwischen += wurf;
				wurf = 0;
			}
			printf("Gesamt: %i\n", zwischen);
			break;
		case 20:
			for (int i = 0; i < wuerfel; i++) {
				wurf = rand() % 20 + 1;
				if (wurf == 21) {
					wurf--;
				}
				zwischen += wurf;
				if (wurf == 1) {
					printf("Wuerfel %i = %i\n", i + 1, wurf);
					printf("KRITISCHER ERFOLG\n");
					erfolge++;
				} else if (wurf == 20) {
					printf("Wuerfel %i = %i\n", i + 1, wurf);
					printf("KRITISCHER MISSERFOLG\n");
					kritische_misserfolge++;
				} else {
					printf("Wuerfel %i = %i\n", i + 1, wurf);
				}
			}
			printf("Kritische Erfolge: %i\n", erfolge);
			printf("Gesamt: %i\n", zwischen);
			break;
		case 100:
			for (int i = 0; i < wuerfel; i++) {
				wurf = rand() % 100 + 1;
				if (wurf == 101) {
					wurf--;
				}
				zwischen += wurf;
				printf("Wuerfel %i = %i\n", i + 1, wurf);
			}
			printf("Gesamt: %i", zwischen);
			break;
		default:
			printf("Wie zum fick konnte das hier passieren?\n");
			printf("Das ist schlicht und einfach nicht moeglich\n");
			break;
		}
	}
}

#endif /* WUERFELN_H_ */
