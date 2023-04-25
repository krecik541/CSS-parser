#include "atrybuty_list.h"
#include<iostream>
#include <cstring>
#include<stdio.h>

using namespace std;

atrybuty_list::atrybuty_list()
{
	;
}

atrybuty_list::~atrybuty_list()
{
	;
}

atrybuty_list* atrybuty_list::append(atrybuty_list** head, char key[], char value[])
{
	bool b = false;
	*head = exists(head, key, value, b);
	if (b == true)
	{
		return *head;
	}
	atrybuty_list* tmp = new atrybuty_list;
	swap(tmp->key, key);
	swap(tmp->value, value);
	tmp->next = nullptr;
	if (*head == nullptr)
		return tmp;
	last(*head)->next = tmp;
	return *head;
}

atrybuty_list* atrybuty_list::last(atrybuty_list* head)
{
	if (head == nullptr)
		return nullptr;
	while (head->next != nullptr)
	{
		head = head->next;
	}
	return head;
}

atrybuty_list* atrybuty_list::pop(atrybuty_list* head, int pos)
{
	atrybuty_list* tmp = head;
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

atrybuty_list* atrybuty_list::exists(atrybuty_list** head, char key[], char value[], bool& b)
{
	atrybuty_list* tmp_head = *head;
	if (tmp_head == nullptr)
		return nullptr;
	while (tmp_head != nullptr)
	{
		//cout << (tmp_head->key == key) ? 1 : 0;

		if (strcmp(key, tmp_head->key) == 0)
		{
			b = true;
			tmp_head->value = value;
			break;
		}
		tmp_head = tmp_head->next;
	}
	return *head;
}

void atrybuty_list::wypisz(atrybuty_list* head)
{
	if (head == nullptr)
		return;
	while (head != nullptr)
	{
		cout << "\t*" << head->key << "*" << head->value << "*" << endl;
		head = head->next;
	}
}

int atrybuty_list::liczEle(atrybuty_list* head)
{
	int i = 0;
	if (head == nullptr)
		return 0;
	while (head != nullptr)
	{
		head = head->next;
		i++;
	}
	return i;
}

char* atrybuty_list::znajdzWartosc(atrybuty_list* head, char* t)
{
	while (head != nullptr)
	{
		if (strcmp(t, head->key) == 0)
		{
			return head->value;
		}
		head = head->next;
	}
	return nullptr;
}

void atrybuty_list::czyszczenie(atrybuty_list* head)
{
	while (head != nullptr)
	{
		atrybuty_list* atr = head;
		head = head->next;
		delete atr;
	}
}

atrybuty_list* atrybuty_list::pop_name(atrybuty_list* head, char* name, bool& empty, bool& correct)
{
	if (head == nullptr || (head->next == nullptr && strcmp(name, head->key) == 0))
	{
		empty = true;
		return nullptr;
	}
	else if (head->next == nullptr)
	{
		return head;
	}
	else if (strcmp(name, head->key) == 0)
	{
		correct = true;
		return head->next;
	}
	atrybuty_list* tmp = head;
	while (tmp->next->next != nullptr)
	{
		if (strcmp(name, tmp->next->key) == 0)
		{
			correct = true;
			tmp->next = tmp->next->next;
			return head;
		}
		tmp = tmp->next;
	}
	if (tmp->next->key == nullptr && strcmp(name, tmp->next->key) == 0)
	{
		correct = true;
		tmp->next = nullptr;
		return head;
	}
	return head;
}

int atrybuty_list::iloscWystapien(atrybuty_list* head, char* t)
{
	while (head != nullptr)
	{
		if (strcmp(t, head->key) == 0)
			return 1;
		head = head->next;
	}
	return 0;
}