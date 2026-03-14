#ifndef MANAGER_H
#define MANAGER_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000
#define FILENAME "Manager.txt"

typedef struct Imformation Imfor;
typedef struct Person Person;
extern Imfor* imfor;
extern Person* head;

struct Person {
    long long password;
    long long M_phone_num;
    int M_area;
    char M_name[MAX];
    char M_sex[MAX];
    int M_age;
    int Area[MAX];
    int Area_count;
    int parking_imfor;
    char Career[MAX];
    int Count_charge;
    int Date_charge[MAX][3];
    Person* next;
};

struct Imformation {
    int Num_Building;
    int Num_parking;
    int parking[MAX];
    int charging_fee;
    int charging_date;
};

void Show_Imfor(Person* head, Imfor* imfor);
void Save(Person* head);
void Imfor_Read();
void AddImfor();
Imfor* Init_imfor(Imfor* imfor);
Person* Init_Person(Person* person);
Person* ADD_TO_LIST(Person* head, Person* person);
Person* Delimfor(Person* head);
Person* ModImfor(Person* head, Imfor* imfor);
Person* Mod_Person(Person* person);

#endif