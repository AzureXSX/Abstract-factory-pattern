#include "include/Solutions^^.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <Windows.h>
class ITask
{
public:
	virtual void setTask(int x, int y) = 0;
	virtual string* getTask() = 0;
	virtual void setpriority(int x, int y) = 0;
	virtual int* getpriority() = 0;
	virtual void setdate(int x, int y) = 0;
	virtual string* getdate() = 0;
	virtual void setTag(int x, int y) = 0;
	virtual string* getTag() = 0;
	virtual void setoptions(string tk, int prt, string dt, string tag) = 0;
	virtual ~ITask() {}
};

class MENU
{
public:

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	void GoToXY(short x, short y)
	{
		SetConsoleCursorPosition(hStdOut, { x,y });
	}

	void ConsoleCursorVisible(bool show, short size)
	{
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(hStdOut, &structCursorInfo);
		structCursorInfo.bVisible = show;
		structCursorInfo.dwSize = size;
		SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	}
};
const char ESCAPE = 27;
const char UP = 72;
const char DOWN = 80;
const char ENTER = 13;

class Task : public ITask
{
public:
	string* task;
	int* priority;
	string* date;
	string* Tag;
	void setoptions(string tk, int prt, string dt, string tag) override
	{
		task = new string(tk);
		priority = new int(prt);
		date = new string(dt);
		Tag = new string(tag);
	}
	void setTask(int x, int y) override
	{
		MENU M;
		M.GoToXY(x, y);
		string tmp;
	fubuki:M.GoToXY(x, y);
		cout << "Enter task: ";
		getline(cin, tmp);
		for (int i = 0; i < tmp.length(); i++)
		{
			if (!isalpha(tmp[i]) && tmp[i] != ' ')
			{
				M.GoToXY(x, y + 1);
				cout << "Error try again." << endl;
				system("pause");
				system("cls");
				goto fubuki;
			}
		}
		if (tmp.length() == 0)
			goto fubuki;
		task = new string(tmp);
	}
	string* getTask() override
	{
		return task;
	}
	void setpriority(int x, int y) override
	{
		char nul = '+';
	retprty:int prty;
		MENU M;
		M.GoToXY(x, y);
		char mas[40];
		int k = 0;
		int m = 0;
		M.GoToXY(x, y);
		cout << "Enter priority(1-10): ";
		gets_s(mas);
		k = 0;
		m = 0;
		for (int i = 0; i < strlen(mas); i++)
		{
			if (nul == '+')
			{
				if (isdigit(mas[i]))
				{
					k++;
				}
			}
			else if (nul == '-')
			{
				if (isdigit(mas[i]) || mas[i] == '-')
				{
					if (mas[i] == '-')
					{
						m++;
					}
					k++;
				}
			}
			else if (nul == 'o')
			{
				if (isdigit(mas[i]))
				{
					k++;
				}
			}
		}
		if (k != strlen(mas) || k == 0 || m > 1)
		{
			M.GoToXY(x, y + 1);
			cout << "Error, try again." << endl;
			system("pause");
			system("cls");
			goto retprty;
		}
		else
		{
			prty = atoi(mas);
			if (nul == '+')
			{
				if (prty == 0)
				{
					M.GoToXY(x, y + 1);
					cout << "Error, try again." << endl;
					system("pause");
					system("cls");
					goto retprty;
				}
			}
			else if (nul == '-')
			{
				if (strlen(mas) == 1)
				{
					if (mas[0] == '-')
					{
						M.GoToXY(x, y + 1);
						cout << "Error, try again." << endl;
						system("pause");
						system("cls");
						goto retprty;
					}
				}
			}
			else if (nul == 'o')
			{
			}
		}
		if (prty > 10)
		{
			system("cls");
			M.GoToXY(x, y);
			cout << "Out of range! Try again." << endl;
			system("pause");
			system("cls");
			goto retprty;
		}
		priority = new int(prty);
	}
	int* getpriority() override
	{
		return priority;
	}
	void setdate(int x, int y) override
	{
		char nul = '+';
		string Date;
		int day, month;
	mret:MENU M;
		char mas[40];
		int k = 0;
		int m = 0;
	ret3:M.GoToXY(x, y);
		cout << "Enter date(month): ";
		gets_s(mas);
		k = 0;
		m = 0;
		for (int i = 0; i < strlen(mas); i++)
		{
			if (nul == '+')
			{
				if (isdigit(mas[i]))
				{
					k++;
				}
			}
			else if (nul == '-')
			{
				if (isdigit(mas[i]) || mas[i] == '-')
				{
					if (mas[i] == '-')
					{
						m++;
					}
					k++;
				}
			}
			else if (nul == 'o')
			{
				if (isdigit(mas[i]))
				{
					k++;
				}
			}
		}
		if (k != strlen(mas) || k == 0 || m > 1)
		{
			M.GoToXY(x, y+1);
			cout << "Error, try again." << endl;
			system("pause");
			system("cls");
			goto ret3;
		}
		else
		{
			month = atoi(mas);
			if (nul == '+')
			{
				if (month == 0)
				{
					M.GoToXY(x, y+1);
					cout << "Error, try again." << endl;
					system("pause");
					system("cls");
					goto ret3;
				}
			}
			else if (nul == '-')
			{
				if (strlen(mas) == 1)
				{
					if (mas[0] == '-')
					{
						M.GoToXY(x, y+1);
						cout << "Error, try again." << endl;
						system("pause");
						system("cls");
						goto ret3;
					}
				}
			}
			else if (nul == 'o')
			{
			}
		}
		if (month > 12)
		{
			M.GoToXY(x, y+1);
			cout << "Erorr!!!" << endl;
			goto mret;
		}
		y++;
	dret:M.GoToXY(x, y);
		cout << "Enter date(day): ";
		gets_s(mas);
		k = 0;
		m = 0;
		for (int i = 0; i < strlen(mas); i++)
		{
			if (nul == '+')
			{
				if (isdigit(mas[i]))
				{
					k++;
				}
			}
			else if (nul == '-')
			{
				if (isdigit(mas[i]) || mas[i] == '-')
				{
					if (mas[i] == '-')
					{
						m++;
					}
					k++;
				}
			}
			else if (nul == 'o')
			{
				if (isdigit(mas[i]))
				{
					k++;
				}
			}
		}
		if (k != strlen(mas) || k == 0 || m > 1)
		{
			M.GoToXY(x, y + 1);
			cout << "Error, try again." << endl;
			system("pause");
			system("cls");
			goto dret;
		}
		else
		{
			day = atoi(mas);
			if (nul == '+')
			{
				if (day == 0)
				{
					M.GoToXY(x, y + 1);
					cout << "Error, try again." << endl;
					system("pause");
					system("cls");
					goto dret;
				}
			}
			else if (nul == '-')
			{
				if (strlen(mas) == 1)
				{
					if (mas[0] == '-')
					{
						M.GoToXY(x, y + 1);
						cout << "Error, try again." << endl;
						system("pause");
						system("cls");
						goto dret;
					}
				}
			}
			else if (nul == 'o')
			{
			}
		}
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if (day > 31)
			{
				M.GoToXY(x, y+1);
				cout << "Error!!! This month has only 31 days" << endl;
				system("pause");
				system("cls");
				goto dret;
			}
		}
		break;
		case 2:
		{
			if (day > 28)
			{
				M.GoToXY(x, y + 1);
				cout << "Error!!! This month has only 28 days" << endl;
				system("pause");
				system("cls");
				goto dret;
			}
		}
		break;
		case 4:
		case 6:
		case 9:
		case 11:
		{

			if (day > 30)
			{
				M.GoToXY(x, y + 1);
				cout << "Error!!! This month has only 30 days" << endl;
				system("pause");
				system("cls");
				goto dret;
			}
		}
		break;
		}
		Date += to_string(day);
		Date += "\\\\";
		Date += to_string(month);
		Date += "\\\\2022";
		date = new string(Date);
	}
	string* getdate() override
	{
		return date;
	}
	void setTag(int x, int y) override
	{
		string tmp;
		MENU M;
		fubuki:M.GoToXY(x, y);
		cout << "Enter tag: ";
		getline(cin, tmp);
		for (int i = 0; i < tmp.length(); i++)
		{
			if (!isalpha(tmp[i]) && tmp[i] != ' ')
			{
				M.GoToXY(x, y+1);
				cout << "Error try again." << endl;
				system("pause");
				system("cls");
				goto fubuki;
			}
		}
		if (tmp.length() == 0)
			goto fubuki;
		Tag = new string(tmp);
	}
	string* getTag() override
	{
		return Tag;
	}

	virtual ~Task()
	{
		delete task;
		delete priority;
		delete date;
		delete Tag;
	}
};

class AbstractTaskFAC
{
public:
	virtual ITask* createTask() = 0;
	virtual ~AbstractTaskFAC() {}
};

class TaskFAC : public AbstractTaskFAC
{
public:
	ITask* createTask()
	{
		Task* temp = new Task();
		int x = 49, y = 10;
		MENU M;
		M.GoToXY(x, y);
		temp->setTask(x,y);
		y++;
		M.GoToXY(x, y);
		temp->setTag(x,y);
		y++;
		M.GoToXY(x, y);
		temp->setpriority(x,y);
		y++;
		M.GoToXY(x, y);
		temp->setdate(x,y);
		y++;
		M.GoToXY(x, y);
		return temp;
	}
};

class Task_Data
{
public:
	vector<ITask*> tasks;
	~Task_Data()
	{
		for (int i = 0; i < tasks.size(); i++)
		{
			delete tasks[i];
		}
	}

	void view_tasks()
	{
		MENU M;
		int x = 45, y = 10;
		
		for (int i = 0; i < tasks.size(); i++)
		{
			M.GoToXY(x, y);
			cout << "x======================================================x" << endl;
			y++;
			M.GoToXY(x, y);
			cout << "|\tTask     -> [" << *tasks[i]->getTask() << "]" << endl;
			y++;
			M.GoToXY(x, y);
			cout << "|\tTag      -> [" << *tasks[i]->getTag() << "]" << endl;
			y++;
			M.GoToXY(x, y);
			cout << "|\tPriority -> [" << *tasks[i]->getpriority() << "]" << endl;
			y++;
			M.GoToXY(x, y);
			cout << "|\tDate     -> [" << *tasks[i]->getdate() << "]" << endl;
			y++;
			M.GoToXY(x, y);
			cout << "x======================================================x" << endl;
			y++;
			M.GoToXY(x, y);
			this_thread::sleep_for(chrono::milliseconds(1000));
		}
	}
};

class Search
{
public:
	void search_by_date(Task_Data* td)
	{
		int x = 49, y = 10;
		char nul = '+';
		string Date;
		int day, month;
	mret:MENU M;
		char mas[40];
		int k = 0;
		int m = 0;
	ret3:M.GoToXY(x, y);
		cout << "Enter date(month): ";
		gets_s(mas);
		k = 0;
		m = 0;
		for (int i = 0; i < strlen(mas); i++)
		{
			if (nul == '+')
			{
				if (isdigit(mas[i]))
				{
					k++;
				}
			}
			else if (nul == '-')
			{
				if (isdigit(mas[i]) || mas[i] == '-')
				{
					if (mas[i] == '-')
					{
						m++;
					}
					k++;
				}
			}
			else if (nul == 'o')
			{
				if (isdigit(mas[i]))
				{
					k++;
				}
			}
		}
		if (k != strlen(mas) || k == 0 || m > 1)
		{
			M.GoToXY(x, y + 1);
			cout << "Error, try again." << endl;
			system("pause");
			system("cls");
			goto ret3;
		}
		else
		{
			month = atoi(mas);
			if (nul == '+')
			{
				if (month == 0)
				{
					M.GoToXY(x, y + 1);
					cout << "Error, try again." << endl;
					system("pause");
					system("cls");
					goto ret3;
				}
			}
			else if (nul == '-')
			{
				if (strlen(mas) == 1)
				{
					if (mas[0] == '-')
					{
						M.GoToXY(x, y + 1);
						cout << "Error, try again." << endl;
						system("pause");
						system("cls");
						goto ret3;
					}
				}
			}
			else if (nul == 'o')
			{
			}
		}
		if (month > 12)
		{
			M.GoToXY(x, y + 1);
			cout << "Erorr!!!" << endl;
			goto mret;
		}
		y++;
	dret:M.GoToXY(x, y);
		cout << "Enter date(day): ";
		gets_s(mas);
		k = 0;
		m = 0;
		for (int i = 0; i < strlen(mas); i++)
		{
			if (nul == '+')
			{
				if (isdigit(mas[i]))
				{
					k++;
				}
			}
			else if (nul == '-')
			{
				if (isdigit(mas[i]) || mas[i] == '-')
				{
					if (mas[i] == '-')
					{
						m++;
					}
					k++;
				}
			}
			else if (nul == 'o')
			{
				if (isdigit(mas[i]))
				{
					k++;
				}
			}
		}
		if (k != strlen(mas) || k == 0 || m > 1)
		{
			M.GoToXY(x, y + 1);
			cout << "Error, try again." << endl;
			system("pause");
			system("cls");
			goto dret;
		}
		else
		{
			day = atoi(mas);
			if (nul == '+')
			{
				if (day == 0)
				{
					M.GoToXY(x, y + 1);
					cout << "Error, try again." << endl;
					system("pause");
					system("cls");
					goto dret;
				}
			}
			else if (nul == '-')
			{
				if (strlen(mas) == 1)
				{
					if (mas[0] == '-')
					{
						M.GoToXY(x, y + 1);
						cout << "Error, try again." << endl;
						system("pause");
						system("cls");
						goto dret;
					}
				}
			}
			else if (nul == 'o')
			{
			}
		}
		switch (month)
		{
		case 1:
		{
			if (day > 31)
			{
				cout << "Error!!! This month has only 31 days" << endl;
				system("pause");
				system("cls");
				goto dret;
			}
		}
		break;
		case 2:
		{
			if (day > 28)
			{
				cout << "Error!!! This month has only 28 days" << endl;
				system("pause");
				system("cls");
				goto dret;
			}
		}
		break;
		case 3:
		{
			if (day > 31)
			{
				cout << "Error!!! This month has only 31 days" << endl;
				system("pause");
				system("cls");
				goto dret;
			}
		}
		break;
		case 4:
		{

			if (day > 30)
			{
				cout << "Error!!! This month has only 30 days" << endl;
				system("pause");
				system("cls");
				goto dret;
			}
		}
		break;
		case 5:
		{
			if (day > 31)
			{
				cout << "Error!!! This month has only 31 days" << endl;
				system("pause");
				system("cls");
				goto dret;
			}
		}
		break;
		case 6:
		{

			if (day > 30)
			{
				cout << "Error!!! This month has only 30 days" << endl;
				system("pause");
				system("cls");
				goto dret;
			}
		}
		break;
		case 7:
		{
			if (day > 31)
			{
				cout << "Error!!! This month has only 31 days" << endl;
				system("pause");
				system("cls");
				goto dret;
			}
		}
		break;
		case 8:
		{
			if (day > 31)
			{
				cout << "Error!!! This month has only 31 days" << endl;
				system("pause");
				system("cls");
				goto dret;
			}
		}
		break;
		case 9:
		{

			if (day > 30)
			{
				cout << "Error!!! This month has only 30 days" << endl;
				system("pause");
				system("cls");
				goto dret;
			}
		}
		break;
		case 10:
		{
			if (day > 31)
			{
				cout << "Error!!! This month has only 31 days" << endl;
				system("pause");
				system("cls");
				goto dret;
			}
		}
		break;
		case 11:
		{

			if (day > 30)
			{
				cout << "Error!!! This month has only 30 days" << endl;
				system("pause");
				system("cls");
				goto dret;
			}
		}
		break;
		case 12:
		{
			if (day > 31)
			{
				cout << "Error!!! This month has only 31 days" << endl;
				system("pause");
				system("cls");
				goto dret;
			}
		}
		break;
		}
		Date += to_string(day);
		Date += "\\\\";
		Date += to_string(month);
		Date += "\\\\2022";

		y++;
		M.GoToXY(x, y);

		cout << "Searching for task..." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		int kw = 0;
		for (int i = 0; i < td->tasks.size(); i++)
		{
			if (Date == *td->tasks[i]->getdate())
			{
				y++;
				y++;
				M.GoToXY(x, y);
				cout << "Task was found -> " << endl;
				y++;
				y++;
				M.GoToXY(x, y);
				cout << "Task     -> [" << *td->tasks[i]->getTask() << "]" << endl;
				y++;
				M.GoToXY(x, y);
				cout << "Tag      -> [" << *td->tasks[i]->getTag() << "]" << endl;
				y++;
				M.GoToXY(x, y);
				cout << "Priority -> [" << *td->tasks[i]->getpriority() << "]" << endl;
				y++;
				M.GoToXY(x, y);
				cout << "Date     -> [" << *td->tasks[i]->getdate() << "]" << endl;
				y++;
				M.GoToXY(x, y);
				kw = 1;
			}
		}
		if (kw == 0)
		{
			y++;
			M.GoToXY(x, y);
			cout << "No tasks weren't found :(" << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
		}
		if(kw == 1)
			this_thread::sleep_for(chrono::milliseconds(2000));
		y++;
		M.GoToXY(x, y);
		cout << "Search ended" << endl;
		
	}
	void search_by_Tag(Task_Data* td)
	{
		string tmp;
		MENU M;
		int x = 49, y = 10;
	fubuki:M.GoToXY(x, y);
		cout << "Enter tag: ";
		getline(cin, tmp);
		for (int i = 0; i < tmp.length(); i++)
		{
			if (!isalpha(tmp[i]) && tmp[i] != ' ')
			{
				M.GoToXY(x, y + 1);
				cout << "Error try again." << endl;
				system("pause");
				system("cls");
				goto fubuki;
			}
		}
		if (tmp.length() == 0)
			goto fubuki;
		y++;
		M.GoToXY(x, y);
		cout << "Searching for task..." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		int kw = 0;

		for (int i = 0; i < td->tasks.size(); i++)
		{
			if (tmp == *td->tasks[i]->getTag())
			{
				y++;
				y++;
				M.GoToXY(x, y);
				cout << "Task was found -> " << endl;
				y++;
				y++;
				M.GoToXY(x, y);
				cout << "Task     -> [" << *td->tasks[i]->getTask() << "]" << endl;
				y++;
				M.GoToXY(x, y);
				cout << "Tag      -> [" << *td->tasks[i]->getTag() << "]" << endl;
				y++;
				M.GoToXY(x, y);
				cout << "Priority -> [" << *td->tasks[i]->getpriority() << "]" << endl;
				y++;
				M.GoToXY(x, y);
				cout << "Date     -> [" << *td->tasks[i]->getdate() << "]" << endl;
				y++;
				M.GoToXY(x, y);
				kw = 1;
			}
		}
		if (kw == 0)
		{
			y++;
			M.GoToXY(x, y);
			cout << "No tasks weren't found :(" << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
		}
		if (kw == 1)
			this_thread::sleep_for(chrono::milliseconds(2000));
		y++;
		M.GoToXY(x, y);
		cout << "Search ended" << endl;
	}
	void search_by_Task(Task_Data* td)
	{
		MENU M;
		int x = 49, y = 10;
		M.GoToXY(x, y);
		string tmp;
	fubuki:M.GoToXY(x, y);
		cout << "Enter task: ";
		getline(cin, tmp);
		for (int i = 0; i < tmp.length(); i++)
		{
			if (!isalpha(tmp[i]) && tmp[i] != ' ')
			{
				M.GoToXY(x, y + 1);
				cout << "Error try again." << endl;
				system("pause");
				system("cls");
				goto fubuki;
			}
		}
		if (tmp.length() == 0)
			goto fubuki;
		y++;
		M.GoToXY(x, y);
		cout << "Searching for task..." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		int kw = 0;
		for (int i = 0; i < td->tasks.size(); i++)
		{
			if (tmp == *td->tasks[i]->getTask())
			{
				y++;
				y++;
				M.GoToXY(x, y);
				cout << "Task was found -> " << endl;
				y++;
				y++;
				M.GoToXY(x, y);
				cout << "Task     -> [" << *td->tasks[i]->getTask() << "]" << endl;
				y++;
				M.GoToXY(x, y);
				cout << "Tag      -> [" << *td->tasks[i]->getTag() << "]" << endl;
				y++;
				M.GoToXY(x, y);
				cout << "Priority -> [" << *td->tasks[i]->getpriority() << "]" << endl;
				y++;
				M.GoToXY(x, y);
				cout << "Date     -> [" << *td->tasks[i]->getdate() << "]" << endl;
				y++;
				M.GoToXY(x, y);
				kw = 1;
			}
		}
		if (kw == 0)
		{
			y++;
			M.GoToXY(x, y);
			cout << "No tasks weren't found :(" << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
		}
		if (kw == 1)
			this_thread::sleep_for(chrono::milliseconds(2000));
		y++;
		M.GoToXY(x, y);
		cout << "Search ended" << endl;

	}
	void search_by_priority(Task_Data* td)
	{
		char nul = '+';
	retprty:int prty;
		MENU M;
		int x = 49, y = 10;
		yrt:M.GoToXY(49, 10);
		char mas[40];
		int k = 0;
		int m = 0;
		M.GoToXY(x, y);
		cout << "Enter priority(1-10): ";
		gets_s(mas);
		k = 0;
		m = 0;
		for (int i = 0; i < strlen(mas); i++)
		{
			if (nul == '+')
			{
				if (isdigit(mas[i]))
				{
					k++;
				}
			}
			else if (nul == '-')
			{
				if (isdigit(mas[i]) || mas[i] == '-')
				{
					if (mas[i] == '-')
					{
						m++;
					}
					k++;
				}
			}
			else if (nul == 'o')
			{
				if (isdigit(mas[i]))
				{
					k++;
				}
			}
		}
		if (k != strlen(mas) || k == 0 || m > 1)
		{
			M.GoToXY(x, y + 1);
			cout << "Error, try again." << endl;
			system("pause");
			system("cls");
			goto yrt;
		}
		else
		{
			prty = atoi(mas);
			if (nul == '+')
			{
				if (prty == 0)
				{
					M.GoToXY(x, y + 1);
					cout << "Error, try again." << endl;
					system("pause");
					system("cls");
					goto yrt;
				}
			}
			else if (nul == '-')
			{
				if (strlen(mas) == 1)
				{
					if (mas[0] == '-')
					{
						M.GoToXY(x, y + 1);
						cout << "Error, try again." << endl;
						system("pause");
						system("cls");
						goto yrt;
					}
				}
			}
			else if (nul == 'o')
			{
			}
		}
		if (prty > 10)
		{
			system("cls");
			M.GoToXY(x, y);
			cout << "Out of range! Try again." << endl;
			system("pause");
			system("cls");
			goto yrt;
		}
		y++;
		M.GoToXY(x, y);
		
		cout << "Searching for task..." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		int kw = 0;
		for (int i = 0; i < td->tasks.size(); i++)
		{
			if (prty == *td->tasks[i]->getpriority())
			{
				y++;
				y++;
				M.GoToXY(x, y);
				cout << "Task was found -> " << endl;
				y++;
				y++;
				M.GoToXY(x, y);
				cout << "Task     -> [" << *td->tasks[i]->getTask() << "]" << endl;
				y++;
				M.GoToXY(x, y);
				cout << "Tag      -> [" << *td->tasks[i]->getTag() << "]" << endl;
				y++;
				M.GoToXY(x, y);
				cout << "Priority -> [" << *td->tasks[i]->getpriority() << "]" << endl;
				y++;
				M.GoToXY(x, y);
				cout << "Date     -> [" << *td->tasks[i]->getdate() << "]" << endl;
				y++;
				M.GoToXY(x, y);
				kw = 1;
			}
		}
		if (kw == 0)
		{
			y++;
			M.GoToXY(x, y);
			cout << "No tasks weren't found :(" << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
		}
		if (kw == 1)
			this_thread::sleep_for(chrono::milliseconds(2000));
		y++;
		M.GoToXY(x, y);
		cout << "Search ended" << endl;
	}
};
class Task_Methods
{
public:
	void add_Task(Task_Data* td, TaskFAC& taskFAC)
	{
		td->tasks.push_back(taskFAC.createTask());
	}
	void edit_Task(Task_Data* td, int pos)
	{
		int x = 49, y = 10;
		MENU M;
		M.GoToXY(x, y);
		td->tasks[pos]->setTask(x, y);
		y++;
		M.GoToXY(x, y);
		td->tasks[pos]->setTag(x, y);
		y++;
		M.GoToXY(x, y);
		td->tasks[pos]->setpriority(x,y);
		y++;
		M.GoToXY(x, y);
		td->tasks[pos]->setdate(x,y);
		y++;
		M.GoToXY(x, y);
	}
	void delete_task(Task_Data* td, int pos)
	{
		td->tasks.erase(td->tasks.begin() + pos);
	}
};

class In_From_File
{
public:
	void transform(string& s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ')
				s[i] = ',';
		}
	}
	void rtransform(string& s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ',')
				s[i] = ' ';
		}
	}
	void Infile(Task_Data* td)
	{
		
		ofstream f("Data.txt");
		if (!f.is_open())
		{
			cout << "Error!!!" << endl;
		}
		for (int i = 0; i < td->tasks.size(); i++)
		{
			string s = *td->tasks[i]->getTask();
			transform(s);
			f << s << "\n";
			s = *td->tasks[i]->getTag();
			transform(s);
			f << s << "\n";
			s = *td->tasks[i]->getdate();
			f << s << "\n";
			int prt = *td->tasks[i]->getpriority();
			f << prt;
		}

		f.close();
	}
	Task_Data* Fromfile()
	{
		Task_Data* fromfile = new Task_Data();
		ifstream myfile("Data.txt");
		if (!myfile.is_open())
		{
			cout << "Unable to open file" << endl;
		}
		int i = 0;
		string tk, dt, tg;
		int prt;
		while (!myfile.eof())
		{
			myfile >> tk;
			rtransform(tk);
			myfile >> tg;
			rtransform(tg);
			myfile >> dt;
			myfile >> prt;			
			fromfile->tasks.resize(fromfile->tasks.size() + 1);
			fromfile->tasks[fromfile->tasks.size() - 1] = new Task();
			fromfile->tasks[fromfile->tasks.size() - 1]->setoptions(tk, prt, dt, tg);
		}
		myfile.close();
		return fromfile;
	}
};

int main()
{
	string menu[8] = { "x==============x", "|Add task      |", "|Delete Task   |", "|Edit Task     |", "|View all tasks|", "|Search Task   |", "|Exit          |", "x==============x" };
	int active_menu = 1;
	Search s;
	In_From_File iff;
	Task_Methods tm;
	TaskFAC tf;
	ifstream f("Data.txt");
	string gh;
	f >> gh;
	f.close();
	Task_Data* TD = new Task_Data();
	if (gh.length() != 0)
	{
		TD = iff.Fromfile();
	}
	MENU M;
	M.ConsoleCursorVisible(false, 100);
	char ch;
	system("cls");
	while (true)
	{

		int x = 49, y = 10;
		M.GoToXY(x, y);
		for (int i = 0; i < 16; i++)
		{
			SetConsoleTextAttribute(M.hStdOut,

				FOREGROUND_GREEN);
			cout << menu[0][i];
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		y++;
		for (int i = 1; i < size(menu)-1; i++)
		{
			if (i == active_menu)
				SetConsoleTextAttribute(M.hStdOut, FOREGROUND_BLUE |
					FOREGROUND_INTENSITY);

			else SetConsoleTextAttribute(M.hStdOut,

				FOREGROUND_GREEN);
			M.GoToXY(x, y++);
			for (int j = 0; j < menu[i].length(); j++)
			{
				cout << menu[i][j];
				this_thread::sleep_for(chrono::milliseconds(10));
			}
		}
		M.GoToXY(x, y);
		for (int i = 0; i < 16; i++)
		{
			SetConsoleTextAttribute(M.hStdOut,

				FOREGROUND_GREEN);
			cout << menu[7][i];
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		ch = _getch();
		if (ch == -32) ch = _getch();
		switch (ch)
		{
		case ESCAPE:
			exit(0);
		case UP:
			if (active_menu > 1)
			{
				--active_menu;
			}
			break;
		case DOWN:
			if (active_menu < 6)
			{
				++active_menu;
			}
			break;
		case ENTER:
			switch (active_menu)
			{
			case 1:
			{
				system("cls");
				M.GoToXY(49, 10);
				tm.add_Task(TD, tf);
				system("cls");
				M.GoToXY(49, 10);
				cout << "Task was successfully added" << endl;
				iff.Infile(TD);
				system("pause");
				system("cls");
			}
				break;
			case 2:
			{
				system("cls");
				M.GoToXY(49, 10);
				if (TD->tasks.size() == 0)
				{
					cout << "You don't have any tasks :(" << endl;
					system("pause");
					system("cls");
				}
				else
				{
					char nul = 'o';
				retpos:int prty;
					MENU M;
					M.GoToXY(x, y);
					char mas[40];
					int k = 0;
					int m = 0;
					M.GoToXY(x, y);
					cout << "Enter task position which you wanna delete(0-" << TD->tasks.size() - 1 << "): ";
					gets_s(mas);
					k = 0;
					m = 0;
					for (int i = 0; i < strlen(mas); i++)
					{
						if (nul == '+')
						{
							if (isdigit(mas[i]))
							{
								k++;
							}
						}
						else if (nul == '-')
						{
							if (isdigit(mas[i]) || mas[i] == '-')
							{
								if (mas[i] == '-')
								{
									m++;
								}
								k++;
							}
						}
						else if (nul == 'o')
						{
							if (isdigit(mas[i]))
							{
								k++;
							}
						}
					}
					if (k != strlen(mas) || k == 0 || m > 1)
					{
						M.GoToXY(x, y + 1);
						cout << "Error, try again." << endl;
						system("pause");
						system("cls");
						goto retpos;
					}
					else
					{
						prty = atoi(mas);
						if (nul == '+')
						{
							if (prty == 0)
							{
								M.GoToXY(x, y + 1);
								cout << "Error, try again." << endl;
								system("pause");
								system("cls");
								goto retpos;
							}
						}
						else if (nul == '-')
						{
							if (strlen(mas) == 1)
							{
								if (mas[0] == '-')
								{
									M.GoToXY(x, y + 1);
									cout << "Error, try again." << endl;
									system("pause");
									system("cls");
									goto retpos;
								}
							}
						}
						else if (nul == 'o')
						{
						}
					}
					if (prty > TD->tasks.size()-1)
					{
						system("cls");
						M.GoToXY(x, y);
						cout << "Out of range! Try again." << endl;
						system("pause");
						system("cls");
						goto retpos;
					}
					tm.delete_task(TD, prty);
					M.GoToXY(x, y+1);
					cout << "Task was successfully deleted" << endl;
					iff.Infile(TD);
					system("pause");
					system("cls");
				}
				
			}
			break;
			case 3:
			{
				system("cls");
				M.GoToXY(49, 10);
				if (TD->tasks.size() == 0)
				{
					cout << "You don't have any tasks :(" << endl;
					system("pause");
					system("cls");
				}
				else
				{
					char nul = 'o';
				retpo2s:int prty;
					MENU M;
					M.GoToXY(x, y);
					char mas[40];
					int k = 0;
					int m = 0;
					M.GoToXY(x, y);
					cout << "Enter task position which you wanna edit(0-" << TD->tasks.size() - 1 << "): ";
					gets_s(mas);
					k = 0;
					m = 0;
					for (int i = 0; i < strlen(mas); i++)
					{
						if (nul == '+')
						{
							if (isdigit(mas[i]))
							{
								k++;
							}
						}
						else if (nul == '-')
						{
							if (isdigit(mas[i]) || mas[i] == '-')
							{
								if (mas[i] == '-')
								{
									m++;
								}
								k++;
							}
						}
						else if (nul == 'o')
						{
							if (isdigit(mas[i]))
							{
								k++;
							}
						}
					}
					if (k != strlen(mas) || k == 0 || m > 1)
					{
						M.GoToXY(x, y + 1);
						cout << "Error, try again." << endl;
						system("pause");
						system("cls");
						goto retpo2s;
					}
					else
					{
						prty = atoi(mas);
						if (nul == '+')
						{
							if (prty == 0)
							{
								M.GoToXY(x, y + 1);
								cout << "Error, try again." << endl;
								system("pause");
								system("cls");
								goto retpo2s;
							}
						}
						else if (nul == '-')
						{
							if (strlen(mas) == 1)
							{
								if (mas[0] == '-')
								{
									M.GoToXY(x, y + 1);
									cout << "Error, try again." << endl;
									system("pause");
									system("cls");
									goto retpo2s;
								}
							}
						}
						else if (nul == 'o')
						{
						}
					}
					if (prty > TD->tasks.size() - 1)
					{
						system("cls");
						M.GoToXY(x, y);
						cout << "Out of range! Try again." << endl;
						system("pause");
						system("cls");
						goto retpo2s;
					}
					system("cls");
					tm.edit_Task(TD, prty);
					M.GoToXY(x, y + 1);
					cout << "Task was successfully edited" << endl;
					iff.Infile(TD);
					system("pause");
					system("cls");
				}
			}
			break;
			case 4:
			{
				
				system("cls");
				M.GoToXY(49, 10);
				if (TD->tasks.size() == 0)
				{
					cout << "You don't have any tasks :(" << endl;
					system("pause");
					system("cls");
				}
				else
				{
					TD->view_tasks();
					system("pause");
					system("cls");
				}
				
			}
			break;
			case 5:
			{
				system("cls");
				M.GoToXY(49, 10);
				if (TD->tasks.size() == 0)
				{
					cout << "You don't have any tasks :(" << endl;
					system("pause");
					system("cls");
				}
				else
				{
					cout << "Select search category -> ";
					M.GoToXY(49, 11);
					cout << "1.By task Name" << endl;
					M.GoToXY(49, 12);
					cout << "2.By task Tag" << endl;
					M.GoToXY(49, 13);
					cout << "3.By task Date" << endl;
					M.GoToXY(49, 14);
					cout << "4.Dy priority" << endl;
					M.GoToXY(49, 15);
					cout << "Make your choice: ";
					tye:char ct = _getch();
					if (ct != '1' && ct != '2' && ct != '3' && ct != '4')
						goto tye;
					switch (ct)
					{
					case'1':
					{
						system("cls");
						s.search_by_Task(TD);
					}
					break;
					case'2':
					{
						system("cls");
						s.search_by_Tag(TD);
					}
					break;
					case'3':
					{
						system("cls");
						s.search_by_date(TD);
					}
					break;
					case'4':
					{
						system("cls");
						s.search_by_priority(TD);
					}
					break;
					}
					system("pause");
					system("cls");
				}
				
			}
			break;
			case 6:
			{
				exit(0);
			}
			break;
			}
			break;
		}
	}
	iff.Infile(TD);
}				