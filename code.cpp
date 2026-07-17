//This is Campus Life v0.3.2.1beta.This version doesn't have English translation.
//No part of this game shoud be copyed to post out
//xiaochentimmy 2026/7/17/15:34
//For WINDOWS
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <time.h>
#include <windows.h>
using namespace std;
long long in, enegry = 100, brain, magic, r, coin = 5, tr;
double happy;
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
    happy -= 0.1;
    if (r == 1)
    {
        cout << "语文课，获得智力值10点，消耗体力5点\n按任意键继续...";
        brain += 10;
        tr = happy / 0.1;
        tr %= 2;
        brain += tr;
        cin >> in;
        return;
    }
    else if (r == 2)
    {
        cout << "数学课，获得智力值10点，消耗体力5点\n按任意键继续...";
        brain += 10;
        tr = happy / 0.1;
        tr %= 2;
        brain += tr;
        cin >> in;
        return;
    }
    else if (r == 3)
    {
        cout << "英语课，获得智力值5点，消耗体力5点\n按任意键继续...";
        brain += 5;
        tr = happy / 0.1;
        tr %= 2;
        brain += tr;
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
void sleep_time ()
{
	system("cls");
	cout << "正在睡觉...\n按任意键继续...\n";
	cin >> in;
	srand(time(0));
	r = rand() % 3;
	if (r == 0)
	{
		cout << "一晚无事\n按任意键继续...\n";
		cin >> in;
		enegry = 100;
		return;
	}
	cout << "有人敲门\n是否回答？\n1.回答2.不回答";
	cin >> in;
	if (r == 1)
	{
		if (in == 1) cout << "打开了房门...";
		cout << "宿管来了：“好好睡觉吧！”\n按任意键继续...";
		cin >> in;
		enegry = 100;
		return; 
	}
	else if (r == 2)
	{
		if (in == 2)
		{
			cout << "没有人进来\n按任意键继续...";
			cin >> in;
			enegry = 100;
			return;
		}
		else
		{
			cout << "打开了房门...糟了，魔鬼来了！\n按任意键继续...\n";
			cin >> in;
			system("cls");
			cout << "加载中...";
			srand(time(0));
		    r = rand() % 5 + 10;
		    Sleep(r * 1000);
		    cout << "交战时间到！\n";
		    long long my_blood = 100, monster_blood = 0, kill, orkill;
			srand(time(0));
			kill = rand() % 30 + 10;
			tr = happy / 0.1;
			my_blood += tr * 10;
			srand(time(0));
		    r = rand() % 500 + my_blood;
		    monster_blood = r;
		    while (1)
		    {
		    	printf("己方血量：%lld 智力值：%lld 魔法值：%lld\n", my_blood, brain, magic);
		    	printf("对方血量：%lld 对方伤害：%lld\n", monster_blood, kill);
		    	orkill = brain % 101 + 20;
		    	cout << "选择动作：\n1.普通攻击（伤害为" << orkill << "）\n";
		    	cout << "2.魔法攻击（消耗1点魔法值，伤害为" << orkill + 50 << "）\n";
		    	cout << "3.闪避（躲避下一个来自魔鬼的攻击, 有50%给予魔鬼一次普通攻击）\n";
		    	cin >> in;
		    	if (in == 1)
		    	{
		    		monster_blood -= orkill;
		    		cout << "\n攻击完成\n";
				}
				else if (in == 2)
				{
					if (magic == 0) cout << "无法执行此攻击，已视为放弃攻击\n";
					else
					{
						monster_blood -= orkill + 50;
						magic--;
						cout << "\n攻击完成\n";
					}
				}
				else if (in == 3) cout << "\n准备躲避\n";
				if (monster_blood <= 0)
				{
					cout << "你获胜了！你获得了10金币\n按任意键继续...";
					coin += 10;
					happy += 0.05;
					cin >> in;
					break; 
				}
				cout << "魔鬼攻击了你...";
				srand(time(0));
				r = rand() % 10;
				if (in == 3 || r == 4)
				{
					cout << "你躲避了攻击！";
					srand(time(0));
					r = rand() % 10;
					if (r == 3 || r == 0 || r == 5 || r == 7 || r == 6)
					{
						cout << "你攻击了对方！\n";
						monster_blood -= orkill;
					}
				}
				else
				{
					my_blood -= kill;
					cout << "你受到了攻击！";
				}
				cout << "\n按任意键继续...";
				cin >> in;
				if (my_blood <= 0)
				{
					cout << "你死了！";
					exit(0);
				}
				if (monster_blood <= 0)
				{
					cout << "你获胜了！你获得了10金币\n按任意键继续...";
					coin += 10;
					happy += 0.05;
					cin >> in;
					break; 
				}
				system("cls");
			}
		}
	}
	return;
}
void sell ()
{
	system("cls");
	cout << "小卖部\n1.*乐：3金币\n2.*碧：4金币\n3.芬*：5金币\n4.佳得*：10金币（回10点能量）\n";
	cin >> in;
	if (in == 1)
	{
		if (coin < 3)
		{
			cout << "不够钱\n按任意键继续...";
			cin >> in;
			return;
		}
		happy += 0.15;
		coin -= 3;
		cout << "喝了一瓶*乐\n按任意键继续...";
		cin  >> in;
		return;
	}
	else if (in == 2)
	{
		if (coin < 4)
		{
			cout << "不够钱\n按任意键继续...";
			cin >> in;
			return;
		}
		happy += 0.2;
		coin -= 4;
		cout << "喝了一瓶*n碧\n按任意键继续...";
		cin  >> in;
		return;
	}
	else if (in == 3)
	{
		if (coin < 5)
		{
			cout << "不够钱\n按任意键继续...";
			cin >> in;
			return;
		}
		coin -= 5;
		happy += 0.35;
		cout << "喝了一瓶芬*\n按任意键继续...";
		cin  >> in;
		return;
	}
	else if (in == 4)
	{
		if (coin < 10)
		{
			cout << "不够钱\n按任意键继续...";
			cin >> in;
			return;
		}
		coin -= 10;
		happy += 0.2;
		enegry += 10;
		check();
		cout << "喝了一瓶佳得*\n按任意键继续...";
		cin >> in;
		return;
	}
}
void menu ()
{
    cout << "InDev_WarningUnstable\n";
    printf("体力%lld 智力%lld 魔力%lld 金币%lld\n", enegry, brain, magic, coin);
    cout << "1.上课（消耗5点体力）\n2.吃饭（补充10点体力，消耗5金币）\n3.睡觉（回满体力）\n4.小卖部\n";
    cin >> in;
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
    else if (in == 3) sleep_time();
    else if (in == 4) sell();
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
    cout << "加载中...";
    srand(time(0));
    r = rand() % 20 + 10;
    Sleep(r * 1000);
    system("cls");
    while (1)
    {
        menu();
    }
    return 0;
}
