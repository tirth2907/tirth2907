// hashmap implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define m 5

struct pair {
    char key[5];
    int value;
};

struct pair HashMap[m];
void f(char k[], int v) {
    int hash = 0;
    for (int i = 0; k[i] != '\0'; i++) {
        hash = (hash + k[i]) % m;
    }
    int index = hash;

    if (HashMap[index].key[0] == '\0')
    {
        strcpy(HashMap[index].key, k);
        HashMap[index].value = v;
        return;
    }
    else if(strcmp(HashMap[index].key, k) == 0)
    {
        HashMap[index].value = v;
        return;
    }
    else
    {
        // collision
        for(int probe = 1; probe < m; probe++){
            int i = (index + probe) % m;
            if (HashMap[i].key[0] == '\0')
            {
                strcpy(HashMap[i].key, k);
                HashMap[i].value = v;
                return;
            }
            if(strcmp(HashMap[i].key, k) == 0)
            {
                HashMap[i].value = v;
                return;
            }
        }
        printf("HashMap is full\n");
        return;
    }
}

int main(){
    for(int i = 0;i<m;i++){
        HashMap[i].key[0] = '\0';
        HashMap[i].value = 0;
    }
    f("i1",10);
    f("i2",20);
    f("i3",30);
    f("i4",40);
    f("i1",50);
    f("i5",60);
    f("i6",70);
    for(int i = 0;i<m;i++){
        if(HashMap[i].key[0] != '\0'){
            printf("Key: %s, Value: %d\n", HashMap[i].key, HashMap[i].value);
        }
        
    }
}