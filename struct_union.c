//----structure-------
// #include <stdio.h>
// #include <string.h>

// struct Student
// {
//     char name[30];
//     int age;
//     float cgpa;
// };

// int main()
// {
//     struct Student s1;

//     strcpy(s1.name, "Rahul");
//     s1.age = 19;
//     s1.cgpa = 9.1;
//     struct Student s2 = {"abs", 20, 8.5};

//     printf("Name : %s\n", s1.name);
//     printf("Age  : %d\n", s1.age);
//     printf("CGPA : %.2f\n", s1.cgpa);
//     printf("---------------------\n");
//     printf("Name : %s\n", s2.name);
//     printf("Age  : %d\n", s2.age);
//     printf("CGPA : %.2f\n", s2.cgpa);

//     return 0;
// }

//----------UNION---------
#include <stdio.h>
#include <string.h>
void main()
{
    union Data
    {
        int i;
        float f;
        char l[30];
    };

    union Data d;

    d.i = 25;
    printf("intger value is %d\n", d.i); // printed direct after writing

    d.f = 8.5;
    strcpy(d.l, "uhhl");

    printf("Final Integer: %d\n", d.i);   // Will print completely corrupted garbage data
    printf("Final Float  : %.1f\n", d.f); // Will print completely corrupted garbage data
    printf("Final String : %s\n", d.l);
}