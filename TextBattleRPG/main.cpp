#define NOMINMAX
#include <windows.h>
#include "Character.h"
#include "Goblin.h"
#include "Orc.h"
#include "Dragon.h"
#include <iostream>
#include <random>
#include <limits>
#include <memory>


using namespace std;


int main()
{
	SetConsoleOutputCP(CP_UTF8);



#pragma region 랜덤퍼센트

	mt19937 gen(random_device{}());
	uniform_int_distribution<int> spawn(0, 2);
	uniform_int_distribution<int> roll(0, 9);

#pragma endregion

#pragma region 몬스터 스폰
	unique_ptr<Character> enemy;

	switch (spawn(gen))
	{
	case 0:
		enemy = make_unique<Goblin>("고블린", 50, 10, false, 5, 0.5f);
		break;
	case 1:
		enemy = make_unique<Orc>("오크", 150, 5, false, 7, 0.7f);
		break;
	case 2:
		enemy = make_unique<Dragon>("드래곤", 100, 13, false, 5, 0.5f);
		break;

	default:
		cout << "잘못된 난수 발생" << endl;
		break;
	}

#pragma endregion

#pragma region 메인 시스템

	Character player("용사", 100, 18, false);
	int chooseNum;


	while (!player.IsDead() && !enemy->IsDead())
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
			cout << "잘못된 키를 입력하셨습니다!" << endl;
			continue;
		}


		enemy->DecideShield(roll(gen));



		player.Attack(*enemy);
		enemy->DecideAction(roll(gen), player);


		cout << player.GetName() << ", 체력 : " << player.GetHealth() << ", 공격력 : " << player.GetAttackDamage() << endl;
		cout << enemy->GetName() << ", 체력 : " << enemy->GetHealth() << ", 공격력 : " << enemy->GetAttackDamage() << endl;






	}

	if (player.IsDead())
	{
		cout << player.GetName() << "가 죽었습니다...";

	}
	else if (enemy->IsDead())
	{
		cout << enemy->GetName() << "을 무찔렀습니다!";

	}

#pragma endregion

	return 0;

}
