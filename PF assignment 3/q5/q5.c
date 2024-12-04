#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*** initializeInventory(int numSpecies, int* speciesSupplyCounts) {
    char*** inventory = (char***)malloc(numSpecies * sizeof(char**));
    if (!inventory) {
        printf("Memory allocation failed for inventory.\n");
        exit(1);
    }
	int i;
    for (i = 0; i < numSpecies; i++) {
        inventory[i] = NULL; 
        speciesSupplyCounts[i] = 0; 
    }

    return inventory;
}

void addSupplies(char*** inventory, int speciesIndex, int* speciesSupplyCounts) {
    int numSupplies,i;
    printf("Enter the number of supplies for species %d: ", speciesIndex + 1);
    scanf("%d", &numSupplies);

    inventory[speciesIndex] = (char**)malloc(numSupplies * sizeof(char*));
    if (!inventory[speciesIndex]) {
        printf("Memory allocation failed for supplies.\n");
        exit(1);
    }

    speciesSupplyCounts[speciesIndex] = numSupplies;

    for (i = 0; i < numSupplies; i++) {
        inventory[speciesIndex][i] = (char*)malloc(50 * sizeof(char));
        if (!inventory[speciesIndex][i]) {
            printf("Memory allocation failed for a supply.\n");
            exit(1);
        }

        printf("Enter supply %d for species %d: ", i + 1, speciesIndex + 1);
        scanf(" %[^\n]", inventory[speciesIndex][i]);
    }
}

void updateSupply(char*** inventory, int speciesIndex, int supplyIndex) {
    printf("Enter the new name for supply %d of species %d: ", supplyIndex + 1, speciesIndex + 1);
    char newSupply[50];
    scanf(" %[^\n]", newSupply);

    strcpy(inventory[speciesIndex][supplyIndex], newSupply);
}


void removeSpecies(char*** inventory, int speciesIndex, int* speciesSupplyCounts, int* numSpecies) {
	int i;
    for (i = 0; i < speciesSupplyCounts[speciesIndex]; i++) {
        free(inventory[speciesIndex][i]); 
    }
    free(inventory[speciesIndex]); 
    
    for (i = speciesIndex; i < (*numSpecies) - 1; i++) {
        inventory[i] = inventory[i + 1];
        speciesSupplyCounts[i] = speciesSupplyCounts[i + 1];
    }

    (*numSpecies)--;
}

void displayInventory(char*** inventory, int numSpecies, int* speciesSupplyCounts) {
	int i,j;
    printf("\nCurrent Inventory:\n");
    for (i = 0; i < numSpecies; i++) {
        printf("Species %d:\n", i + 1);
        for (j = 0; j < speciesSupplyCounts[i]; j++) {
            printf("  - %s\n", inventory[i][j]);
        }
    }
}

int main() {
    int numSpecies,i,j;
    printf("Enter the number of species in the inventory: ");
    scanf("%d", &numSpecies);

    int* speciesSupplyCounts = (int*)malloc(numSpecies * sizeof(int));
    if (!speciesSupplyCounts) {
        printf("Memory allocation failed for supply counts.\n");
        return 1;
    }

    char*** inventory = initializeInventory(numSpecies, speciesSupplyCounts);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add supplies for a species\n");
        printf("2. Update a supply\n");
        printf("3. Remove a species\n");
        printf("4. Display inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int speciesIndex;
                printf("Enter the species index (1 to %d): ", numSpecies);
                scanf("%d", &speciesIndex);
                if (speciesIndex < 1 || speciesIndex > numSpecies) {
                    printf("Invalid species index.\n");
                    break;
                }
                addSupplies(inventory, speciesIndex - 1, speciesSupplyCounts);
                break;
            }
            case 2: {
                int speciesIndex, supplyIndex;
                printf("Enter the species index (1 to %d): ", numSpecies);
                scanf("%d", &speciesIndex);
                if (speciesIndex < 1 || speciesIndex > numSpecies) {
                    printf("Invalid species index.\n");
                    break;
                }
                printf("Enter the supply index (1 to %d): ", speciesSupplyCounts[speciesIndex - 1]);
                scanf("%d", &supplyIndex);
                if (supplyIndex < 1 || supplyIndex > speciesSupplyCounts[speciesIndex - 1]) {
                    printf("Invalid supply index.\n");
                    break;
                }
                updateSupply(inventory, speciesIndex - 1, supplyIndex - 1);
                break;
            }
            case 3: {
                int speciesIndex;
                printf("Enter the species index to remove (1 to %d): ", numSpecies);
                scanf("%d", &speciesIndex);
                if (speciesIndex < 1 || speciesIndex > numSpecies) {
                    printf("Invalid species index.\n");
                    break;
                }
                removeSpecies(inventory, speciesIndex - 1, speciesSupplyCounts, &numSpecies);
                break;
            }
            case 4:
                displayInventory(inventory, numSpecies, speciesSupplyCounts);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    for (i = 0; i < numSpecies; i++) {
        for (j = 0; j < speciesSupplyCounts[i]; j++) {
            free(inventory[i][j]);
        }
        free(inventory[i]);
    }
    free(inventory);
    free(speciesSupplyCounts);

    printf("Exiting program.\n");
    return 0;
}
