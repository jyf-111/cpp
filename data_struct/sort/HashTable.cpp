#include<iostream>
#define HashSize 10000
#define LoadFactor 0.8
using namespace std;

typedef enum status Status;
enum status {Valid,inValid,Empty};

typedef struct HashElem {
    int key;
    int value;
    Status status;
}HashElem;

typedef struct HashTable {
    HashElem data[HashSize];
    int size;
    HashFunc hashfunc;
}HashTable;

typedef int(*HashFunc)(int Key);
int Hash(int Key) {
    return Key%HashSize;
}

void HashInit(HashTable* ht,HashFunc hashfunc) {
    ht->size = 0;
    ht->hashfunc = hashfunc;
    for(int i=0;i<HashSize;i++) {
        ht->data[i].key=0;
        ht->data[i].status = Empty;
        ht->data[i].value = 0;
    }
}

int HashTableInsert(HashTable* ht,int Key,int value) {
    if(ht->size>=HashSize*LoadFactor){
        return 0;
    }
    int cur = ht->hashfunc(Key);
    while(1) {
        if(ht->data[cur].key==Key) {
            return 0;
        }
        if(ht->data[cur].status!=inValid) {
            ht->data[cur].key = Key;
            ht->data[cur].status = Valid;
            ht->data[cur].value = value;
            ht->size++;
            return 1;
        }
        cur++;
    }
}

int HashTableFind(HashTable* ht,int key,int* value) {
    int offset = ht->hashfunc(key);
    if(ht->data[offset].key == key && ht->data[offset].status==Valid) {
        *value = ht->data[offset].value;
        return offset;
    }else {
        while(ht->data[offset].status != Empty) {
            if(ht->data[offset].key!=key) {
                offset++;
                if(offset>=HashSize) {
                    return -1;
                }
            }else{
                if(ht->data[offset].status==Valid) {
                    *value = ht->data[offset].value;
                    return offset;
                }else{
                    offset++;
                }
            }
        }
    }
    return -1;
}

void HashMove(HashTable* ht,int key) {
    int value = 0;
    int Pos = HashTableFind(ht,key,&value);
    if(Pos==-1) {
        return;
    }else{
        ht->data[Pos].status = inValid;
        ht->size--;
    }
}

int main() {

}