//Hash Table Linear Probing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int const tableSize = 10;

struct hashNode {
	char key[100];
	int value;
};

int convertStringToInt(char *key){
	int stringLength = strlen(key);
	int ascii = 0;
	int i;
	for (i = 0; i < stringLength; i++){
		ascii+= key[i];
	}
	return ascii;
}

int hashDivision(int keyInt){
	
	return keyInt % tableSize;
}

void insert(char *key, int value, struct hashNode *hashTable[]){
	struct hashNode *new_node = (struct hashNode*)malloc(sizeof(struct hashNode));
	
	strcpy(new_node->key, key);
	new_node->value = value;
	
	//KEY = ARIF, perlu ambil ASCII dari KEY
	int keyInt = convertStringToInt(key);
	//ambil index dengan hash function division
	int index = hashDivision(keyInt);
	//cek jika index sudah ada data
	while (hashTable[index] != NULL){
		index++;
	}
	hashTable[index] = new_node;
}

void show(struct hashNode *hashTable[]){
	int i;
	
	for (i = 0; i < tableSize; i++){
		if (hashTable[i] != NULL){
			printf("Index ke-%d -> %s:%d\n", i, hashTable[i]->key, hashTable[i]->value);
		}else
			printf("index ke-%d -> NULL\n", i);		
	}
}

int retrieve(char *key, struct hashNode *hashTable[]){
	int keyInt = convertStringToInt(key);
	int index = hashDivision(keyInt);
	
	if (hashTable[index] == NULL){
		printf("\n%s was not found", key);
	}else{
		while (hashTable[index] != NULL){
			if (strcmp(hashTable[index]->key, key) == 0){
				printf("\n\n%s was found at index %d with value %d\n", key, index, hashTable[index]->value);
				return hashTable[index]->value;
			}
			index++;
		}
	}
	return 0;
}

int main(){
	struct hashNode *hashTableSize[tableSize];
	int i = 0;
	//assign address NULL
	for (i; i < tableSize; i++){
		hashTableSize[i] = NULL;
	}	
	insert("Arif", 10, hashTableSize); //ASCII ARIF = 386
	insert("Budi", 11, hashTableSize);
	insert("Citra", 12, hashTableSize);
	insert("Dwi", 13, hashTableSize);
	insert("Kurniawan", 14, hashTableSize);
	insert("Eko", 15, hashTableSize);
	insert("Fajar", 16, hashTableSize);
	insert("Indah", 17, hashTableSize);
	show(hashTableSize);
	
	int value = retrieve("Dwi", hashTableSize);
	value = retrieve("Kurniawan", hashTableSize);
	value = retrieve("Dian", hashTableSize);
	
	return 0;
}
