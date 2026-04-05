void show_my_info(int index);
void add_record(int staff_id);
void show_my_records(int staff_id);
void change_password(int index,char* new_password);
void query_my_area(int index);
void query_owner_by_name(char* name);
void statistics_by_year(int year,int index);
int statistics_by_area(char* area,int index);
int statistics_by_year_and_area(int year,char* area,int index);
void statistics_2026_unpaid(int index);
void statistics_year_condition(int index);
void query_all_payment(int owner_id);
void query_payment_by_year(int owner_id, int year);
void query_unpaid_by_year(int year, int index);
void check_birthday_and_care();
void edit_owner_profile(int index);
void query_owner_by_tag();
void query_birthday_this_month();
void statistics_by_tags();
int calculate_weekly_score(int staff_id);
void generate_weekly_report(int staff_id,int index);
void show_weekly_rank();
int get_my_rank(int staff_id);

//物业服务人员系统
void server_system();