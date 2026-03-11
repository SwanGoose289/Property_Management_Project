#include "Manager.h"
Imfor* imfor = NULL;
Person* head = NULL;
int Init_imfor() {//初始化imfor对象
    imfor = malloc(sizeof(Imfor));
    if (imfor == NULL) {
        printf("基本信息初始化失败！\n");
        return -1;
    }
    for (int i = 0; i < 10; i++) {
        imfor->parking[i] = 0;
    }
    for (int i = 10; i < MAX; i++) {
        imfor->parking[i] = -1;
    }
    imfor->Num_Building=40;
    imfor->Num_parking = 10;
    imfor->charging_fee = 50;
    imfor->charging_date = 6;
    return 0;
}
void Init_Person(Person* person){//初始化人
    person->password=11111111;
    person->Count_charge=0;
    person->Date_charge[0][0]=0;
    person->Date_charge[0][1]=0;
    person->Date_charge[0][2]=0;
    person->parking_imfor=0;
}
void Save(Person* head) {
    FILE* fp;
    fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("文件打开遇到错误！\n");
        return;
    }
    fprintf(fp, "%d %d %d\n", imfor->Num_Building,imfor->charging_date, imfor->charging_fee);
    /*楼宇数量，收费周期，单次收费金额*/
    for (int i = 0; i < imfor->Num_parking; i++) {
        if(i==0){
            fprintf(fp,"%d",imfor->parking[i]);
        }
        else{
            fprintf(fp, " %d", imfor->parking[i]);//停车位情况
        }
    }
    fprintf(fp, "\n");
    Person* node=head;
    while(node!=NULL){
        fprintf(fp,"%s %s %d %d %lld %lld %d %s\n",node->M_name,node->M_sex,node->M_age,node->M_area,node->M_phone_num,node->password,
            node->parking_imfor,node->Career);
            /*姓名，性别，年龄，住址，电话号，密码，停车位占用，工作*/
        if(strcmp(node->Career,"业主")==0){//工作区域
            fprintf(fp,"0\n");
        }
        else{
            for(int i=0;i<node->Area_count;i++){
                fprintf(fp,"%d ",node->Area[i]);
            }
            fprintf(fp,"\n");
        }
        fprintf(fp,"%d\n",node->Count_charge);
        for(int i=0;i<node->Count_charge;i++){
            fprintf(fp,"%d %d %d ",node->Date_charge[i][0],node->Date_charge[i][1],node->Date_charge[i][2]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    fp = NULL;
    return;
}
void Imfor_Read() {
    Imfor* temp_imfor = malloc(sizeof(Imfor));
    Init_imfor(temp_imfor);
    FILE* fp;
    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("文件打开遇到错误！\n");
        free(temp_imfor);
        temp_imfor = NULL;
        return;
    }
    if (fscanf(fp, "%d %d %d", &temp_imfor->Num_Building,&temp_imfor->charging_date, &temp_imfor->charging_fee) != 3) {
        printf("文件读取失败！\n");//读取楼宇数量，收费周期，单次收费金额
        fclose(fp);
        free(temp_imfor);
        temp_imfor = NULL;
        return;
    }
    int parking_count = 0; // 读取到的停车位数量
    while (fscanf(fp, "%d", &temp_imfor->parking[parking_count]) == 1) {
        parking_count++;
        // 遇到换行停止
        if (fgetc(fp) == '\n') {
            break;
        }
    }
    temp_imfor->Num_parking = parking_count;
    if (imfor == NULL) { // 如果全局imfor没初始化，先分配内存
        imfor = malloc(sizeof(Imfor));
        if (imfor == NULL) {
            printf("全局imfor内存分配失败！\n");
            fclose(fp);
            free(temp_imfor);
            temp_imfor = NULL;
            return;
        }
    }
    *imfor = *temp_imfor;
    free(temp_imfor);
    /*接下来读取人员信息*/
    Person*temp_person=(Person*)malloc(sizeof(Person));
    
    fclose(fp);
}
Person* ADD_TO_LIST(Person* head,Person* person){
    if(person==NULL){
        printf("系统错误！\n");
        return head;
    }
    if(head==NULL){
        head=person;
        person->next=NULL;
        return head;
    }
    Person* node=head;
    while(node->next!=NULL){
        node=node->next;
    }
    node->next=person;
    person->next=NULL;
    return head;
}
void AddImfor() {//添加信息
    Person*person=(Person*)malloc(sizeof(Person));
    if(person==NULL){
        printf("系统异常！");
        return;
    }
    Init_Person(person);//初始化
    printf("请输入你要添加的人员姓名：\n");
    char name[MAX];
    scanf("%s",name);
    strcpy(person->M_name,name);
    printf("请输入ta的性别：1.男2.女\n");
    int sex_choice;
    scanf("%d",&sex_choice);
    switch(sex_choice)
    {
        case 1:
            strcpy(person->M_sex,"男");
            break;
        case 2:
            strcpy(person->M_sex,"女");
            break;
        default:
            printf("输入错误！\n");
            free(person);
            break;
    }
    printf("请输入ta的年龄:\n");
    int age;
    scanf("%d",&age);
    person->M_age=age;
    printf("请输入ta的电话号:\n");
    long long phone_num;
    scanf("%lld",&phone_num);
    person->M_phone_num=phone_num;
    printf("请输入ta的家庭住址:\n");
    int area;
    scanf("%d",&area);
    person->M_area=area;
    printf("请输入ta的工作:1.保安2.保洁3.管家4.业主\n");
    int career_choice;
    scanf("%d",&career_choice);
    switch (career_choice)
    {
    case 1:
        strcpy(person->Career,"保安");
        break;
    case 2:
        strcpy(person->Career,"保洁");
        break;
    case 3:
        strcpy(person->Career,"管家");
        break;
    case 4:
        strcpy(person->Career,"业主");
        break;
    default:
        printf("输入错误！已退出\n");
        free(person);
        return;
        break;
    }
    if(strcmp(person->Career,"业主")!=0){
        printf("请输入ta的工作区域(输入-1停止输入)\n");
        int num;
        int M_count=0;
        while(1){
            scanf("%d",&num);
            if(num==-1){
                break;
            }
            if(M_count>=MAX){
                printf("输入过多\n");
                break;
            }
            person->Area[M_count++]=num;
            person->Area_count=M_count;
        }
    }
    head=ADD_TO_LIST(head,person);\
    Save(head);
}
Person* Delimfor(Person* head){//删除人员
    if(head==NULL){
        printf("系统错误！\n");
        return head;
    }
    printf("请输入你要删除的对象姓名：\n");
    char delname[MAX];
    scanf("%s",delname);
    Person* node=head;
    if(strcmp(node->M_name,delname)==0&&node->next!=NULL){
        head=node->next;
        free(node);
        printf("删除成功！\n");
        Save(head);
        return head;
    }
    if(node->next==NULL){//链表仅1成员
        if(strcmp(node->M_name,delname)!=0){
            printf("找不到对象！\n");
            return head;
        }
        else{
            free(node);
            node=NULL;
            head=NULL;
            printf("删除成功！\n");
            Save(head);
            return head;
        }
    }
    while(node->next!=NULL){
        if(strcmp(node->next->M_name,delname)==0&&node->next->next!=NULL){
            Person* tempnode=node->next;
            node->next=node->next->next;
            free(tempnode);
            printf("删除成功！\n");
            Save(head);
            return head;
        }
        if(strcmp(node->next->M_name,delname)==0&&node->next->next==NULL){
            Person* tempnode=node->next;
            node->next=NULL;
            free(tempnode);
            printf("删除成功！\n");
            Save(head);
            return head;
        }
        node=node->next;
    }
    printf("找不到对象！\n");
    return head;
}
Imfor ModImfor(Person* head) {//更改信息
A:printf("请输入你要修改的对象类型：\n1.人员信息 2.公共服务\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        printf("请输入你要更改的人员姓名：\n");
        S_LIST S_node = server_head;
        char name[MAX];
        scanf("%s", name);
        break;
    case 2:
        printf("请输入你要更改的服务信息：\n1.停车位 2.收费细则");
        int P_choice;
        scanf("%d", &P_choice);
        switch (P_choice) {
        case 1:
        {
            printf("请输入你要操作的停车位：");
            int modparking = 0;
            scanf("%d", &modparking);
            if (imfor->parking[modparking + 1] == 0) {
                printf("是否要关闭该停车位？1.yes 2.no");
                int mod_parking = 0;
                scanf("%d", &mod_parking);
                switch (mod_parking) {
                case 1:
                    imfor->parking[modparking + 1] = -1;
                    printf("已成功关闭！");
                    break;
                case 2:
                    printf("已取消操作");
                    break;
                default:
                    printf("输入错误，已退出");
                    break;
                }
            }
            else if (imfor->parking[modparking + 1] == 1) {
                printf("无法操作！该停车位正在被占用！");
            }
            else {
                printf("是否要开启该停车位？1.yes 2.no");
                int mod_parking = 0;
                scanf("%d", &mod_parking);
                switch (mod_parking) {
                case 1:
                    imfor->parking[modparking + 1] = 0;
                    printf("已成功开放！");
                    break;
                case 2:
                    printf("已取消操作");
                    break;
                default:
                    printf("输入错误，已退出");
                    break;
                }
            }
        }
        case 2:
            printf("请输入你要更改的收费信息：\n1.收费周期 2.单次收费金额\n");
            int chioce;
            switch (choice) {
            case 1:
                printf("请输入更改后的收费周期：\n");
                int newdate;
                scanf("%d", &newdate);
                imfor->charging_date = newdate;
                printf("修改成功！");
                break;
            case 2:
                printf("请输入更改后的单次收费金额：\n");
                int newfee;
                scanf("%d", &newfee);
                imfor->charging_fee = newfee;
                printf("修改成功！");
                break;
            default:
                printf("输入错误，已退出");
                break;
            }
        }
        break;
    default:
        printf("请输入正确的选择！");
        goto A;
        break;
    }
}