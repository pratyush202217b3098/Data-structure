#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List node
struct node {
    char* key;
    char* value;
    struct node* next;
};

// Function to initialize a node
void setNode(struct node* node, char* key, char* value) {
    node->key = key;
    node->value = value;
    node->next = NULL;
}

// HashMap structure
struct hashMap {
    int numOfElements;
    int capacity;
    struct node** arr; // Array of linked lists
};

// Function to initialize the HashMap
void initializeHashMap(struct hashMap* mp) {
    mp->capacity = 100;
    mp->numOfElements = 0;
    mp->arr = (struct node**)malloc(mp->capacity * sizeof(struct node*));
}

// Hash function to compute bucket index
int hashFunction(struct hashMap* mp, char* key) {
    int sum = 0;
    int factor = 31;

    for (int i = 0; i < strlen(key); i++) {
        sum = ((sum % mp->capacity) + (((int)key[i]) * factor) % mp->capacity) % mp->capacity;
        factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
    }

    return sum;
}

// Function to insert key-value pair into HashMap
void insert(struct hashMap* mp, char* key, char* value) {
    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    setNode(newNode, key, value);

    if (mp->arr[bucketIndex] == NULL) {
        mp->arr[bucketIndex] = newNode;
    } else {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
}

// Function to delete key from HashMap
void delete (struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];

    while (currNode != NULL) {
        if (strcmp(key, currNode->key) == 0) {
            if (currNode == mp->arr[bucketIndex]) {
                mp->arr[bucketIndex] = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode);
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Function to search for value by key in HashMap
char* search(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* bucketHead = mp->arr[bucketIndex];

    while (bucketHead != NULL) {
        if (strcmp(bucketHead->key, key) == 0) {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }

    char* errorMssg = "Oops! No data found.\n";
    return errorMssg;
}

// Driver function
int main() {
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    initializeHashMap(mp);

    // Inserting key-value pairs
    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "BITS");
    insert(mp, "decentBoy", "Mayank");

    // Searching for values by keys
    printf("%s\n", search(mp, "elite_Programmer"));
    printf("%s\n", search(mp, "Yogaholic"));
    printf("%s\n", search(mp, "pluto14"));
    printf("%s\n", search(mp, "decentBoy"));
    printf("%s\n", search(mp, "GFG"));

    // Searching for a key that doesn't exist
    printf("%s\n", search(mp, "randomKey"));

    // Deleting a key from HashMap
    delete(mp, "decentBoy");

    // Searching for the deleted key
    printf("%s\n", search(mp, "decentBoy"));

    return 0;
}
