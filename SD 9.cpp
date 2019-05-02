
#include <iostream>
#include<fstream>
#include<string>
using namespace std;
typedef struct seq_file
{
    int id;
    char name[20],desg[20];
    long int sal;
}record;
typedef struct ind_file
{
    int id;
}index;
class file
{
    record data;
    index info;
public:
    void get_data()
    {
        cout<<"Enter id: ";
        cin>>data.id;
        cout<<"Enter name: ";
        cin>>data.name;
        cout<<"Enter designation: ";
        cin>>data.desg;
        cout<<"Enter salary: ";
        cin>>data.sal;
        info.id=data.id;
    }
    void add()
    {
        fstream out1;
        fstream out2;
        out1.open("pos.txt",ios::app);
        out2.open("rec.txt",ios::app);
        get_data();
        out2.write((char*)&data,sizeof(data));
        out1.write((char*)&info,sizeof(info));
        out1.close();
        out2.close();
    }
    void search_rec(int id)
    {
        int pos=0,loc=-1;
        fstream out1;
        fstream out2;
        out1.open("pos.txt");
        out2.open("rec.txt");
        loc=sizeof(info)*pos;
        out2.seekg(loc,ios::beg);
        for(pos=0;out2.read((char*)&info,sizeof(info));pos++)
        {
            loc=sizeof(info)*pos;
            out2.seekg(loc,ios::beg);
            out2.read((char*)&info,sizeof(info));
            if(info.id==id)
            {
                break;
            }
        }
        if(loc==-1)
        {
            cout<<"Record not found\n";
        }
        else
        {
            pos--;
            pos=sizeof(data)*pos;
            out1.seekg(pos,ios::beg);
            out1.read((char*)&data,sizeof(data));
            cout<<"Record found\n";
            cout<<data.id<<"\t"<<data.name<<"\t"<<data.desg<<"\t"<<data.sal<<endl;
        }
        out1.close();
        out2.close();
    }
};
int main()
{
    char r;
    do
    {
        char op;
        file f;
        do
        {
            int c;
            cout<<"\n=======================Menu======================\n";
            cout<<"1] Add record\n2] Search record\n3] Delete record\n";
            cout<<"___________________________________________________\n";
            cout<<"Enter your choice: ";
            cin>>c;
            switch(c)
            {
                case 1: {
                            f.add();
                        }
                        break;
                case 2: {
                            int id;
                            cout<<"Enter id to search: ";
                            cin>>id;
                            f.search_rec(id);
                        }
                        break;
                case 3: {

                        }
                        break;
                case 4: {

                        }
                        break;
                default:cout<<"Error 404.....page not found\n";
            }
            cout<<"Do you wish to continue(y/n): ";
            cin>>op;
        }while(op=='y' || op=='Y');
        cout<<"Test pass(y/n): ";
        cin>>r;
    }while(r=='n' || r=='N');
    cout<<"******************\n";
    cout<<"*   Thank You!   *\n";
    cout<<"******************\n";
    return 0;
}
