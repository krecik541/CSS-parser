#include"selector_list.h"
#include<iostream>
#include<stdio.h>

using namespace std;

selector_list::selector_list()
{
	;
}

selector_list::~selector_list()
{
	;
}

selector_list* selector_list::append(selector_list** head, char *t)
{
	if(t[0] == 0 || t == "" || t == " " || t == nullptr)
		return *head;
	selector_list* tmp = new selector_list;
	swap(tmp->c, t);
	tmp->next = nullptr;
	if (*head == nullptr)
		return tmp;
	last(*head)->next = tmp;
	return *head;
}

selector_list* selector_list::last(selector_list* head)
{
	if (head == nullptr)
		return nullptr;
	while (head->next != nullptr)
	{
		head = head->next;
	}
	return head;
}

selector_list* selector_list::pop(selector_list* head, int pos)
{
	selector_list* tmp = head;
	int i = 1;
	if (head == nullptr)
		return nullptr;
	while (i <= pos)
	{
		tmp = tmp->next;
		if (tmp == nullptr)
			return head;
		i++;
	}
	delete tmp;
	return head;
}

void selector_list::wypisz(selector_list* head)
{
	if (head == nullptr)
		return;
	while (head != nullptr)
	{
		cout << head->c << "*";
		head = head->next;
	}
	cout << endl;
}

int selector_list::liczEle(selector_list* head)
{
	int i = 0;
	if (head == nullptr)
		return -1;
	while (head != nullptr)
	{
		head = head->next;
		i++;
	}
	return i;
}

void selector_list::czyszczenie(selector_list* head)
{
	while (head != nullptr)
	{
		selector_list* atr = head;
		head = head->next;
		delete atr;
	}
}

int selector_list::iloscWystapien(selector_list* head, char* t)
{
	/*selector_list* tmp = head;
	char* x = new char[3];
	x[0] = 'h';
	x[1] = '5';
	x[2] = '\0';*/
	while (head != nullptr)
	{
		/*if (t[0] == 'h')
			cout << "--t = " << t[0] << t[1] << " -- head->c = " << head->c << " --" << endl;*/
		if (strcmp(t, head->c) == 0)
		{

			/*if (strcmp(t, x) == 0)
			{
				while (tmp != nullptr)
				{
					cout << tmp->c;
					tmp = tmp->next;
				}
				cout << "\n";
			}*/
			return 1;
		}	
		head = head->next;
	}
	return 0;
}

char* selector_list::jtySelektor(selector_list* head, int j)
{
	int i = 0;
	while (head != nullptr)
	{
		i++;
		if (i == j)
		{
			return head->c;
		}
		head = head->next;
	}
	return nullptr;
}