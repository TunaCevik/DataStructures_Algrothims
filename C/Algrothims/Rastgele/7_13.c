// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>



#define SUITS 4
#define FACES 13
#define CARDS 52
#define Player5Card 5

// prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
//void deal(unsigned int wDeck[][FACES], const char *wFace[], const char *wSuit[]); // dealing doesn't modify the arrays

void RastegeleSayilarvermeDeclere(unsigned int deckP[], unsigned int deckM[]);
void Dedect(unsigned int wDeck[][FACES], unsigned int deckP[], unsigned int deckM[],  const char *wFace[], const char *wSuit[]);
void tekrarEdenSayilariBulma(unsigned int deckPFace[], unsigned int deckMFace[], unsigned int deckPSuit[], unsigned int deckMSuit[]);

int main(void)
{
   // initialize deck array
   unsigned int deck[SUITS][FACES] = { 0 };
   unsigned int deckP[Player5Card] = {0};
   unsigned int deckM[Player5Card] = {0};
   

   srand(time(NULL)); // seed random-number generator

   shuffle(deck); // shuffle the deck

   // initialize suit array                       
   const char *suit[SUITS] =            
      {"Hearts", "Diamonds", "Clubs", "Spades"};
   
   // initialize face array                   
   const char *face[FACES] =
      {"Ace", "Deuce", "Three", "Four",         
       "Five", "Six", "Seven", "Eight",         
       "Nine", "Ten", "Jack", "Queen", "King"};

   //deal(deck, face, suit); // deal the deck

   RastegeleSayilarvermeDeclere(deckP,deckM);
   Dedect(deck, deckP, deckM, face, suit);


   
   


    return 0;
} 

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
   // for each of the cards, choose slot of deck randomly
   for (size_t card = 1; card <= CARDS; ++card) {
      size_t row; // row number
      size_t column; // column number

      // choose new random location until unoccupied slot found
      do {                                                        
         row = rand() % SUITS;                                   
         column = rand() % FACES;                             
      } while(wDeck[row][column] != 0); // end do...while

      // place card number in chosen slot of deck
      wDeck[row][column] = card;
   } 
}

// deal cards in deck
/*void deal(unsigned int wDeck[][FACES], const char *wFace[],
   const char *wSuit[])
{
   // deal each of the cards
   for (size_t card = 1; card <= CARDS; ++card) {
      // loop through rows of wDeck
      for (size_t row = 0; row < SUITS; ++row) {
         // loop through columns of wDeck for current row
         for (size_t column = 0; column < FACES; ++column) {
            // if slot contains current card, display card
            if (wDeck[row][column] == card) {
               printf("%5s of %-8s%c", wFace[column], wSuit[row],
                  card % 2 == 0 ? '\n' : '\t'); // 2-column format
            } 
         } 
      } 
   } 
}*/
void RastegeleSayilarvermeDeclere(unsigned int deckP[], unsigned int deckM[])
{
    unsigned int a[10] = {0};

    size_t count =0;
    while(count < 10){
        bool unique = true;

        unsigned int canditate;
        canditate = rand() % CARDS +1;
        for(size_t i =0; i< count; i++){
            if(a[i] == canditate){
                unique = false;
                break;
            }
        }
        if(unique){
            a[count++] = canditate;
        }
    }


    for(size_t i = 0; i < 5; i++){
        deckP[i] =a[i];
    }
    for(size_t i =5; i <= 9; i++){
        deckM[i-5] = a[i];
    }


    
}
void Dedect(unsigned int wDeck[][FACES], unsigned int deckP[], unsigned int deckM[], const char *wFace[], const char *wSuit[])
{

   void tekrarEdenSayilariBulma(unsigned int deckPFace[], unsigned int deckMFace[], unsigned int deckPSuit[], unsigned int deckMSuit[]);


    unsigned int deckPFace[Player5Card] = {0};
    unsigned int deckPSuit[Player5Card] = {0};
    unsigned int deckMFace[Player5Card] = {0};
    unsigned int deckMSuit[Player5Card] = {0};

    for (size_t card = 0; card < Player5Card; ++card) {

      for (size_t row = 0; row < SUITS; ++row) {

         for (size_t column = 0; column < FACES; ++column) {
            //en baştaki (shufflandamadan önceki) columun[wface] ve row[wSuit saklanıyor] onu yazdırıyoruz
            if (wDeck[row][column] == deckP[card]) {
                deckPFace[card] = column;
                deckPSuit[card] = row;
               printf("                            %5s P of %-8s \n", wFace[column], wSuit[row]);
                          
            } 
            // zaten if' li deckeler aynı olamaz
            if(wDeck[row][column] == deckM[card]){
                deckMFace[card] = column;
                deckMSuit[card] = row;
               printf("%5s M of %-8s \n", wFace[column], wSuit[row]);
            }
         } 
      } 
   } 
   
   tekrarEdenSayilariBulma(deckPFace, deckMFace, deckPSuit, deckMSuit);
   


}
void tekrarEdenSayilariBulma(unsigned int deckPFace[], unsigned int deckMFace[], unsigned int deckPSuit[], unsigned int deckMSuit[])
{
   unsigned int tekrarSayisiBul(unsigned int dizi[], size_t boyut, unsigned int aranan);
   unsigned int tekrarEdiyorMu(unsigned int dizi[], size_t boyut, unsigned int aranan);

   unsigned int boyut1 = Player5Card;
   unsigned int boyut2 = Player5Card;
   unsigned int boyut3 = Player5Card;
   unsigned int boyut4 = Player5Card;

   unsigned int tekrarEdenlerDizi1[boyut1];//deckPFace
   unsigned int tekrarEdenlerDizi2[boyut2];//deckMFace
   unsigned int tekrarEdenlerDizi3[boyut3];//deckPSuit
   unsigned int tekrarEdenlerDizi4[boyut4];//deckMSuit

   unsigned int tekrarSayilariDizi1[boyut1];
   unsigned int tekrarSayilariDizi2[boyut2];
   unsigned int tekrarSayilariDizi3[boyut3];
   unsigned int tekrarSayilariDizi4[boyut4];
    
   size_t tekrarEdenlerIndex1 = 0;
   size_t tekrarEdenlerIndex2 = 0;
   size_t tekrarEdenlerIndex3 = 0;
   size_t tekrarEdenlerIndex4 = 0;

   for (int i = 0; i < boyut1; i++) {
      if (tekrarEdiyorMu(tekrarEdenlerDizi1, tekrarEdenlerIndex1, deckPFace[i]) == 0) {
         unsigned int tekrarSayisi = tekrarSayisiBul(deckPFace, boyut1, deckPFace[i]);
         tekrarEdenlerDizi1[tekrarEdenlerIndex1] = deckPFace[i];
         tekrarSayilariDizi1[tekrarEdenlerIndex1] = tekrarSayisi;
         tekrarEdenlerIndex1++;
      }
   } 

   for (int i = 0; i < boyut1; i++) {
      if (tekrarEdiyorMu(tekrarEdenlerDizi2, tekrarEdenlerIndex2, deckMFace[i]) == 0) {
         unsigned int tekrarSayisi = tekrarSayisiBul(deckMFace, boyut2, deckMFace[i]);
         tekrarEdenlerDizi2[tekrarEdenlerIndex2] = deckMFace[i];
         tekrarSayilariDizi2[tekrarEdenlerIndex2] = tekrarSayisi;
         tekrarEdenlerIndex2++;
      }
   } 

   for (int i = 0; i < boyut1; i++) {
      if (tekrarEdiyorMu(tekrarEdenlerDizi3, tekrarEdenlerIndex3, deckPSuit[i]) == 0) {
         unsigned int tekrarSayisi = tekrarSayisiBul(deckPSuit, boyut3, deckPSuit[i]);
         tekrarEdenlerDizi3[tekrarEdenlerIndex3] = deckPSuit[i];
         tekrarSayilariDizi3[tekrarEdenlerIndex3] = tekrarSayisi;
         tekrarEdenlerIndex3++;
      }
   } 

   for (int i = 0; i < boyut1; i++) {
      if (tekrarEdiyorMu(tekrarEdenlerDizi4, tekrarEdenlerIndex4, deckMSuit[i]) == 0) {
         unsigned int tekrarSayisi = tekrarSayisiBul(deckMSuit, boyut4, deckMSuit[i]);
         tekrarEdenlerDizi4[tekrarEdenlerIndex4] = deckMSuit[i];
         tekrarSayilariDizi4[tekrarEdenlerIndex4] = tekrarSayisi;
         tekrarEdenlerIndex4++;
      }
   } 

   printf("deckPFace icin tekrar eden sayilar ve tekrar sayilari:\n");
   for (int i = 0; i < tekrarEdenlerIndex1; i++) {
      printf("%d tekrar ediyor ve %d kere\n", tekrarEdenlerDizi1[i], tekrarSayilariDizi1[i]);
   }

    // Dizi 2 için tekrar edenleri ve tekrar sayılarını yazdı
   printf("\ndeckMFace icin tekrar eden sayilar ve tekrar sayilari:\n");
   for (int i = 0; i < tekrarEdenlerIndex2; i++) {
      printf("%d tekrar ediyor ve %d kere\n", tekrarEdenlerDizi2[i], tekrarSayilariDizi2[i]);
   }

    // Dizi 3 için tekrar edenleri ve tekrar sayılarını yazdır
   printf("\ndeckPSuit icin tekrar eden sayilar ve tekrar sayilari:\n");
   for (int i = 0; i < tekrarEdenlerIndex3; i++) {
      printf("%d tekrar ediyor ve %d kere\n", tekrarEdenlerDizi3[i], tekrarSayilariDizi3[i]);
   }

    // Dizi 4 için tekrar edenleri ve tekrar sayılarını yazdır
   printf("\ndeckMSuit icin tekrar eden sayilar ve tekrar sayilari:\n");
   for (int i = 0; i < tekrarEdenlerIndex4; i++) {
      printf("%d tekrar ediyor ve %d kere\n", tekrarEdenlerDizi4[i], tekrarSayilariDizi4[i]);
   }
   
}


unsigned int tekrarSayisiBul(unsigned int dizi[], size_t boyut, unsigned int aranan) {
   unsigned int tekrarSayisi = 0;
   for (int i = 0; i < boyut; i++) {
      if (dizi[i] == aranan) {
         tekrarSayisi++;
      }
   }
    return tekrarSayisi;
}

// Bir sayının belirli bir dizide tekrar edip etmediğini kontrol eden fonksiyon
unsigned int tekrarEdiyorMu(unsigned int dizi[], size_t boyut, unsigned int aranan) {
   for (int i = 0; i < boyut; i++) {
      if (dizi[i] == aranan) {
         return 1; // Eğer aranan sayı dizide bulunursa 1 döndür
      }
   }
   return 0; // Bulunmazsa 0 döndür
}