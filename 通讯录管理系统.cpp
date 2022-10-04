#include<iostream>
using namespace std;
#define Max 1000

struct Person
{
	string m_name;
	int m_sex;//1.男 2，女
	int m_age;
	string m_phone;
	string m_addr;
};

struct Addressbooks
{
	struct Person personArray[Max];
	int m_size;
};

void Showmenu()
{
	cout << "****************************" << endl;
	cout << "*****   1.添加联系人   *****" << endl;
	cout << "*****   2.显示联系人   *****" << endl;
	cout << "*****   3.删除联系人   *****" << endl;
	cout << "*****   4.查找联系人   *****" << endl;
	cout << "*****   5.修改联系人   *****" << endl;
	cout << "*****   6.清空联系人   *****" << endl;
	cout << "*****   0.退出联系人   *****" << endl;
	cout << "****************************" << endl;
}


void addperson(Addressbooks *abs)
{
	if (abs->m_size == Max)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;

		cout << "请输入性别： " << endl;
		cout << "1.男" << endl;
		cout << "2.女" << endl;

		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;

		cout << "请输入电话：" << endl;
		string number;
		cin >> number;
		abs->personArray[abs->m_size].m_phone = number;

		cout << "请输入地址： " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_addr = address;

		abs->m_size++;
		cout << "添加成功！" << endl;
		system("pause");
		system("cls");
	}
}

void Showperson(Addressbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_name << "\t";
			cout << "性别： " << (abs->personArray[i].m_sex== 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->personArray[i].m_age<< "\t";
			cout << "电话:" << abs->personArray[i].m_phone<< "\t";
			cout << "住址: " << abs->personArray[i].m_addr<< endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_name == name)
		{
			return i;//找到了返回此人的数组下标
		}
	}
	return -1;
}

void Deleteperson(Addressbooks* abs)
{
	string name;
	cout << "请输入删除人的姓名： " << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void Findperson(Addressbooks* abs)
{
	cout << "请输入你要查找的联系人： " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名： " << abs->personArray[ret].m_name << "\t";
		cout << "性别： " << abs->personArray[ret].m_sex << "\t";
		cout << "年龄： " << abs->personArray[ret].m_age << "\t";
		cout << "电话： " << abs->personArray[ret].m_phone << "\t";
		cout << "住址： " << abs->personArray[ret].m_addr << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

void Modifyperson(Addressbooks* abs)
{
	cout << "请输入需要修改的联系人： " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		int select = 0;
		cout << "请选择修改项目： " << endl;
		cout << "1.姓名 2.性别 3.年龄 4.电话 5.地址" << endl;
		cin >> select;
		switch (select)
		{
			case 1:
			{
				string name;
				cout << "请输入姓名： " << endl;
				cin >> name;
				abs->personArray[ret].m_name = name;
			}
			break;
			case 2:
			{
				int sex = 0;
				cout << "请输入性别： " << endl;
				cin >> sex;
				while (true)
				{
					if (sex == 1 || sex == 2)
					{
						abs->personArray[ret].m_sex = sex;
						break;
					}
					cout << "输入错误！" << endl;
				}
			}
			break;
			case 3:
			{
				cout << "请输入年龄： " << endl;
				int age;
				cin >> age;
				abs->personArray[ret].m_age = age;
			}
			break;
			case 4:
			{
				cout << "请输入电话： " << endl;
				string phone;
				cin >> phone;
				abs->personArray[ret].m_phone = phone;
			}
			break;
			case 5:
			{
				cout << "请输入地址： " << endl;
				string address;
				cin >> address;
				abs->personArray[ret].m_addr = address;
			}
			break;
			default:
				break;
		}
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人!" << endl;
	}
	system("pause");
	system("cls");
}
void Cleanperson(Addressbooks*abs)
{
	cout << "是否确定清空？" << endl;
	cout << "1-清空，2-保留" << endl;
	int i = 0;
	cin >> i;
	if (i == 1)
	{
		abs->m_size = 0;
		cout << "通讯录已清空！" << endl;
		
	}
	else if(i == 2)
	{
		cout << "通讯录已保留!" << endl;
	}
	system("pause");
	system("cls");
}

int main()
{
	Addressbooks abs;
	abs.m_size = 0;
	int select = 0;
	while (true)
	{
		Showmenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&abs);
			break;
		case 2:
			Showperson(&abs);
			break;
		case 3:
			Deleteperson(&abs);
			break;
		case 4:
			Findperson(&abs);
			break;
		case 5:
			Modifyperson(&abs);
			break;
		case 6:
			Cleanperson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}