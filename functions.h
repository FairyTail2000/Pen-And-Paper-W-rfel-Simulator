#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "wuerfeln.h"
#include "scripting.h"
#include "settings.h"

struct limit {
	int geistig, koerperlich, magisch;
};

struct player {
	char name[100], sexualitaet[50], geschlecht[30], beruf[50];
	int leben, schaden, alter, cp, fp, skillpunkte, geld, totab, initiative;
	double manifest;
	struct limit limitierung;

};

void addspieler (int ziel);
int spielerspeichern (struct player towrite[], int groe);
void spielerausgeben (char Name_des_spielers[]);
void init();
int openscript();
void gencharakter ();
struct player spieler_[20];
int aktuell = 0;
char *berufe[9];

char *geschlecht[2];
char *sexualitaet[3];
char *names[20];

void gencharakter () {
	struct player pl;
	srand(time(NULL));
	strcpy(pl.name, names[rand() % 20]);
	printf("Name: %s\n", pl.name);
	pl.alter = rand() % 100;
	printf("Alter: %i\n", pl.alter);
	pl.leben = rand() % 300;
	printf("Leben: %i\n", pl.leben);
	strcpy(pl.beruf, berufe[rand() % 9]);
	printf("Beruf: %s\n", pl.beruf);
	pl.cp = rand() % 30;
	printf("CP: %i\n", pl.cp);
	pl.fp = rand() % 60;
	printf("FP: %i\n", pl.fp);
	pl.geld = rand() % 100000;
	printf("Geld: %i\n", pl.geld);
	strcpy(pl.geschlecht, geschlecht[rand() % 2]);
	printf("Geschlecht: %s\n", pl.geschlecht);
	strcpy(pl.sexualitaet, sexualitaet[rand() % 3]);
	printf("Sexualitaet: %s\n", pl.sexualitaet);
	pl.limitierung.geistig = rand() % 10;
	pl.limitierung.koerperlich = rand() % 10;
	pl.limitierung.magisch = rand() % 10;
	pl.manifest = rand() % 10;
	printf("Manifest: %i\n", (int) pl.manifest);
	pl.schaden = rand() % 100;
	printf("Schaden: %i\n", pl.schaden);
	pl.skillpunkte = rand() % 10;
	printf("Skillpunkte: %i\n", pl.skillpunkte);
	int totab = rand() % 100;
	totab = totab - (totab * 2);
	pl.totab = totab;
	printf("Totab: %i\n", totab);
	if(strcmp(pl.name, "Kevin")==0) {
		pl.initiative = 0;
		pl.limitierung.geistig = 0;
		pl.limitierung.magisch = 0;
		printf("Initiative: 0");
		printf("Limitierung Koerperlich: 0\n");
		printf("Limitierung Geistig: 0\n");
		printf("Limitierung Magisch: 0\n");
	} else {
		pl.initiative = rand() % 10;
		printf("Initiative: %i\n", pl.initiative);
		printf("Limitierung Koerperlich: %i\n", pl.limitierung.koerperlich);
		printf("Limitierung Geistig: %i\n", pl.limitierung.geistig);
		printf("Limitierung Magisch: %i\n", pl.limitierung.magisch);
	}
	spieler_[aktuell + 1] = pl;
}


void caller() {
	init();
	char temp[100];
	char possible[20];
	int first = 0;
	while (1) {
		if(first == 0) {
			system("clear");
			//system("cls");
			first++;
		}
		printf("Hilfe bekommst indem du 'hilfe' eingibst\n");
		printf("Bitte Aktion eingeben:\n");

		printf(">");
		scanf("%99s", temp);
		if (strcmp(temp, "add") == 0) {
			printf("Was moechtest du hinzufügen?\n");
			scanf("%18s", possible);
			if(strcmp(possible, "player") == 0){
				printf("Wie viele Spieler möchtest du hinzufügen?\n");
				printf(">");
				int i = 0;
				scanf("%i", &i);
				addspieler(i);
				first--;
			} else if (strcmp(possible, "npc") == 0) {
				printf("Ok\n");
			}
		} else if (strcmp(temp, "exit") == 0) {
			spielerspeichern(spieler_, aktuell);
			printf("Beende....\n");
			system("clear");
			//system("cls");
			return;
		} else if (strcmp(temp, "hilfe") == 0) {
			printf("Verfuegbare Befehle:\n");
			printf("add <player|npc>\n");
			printf("Fuegt einen Spieler|NPC hinzu\n\n");
			printf("'exit'\n");
			printf("Das brauche ich wohl nicht zu erklaeren xD\n");
			printf("wuerfeln\n");
			printf("Mit diesem Befehl benutzt du den Wuerfelsimulator\n");
			printf("Verfuegbare Modifikationen: gw (Einfaches Glueck)\n");
			printf("ww (Doppeltes Glueck) und tw (Tollpatsch)");
			printf("ausgeben\n");
			printf("Mit diesem Befehl kann man alle Spieler ausgeben\n");
			printf("random\n");
			printf("Mit diesem Befehl kann man einen spieler|npc random generieren lassen\n");
			printf("Mehr gibt es noch nicht\n");
		}  else if (strcmp(temp, "random") == 0) {
			gencharakter();
		} else if (strcmp(temp, "wuerfeln") == 0 || strcmp(temp, "w") == 0 || strcmp(temp, "gw") == 0 || strcmp(temp, "ww") == 0 || strcmp(temp, "tw") == 0) {
			if (strcmp(temp, "gw") == 0) {
				printf("Du hast Glueck :)\n");
				configuration.glueck = true;
			} else if (strcmp(temp, "ww") == 0) {
				printf("Du hast noch mehr Glueck :)\n");
				configuration.BesseresGlueck = true;
			} else if (strcmp(temp, "tw") == 0) {
				printf("Du bist nun ein Tollpatsch :(\n");
				configuration.tollpatsch = true;
			}
			int anzahl = 0, Wuerfel = 0;
			printf("Die Wuerfelanzahl eingeben:\n");
			printf(">");
			scanf("%i", &anzahl);
			printf("Bitte die Wuerfel angeben:\n");
			printf("Moeglich ist: 4 6 8 12 20 100\n");
			printf(">");
			scanf("%i", &Wuerfel);
			if(Wuerfel == 4 || Wuerfel == 6 || Wuerfel == 8 || Wuerfel == 12 || Wuerfel == 20 || Wuerfel == 100) {
				wuerfel(anzahl, Wuerfel);
			} else {
				printf("Ungueltige Zahl: %i\n", Wuerfel);
			}
			if (configuration.debug == true) {
				printf("Resette Modifikatoren...\n");
				configuration.glueck = false;
				configuration.BesseresGlueck = false;
				configuration.tollpatsch = false;
				printf("Fertig\n");
			} else {
				configuration.glueck = false;
				configuration.BesseresGlueck = false;
				configuration.tollpatsch = false;
			}


		} else if (strcmp(temp, "ausgeben") == 0) {
			spielerausgeben("Nothing special");
		} else if (strcmp(temp, "script") == 0) {
			if(openscript() == 1) {}
				else {
					printf("Fehler beim Laden des scriptes\n");
				}
		} else if (strcmp(temp,"tasten") == 0) {
			printf("Taste eingeben, Nummer kommt zurück\n");
			printf("'#' eigeben um zurückzukommen\n");
			char in;
			while (1) {
				scanf("%1s", &in);
				if (in == '#') {
					first = 0;
					break;
				}
				printf ("%c=%i\n", in, in);
			}
		} else if (strcmp(temp, "restart") == 0) {
			if (configuration.debug == false) {
				printf("Nicht im Debug Modus\n");
				continue;
			} else {
				printf("Startet neu...\n");
				first = 0;
				init();
				printf("Fertig\n");
			}
		} else {
			printf("Um Hilfe zu erhalten gebe 'hilfe' ein\n");
			printf("Nope\n");
		}
	}
}


void addspieler (int ziel) {
	char Name[100];
	char buff[50];
	int buffe;
	double doublebuff;
	int Spieleranzahl;
	printf("Bitte die Spieleranzahl eingeben:\n");
	scanf("%i", & Spieleranzahl);
	for (int i = aktuell; i < ziel; i++) {
		if (i <= 20) {
			//Namen
			printf("Bitte den Namen von Spieler %i eingeben:\n", i + 1);
			scanf("%99s", Name);
			strcpy(spieler_[i].name, Name);
			//Leben
			printf("Bitte das Leben von %s eingeben:\n", spieler_[i].name);
			scanf("%i", &buffe);
			spieler_[i].leben = buffe;
			//Sexualität
			printf("Bitte die Sexualitaet von %s eingeben:\n", spieler_[i].name);
			scanf("%99s", buff);
			strcpy(spieler_[i].sexualitaet, buff);
			//Geschlecht
			printf("Bitte das Geschlecht von %s eingeben:\n", spieler_[i].name);
			scanf("%99s", buff);
			strcpy(spieler_[i].sexualitaet, buff);
			//Beruf
			printf("Bitte den Beruf von %s eingeben:\n", spieler_[i].name);
			scanf("%99s", buff);
			strcpy(spieler_[i].beruf, buff);
			//Schaden
			printf("Bitte den Schaden von %s eingeben:\n", spieler_[i].name);
			scanf("%i", &buffe);
			spieler_[i].schaden = buffe;
			//Tot ab
			printf("Bitte den \"Tot ab\" Wert von %s eingeben:\n", spieler_[i].name);
			scanf("%i", &buffe);
			spieler_[i].totab = buffe;
			//manifest
			printf("Bitte das Manifest von %s eingeben:\n", spieler_[i].name);
			scanf("%lf", &doublebuff);
			spieler_[i].manifest = doublebuff;
			//Alter
			printf("Bitte das Alter von %s eingeben:\n", spieler_[i].name);
			scanf("%i", &buffe);
			spieler_[i].alter = buffe;
			//CP
			printf("Bitte die vorhanden CP von %s eingeben:\n", spieler_[i].name);
			scanf("%i", &buffe);
			spieler_[i].cp = buffe;
			//FP
			printf("Bitte die vorhanden FP von %s eingeben:\n", spieler_[i].name);
			scanf("%i", &buffe);
			spieler_[i].fp = buffe;
			//Skillpunkte
			printf("Bitte die vorhanden Skillpunkte von %s eingeben:\n", spieler_[i].name);
			scanf("%i", &buffe);
			spieler_[i].skillpunkte = buffe;
			//Geld
			printf("Bitte das Geld von %s eingeben:\n", spieler_[i].name);
			scanf("%i", &buffe);
			spieler_[i].geld = buffe;
			//limit geistig
			printf("Bitte das Geistige Limit von %s eingeben:\n", spieler_[i].name);
			scanf("%i", &buffe);
			spieler_[i].limitierung.geistig = buffe;
			//limit geistig
			printf("Bitte das Koerpeliche Limit von %s eingeben:\n", spieler_[i].name);
			scanf("%i", &buffe);
			spieler_[i].limitierung.koerperlich = buffe;
			//limit geistig
			printf("Bitte das Magisches Limit von %s eingeben:\n", spieler_[i].name);
			scanf("%i", &buffe);
			spieler_[i].limitierung.magisch = buffe;
		} else {
			printf("Zu viele Spieler");
			printf("Maximal 20 möglich");
			return;
		}
	}
}


int lebenvonspieler (char Spielername[100], int spieleranzahl ) {
	for (int i = 0; i < spieleranzahl; i++) {
		if (strcasecmp(spieler_[i].name,Spielername) == 0) {
			return spieler_[i].leben - spieler_[i].schaden;
		}
	}
	return -1;
}

void ladespieler (void) {
	FILE *p = fopen("spieler.txt", "r");
	 char line[256];
	 int aktuell = 0;
		 while(fgets(line, 256, p)) {
		     char *wort;
		     int i = 0;
		     wort = strtok(line, " ");
		     while(wort != NULL) {
		         wort = strtok(NULL, " ");
		         if (i == 0) {
		        	 i++;
		        	 sscanf(wort, "%s", spieler_[aktuell].name);
		         } else if (i == 1) {
		        	 i++;
		        	 sscanf(wort, "%i", &spieler_[aktuell].leben);
		        	 //printf("Leben: %i\n", spieler_[aktuell].leben);
		         } else if (i == 2) {
		        	 i++;
		        	 sscanf(wort, "%s", spieler_[aktuell].sexualitaet);
		        	 //printf("Sexualität: %s\n", spieler_[aktuell].sexualitaet);
		         } else if (i == 3) {
		        	 i++;
		        	 sscanf(wort, "%s", spieler_[aktuell].beruf);
		     		 //printf("Beruf: %s\n", spieler_[aktuell].beruf);
		         } else if (i == 4) {
		        	 i++;
		        	 sscanf(wort, "%i", &spieler_[aktuell].schaden);
		        	 //printf("Schaden: %i\n", spieler_[aktuell].schaden);
		         }else if (i == 5) {
		        	 i++;
		        	 sscanf(wort, "%i", &spieler_[aktuell].totab);
		        	 //printf("Tot ab: %i\n", spieler_[aktuell].totab);
		         } else if (i == 6) {
		        	 i++;
		        	 sscanf(wort, "%lf", &spieler_[aktuell].manifest);
		        	 //printf("Maifest: %lf\n", spieler_[aktuell].manifest);
		         } else if (i == 7) {
		        	 i++;
		        	 sscanf(wort, "%i", &spieler_[aktuell].alter);
		        	 //printf("Alter: %i\n", spieler_[aktuell].alter);
		         } else if (i == 8) {
		        	 i++;
		        	 sscanf(wort, "%i", &spieler_[aktuell].cp);
		        	 //printf("CP: %i\n", spieler_[aktuell].cp);
		         } else if (i == 9) {
		        	 i++;
		        	 sscanf(wort, "%i", &spieler_[aktuell].fp);
		        	 //printf("FP: %i\n", spieler_[aktuell].fp);
		         } else if (i == 10) {
		        	 i++;
		        	 sscanf(wort, "%i", &spieler_[aktuell].skillpunkte);
		        	 //printf("Skillpunkte: %i\n", spieler_[aktuell].skillpunkte);
		         } else if (i == 11) {
		        	 i++;
		        	 sscanf(wort, "%i", &spieler_[aktuell].geld);
		        	 //printf("Geld: %i\n", spieler_[aktuell].geld);
		         } else if (i == 12) {
		        	 i++;
		        	 sscanf(wort, "%i", &spieler_[aktuell].limitierung.geistig);
		        	// printf("Geistiges Limit: %i\n", spieler_[aktuell].limitierung.geistig);
		         } else if (i == 13) {
		        	 i++;
		        	 sscanf(wort, "%i", &spieler_[aktuell].limitierung.koerperlich);
		        	// printf("Koerperliches Limit: %i\n", spieler_[aktuell].limitierung.koerperlich);
		         } else if (i == 14) {
		        	 i++;
		        	 sscanf(wort, "%i", &spieler_[aktuell].limitierung.magisch);
		        	 //printf("Magische Limitierung: %i\n", spieler_[aktuell].limitierung.magisch);
		        	 aktuell++;
		         }
		     }
	 }

	 fclose(p);
}

void spielerausgeben (char Name_des_spielers[]) {
	for (int i = 0; i < 20; i++) {
		printf("Name: %s\n", spieler_[i].name);
		printf("Maximales Leben: %i\n", spieler_[i].leben);
		printf("Schaden: %i\n", spieler_[i].schaden);
		printf("Aktuelles Leben: %i\n", spieler_[i].leben - spieler_[i].schaden);
		if ((spieler_[i].leben - spieler_[i].schaden) <= spieler_[i].totab) {
			printf("Dieser Spieler ist Tot!\n");
		}
		printf("Tot ab: %i\n", spieler_[i].totab);
		printf("Alter: %i\n", spieler_[i].alter);
		printf("Sexualität: %s\n", spieler_[i].sexualitaet);
		printf("Beruf: %s\n", spieler_[i].beruf);
		printf("Maifest: %1lf\n", spieler_[i].manifest);
		printf("Geld: %i\n", spieler_[i].geld);
		printf("CP: %i\n", spieler_[i].cp);
		printf("FP: %i\n", spieler_[i].fp);
		printf("Skillpunkte: %i\n", spieler_[i].skillpunkte);
		printf("Geistiges Limit: %i\n", spieler_[i].limitierung.geistig);
		printf("Koerperliches Limit: %i\n", spieler_[i].limitierung.koerperlich);
		printf("Magische Limitierung: %i\n", spieler_[i].limitierung.magisch);
		printf("\n");
	}
}



int spielerspeichern (struct player towrite[], int groe) {
	if(groe == 0) {
		printf("Speichere nichts\n");
		return 1;
	}
	FILE *p = fopen("spieler.txt", "a");
	FILE *p2 = fopen("spielerzahl.txt", "a");
	if(p == NULL || p2 == NULL) {
		if (p == NULL) {
			p = fopen("spieler.txt", "rw");
			fclose(p);
		} else if (p2 == NULL) {
			p2 = fopen("spieler.txt", "rw");
			fclose(p2);
		}
		return spielerspeichern(towrite, groe);
	} else {
		fclose(p);
		p = fopen("spieler.txt", "a");
		for (int i = 0; i < groe; i++) {
		fprintf(p, "%i %s %i %s %s %i %i %lf %i %i %i %i %i %i %i %i\n", i, towrite[i].name, towrite[i].leben, towrite[i].sexualitaet, towrite[i].beruf, towrite[i].schaden, towrite[i].totab, towrite[i].manifest, towrite[i].alter, towrite[i].cp, towrite[i].fp, towrite[i].skillpunkte, towrite[i].geld, towrite[i].limitierung.geistig, towrite[i].limitierung.koerperlich, towrite[i].limitierung.magisch);
		}
		fclose(p);
		printf("Gespeichert\n");
		return 1;
	}
}

void init() {
	//system("chcp 1252");
	if (load_settings() == true) {
		printf("Einstellungen geladen\n");
	}
	berufe[0] = "Maurer";
	berufe[1] = "Chemiker";
	berufe[2] = "Magier";
	berufe[3] = "Lehrer";
	berufe[4] = "Vater";
	berufe[5] = "Programmierer";
	berufe[6] = "Designer";
	berufe[7] = "Biotiker";
	berufe[8] = "Genhacker";
	berufe[9] = "Musiker";
	geschlecht[0] = "Maennlich";
	geschlecht[1] = "Weiblich";
	sexualitaet[0] = "Hetero";
	sexualitaet[1] = "Homo";
	sexualitaet[2] = "Undefiniert";
	names[0] = "Peter";
	names[1] = "Dieter";
	names[2] = "Felix";
	names[3] = "Thomas";
	names[4] = "Sven";
	names[5] = "Rafael";
	names[6] = "Kerstin";
	names[7] = "Luka";
	names[8] = "Luca";
	names[9] = "Lucy";
	names[10] = "Natsu";
	names[11] = "Phillip";
	names[12] = "Anna";
	names[13] = "Marius";
	names[14] = "Martin";
	names[15] = "Emma";
	names[16] = "Lukas";
	names[17] = "Linus";
	names[18] = "Jonas";
	names[19] = "Ali";
	names[20] = "Kevin";
}

#endif /* FUNCTIONS_H_ */
