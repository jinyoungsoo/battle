// BattleGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int playerHp = 50;
int playerDamage = 20;

int monsterHp = 100;
int monsterDamage = 7;

int count = 0;

void randomSelect();
void battle();
void recoverHp();

void randomSelect()
{
    int random = 100;

    if (random <= 30)
    {
        printf("길에 도착했습니다 \n");
        Sleep(3000);
        count++;

        if (count >= 6)
        {
            printf("6번 길에 도착하여 게임을 종료합니다.\n");
            Sleep(3000);
            exit(0);
        }

    }
    else if (random <= 20)
    {
        printf("강에 도착했습니다 \n");
        Sleep(3000);

    }
    else if (random <= 100)
    {
        printf("산에 도착했습니다 \n");
        Sleep(3000);


        int battleChance = (rand() % 100) + 1;
        if (battleChance <= 40)
        {
            battle();
        }

    }

    printf("다음 지역으로 이동합니다 \n");
    Sleep(3000);
}

void battle()
{
    printf("플레이어와 몬스터가 전투를 시작합니다\n");
    Sleep(3000);
    while (playerHp > 0 && monsterHp > 0)
    {
        monsterHp -= playerDamage;
        printf("플레이어가 몬스터에게 %d의 데미지를 입혔습니다\n", playerDamage);
        Sleep(3000);

        if (monsterHp <= 0)
        {
            printf("몬스터를 처치했습니다\n");
            Sleep(3000);
            break;
        }

        playerHp -= monsterDamage;
        printf("몬스터가 플레이어에게 %d의 데미지를 입혔습니다\n", monsterDamage);
        Sleep(3000);

        if (playerHp <= 0)
        {
            printf("플레이어가 사망했습니다\n");
            Sleep(3000);
            printf("게임을 종료합니다.\n");
            Sleep(3000);
            exit(0);
        }
    }

    printf("플레이어의 남은 HP: %d\n", playerHp);
    Sleep(3000);

    int recoverChance = (rand() % 100) + 1;
    if (recoverChance <= 60)
    {
        recoverHp();
    }
}

void recoverHp()
{
    playerHp = 50;
    printf("60%% 확률로 회복이 발동했습니다. \n플레이어의 HP가 전부 회복되었습니다.\n");
    Sleep(3000);
}

int main()
{
    srand(time(NULL));
    printf("게임 시작 \n");
    Sleep(3000);

    int loopCount = 1;
    while (loopCount <= 100)
    {
        randomSelect();
        loopCount++;
    }
    return 0;
}