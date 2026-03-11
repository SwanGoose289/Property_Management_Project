#include "Manager.h"
int main() {
    int res = Init_imfor();
    if (res == -1) {
        printf("系统异常！\n");
        exit(1);
    }
    Imfor_Read();
    Person* person = (Person*)malloc(sizeof(Person));
    AddImfor();
    return 0;
}