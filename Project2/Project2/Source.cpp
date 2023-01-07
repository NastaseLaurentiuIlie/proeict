#include <iostream>
#include <string>
#include <list>
#include <fstream>
using namespace std;

class Produs {
    string _producator;
public:
    Produs(string producator)
    {
        _producator = producator;
    }
    string getProd()
    {
        return _producator;
    }
};
class Tableta : public Produs
{
    string _culoare;
    float _dimensiune;
public:
    Tableta(string producator, string culoare, float dimensiune) : Produs(producator)
    {
        _culoare = culoare;
        _dimensiune = dimensiune;
    }
    string getColor()
    {
        return _culoare;
    }
    float getDimension()
    {
        return _dimensiune;
    }
};
class Smartphone : public Produs
{
    int _anFabricatie;
    float _pret;
public:
    Smartphone(string producator, int an, float pret) : Produs(producator)
    {
        _anFabricatie = an;
        _pret = pret;
    }
    int getAn()
    {
        return _anFabricatie;
    }
    float getPrice()
    {
        return _pret;
    }
};
ostream& operator<<(ostream& iesire, Tableta t)
{
    iesire << "Producator: " << t.getProd() << endl;
    iesire << "Culoare: " << t.getColor() << endl;
    iesire << "Dimensiune: " << t.getDimension() << endl;
    return iesire;
}
ostream& operator<<(ostream& iesire, Smartphone s)
{
    iesire << "Producator: " << s.getProd() << endl;
    iesire << "An fabricatie: " << s.getAn() << endl;
    iesire << "Pret: " << s.getPrice() << endl;
    return iesire;
}
void introducereTableta(list<Tableta>* tablete)
{
    string prod, cul;
    float dim;
    cout << "\nIntroduceti producatorul: ";
    getchar();
    getline(cin, prod);
    cout << "Introduceti culoarea: ";
    getline(cin, cul);

    cout << "Introduceti dimensiunea: ";
    cin >> dim;
    tablete->push_back(*(new Tableta(prod, cul, dim)));
    cout << cul << endl;
}
void introducereSmartphone(list<Smartphone>* smarts)
{
    string prod;
    int an;
    float pret;
    cout << "\nIntroduceti producatorul: ";
    getchar();
    getline(cin, prod);
    cout << "Introduceti anul fabricatiei: ";
    cin >> an;
    cout << "Introduceti pretul: ";
    cin >> pret;
    smarts->push_back(*(new Smartphone(prod, an, pret)));
}
void citireFisier(list<Tableta>* tablete, list<Smartphone>* smarts)
{
    cout << " [ + ] SE INCARCA ARTICOLELE DIN BAZA DE DATE\n";
    fstream f("/home/camil/CLionProjects/IACOB_CALIN_TEST2/input.txt");
    int mode;
    string producator;
    try {
        if (f.is_open()) {
            while (!f.eof()) {
                f >> mode >> producator;

                if (mode == 0) {
                    ;
                    string culoare;
                    float dimensiune;
                    f >> culoare >> dimensiune;
                    cout << culoare << " " << dimensiune;
                    tablete->push_back(*(new Tableta(producator, culoare, dimensiune)));

                }
                else if (mode == 1) {
                    int an;
                    float pret;
                    f >> an >> pret;
                    smarts->push_back(*(new Smartphone(producator, an, pret)));
                }

            }

        }
        else
            throw 44;
    }
    catch (int x)
    {
        cout << "[ ! ] CEREREA NU A PUTUT FI PROCESATA!";
        cout << "COD :" << x;
    }
}
void introducereArticol(list<Tableta>* tablete, list<Smartphone>* smarts)
{
    int ans1, ans2;
    cout << "\n1.Citire fisier\n2.Citire tastatura\nIntroduceti optiunea dumneavoastra: " << endl;
    cin >> ans1;
    if (ans1 == 1)
        citireFisier(tablete, smarts);
    else {
        cout << "\n1.Tableta\n2.Smarthphone\nIntroduceti optiunea dumneavoastra ";
        cin >> ans2;
        if (ans2 == 1)
            introducereTableta(tablete);
        else if (ans2 == 2)
            introducereSmartphone(smarts);
        else
            cout << "[ ! ] CEREREA NU A PUTU FI PROCESATA\n";
    }
}
void afisareTablete(list<Tableta>* tablete)
{
    cout << "[ + ] STOC TABLETE\n";
    for (auto& t : *tablete)
    {
        cout << t;
    }

}

void afisareSmarts(list<Smartphone>* smarts)
{
    cout << "[ + ] STOC SMARTPHONE\n";
    for (auto& s : *smarts)
    {
        cout << s;
    }
}

void afisareArticole(list<Tableta>* tablete, list<Smartphone>* smarts)
{
    cout << "[ + ] STOC MAGAZIN\n";
    afisareTablete(tablete);
    afisareSmarts(smarts);

}
void afisareProducatorTab(list<Tableta>* tablete)
{
    string prod;
    cout << "\nIntroduceti producatorul: ";
    getchar();
    getline(cin, prod);
    for (auto& t : *tablete)
    {
        if (t.getProd() == prod)
            cout << t;
    }
}
void afisareProducatorSmart(list<Smartphone>* smarts)
{
    string prod;
    cout << "\nIntroduceti producatorul: ";
    getchar();
    getline(cin, prod);
    for (auto& s : *smarts)
    {
        if (s.getProd() == prod)
            cout << s;
    }
}
void afisareProducatorToate(list<Tableta>* tablete, list<Smartphone>* smarts)
{
    string prod;
    cout << "Introduceti producatorul: ";
    getchar();
    getline(cin, prod);
    cout << "\n[ + ] AFISARE TABLETE\n";
    for (auto& t : *tablete)
    {
        if (t.getProd() == prod)
            cout << t;
    }
    cout << "\n[ + ] AFISARE SMARTPHONE\n";
    for (auto& s : *smarts)
    {
        if (s.getProd() == prod)
            cout << s;
    }


}
void afisareProducator(list<Tableta>* tablete, list<Smartphone>* smarts)
{
    int ans2;
    cout << "\n1.Tableta\n2.Smarthphone\n3.Toate\nIntroduceti optiunea dumneavoastra ";
    getchar();
    cin >> ans2;
    if (ans2 == 1)
        afisareProducatorTab(tablete);
    else if (ans2 == 2)
        afisareProducatorSmart(smarts);
    else if (ans2 == 3)
        afisareProducatorToate(tablete, smarts);
    else
        cout << "[ ! ] CEREREA NU A PUTUT FI PROCESATA\n";

}
int main() {
    list<Tableta> tablete;
    list<Smartphone> smarts;
    int ans;
    while (1)
    {
        cout << "\n0.Iesire\n1.Citire\n2.Cautare\n3.Afisare\nIntroduceti optiunea dumneavoastra: ";
        cin >> ans;
        switch (ans) {
        case 0:
            exit(0);
            break;
        case 1:
            introducereArticol(&tablete, &smarts);
            break;
        case 2:
            afisareProducator(&tablete, &smarts);
            break;
        case 3:
            afisareArticole(&tablete, &smarts);
            break;
        }
    }
    return 0;
}
