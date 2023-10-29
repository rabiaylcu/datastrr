#include <stdio.h>
#include <stdlib.h>

struct Ogrenci {
    int data;
    struct Ogrenci* next;
};

// Node olu�turma
struct Ogrenci* Ogrenc�Olustur(int data) {
    struct Ogrenci* newOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    newOgrenci->data = data;
    newOgrenci->next = NULL;
    return newOgrenci;
}
// Node'lar� ba�lama
void Ogrenciekleme(struct Ogrenci** head, struct Ogrenci* newOgrenci) {
    if (*head == NULL) {
        *head = newOgrenci;
    } else {
        struct Ogrenci* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newOgrenci;
    }
}


// soru1

------------------------------------------------------------------------------

// soru2 (fonksiyonu haz�r buldum)
int kars�last�r(const void* a, const void* b) {
    return ((int*) b - (int*) a);
}

int main() {
    int sayi[100];
    int i;

    // Rastgele say�larla diziyi doldur
    for (i = 0; i < 100; i++) {
        sayi[i] = rastgele() % 500; 
    }

    // Say�lar� b�y�kten k����e s�rala
    qsort(sayi, 100, sizeof(int), karsilastir);

    // Say�lar� S�ral� yazd�rma
    for (i = 0; i < 100; i++) {
        printf("%d", sayi[i]);
        if (i < 99) {
            printf("->");
        }
    }
    printf("\n");

    return 0;
}

------------------------------------------------------------------------------

// soru3
void Gez(struct Student* head) {
    int OgrenciSayisi = 0; 
    struct Ogrenci* temp = head;
	int OgrenciNo;
	int yas,isim;
    while (temp != NULL) {
        printf("%d- ��renci No: %d, �sim: %s, Ya�: %d\n", OgrenciSayisi + 1, temp->OgrenciNo, temp->isim, temp->yas);
        OgrenciSayisi++;
        temp = temp->next;
    }

    if (OgrenciSayisi == 0) {
        printf("Listede hi� ��renci bulunmuyor.\n");
    } else {
        printf("Toplam %d ��renci bulunuyor.\n", OgrenciSayisi);
    }
}

------------------------------------------------------------------------------

// soru4

struct Ogrenci* Ara(struct Ogrenci* head, const char* isim) {
    struct Ogrenci* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->isim, isim) == 0) {
            return temp; // �sim bulundu
        }
        temp = temp->next;
    }

    return NULL; // �sim bulunamad�
}
 
------------------------------------------------------------------------------
   
// soru5
	
	void Sil(struct Ogrenci* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        return; 
    }
    struct Ogrenci* nodeSil = prevNode->next;
    prevNode->next = nodeSil->next;
    free(nodeSil);
}

------------------------------------------------------------------------------

// soru6
void EnUzun�sim(struct Ogrenci* head) {
    struct Ogrenci* temp = head;
    int maxUzunluk = 0;
    char EnUzun�sim[50] = "";

    while (temp != NULL) {
        if (strlen(temp->isim) > maxUzunluk) {
            maxUzunluk = strlen(temp->isim);
            strcpy(EnUzun�sim, temp->isim);
        }
        temp = temp->next;
    }

    if (maxUzunluk > 0) {
        printf("Listedeki en uzun isim: %s\n", EnUzun�sim);
        printf("Uzunluk: %d\n", maxUzunluk);
    } else {
        printf("Hi� ��renci kayd� yok.\n");
    }
}
