//This is 校园生活 v0.2beta.This version does not support English,and the 睡觉 part was not complete.
//No part of this game shoud be copyed to post out
//xiaochentimmy 2026/7/19/18:02
//For WINDOWS
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <time.h>
#include <windows.h>
using namespace std;
long long in, enegry = 100, brain, magic, r, coin = 5;
void have_class ()
{
    cout << "InDev_WarningUnstable\n";
    srand(time(0));
    r = rand() % 5;
    if (r == 0)
    {
        cout << "没有课上\n按任意键继续...";
        cin >> in;
        return;
    }
    enegry -= 5;
    if (r == 1)
    {
        cout << "语文课，获得智力值10点，消耗体力5点\n按任意键继续...";
        brain += 10;
        cin >> in;
        return;
    }
    else if (r == 2)
    {
        cout << "数学课，获得智力值10点，消耗体力5点\n按任意键继续...";
        brain += 10;
        cin >> in;
        return;
    }
    else if (r == 3)
    {
        cout << "英语课，获得智力值5点，消耗体力5点\n按任意键继续...";
        brain += 5;
        cin >> in;
        return;
    }
    else if (r == 4)
    {
        cout << "科学课，获得魔力值1点，消耗体力5点\n按任意键继续...";
        magic++;
        cin >> in;
        return;
    }
}
void eat ()
{
    coin -= 5;
    enegry += 10;
    cout << "吃了一顿饭\n按任意键继续...";
    cin >> in;
    return;
}
void check ()
{
    if (enegry > 100) enegry = 100;
    return;
}
void menu ()
{
    cout << "InDev_WarningUnstable\n";
    printf("体力%lld 智力%lld 魔力%lld 金币%lld\n", enegry, brain, magic, coin);
    cout << "1.上课（消耗5点体力）\n2.吃饭（补充10点体力，消耗5金币）\n3.睡觉（回满体力）\n";
    cin >> in;
    if (in == 4) return;
    if (in == 1)
    {
        if (enegry < 5)
        {
            cout << "体力不足，无法上课\n按任意键继续...";
            cin >> in;
            return;
        }
        have_class();
    }
    else if (in == 2)
    {
        if (coin < 5)
        {
            cout << "你没钱了，吃不了饭\n按任意键继续...";
            cin >> in;
            return;
        }
        eat();
        check();
    }
	system("cls");
    return;
}
int main ()
{
    cout << "更多游戏，前往GitHub搜索xiaochentimmy\n按任意键继续...";
    cin >> in;
    system("cls");
    cout << "InDev_WarningUnstable\n校园生活\n1.进入游戏\n2.退出\n";
    cin >> in;
    system("cls");
    if (in == 2) return 0;
    while (1)
    {
        menu();
    }
    return 0;
}
