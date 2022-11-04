
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


template <typename T>
T GetCorrectNumber(T min, T max)
{
    T x;
    while ((cin >> x).fail() || x<min || x>max)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "Enter number(" << min << "-" << max << "):";
    }
    return x;
}

struct CS
{
    string name;
    double shop;
    double shopr;
    double ef;
    double s;
};

struct Pipe
{
    double lenght;
    double diametr;
    double repair;
};


void DefaultPipe(Pipe& pipe) {
    pipe.lenght = 0;
    pipe.diametr = 0;
    pipe.repair = 0;
}
void DefaultCS(CS& CS) {
    CS.name = "NULL";
    CS.shop = 0;
    CS.shopr = 0;
    CS.ef = 0;
    CS.s = 0;
}


void PrintPipe(const Pipe& s)
{
    cout << "lenght: " << s.lenght;
    cout << "\tdiametr: " << s.diametr;
    cout << "\trepair: " << s.repair << endl;
}
void PrintCS(const CS& c)
{
    cout << "Name: " << c.name;
    cout << "\tShops: " << c.shop;
    cout << "\tRepair shops: " << c.shopr;
    cout << "\tefficiency:" << c.ef;
    cout << "\tstart or stop the shop(0-no, 1-yes):" << c.s << endl;
}



Pipe LoadPipe(ifstream& fin)
{
    Pipe s;

    fin >> s.lenght;
    fin >> s.diametr;
    fin >> s.repair;
    return s;
}
CS LoadCS(ifstream& fin)
{
    string cs_word;
    CS c;
    if (fin.is_open())
    {
        while (fin >> cs_word) {
            if (cs_word == "CS") {
                fin >> c.name;
                fin >> c.shop;
                fin >> c.shopr;
                fin >> c.ef;
                fin >> c.s;
            }
        }
        fin.close();
    }
    return c;

}


void SavePipe(ofstream& fout, const Pipe& s) {
        if (s.lenght == 0) {
            fout << "" << endl;
        }
        else {
            fout << s.lenght << endl
                << s.diametr << endl
                << s.repair << endl;
        }
}

void SaveCS(ofstream& fout, const CS& c) {

        if (c.shop == 0) {
            fout << "" << endl;
        }
        else {
            fout << "CS" << endl
                << c.name << endl
                << c.shop << endl
                << c.shopr << endl
                << c.ef << endl
                << c.s << endl;
        }
}


void EditPipe(Pipe& s)
{
    if (s.repair == 0) {
        s.repair = 1;
    }
    if (s.repair == 1) {
        s.repair = 0;
    }
    else {
        s.repair = GetCorrectNumber(0, 1);
    }
}


void EditCS(CS& c)
{
    if (c.s == 0) {
        c.s = 1;
    }
    if (c.s == 1) {
        c.s = 0;
    }
    else {
        c.s = GetCorrectNumber(0, 1);
    }

}

void PrintMenu()
{
    cout << "1.Input pipe" << endl
        << "2.Input CS" << endl
        << "3.Print" << endl
        << "4.Save to file" << endl
        << "5.Load from file" << endl
        << "6. Edit pipe" << endl
        << "7. Edit CS" << endl
        << "0. Exit" << endl
        << "Choose action:";
}

ostream& operator << (ostream& out, const Pipe& s)
{
    out << "lenght: " << s.lenght
        << "\tdiametr: " << s.diametr
        << "\trepair: " << s.repair << endl;
    return out;
}
istream& operator >> (istream& in, Pipe& s)
{
    cout << "lenght:";
    s.lenght = GetCorrectNumber(2.0, 10000.0);
    cout << "diametr:";
    s.diametr = GetCorrectNumber(2.0, 1000.0);
    cout << "repair: ";
    s.repair = GetCorrectNumber(0, 1);
    return in;
}

ostream& operator << (ostream& out, const CS& c)
{
    out << "Name: " << c.name
        << "\tShops: " << c.shop
        << "\tRepair shops: " << c.shopr
        << "\tefficiency:" << c.ef << endl;
    return out;
}
istream& operator >> (istream& in, CS& c)
{
    cout << "Name: ";
    in >> c.name;
    cout << "Shops: ";
    c.shop = GetCorrectNumber(1.0, 10000.0);
    cout << "Repair shops: ";
    c.shopr = GetCorrectNumber(0.0, 1000.0);
    cout << "efficiency: ";
    c.ef = GetCorrectNumber(10.0, 100.0);
    cout << "start or stop the shop: ";
    c.ef = GetCorrectNumber(0, 1);
    return in;
}

Pipe& SelectPipe(vector<Pipe>& g)
{
    cout << "Enter index: ";
    unsigned int index = GetCorrectNumber<unsigned int>(1u, g.size());
    return g[index-1];
}

CS& SelectCS(vector<CS>& g)
{
    cout << "Enter index ";
    unsigned int index = GetCorrectNumber<unsigned int>(1u, g.size());
    return g[index-1];
}

int main()
{
    vector <Pipe> group;
    vector <CS> groupc;
    //DefaultPipe(st);
    //DefaultCS(cs);
    while (1)
    {
        PrintMenu();

        switch (GetCorrectNumber(0, 7))
        {
        case 1:
        {
            Pipe st;
            cin >> st;
            group.push_back(st);
            break;
        }
        case 2:
        {
            CS cs;
            cin >> cs;
            groupc.push_back(cs);
            break;
            
        }
        case 3:
        {
            /*
            Pipe st;
            CS cs;
            if (st.diametr == 0) {
                cout << "No Pipe" << endl;
            }
            else { cout << SelectPipe(group) << endl; }
            if (cs.shopr == 0) { cout << "No CS" << endl; }
            else { cout << SelectCS(groupc) << endl; }
            break;
            */
            cout << SelectPipe(group) << endl;
            cout << SelectCS(groupc) << endl;
            break;
        }
        case 4:
        {
            ofstream fout;
            fout.open("data.txt", ios::out);
            if (fout.is_open())
            {
                fout << group.size() << endl;
                for (Pipe st : group)
                    SavePipe(fout, st);
                //fout.close();
            }
            
            //fout.open("data.txt", ios::out);
            if (fout.is_open())
            {
                fout << groupc.size() << endl;
                for (CS cs : groupc)
                    SaveCS(fout, cs);
                fout.close();
            }
            
            break;
        }
        case 5:
        {
            ifstream fin;
            fin.open("data.txt", ios::in);
            if (fin.is_open())
            {
                int count;
                fin >> count;
                while (count--)
                    group.push_back(LoadPipe(fin));
                fin.close();
                
            }
            
            fin.open("data.txt", ios::in);
            if (fin.is_open())
            {
                int count;
                fin >> count;
                while (count--)
                    groupc.push_back(LoadCS(fin));
                fin.close();
            }
            break;
        }
        case 6:
        {
            EditPipe(SelectPipe(group));
            break;
        }
        case 7:
        {
            EditCS(SelectCS(groupc));
            break;
        }
        case 0:
        {
            /*
            cout << "Should you save to file objects?Print 1 or 0" << endl;
            if (GetCorrectNumber(0, 1) == 1) {
                Save(st, cs);
                return 0;
            }
            else {
            }
            return 0;
            */
        }
        default:
        {
            cout << "Wrong action" << endl;
        }
        }
    }
    return 0;
}


