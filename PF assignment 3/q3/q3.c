#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int validateEmail(char* email) {
    if (email == NULL || strlen(email) == 0) {
        return 0; 
    }

    char* atSymbol = strchr(email, '@');
    if (!atSymbol) {
        return 0; 
    }

    
    if (strchr(atSymbol + 1, '@')) {
        return 0;
    }

   
    if (!strchr(atSymbol + 1, '.')) {
        return 0;
    }

    return 1; 
}

int main() {
    char* email;
    size_t size;

   
    printf("Enter your email address: ");
    size = 256; 
    email = (char*)malloc(size * sizeof(char));
    if (email == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

  
    if (fgets(email, size, stdin) == NULL) {
        printf("Error reading input.\n");
        free(email);
        return 1;
    }

  
    email[strcspn(email, "\n")] = '\0';

  
    if (validateEmail(email)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }

      free(email);

    return 0;
}
