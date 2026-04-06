#include "Manager.h"
int main() {
    Authorize();
    system("cls");
    if (imfor == NULL) {
        imfor = Init_imfor(imfor);
    }
    Imfor_Read();
    Get_time();
    while (1) {
        printf("—————————————————————————————————————\n|欢迎回来！管理员，今天是%d年%d月%d日 |\n| 1.展示                              |\n| 2.添加                              |\n| 3.删除                              |\n\
| 4.修改                              |\n| 5.查询                              |\n| 6.统计                              |\n| 7.维护密码                          |\n| 8.账单生成                          |\n| 9.排序                              |\n\
| 10.备份与恢复                       |\n| 11.发布公告                         |\n| 0.退出                              |\n—————————————————————————————————————\n",year,month,day);
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            Show_Imfor(head, imfor);
            system("pause");
            system("cls");
            break;
        case 2:
            AddImfor();
            system("pause");
            system("cls");
            break;
        case 3:
            head = Delimfor(head);
            system("pause");
            system("cls");
            break;
        case 4:
            head = ModImfor(head, imfor);
            Save(head);
            system("pause");
            system("cls");
            break;
        case 5:
            FindPerson();
            system("pause");
            system("cls");
            break;
        case 6:
            Sta_Imfor(head);
            system("pause");
            system("cls");
            break;
        case 7:
            maintain_password(head);
            system("pause");
            system("cls");
            break;
        case 8:
            Generate();
            system("pause");
            system("cls");
        case 9:
            head = Sort_Person(head);
            system("pause");
            system("cls");
            break;
        case 10:
            head= Backup_or_Reverse(imfor, head);
            system("pause");
            system("cls");
            break;
        case 11:
            Annouce(imfor);
            system("pause");
            system("cls");
            break;
        case 0:
            Save(head);
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}