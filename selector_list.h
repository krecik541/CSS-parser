#pragma once
#include<iostream>

using namespace std;

class selector_list {
private:
	char* c = nullptr;
	selector_list* next = nullptr;
public:
	selector_list();
	~selector_list();//delete 

	selector_list* append(selector_list** head, char* t);//dodaje na koniec listy 
	selector_list* last(selector_list* head);//ostatnia pozycja 
	selector_list* pop(selector_list* head, int pos);//usuwa z wyznaczonej pozycji

	void wypisz(selector_list* head);

	int liczEle(selector_list* head);

	void czyszczenie(selector_list* head);
	int iloscWystapien(selector_list* head, char* t);
	char* jtySelektor(selector_list* head, int j);
};
