#include <stdio.h>
#include <stdlib.h>
struct DOJ {
    int date, month, year;
};
struct Salary {
    int Basic, Da, HRA;
};
typedef struct {
    char *Ename, *Eid;
    struct DOJ dateofjoin;
    struct Salary salaryofemployee;
} emp;
emp* create(int n) {
    return (emp*)malloc(n * sizeof(emp));
}
void read(emp *employees, int n) {
    for (int i = 0; i < n; i++) {
        employees[i].Ename = (char *)malloc(50 * sizeof(char));
        employees[i].Eid = (char *)malloc(10 * sizeof(char));
        printf("Enter Employee name, ID, Joining date (dd mm yyyy), Basic, DA, HRA:\n");
        scanf("%s %s %d %d %d %d %d %d",
              employees[i].Ename, employees[i].Eid,
              &employees[i].dateofjoin.date, &employees[i].dateofjoin.month, &employees[i].dateofjoin.year,
              &employees[i].salaryofemployee.Basic, &employees[i].salaryofemployee.Da, &employees[i].salaryofemployee.HRA);
    }
}
void display(emp *employees, int n) {
    printf("Employee details:\n");
    for (int i = 0; i < n; i++) {
        printf("\n%s (ID: %s) Joining date: %d/%d/%d Basic: %d, DA: %d, HRA: %d\n",
               employees[i].Ename, employees[i].Eid,
               employees[i].dateofjoin.date, employees[i].dateofjoin.month, employees[i].dateofjoin.year,
               employees[i].salaryofemployee.Basic, employees[i].salaryofemployee.Da, employees[i].salaryofemployee.HRA);
    }
}
void deallocate(emp *employees, int n) {
    for (int i = 0; i < n; i++) {
        free(employees[i].Ename);
        free(employees[i].Eid);
    }
    free(employees);
}
int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    emp *employees = create(n);
    read(employees, n);
    display(employees, n);
    deallocate(employees, n);
    return 0;
}
