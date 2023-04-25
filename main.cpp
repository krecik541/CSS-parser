#include <iostream>
#include"function.h"
#include"blok.h"
#include"selector_list.h"
#include"atrybuty_list.h"

using namespace std;

int main()
{
    lista* tail = nullptr;
    tail = push_end(tail);
    lista* head = tail;
    char *t = new char[250];
    int i = 0, pos = -1, nrlinii = 0;
    bool css = true, selektor = true, atrybut = false, wartosc = false;
    blok *x = new blok;
    x->atrybuty = nullptr;
    x->selektory = nullptr;
    char* r = nullptr;
    while (cin.getline(t, 250))
    {
        i = 0;
        bool napis = false, komenda = false, nawias = false;
        int poczatek = 0, prawa = 0, i1 = 0, i2 = 0, cudzyslow = 0;
        char * v = nullptr, * c1 = nullptr, * c2 = nullptr, funkcja = NULL;
        while (t[i] != '\0')
        {
            if (css == true)
            {
                if ((t[i] == '(' || t[i] == '[' || nawias == true) && t[i] != ')' && t[i] != ']')
                {
                    nawias = true;
                    napis = true;
                }
                else if (t[i] == ')' || t[i] == ']' || nawias == true)
                    nawias = false;
                else if ((t[i] == '\'' && cudzyslow == 0) || (cudzyslow == 1 && t[i] != '\''))
                {
                    cudzyslow = 1;
                    napis = true;
                }
                else if (t[i] == '\'')
                    cudzyslow = 0; 
                /*else if (((t[i] == '\'' || t[i] == '"') && cudzyslow == 0) || (t[i] != '\'' && t[i] != '"' && cudzyslow == 1))
                    cudzyslow = 1;
                else if ((t[i] == '\'' || t[i] == '"') && cudzyslow == 1)
                    cudzyslow = 0;*/
                else if ((t[i] == ':' || t[i] == '.' || t[i] == '_' || t[i] == '#' || t[i] == '-') && selektor == true);//selektor -> przecinek
                else if (t[i] != ' ' && t[i] != '{' && t[i] != ',' && t[i + 1] == '\0' && selektor == true && napis == true)
                {
                    r = makeString(++i, poczatek, prawa, t, napis);
                    x->selektory = fun_naw_otw(selektor, atrybut, x->selektory, r);
                    break;
                }
                else if (t[i] == ' ' || t[i] == '\t' || t[i] == '\r' || (t[i + 1] == '\0' && selektor == true && t[i] != ','))
                {
                    if (wartosc == true)
                    {
                        if (t[i - 1] == ':')
                            poczatek = i + 1;
                        else if (t[i + 1] == EOF && napis == true)
                        {
                            r = makeString(i, poczatek, prawa, t, napis);
                            x->atrybuty = sred(wartosc, atrybut, x->atrybuty, r, &v);
                        }
                        else if (napis == true && (t[i+1] == '.' || (t[i + 1] >= '0' && t[i + 1] <= '9') || (t[i + 1] >= 'a' && t[i + 1] <= 'z') || (t[i + 1] >= 'A' && t[i + 1] <= 'Z') || (t[i + 1] == '#' || t[i + 1] == '%' || t[i + 1] == '.' || t[i + 1] == '*' || t[i + 1] == '"' || t[i + 1] == '\'' || t[i + 1] == ',')));
                        else if (napis == true)
                            prawa++;
                        else if (napis == false)
                            poczatek = i + 1;
                    }
                    else if (selektor == true)
                    {
                        if (t[i] == '{')
                        {
                            selektor = false;
                            atrybut = true;
                        }
                        if ((t[i + 1] == EOF || t[i + 1] == '{' || t[i + 1] == '\0') && napis == true)
                        {
                            r = makeString(i, poczatek, prawa, t, napis);
                            x->selektory = fun_naw_otw(selektor, atrybut, x->selektory, r);
                        }
                        else if (napis == true && (t[i+1] == '.' ||  t[i+1] == '+' ||  t[i+1] == '~' || (t[i + 1] >= 'a' && t[i + 1] <= 'z') || (t[i + 1] >= 'A' && t[i + 1] <= 'Z')));
                        else if (napis == true && t[i + 1] == ',')
                            prawa++;
                        else if (napis == true)
                            prawa++;
                        else if (napis == false)
                            poczatek++;
                    }
                    else if (atrybut == true)
                        poczatek++;
                }
                else if ((t[i] == '#' || t[i] == '%' || t[i] == '.' || t[i] == '"' || t[i] == '*' || t[i] == '\'' || t[i] == '\\' || t[i] == ',') && wartosc == true);
                else if ((t[i] == '-' || t[i] == '*') && atrybut == true);
                else if (t[i] < 32);
                else if ((t[i] < 'a' || t[i] > 'z') && (t[i] < 'A' || t[i] > 'Z') && (t[i] < '0' || t[i] > '9') && t[i] != '"' && t[i] != '\'' && t[i] != '-' && t[i] != '#' && t[i] != '%' && t[i] != '.' && t[i] != '_' && t[i] != '+' && t[i] != '~')
                {
                    r = makeString(i, poczatek, prawa, t, napis);
                    //cout << "*" << r << "*" << endl;
                    if (css == true && r != "")
                    {
                        if (t[i] == '{')
                            x->selektory = fun_naw_otw(selektor, atrybut, x->selektory, r);
                        else if (t[i] == '}')
                        {
                            tail = fun_naw_zam(head, tail, wartosc, selektor, atrybut, x, r, v);
                            x = new blok;
                            x->atrybuty = nullptr;
                            x->selektory = nullptr;
                            //wypisz_lista(head);
                        }
                        else if (t[i] == ',' && selektor == true)
                            x->selektory = x->selektory->append(&(x->selektory), r);
                        else if (t[i] == ':' && atrybut == true)
                            fun_naw_dwukr(wartosc, atrybut, &r, &v);
                        else if (t[i] == ';' && wartosc == true)
                            x->atrybuty = sred(wartosc, atrybut, x->atrybuty, r, &v);
                        else if (t[i] == '?' && t[i + 1] == '?' && t[i + 2] == '?' && t[i + 3] == '?')
                        {
                            css = false;
                            break;
                        }
                        r = nullptr;
                    }
                }
                else if (t[i + 1] == '\0' && wartosc == true)
                {
                    r = makeString(++i, poczatek, prawa, t, napis);
                    x->atrybuty = sred(wartosc, atrybut, x->atrybuty, r, &v);
                }
                
                else
                {
                    napis = true;
                }
            }
            else//komendy nie css
            {
                if ((t[i] >= 'a' && t[i] <= 'z') || (t[i] >= 'A' && t[i] <= 'Z') || t[i] == ':' || t[i] == '?' || t[i] == '*' || t[i] == '#' || t[i] == '-' || t[i] == '.' || t[i] == '_')
                {
                    if (t[i + 1] == ',')
                    {
                        funkcja = t[i];
                        komenda = true;
                    }
                    else if (c1 == nullptr)
                    {
                        czytaj_str(t, i, &c1);
                        if (c1 == nullptr)
                            break;
                        if (c1[0] == '?' && komenda == false)
                        {
                            cout << "? == " << fun_znak_zap(head) << endl;
                            break;
                        }
                        else if (c1[0] == '*' && c1[1] == '*' && c1[2] == '*' && c1[3] == '*' )
                        {
                            css = true;
                            break;
                        }
                        else if (funkcja == 'S' && c1[0] == '?')//i,S,?
                        {
                            i_S_znakZap(head, i1);
                            //cout << "i,S,?\n";
                            break;
                        }
                        else if (funkcja == 'A' && c1[0] == '?')//i,A,?
                        {
                            i_A_znakZap(head, i1);
                            //cout << "i,A,?\n";;
                            break;
                        }
                        else if (funkcja == 'A')//i,A,n
                        {
                            i_A_n(head, i1, c1);
                            //cout << "i,A,n\n" << "*" << i1 << "*" << c1 << "*";
                            break;
                        }
                        else if (funkcja == 'D' && c1[0] == '*')//i,D,*
                        {
                            head = i_D_gwiazdka(head, i1);//funkcja
                            //cout << "i,D,*\n";
                            break;
                        }
                        else if (funkcja == 'D')//i,D,n
                        {
                            head = i_D_n(head, i1, c1);//funkcja
                            //cout << "i,D,n\n";
                            break;
                        }
                    }
                    else
                    {
                        czytaj_str(t, i, &c2);
                        if (funkcja == 'A')//n,A,?
                        {
                            n_A_znakZap(head, c1);//funkcja
                            //cout << "n,A,?\n";
                            break;
                        }
                        else if (funkcja == 'S')//z,S,?
                        {
                            z_S_znakZap(head, c1);//funkcja
                            //cout << "z,S,?\n";
                            break;
                        }
                        else if (funkcja == 'E')
                        {
                            z_E_n(tail, c1, c2);//funkcja
                            //cout << "z,E,n\n";
                            break;
                        }
                    }
                }
                else if ((t[i] >= '0' && t[i] <= '9'))
                {
                    komenda = true;
                    //zczytywanie inta
                    if (i1 == 0)
                        i1 = str_to_int(t, i);
                    else
                    {
                        i2 = str_to_int(t, i);
                        if (funkcja == 'S')
                        {
                            i_S_j(head, i1, i2);//funkcja
                            //cout << "i,S,j\n";
                            break;
                        }
                    }
                }
            }
            i++;
        } 
    }
    czyszczenie_lista(head);
    return 0;
}