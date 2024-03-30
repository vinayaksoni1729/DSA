#include <stdio.h>
#include <string.h>
struct myvar{
    char name[10];
    int empid;
    int salary;
};
int main(){
    struct myvar emp;
    strcpy(emp.name,"Abc");
    emp.empid=525;
    emp.salary=239800;
    printf("Name=%s empid=%d salary=%d",emp.name,emp.empid,emp.salary);
    return 0;
}

