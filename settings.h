/*
 * settings.h
 *
 *  Created on: 10.03.2018
 *      Author: rafael
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef enum {true, false, null} bool;
FILE *settings_file = NULL;
char line[100];

struct settings {
	bool ultimate;
	bool debug;
	bool glueck;
	bool BesseresGlueck;
	bool tollpatsch;
};

struct settings configuration;

bool getbool();
bool getvalue();
char booleantostring();
void standart();
int retries = 0;

bool load_settings () {
	settings_file = fopen("settings.txt", "wr");
	if (settings_file == NULL) {
		printf("Fehler beim laden der Einstellungen\n");
		printf("Einstellungsdatei wird mit den Standarteinstellungen erstellt\n");
		fprintf(settings_file, "ultimate=false\ndebug=false");
		fflush(settings_file);
		retries++;
		if (retries == 30) {
			printf("Okay habe es jetzt 30 mal versucht kein Bock mehr");
			configuration.BesseresGlueck = false;
			configuration.glueck = false;
			configuration.tollpatsch = false;
			configuration.debug = false;
			configuration.ultimate = false;
		}
		return load_settings();
	}
	configuration.debug = null;
	configuration.ultimate = null;
	configuration.BesseresGlueck = false;
	configuration.glueck = false;
	configuration.tollpatsch = false;
	int aktuell = 0;
	while (fgets(line, 50, settings_file) != NULL) {
		char *cfline;
		cfline = strstr((char *) line, "=");
		cfline = cfline + strlen("=");
		strcpy(line, cfline);

		//printf("%s\n",line);
		if (strcmp(line, "ultimate=true\n") == 0 || strcmp(line, "ultimate=false\n") == 0) {
			configuration.ultimate = getvalue();
			printf("Ultimate: %c\n", booleantostring(configuration.ultimate));
		} else if (strcmp(line, "debug=true") == 0 || strcmp(line, "debug=false") == 0) {
			configuration.debug = getvalue();
		}
	}
	aktuell++;
	configuration.glueck = false;
	configuration.BesseresGlueck = false;
	fclose(settings_file);
	return true;
}

bool getvalue() {
	if (line[0] == 'f') {
		return false;
	} else {
		return true;
	}
}

char booleantostring (bool tostring) {
if (tostring == true) {
	return 't';
} else {
	return 'f';
}
}
#endif /* SETTINGS_H_ */
