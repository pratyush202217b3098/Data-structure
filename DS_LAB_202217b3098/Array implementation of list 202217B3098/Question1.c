#include <stdio.h>

#define MAX_SIZE 100

// Global variables
int list[MAX_SIZE];
int count = 0;

// Function prototypes
void insert(int number);
void delete(int number);
void display();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int option, number;

    do {
        printf("\nList Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &number);
                insert(number);
                break;
            case 2:
                printf("Enter number to delete: ");
                scanf("%d", &number);
                delete(number);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (option != 4);
}

void insert(int number) {
    if (count >= MAX_SIZE) {
        printf("List is full! Cannot insert %d.\n", number);
        return;
    }

    // If list is empty or the number is the smallest, insert as the first element
    if (count == 0 || list[count - 1] <= number) {
        list[count++] = number;
        printf("%d inserted.\n", number);
        return;
    }

    // Find correct position to insert number while maintaining sorted order
    int position;
    for (position = 0; position < count; position++) {
        if (list[position] > number) {
            break; // Found position to insert
        }
    }

    // Shift elements to the right to make space for the new number
    for (int i = count; i > position; i--) {
        list[i] = list[i - 1];
    }

    // Insert the number
    list[position] = number;
    count++;
    printf("%d inserted.\n", number);
}

void delete(int number) {
    if (count == 0) {
        printf("List is empty! Cannot delete %d.\n", number);
        return;
    }

    // Search for the number to delete
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (list[i] == number) {
            found = 1;
            // Shift elements to the left to remove the number
            for (int j = i; j < count - 1; j++) {
                list[j] = list[j + 1];
            }
            count--;
            printf("%d deleted.\n", number);
            break;
        }
    }

    if (!found) {
        printf("%d not found in the list.\n", number);
    }
}

void display() {
    if (count == 0) {
        printf("List is empty.\n");
        return;
    }

    printf("List elements: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}
