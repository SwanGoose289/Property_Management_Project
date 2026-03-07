
//cout << "1. 添加联系人（最多存储1000条）" << endl;
//cout << "2. 显示所有联系人" << endl;
//cout << "3. 删除指定联系人" << endl;
//cout << "4. 查询指定联系人" << endl;
//cout << "5. 修改指定联系人" << endl;
//cout << "6. 清空所有联系人" << endl;
//cout << "7. 退出通讯录系统" << endl;
int main()
{
	person abs[1000];
	int size = 0;
	while(1)
	{
		showmenu();
		int select;
		cin >> select;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "输入无效，请输入数字！" << endl;
			continue;
		}
		switch (select)
		{
		case 1:
			my_add(abs, &size);
			break;
		case 2:
			my_show(abs,size);
			break;
		case 3:
			my_delete(abs, &size);
			break;
		case 4:
			my_search_and_out(abs, size);
			break;
		case 5:
			my_change(abs, size);
			break;
		case 6:
			my_all_delete(&size);
			break;
		case 7:
			cout << "欢迎下次使用，再见" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误，请输入1-7之间的功能编号！" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}
