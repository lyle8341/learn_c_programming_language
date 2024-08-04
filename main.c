#include <stdio.h>

typedef struct {
    int number;
    char name[20];
    int age;
} Student;

int main() {
    Student user2 = {30, "lyle", 59};

    Student user3 = {.name="zhangsan", .number=78};

    printf("%d %s %d\n", user2.number, user2.name, user2.age);
    printf("%d %s %d\n", user3.number, user3.name, user3.age);
    printf("%d %s %d\n", (&user3)->number, (&user3)->name, (&user3)->age);
    return 0;
}