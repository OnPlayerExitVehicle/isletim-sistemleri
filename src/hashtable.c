#include <hashtable.h>

//Komutlarım için random hash değeri elde ediyorum.
unsigned int getHash(char *data){
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

int hash_table_insert(datas* c){
    if(c == NULL) return -2;
    int index = getHash(c->data);
    //Eğer hash fonksiyonunun getirdiği yer dolu ise bir sonraki yere bakıyor, boş yer bulunca veriyi yerleştiriyor.
    for(int i = 0; i < TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if(hash_table[try] == NULL){
            hash_table[try] = c;
            return try;
        }
    }
    return -1;
}

datas *hash_table_lookup(char *data_name){
    int index = getHash(data_name);
    for(int i = 0; i < TABLE_SIZE; i++){
        int try = (index + i) % TABLE_SIZE;
        if(hash_table[try] == NULL){
            return NULL; //Burada değil direkt çık.
        }
        if(strncmp(hash_table[try]->data, data_name, TABLE_SIZE) == 0){
            return hash_table[try];
        }
    }
    return NULL; 
}

int hash_table_get_key(char* data_name)
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(!hash_table[i]) continue;
        if(!strcmp(hash_table[i]->data, data_name))
        {
            return i;
        }
    }
    
    return -1;
}