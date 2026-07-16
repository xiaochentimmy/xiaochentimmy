//This is Campus Life v0.3.2beta.I add the English translate.If you found any grammer error(my grammer is bad),please tell me.
//No part of this game shoud be copyed to post out
//xiaochentimmy 2026/7/17/07:43
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
		    srand(time(0));
		    r = rand() % 500 + 100;
		    long long my_blood = 100, monster_blood = r, kill, orkill;
			srand(time(0));
			kill = rand() % 10 + 10;
		    while (1)
		    {
		    	printf("己方血量：%lld 智力值：%lld 魔法值：%lld\n", my_blood, brain, magic);
		    	printf("对方血量：%lld 对方伤害：%lld\n", monster_blood, kill);
		    	orkill = brain % 101;
		    	cout << "选择动作：\n1.普通攻击（伤害为" << orkill << "）\n";
		    	cout << "2.魔法攻击（消耗1点魔法值，伤害为" << orkill + 50 << "）\n";
		    	cout << "3.闪避（躲避下一个来自魔鬼的攻击, 如果还有魔法值，则能反弹伤害）\n";
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
					cin >> in;
					break; 
				}
				cout << "魔鬼攻击了你...";
				srand(time(0));
				r = rand() % 10;
				if (in == 3 || r == 4)
				{
					cout << "你躲避了攻击！";
					if (magic > 0)
					{
						cout << "你反弹了伤害";
						monster_blood -= kill;
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
					cin >> in;
					break; 
				}
				system("cls");
			}
		}
	}
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
    else if (in == 3) sleep_time();
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
