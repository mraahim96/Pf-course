//M.RAAHIM //24k-0543 //q8
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int BinaryToDecimal(int number);
int DecimalToBinary(int number);
void DecimalToHexadecimal(int number);
void HexadecimalToDecimal(char hexnumber[]);
void BinaryToHexadecimal(int number);
void HexadecimalToBinary(char hexnumber[]);

int displaymenu() {
    int choice;
    
    printf("\nNumerical Conversion Menu:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Hexadecimal to Decimal\n");
    printf("5. Binary to Hexadecimal\n");
    printf("6. Hexadecimal to Binary\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    
    while (scanf("%d", &choice) != 1) {
        printf("Invalid input! Please enter a number.\n");
        while(getchar() != '\n');
        printf("Enter your choice: ");
    }
    
    return choice;
}

int checkbinary(int x)
{
	int j;
  while (x > 0) 
  {
    j = x % 10;
    if (j != 0 && j != 1) 
	{
      return 0;
      break;
    }
    x = x / 10;
    if (x == 0) 
	{
     return 1;
    }
  }
}

int checkhex(const char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) {
            return 0; 
        }
    }
    return 1;
}

int main() {
    int choice, decimalnumber, binarynumber;
    char hexnumber[20];

    while (1) {
        choice = displaymenu();

        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%d", &binarynumber);
                while (checkbinary(binarynumber)==0)
                {
                	printf("Enter a valid binary number: ");
                	scanf("%d", &binarynumber);
				}
				printf("Decimal equivalent: %d\n", BinaryToDecimal(binarynumber));
                break;

            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalnumber);
                printf("Binary equivalent: %d\n", DecimalToBinary(decimalnumber));
                break;

            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalnumber);
                DecimalToHexadecimal(decimalnumber);
                break;

            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexnumber);
                 while (checkhex(hexnumber)==0)
                {
                	printf("Enter a valid hexadecimal number: ");
                	scanf("%s", hexnumber);
				}
                HexadecimalToDecimal(hexnumber);
                break;

            case 5:
                printf("Enter a binary number: ");
                scanf("%d", &binarynumber);
                 while (checkbinary(binarynumber)==0)
                {
                	printf("Enter a valid binary number: ");
                	scanf("%d", &binarynumber);
				}
                BinaryToHexadecimal(binarynumber);
                break;

            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexnumber);
                 while (checkhex(hexnumber)==0)
                {
                	printf("Enter a valid hexadecimal number: ");
                	scanf("%s", hexnumber);
				}
                HexadecimalToBinary(hexnumber);
                break;

            case 7:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}

int BinaryToDecimal(int number) {
    int decimal = 0, base = 1, remainder;
    
    while (number > 0) {
        remainder = number % 10;
        decimal += remainder * base;
        number /= 10;
        base *= 2;
    }
    
    return decimal;
}

int DecimalToBinary(int number) {
    int binary = 0, base = 1;
    
    while (number > 0) {
        int lastdigit = number % 2;
        binary += lastdigit * base;
        number /= 2;
        base *= 10;
    }
    
    return binary;
}

void DecimalToHexadecimal(int number) {
    char hex[20];
    int i = 0;

    if (number == 0) {
        printf("Hexadecimal equivalent: 0\n");
        return;
    }

    while (number != 0) {
        int temp = number % 16;
        
        if (temp < 10)
            hex[i++] = temp + '0';
        else
            hex[i++] = temp - 10 + 'A';
        
        number /= 16;
    }

    printf("Hexadecimal equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        putchar(hex[j]);
    }
    putchar('\n');
}

void HexadecimalToDecimal(char hexnumber[]) {
    int decimal = (int)strtol(hexnumber, NULL, 16);
    printf("Decimal equivalent: %d\n", decimal);
}

void BinaryToHexadecimal(int number) {
    int decimal = BinaryToDecimal(number);
    DecimalToHexadecimal(decimal);
}

void HexadecimalToBinary(char hexnumber[]) {
    int decimal = (int)strtol(hexnumber, NULL, 16);
    
    if (decimal == 0) {
        printf("Binary equivalent: 0\n");
        return;
    }

    char binary[100];
    int index = 0;

    while (decimal > 0) {
        binary[index++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    printf("Binary equivalent: ");
    for (int j = index - 1; j >= 0; j--) {
        putchar(binary[j]);
    }
    putchar('\n');
}