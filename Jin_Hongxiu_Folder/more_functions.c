#include "head.h"
void e_system()
{
	FILE* fp = fopen("park.txt", "r+");//r+读写打开方式
	char line[1024];
	fgets(line, sizeof(line), fp);
	char* name[10] = { "灯1","灯2","灯3","灯4","冰箱","洗衣机","热水器","空调","电视","风扇"};
	while (1)
	{
		printf("1.打开电器\n");
		printf("2.关闭电器\n");
		printf("3.退出\n");
		printf("请选择\n");
		int tmp = 0;
		scanf("%d", &tmp);
		if (tmp == 1)
		{
			open(line,name);//关闭电器
			rewind(fp);//把指针重新拉回开头，要不然就在尾部继续写了，fgets会让指针往后走
			fputs(line, fp);
			break;
		}
		else if (tmp == 2)
		{
			off(line,name);//打开电器
			rewind(fp);
			fputs(line, fp);
			break;
		}
		else if (tmp == 3)
		{
			printf("欢迎下次使用\n");
			break;
		}
		else
		{
			printf("错误，请重新输入\n");
		}
	}
	fclose(fp);
}
void open(char line[],char* name[])
{
	printf("电器使用情况：\n");
	int i = 0;
	int count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '1')
		{
			printf("%s 开启\n",name[i]);
			count++;
		}
		else
		{
			printf("%s 关闭\n", name[i]);
		}
		i++;
	}
	printf("\n");
	printf("现有%d个电器正在使用\n", count);
	printf("请选择:\n");
	int num;
	scanf("%d", &num);
	if (line[num - 1] == '0')
	{
		line[num - 1] = '1';
		printf("成功\n");
	}
	else
	{
		printf("该电器已开启\n");
	}
}
// 关闭
void off(char line[],char* name[])
{
	printf("电器使用情况：\n");
	int i = 0;
	int count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '1')
		{
			printf("%s 开启\n", name[i]);
			count++;
		}
		else
		{
			printf("%s 关闭\n", name[i]);
		}
		i++;
	}
	printf("\n");
	printf("现有%d个电器正在使用\n", count);
	printf("\n请输入要关闭的电器：");
	int num;
	scanf("%d", &num);
	if (line[num - 1] == '1')
	{
		line[num - 1] = '0';  // 变回可用
		printf("成功！\n");
	}
	else
	{
		printf("该电器未使用\n");
	}
}
void submit()
{
	FILE* fp = fopen("submit.txt", "r+");
	if (fp == NULL)//没找到文件
	{
		while (1)
		{
			printf("暂无维修\n");
			printf("是否上报新维修？（y/n）\n");
			clean();//吃换行
			char tmp;
			scanf("%c", &tmp);
			if (tmp == 'y')
			{
				clean();//吃换行
				fp = fopen("submit.txt", "w+");
				printf("请写入需要维修的问题\n");
				char wrongs[1024];
				fgets(wrongs, sizeof(wrongs), stdin);
				wrongs[strcspn(wrongs, "\n")] = '\0';//找到换行符的位置，把它改成字符串结束符 \0,strcspn 从字符串开头往后数:数到 \n 时，一共走了多少个字符。
				fputs(wrongs, fp);
				fclose(fp);
				printf("成功\n");
				return;
			}
			else if (tmp == 'n')
			{
				printf("欢迎下次使用\n");//文件没找到就不用关闭了
				return;
			}
			else
			{
				printf("错误，请重新输入\n");
			}
		}
	}
	else//找到文件了
	{
		char wrongs[1024];
		fgets(wrongs, sizeof(wrongs), fp);
		while (1)
		{
			printf("问题：%s\n",wrongs);
			printf("等待维修中\n");
			printf("1.标记维修已完成(删除文件)\n");
			printf("2.退出维修系统\n");
			printf("请输入\n");
			int tmp = 0;
			scanf("%d", &tmp);
			clean();

			if (tmp == 1)
			{
				fclose(fp);//关闭文件
				remove("submit.txt");//删除文件
				printf("成功\n");
				return;
			}
			else if (tmp == 2)
			{
				fclose(fp);
				printf("欢迎下次使用\n");
				return;
			}
			else
			{
				printf("错误，请重新输入\n");
			}
		}
	}
}
void suggestions()//给出建议
{
	FILE* fp = fopen("suggestions.txt", "a");
	char suggestion[1024];
	printf("请输入您的建议\n");
	clean();//去掉缓冲区残留的\n（在选择功能的时候产生的）
	fgets(suggestion, sizeof(suggestion), stdin);
	fputs(suggestion, fp);
	fputs("\n", fp);
	fputs("-----------------------------------------\n", fp);
	fclose(fp);
	printf("提交成功\n");
}
