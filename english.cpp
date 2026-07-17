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
        cout << "No classes today\nPress any key to continue...";
        cin >> in;
        return;
    }
    enegry -= 5;
    if (r == 1)
    {
        cout << "Chinese Class，gain 10 Intelligence，consume 5 Energy\nPress any key to continue...";
        brain += 10;
        cin >> in;
        return;
    }
    else if (r == 2)
    {
        cout << "Math Class，gain 10 Intelligence，consume 5 Energy\nPress any key to continue...";
        brain += 10;
        cin >> in;
        return;
    }
    else if (r == 3)
    {
        cout << "English class，gain 5 Intelligence，consums 5 Energy\nPress any key to continue...";
        brain += 5;
        cin >> in;
        return;
    }
    else if (r == 4)
    {
        cout << "Science Class，gain 1 Magic Point，consume 5 Energy\nPress any key to continue...";
        magic++;
        cin >> in;
        return;
    }
}
void eat ()
{
    coin -= 5;
    enegry += 10;
    cout << "You finished a meal\nPress any key to continue...";
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
	cout << "You are sleeping...\nPress any key to continue...\n";
	cin >> in;
	srand(time(0));
	r = rand() % 3;
	if (r == 0)
	{
		cout << "A quiet night with nothing happening\nPress any key to continue...\n";
		cin >> in;
		enegry = 100;
		return;
	}
	cout << "Someone knocks at your door\nWill you answer？\n1.Answer2.Ignore";
	cin >> in;
	if (r == 1)
	{
		if (in == 1) cout << "Opened the door...";
		cout << "Dorm Manager says：“Sleep well！”\nPress any key to continue...";
		cin >> in;
		enegry = 100;
		return; 
	}
	else if (r == 2)
	{
		if (in == 2)
		{
			cout << "No one came inside\nPress any key to continue...";
			cin >> in;
			enegry = 100;
			return;
		}
		else
		{
			cout << "You opened the door... Uh-oh，a Demon appeared！\nPress any key to continue...\n";
			cin >> in;
			system("cls");
			cout << "Loading...";
			srand(time(0));
		    r = rand() % 5 + 10;
		    Sleep(r * 1000);
		    cout << "Battle Start！\n";
		    srand(time(0));
		    r = rand() % 500 + 100;
		    long long my_blood = 100, monster_blood = r, kill, orkill;
			srand(time(0));
			kill = rand() % 10 + 10;
		    while (1)
		    {
		    	printf("Your HP：%lld Intelligence：%lld Magic：%lld\n", my_blood, brain, magic);
		    	printf("Demon HP：%lld Demon Attack：%lld\n", monster_blood, kill);
		    	orkill = brain % 101;
		    	cout << "Choose your action：\n1.Normal Attack（Damage：" << orkill << "）\n";
		    	cout << "2.Magic Strike（Cost 1 Magic, Damage：" << orkill + 50 << "）\n";
		    	cout << "3.Dodge（Evade next demon attack; reflect damage if you have Magic left）\n";
		    	cin >> in;
		    	if (in == 1)
		    	{
		    		monster_blood -= orkill;
		    		cout << "\nAttack landed\n";
				}
				else if (in == 2)
				{
					if (magic == 0) cout << "Not enough Magic, your attack failed\n";
					else
					{
						monster_blood -= orkill + 50;
						magic--;
						cout << "\nMagic attack landed\n";
					}
				}
				else if (in == 3) cout << "\nYou prepare to dodge\n";
				if (monster_blood <= 0)
				{
					cout << "Victory！You gain 10 Coins\\nPress any key to continue...";
					coin += 10;
					cin >> in;
					break; 
				}
				cout << "The demon strikes you...";
				srand(time(0));
				r = rand() % 10;
				if (in == 3 || r == 4)
				{
					cout << "You dodged the hit！";
					if (magic > 0)
					{
						cout << "You reflected damage back to the demon";
						monster_blood -= kill;
					}
				}
				else
				{
					my_blood -= kill;
					cout << "You took damage！";
				}
				cout << "\nPress any key to continue...";
				cin >> in;
				if (my_blood <= 0)
				{
					cout << "You died！";
					exit(0);
				}
				if (monster_blood <= 0)
				{
					cout << "Victory! You gain 10 Coins\nPress any key to continue...";
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
    printf("Energy：%lld Intelligence：%lld Magic：%lld Coins：%lld\n", enegry, brain, magic, coin);
    cout << "1.Attend class（Consumes 5 Energy）\n2.Eat meal（Restore 10 Energy, Costs 5 Coins）\n3.Sleep（Full Energy Restor）\n";
    cin >> in;
    if (in == 4) return;
    if (in == 1)
    {
        if (enegry < 5)
        {
            cout << "Insufficient Energy, cannot attend class\nPress any key to continue...";
            cin >> in;
            return;
        }
        have_class();
    }
    else if (in == 2)
    {
        if (coin < 5)
        {
            cout << "You don't have enough coins to eat\nPress any key to continue...";
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
    cout << "Find more games by searching xiaochentimmy on github\nPress any key to continue...";
    cin >> in;
    system("cls");
    cout << "InDev_WarningUnstable\nCampus life\n1.Start game\n2.Exit\n";
    cin >> in;
    system("cls");
    if (in == 2) return 0;
    cout << "Loading...";
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
