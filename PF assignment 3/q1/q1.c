// M.Raahim 24k-0543 
// Assignment 3 q1

#include <stdio.h>
#include <string.h>

typedef struct {
    int employeeCode;
    char employeeName[50];
    int dateOfJoining;
} Employee;

void assignEmployee(Employee *emp) {
    printf("Enter Employee Code: ");
    scanf("%d", &emp->employeeCode);
    getchar();
    printf("Enter Employee Name: ");
    fgets(emp->employeeName, sizeof(emp->employeeName), stdin);
    emp->employeeName[strcspn(emp->employeeName, "\n")] = '\0';
    printf("Enter Date of Joining (YYYYMMDD): ");
    scanf("%d", &emp->dateOfJoining);
}

void checkTenure(Employee employees[], int size) {
    int i,currentDate, count = 0;
    printf("Enter the current date (YYYYMMDD): ");
    scanf("%d", &currentDate);
    printf("\nEmployees with more than 3 years tenure:\n");
    for (i = 0; i < size; i++) {
        int joiningYear = employees[i].dateOfJoining / 10000;
        int currentYear = currentDate / 10000;
        int tenure = currentYear - joiningYear;
        if (tenure > 3) {
            printf("Employee Code: %d\n", employees[i].employeeCode);
            printf("Employee Name: %s\n", employees[i].employeeName);
            printf("Date of Joining: %d\n", employees[i].dateOfJoining);
            printf("Tenure: %d years\n\n", tenure);
            count++;
        }
    }
    printf("Total employees with more than 3 years tenure: %d\n", count);
}

int main() {
    Employee employees[4];
    int i;
    for (i = 0; i < 4; i++) {
        printf("Enter details for Employee %d:\n", i + 1);
        assignEmployee(&employees[i]);
    }
    checkTenure(employees, 4);
    return 0;
}
