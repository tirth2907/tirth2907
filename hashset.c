// HashSet implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define m 5

struct pair {
    char key[5];
    int value;
};

struct pair HashSet[m];
void f(char k[], int v) {
    int hash = 0;
    for (int i = 0; k[i] != '\0'; i++) {
        hash = (hash + k[i]) % m;
    }
    int index = hash;

    if (HashSet[index].key[0] == '\0')
    {
        strcpy(HashSet[index].key, k);
        HashSet[index].value = v;
        return;
    }
    else if(strcmp(HashSet[index].key, k) == 0)
    {
        return;
    }
    else
    {
        
        for(int probe = 1; probe < m; probe++){
            int i = (index + probe) % m;
            if (HashSet[i].key[0] == '\0')
            {
                strcpy(HashSet[i].key, k);
                HashSet[i].value = v;
                return;
            }
            if(strcmp(HashSet[i].key, k) == 0)
            {
            printf("Element already exists\n");
                return;
            }
        }
        printf("HashSet is full\n");
        return;
    }
}

int main(){
    for(int i = 0; i < m; i++){
        HashSet[i].key[0] = '\0';
    }

    
    f("i1", 1);
    f("i2", 1);
    f("i3", 1);
    f("i4", 1);
    f("i1", 1); 
    f("i5", 1);
    f("i6", 1); 

   
    for(int i = 0; i < m; i++){
        if(HashSet[i].key[0] != '\0'){
            printf("Key: %s\n", HashSet[i].key);
        }
    }
}