#include <iostream>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* next;
    Elem* prev;
    Info info;
};

void insert(Elem*& L, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    Elem* T = L;
    if (L != NULL)
    {
        while (T->next != L)
            T = T->next;
        T->next = tmp;
        tmp->prev = T;
    }
    else
        L = tmp;
    L->prev = tmp;
    tmp->next = L;
}

void LPrint(Elem* L)
{
    Elem* first = L;
    cout << L->info << "  ";
    while (L->next != first)
    {
        L = L->next;
        cout << L->info << "  ";
    }
    cout << endl;
}



int main()
{
    Elem* L = NULL; int imax, value;
    cout << "Enter the amount of values : ";
    cin >> imax;
    for (int i = 0; i < imax; i++)
    {
        cout << "Enter the value : ";
        cin >> value;
        insert(L, value);
    }
    LPrint(L);
}