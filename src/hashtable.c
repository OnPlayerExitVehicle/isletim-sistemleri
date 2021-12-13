#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_DATA 80
#define TABLE_SIZE 10

typedef struct {
    char data[MAX_DATA];
} datas;

datas * hash_table[TABLE_SIZE];

//Komutlarım için random hash değeri elde ediyorum.
unsigned int hash(char *data){
    int length = strnlen(data,MAX_DATA);
    unsigned int hash_value = 0;
    //Komutların hash tablosunda random noktalara denk gelmeleri için random sayılar elde edebileceğimiz işlemler yaptık.
    for(int i = 0; i < length; i++){
        hash_value += data[i];
        hash_value = (hash_value * data[i]) % TABLE_SIZE;

    }
    return hash_value;
}

void print_table(){
    for(int i=0;i<TABLE_SIZE;i++){
        //tablodaki yer boş ise boş olduğunu görürüz.
        if(hash_table[i] == NULL) {
            printf("\t%i\t---\n",i);
        } else {
            //tablodaki yer dolu ise komutun ismini yazdırır.
            printf("\t%i\t%s\n",i,hash_table[i]->data);
        }
    }
}

bool hash_table_insert(datas* c){
    if(c == NULL) return false;
    int index = hash(c->data);
    //Eğer hash fonksiyonunun getirdiği yer dolu ise bir sonraki yere bakıyor, boş yer bulunca veriyi yerleştiriyor.
    for(int i = 0; i < TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if(hash_table[try] == NULL){
            hash_table[try] = c;
            return true;
        }
    }
    return false;
}

datas *hash_table_lookup(char *data_name){
    int index = hash(data_name);
    //
    for(int i = 0; i < TABLE_SIZE; i++){
        int try = (index + i) % TABLE_SIZE;
        if(hash_table[try] == NULL){
            return false; //Burada değil direkt çık.
        }
        if(strncmp(hash_table[try]->data, data_name, TABLE_SIZE) == 0){
            return hash_table[try];
        }
    }
    return NULL; 
}



int main(){
    datas c1 = {.data = "C1"};
    datas c2 = {.data = "C2"};
    datas c3 = {.data = "C3"};
    datas c4 = {.data = "C4"};

    hash_table_insert(&c1);
    hash_table_insert(&c2);
    hash_table_insert(&c3);
    hash_table_insert(&c4);
    print_table();

    datas *tmp = hash_table_lookup("C1");
    if(tmp == NULL){
        printf("Not found!\n");
    }else{
        printf("Found %s. \n",tmp->data);
    }


    tmp = hash_table_lookup("C3");
    if(tmp == NULL){
        printf("Not found!\n");
    }else{
        printf("Found %s. \n",tmp->data);
    }

    tmp = hash_table_lookup("C5");
    if(tmp == NULL){
        printf("Not found!\n");
    }else{
        printf("Found %s. \n",tmp->data);
    }
    return 0;
}