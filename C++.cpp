#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;

class car_bass
{
protected:
    string number;
    string type;
};

class Contact : public car_bass
{
protected:

    string color;

    string time;
public:
    void add();//增加数据
    void view();//浏览数据
    string getnumber();
    string gettime();
};
void Contact::add()
{
    cout << "请输入车牌号:";
    cin >> number;
    cout << endl << "请输入颜色:";
    cin >> color;
    cout << endl << "请输入车型:";
    cin >> type;
    cout << endl << "请输入到达和离开的时间:";
    cin >> time;
}
void Contact::view()
{
    //cout<<"  车牌号   颜色   车型        到达和离开的时间"<<endl;
    cout << setw(6) << number << setw(6) << color << setw(6) << type << setw(20) << time << endl;
}

string Contact::getnumber()
{
    return number;
}

string Contact::gettime()
{
    return time;
}
class manage
{
private:
    static int num;
public:
    Contact a[45];
    void add();
    void view();
    void alter();
    void select();//查找数据
    void save();

};

int manage::num = 0;

void manage::add()
{
    a[num].add();
    cout << endl << "添加成功！" << endl;
    system("pause");
    num++;
}

void manage::view()
{
    int i;
    cout << "  车牌号   颜色   车型        到达和离开的时间" << endl;
    for (i = 0; i<num; i++)
        a[i].view();

    system("pause");
}
void manage::alter()
{
    int m, i;
    string linshi;
e:
    cout << "1.按车牌号修改" << endl;
    cout << "2.按车型" << endl;
    cout << "请选择:" << endl;
    cin >> m;
    if (m != 1 && m != 2)
    {
        cout << "输入错误！" << endl;
        system("pause");
        system("cls");
        goto e;
    }
    cout << "请输入新的信息:" << endl;
    switch (m)
    {
    case 1:
        cout << "请输入车牌号:";
        cin >> linshi;
        for (i = 0; i<num; i++)
        {
            if (a[i].getnumber() == linshi)
            {
                a[i].add();
                break;
            }
        }
        break;
    case 2:
        cout << "请输入车型:";
        cin >> linshi;
        for (i = 0; i<num; i++)
        {
            if (a[i].gettime() == linshi)
            {
                a[i].add();
                break;
            }
        }
        break;
    }
    system("pause");
}
void manage::select()
{
    int m, i;
    string linshi;
e:
    cout << "1.按车牌号查找" << endl;
    cout << "2.按车型查找" << endl;
    cout << "请选择:" << endl;
    cin >> m;
    if (m != 1 && m != 2)
    {
        cout << "输入错误！" << endl;
        system("pause");
        system("cls");
        goto e;
    }
    switch (m)
    {
    case 1:
        cout << "请输入车牌号:";
        cin >> linshi;
        for (i = 0; i<num; i++)
        {
            if (a[i].getnumber() == linshi)
            {
                cout << "  车牌号   颜色   车型        到达和离开的时间" << endl;
                a[i].view();
                break;
            }
        }
        break;
    case 2:
        cout << "请输入车型:";
        cin >> linshi;
        for (i = 0; i<num; i++)
        {
            if (a[i].gettime() == linshi)
            {
                cout << "  车牌号   颜色   车型        到达和离开的时间" << endl;
                a[i].view();
                break;
            }
        }
        break;
    }
    system("pause");
}



int main()
{
    int m, t = 1;
    manage n;
    while (t)
    {
        system("cls");
        cout << endl;
        cout << endl << endl;
        cout << "            ***********************************************" << endl << endl;
        cout << "                         **停车场管理系统 **        " << endl;
        cout << endl;
        cout << "                           * 1.添加车辆           " << endl << endl;
        cout << "                           * 2.浏览车辆           " << endl << endl;
        cout << "                           * 3.修改车辆           " << endl << endl;
        cout << "                           * 4.查找车辆           " << endl << endl;
        cout << "                           * 5.退出                 " << endl << endl;
        cout << "                                  " << endl << endl;
        cout << "请选择:" << endl;
        cin >> m;
        system("cls");
        switch (m)
        {
        case 1:
            n.add();
            break;
        case 2:
            n.view();
            break;
        case 3:
            n.alter();
            break;
        case 4:
            n.select();
            break;
        case 5:
            t = 0;
            cout << endl << endl << endl << endl << endl << endl << "                        **谢谢您的使用！**";
            break;


        }
    }

}
