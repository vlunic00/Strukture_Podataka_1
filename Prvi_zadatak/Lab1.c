#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char ime[15];
	char prezime[15];
	int bodovi;
}_student;

void ispis(_student*, int, int*);
void relative(_student*, int, int*);

int main() {

	_student* s;
	int n = 0, i = 0;
	int* relBodovi = NULL;
	char pom[50];
	FILE* ulz = NULL;
	ulz = fopen("Lista.txt", "r");
	if (ulz == NULL) {
		printf("Greska pri otvaranju datoteke");
		return -1;
	}

	//broji linije u datoteci
	//-----------------
	while (!feof(ulz)) {
		fgets(pom, sizeof(pom), ulz);
		n++;
	}

	rewind(ulz);

	s = (_student*)malloc(sizeof(_student) * n);
	relBodovi = (int*)malloc(sizeof(int) * n);

	//upisuje podatke iz datoteke u strukture
	//-----------------------
	while (!feof(ulz)) {
		fscanf(ulz, "%s %s %d", s[i].ime, s[i].prezime, &s[i].bodovi);
		i++;
		if (i == n)  //provjera ako krene upisivati u nepostojece clanove (krivo izracunat broj redaka)
			return -2;
	}

	fclose(ulz);

	relative(s, n, relBodovi);
	ispis(s, n, relBodovi);

}

//racuna relativne bodove svakog studenta i popunjava niz tih bodova
//----------------------------
void relative(_student* s, int br, int* rel) {
	int max = 0, i = 0;

	//racuna maksimalne ostvarene bodove
	//--------------------
	for (i = 0; i < br; i++) {

		if (s[i].bodovi > max)
			max = s[i].bodovi;
	}

	for (i = 0; i < br; i++) {
		rel[i] = s[i].bodovi / max * 100;
	}
}

void ispis(_student* s, int br, int* rel) {
	int i = 0;

	for (i = 0; i < br; i++)
		printf("%s %s %d %d", s[i].ime, s[i].prezime, s[i].bodovi, rel[i]);
}