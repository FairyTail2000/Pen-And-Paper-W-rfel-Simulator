/*
 * scripting.h
 *
 *  Created on: 06.02.2018
 *      Author: rafael
 */

#ifndef SCRIPTING_H_
#define SCRIPTING_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wuerfeln.h"

// Forward declaration
void gencharakter ();

FILE *scritfile;
char scriptcontent[1024][1024];
int readscript();
int execscript();
void wuerfel(int wuerfel,int augenzahl);

int thisline = 0;

int openscript() {
	scritfile = fopen("script.ws","r");
	if(scritfile == NULL) {
		printf("Kein Script im aktuellem Ordner gefunden\n");
		return 0;
	}
	if (readscript() == 1) {
		printf("Script erfolgreich gelesen\n");
		printf("Script wird nun ausgeführt...\n");
		if(execscript() == 1) {
			printf("Erfolgreich ausgeführt\n");
		}
	}
	if(fclose(scritfile) != 0) {
		printf("Fehler beim schließen der Datei");
	}
	return 0;
}

int readscript() {
	 char line[1024];
	 int aktuell = 0;
		 while(1) {
		    	 if(fgets(line, 1024, scritfile) == NULL) {
		    		 break;
		    	 }
				 strcpy(scriptcontent[aktuell], line);
		    	 if (strcmp("ende", scriptcontent[aktuell]) == 0 || aktuell == 1000) {
		    		 printf("\n");
		    		 break;
		}
		aktuell++;
	 }
	return 1;
}

int execscript() {
	char temp[1024];
	int i = 0;
	while (1) {
		strncpy(temp, scriptcontent[thisline], sizeof(scriptcontent[thisline]));
		if (temp == NULL) {
			break;
		}

		if (strcmp(temp, "ende") == 0) {
			break;
		}
		int Wuerfel = atoi(scriptcontent[thisline + 1]);
		int augen = atoi(scriptcontent[thisline + 2]);
		//printf("%i, %i\n", Wuerfel,augen);
		if (strcmp(temp, "wuerfeln\n" )== 0) {
			if (augen == 4 || augen == 6 || augen == 8 || augen == 12 || augen == 20 || augen == 100) {
			wuerfel(Wuerfel,augen);
		} else {
			printf("Fehlerhafte augenzahl\n");
		}

		thisline = thisline + 3;
		} else if (strcmp(temp, "random\n") == 0) {
			gencharakter();
			thisline++;
		}
		printf("\n\n");
	}
	return 1;
}



#endif /* SCRIPTING_H_ */
