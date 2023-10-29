#include <stdio.h>
#include <stdlib.h>

struct Ogrenci {
    int data;
    struct Ogrenci* next;
};

// Node oluþturma
struct Ogrenci* OgrencýOlustur(int data) {
    struct Ogrenci* newOgrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    newOgrenci->data = data;
    newOgrenci->next = NULL;
    return newOgrenci;
}
// Node'larý baðlama
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

// soru2 (fonksiyonu hazýr buldum)
int karsýlastýr(const void* a, const void* b) {
    return ((int*) b - (int*) a);
}

int main() {
    int sayi[100];
    int i;

    // Rastgele sayýlarla diziyi doldur
    for (i = 0; i < 100; i++) {
        sayi[i] = rastgele() % 500; 
    }

    // Sayýlarý büyükten küçüðe sýrala
    qsort(sayi, 100, sizeof(int), karsilastir);

    // Sayýlarý Sýralý yazdýrma
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
        printf("%d- Öðrenci No: %d, Ýsim: %s, Yaþ: %d\n", OgrenciSayisi + 1, temp->OgrenciNo, temp->isim, temp->yas);
        OgrenciSayisi++;
        temp = temp->next;
    }

    if (OgrenciSayisi == 0) {
        printf("Listede hiç öðrenci bulunmuyor.\n");
    } else {
        printf("Toplam %d öðrenci bulunuyor.\n", OgrenciSayisi);
    }
}

------------------------------------------------------------------------------

// soru4

struct Ogrenci* Ara(struct Ogrenci* head, const char* isim) {
    struct Ogrenci* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->isim, isim) == 0) {
            return temp; // Ýsim bulundu
        }
        temp = temp->next;
    }

    return NULL; // Ýsim bulunamadý
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
void EnUzunÝsim(struct Ogrenci* head) {
    struct Ogrenci* temp = head;
    int maxUzunluk = 0;
    char EnUzunÝsim[50] = "";

    while (temp != NULL) {
        if (strlen(temp->isim) > maxUzunluk) {
            maxUzunluk = strlen(temp->isim);
            strcpy(EnUzunÝsim, temp->isim);
        }
        temp = temp->next;
    }

    if (maxUzunluk > 0) {
        printf("Listedeki en uzun isim: %s\n", EnUzunÝsim);
        printf("Uzunluk: %d\n", maxUzunluk);
    } else {
        printf("Hiç öðrenci kaydý yok.\n");
    }
}
