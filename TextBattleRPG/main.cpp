#define NOMINMAX
#include <windows.h>
#include "Character.h"
#include <iostream>
#include <random>
#include <limits>

using namespace std;


int main()
{
	SetConsoleOutputCP(CP_UTF8);

	Character player("용사", 100, 18, false);
	Character monster("마왕", 200, 11, false);
	

	int chooseNum;

	mt19937 gen(random_device{}());              // 실행할 때마다 다른 시드
	uniform_int_distribution<int> coin(0, 1);    // 0 또는 1


	while (!player.IsDead() && !monster.IsDead())
	{
		
			cout << "공격 하시겠습니까? 방어 하시겠습니까? (공격: 1, 방어: 2)" << endl;
			cin >> chooseNum;


			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			if (chooseNum == 1)
			{
				player.SetShield(false);

			}
			else if (chooseNum == 2)
			{
				player.SetShield(true);
			}
			else
			{
				cout << "잘못된 키를 입력하셨습니다!";
				continue;
			}
			


			if (coin(gen) == 0)
			{
				monster.SetShield(false);
			}
			else
			{
				monster.SetShield(true);
			}



			player.Attack(monster);
			monster.Attack(player);

			cout << player.GetName() << ", 체력 : " << player.GetHealth() << ", 공격력 : " << player.GetAttackDamage() << endl;
			cout << monster.GetName() << ", 체력 : " << monster.GetHealth() << ", 공격력 : " << monster.GetAttackDamage() << endl;

		




	}

	if (player.IsDead())
	{
		cout << player.GetName() << "가 죽었습니다...";
		
	}
	else if (monster.IsDead())
	{
		cout << monster.GetName() << "을 무찔렀습니다!";
		
	}



	return 0;

}
