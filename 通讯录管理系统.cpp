#include<iostream>
using namespace std;
#define Max 1000

struct Person
{
	string m_name;
	int m_sex;//1.�� 2��Ů
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
	cout << "*****   1.�����ϵ��   *****" << endl;
	cout << "*****   2.��ʾ��ϵ��   *****" << endl;
	cout << "*****   3.ɾ����ϵ��   *****" << endl;
	cout << "*****   4.������ϵ��   *****" << endl;
	cout << "*****   5.�޸���ϵ��   *****" << endl;
	cout << "*****   6.�����ϵ��   *****" << endl;
	cout << "*****   0.�˳���ϵ��   *****" << endl;
	cout << "****************************" << endl;
}


void addperson(Addressbooks *abs)
{
	if (abs->m_size == Max)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;

		cout << "�������Ա� " << endl;
		cout << "1.��" << endl;
		cout << "2.Ů" << endl;

		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		cout << "���������䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;

		cout << "������绰��" << endl;
		string number;
		cin >> number;
		abs->personArray[abs->m_size].m_phone = number;

		cout << "�������ַ�� " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_addr = address;

		abs->m_size++;
		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls");
	}
}

void Showperson(Addressbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������ " << abs->personArray[i].m_name << "\t";
			cout << "�Ա� " << (abs->personArray[i].m_sex== 1 ? "��" : "Ů") << "\t";
			cout << "���䣺 " << abs->personArray[i].m_age<< "\t";
			cout << "�绰:" << abs->personArray[i].m_phone<< "\t";
			cout << "סַ: " << abs->personArray[i].m_addr<< endl;
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
			return i;//�ҵ��˷��ش��˵������±�
		}
	}
	return -1;
}

void Deleteperson(Addressbooks* abs)
{
	string name;
	cout << "������ɾ���˵������� " << endl;
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
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void Findperson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ� " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������ " << abs->personArray[ret].m_name << "\t";
		cout << "�Ա� " << abs->personArray[ret].m_sex << "\t";
		cout << "���䣺 " << abs->personArray[ret].m_age << "\t";
		cout << "�绰�� " << abs->personArray[ret].m_phone << "\t";
		cout << "סַ�� " << abs->personArray[ret].m_addr << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

void Modifyperson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ� " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		int select = 0;
		cout << "��ѡ���޸���Ŀ�� " << endl;
		cout << "1.���� 2.�Ա� 3.���� 4.�绰 5.��ַ" << endl;
		cin >> select;
		switch (select)
		{
			case 1:
			{
				string name;
				cout << "������������ " << endl;
				cin >> name;
				abs->personArray[ret].m_name = name;
			}
			break;
			case 2:
			{
				int sex = 0;
				cout << "�������Ա� " << endl;
				cin >> sex;
				while (true)
				{
					if (sex == 1 || sex == 2)
					{
						abs->personArray[ret].m_sex = sex;
						break;
					}
					cout << "�������" << endl;
				}
			}
			break;
			case 3:
			{
				cout << "���������䣺 " << endl;
				int age;
				cin >> age;
				abs->personArray[ret].m_age = age;
			}
			break;
			case 4:
			{
				cout << "������绰�� " << endl;
				string phone;
				cin >> phone;
				abs->personArray[ret].m_phone = phone;
			}
			break;
			case 5:
			{
				cout << "�������ַ�� " << endl;
				string address;
				cin >> address;
				abs->personArray[ret].m_addr = address;
			}
			break;
			default:
				break;
		}
		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴���!" << endl;
	}
	system("pause");
	system("cls");
}
void Cleanperson(Addressbooks*abs)
{
	cout << "�Ƿ�ȷ����գ�" << endl;
	cout << "1-��գ�2-����" << endl;
	int i = 0;
	cin >> i;
	if (i == 1)
	{
		abs->m_size = 0;
		cout << "ͨѶ¼����գ�" << endl;
		
	}
	else if(i == 2)
	{
		cout << "ͨѶ¼�ѱ���!" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
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