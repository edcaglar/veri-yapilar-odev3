/*Veri Yapilari Odev 3
    Bol ve Yonet Algoritmasi */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap (int *a, int *b);     //Dizinin elemanlarinin degerlerini degistirmek icin kullandigim fonk.
int sort(int *array, int low, int high, int randomkey, int n); //Pivot degerini donduren ve diziyi siralayan fonk.
void partition(int *key ,int *lock, int low, int high, int n);  //Recursive sekilde 1 eleman kalana kadar diziyi bolen fonk.

int main(){
    int i, n;
    printf("Oda sayisini girin.");
    scanf("%d",&n);                 // n degiskeni ile kilit sayisini alip
    int *lock=(int *)malloc(sizeof(int)*n); //n boyutunda key ve lock dizileri olusturdum.
    int *key=(int *)malloc(sizeof(int)*n);

    printf("Kilit dizisinin elemanlarini giriniz.\n");  //Lock dizisinin elemanlarini al
    for(i = 0; i < n;i++){
        printf("%d.eleman:",i+1);
        scanf("%d",&lock[i]);
    }

    printf("Anahtar dizisinin elemanlarini giriniz.\n");//Key dizisinin elemanlarini al
    for(i = 0; i < n; i++){
        printf("%d.eleman:",i+1);
        scanf("%d",&key[i]);
    }

    partition(key, lock, 0, n-1, n);    //Dizileri siralayacak fonksiyon

    printf("Sirali kilit dizisi   :");
    for(i = 0; i < n; i++)
        printf("%d ",lock[i]);
                                        //Sirali diziler burada bastirildi
    printf("\nSirali anahtar dizisi :");
    for(i = 0; i < n ;i++)
        printf("%d ",key[i]);
    printf("\n");

}

void partition(int *key ,int *lock, int low, int high, int n){
    srand(time(NULL));              //Random degerler uretebilmek icin srand kullandim
    int randomkey, pivot;           //Randomkey degiskeni key dizisinden gelen elemanin degerini tutmak icin
                        //Pivot degiskeni sort fonksiyonundan return edilen elemanin sirasini tutmak icin
    if (high > low){
        randomkey = key[(rand()%(high-low))+low];           //Key dizisinden rastgele bir deger seciyoruz
        pivot = sort(lock,low,high,randomkey,n);   //Randomkeyden buyuk ve kucuk sayilara gore lock dizisi siralandi.Pivot degeri lock dizisindeki randomkey sayisinin yerini gosteriyor.
        sort(key, low, high, lock[pivot], n);   //Key dizisi randomkey degerinden buyuk ve kucuk sayilara gore siralandi

        partition(key, lock, low , pivot-1, n);   //Her adimda dizinin low elemanindan  pivot elemanina kadar olan kismi siralaniyor
        partition(key, lock , pivot+1, high, n);  //Her donuste dizinin pivot elemanindan bir sonraki elemandan high elemanina kadar olan kismi siralaniyor

    }
}

int sort(int *arr, int low, int high, int randomkey, int n){
    int j, i = low;

    for(j = low; j < high; j++){
        if(randomkey == arr[j])     //Eger pivot degerimiz bulunursa daha sonra yerini degistirmek icin dizinin sonuna atiyor
            swap(&arr[j], &arr[high]);
        if(arr[j] < randomkey){     //Gonderilen dizinin icinde randomkeyden kucuk elemanlari
            swap(&arr[j], &arr[i]);   //Dizinin lowundan baslamak uzere sirayla j. elemanla yer degistiriyor
            i++;
        }
    }
    swap(&arr[i], &arr[high]); //Dizinin sonunda bulunan pivot degeri, dizinin kendisinden kucuk ve
                                //en sagda olan elemaninin bir sonrasindaki kendisinden buyuk elemanla yer degisiyor.
    return i;                    //Randomkey degerinin dizideki yeri return ediliyor
}

void swap(int *a, int *b){  //Gonderilen 2 tane degiskenin degerlerini swaplamak icin
    int tmp = *a;           //Referansa gore cagirip yerlerini degistirdim
    *a = *b;
    *b = tmp;
}
