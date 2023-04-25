#pragma once
#include<iostream>

using namespace std;

class atrybuty_list
{
private:
	char* key = nullptr;
	char* value = nullptr;
	atrybuty_list* next = nullptr;
public:
	atrybuty_list();
	~atrybuty_list();

	atrybuty_list* append(atrybuty_list** head, char key[], char value[]);//dodaje na koniec listy 
	atrybuty_list* last(atrybuty_list* head);//ostatnia pozycja 
	atrybuty_list* pop(atrybuty_list* head, int pos);//usuwa z wyznaczonej pozycji
	atrybuty_list* pop_name(atrybuty_list* head, char* name, bool& empty, bool& correct);//usuwa atrybut o konkretnej nazwie
	atrybuty_list* exists(atrybuty_list** head, char key[], char value[], bool& b);//czy istnieje element taki jak podany

	void wypisz(atrybuty_list* head);
	int liczEle(atrybuty_list* head);
	char* znajdzWartosc(atrybuty_list* head, char* t);
	void czyszczenie(atrybuty_list* head);
	int iloscWystapien(atrybuty_list* head, char* t);
}; 
