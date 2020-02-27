#include <stdio.h>
#include <string.h>

int main(void)
{

    int quit = 0; //判断是否退出，0不退出，1退出
    int choice;   //用户选择
    char goods[5] = {"A", "B", "C", "D", "E"};
    int price[5] = {10, 6, 5, 8, 7}; 
	int stock[5] = {9, 9, 9, 9, 9}; 
	int deposit = 0; //押金
	char *x = "=";

    {
        printf("*---------------------------*\n");
        printf("|     Vending   Machine     |\n");
        printf("*---------------------------*\n");

        //商品
        printf("| ");
        for (int i = 0; i < 5; i++)
        {
            if (i == 0)
            {
                printf("%4c", goods[i]);
            }
            else
            {
                printf("%5c", goods[i]);
            }
        }
        printf("|\n");

        //价格
        printf("|");
        for (int i = 0; i <5 ; i++)
        {
            printf("  $%2d", price[i]);
        }
        printf("  |\n");

        //购买数
        printf("|");
        for (int i = 0; i <= 4; i++)
        {
            printf("  [");
            if (stock[i] <= 0)
                printf("X");
            else if (deposit >= price[i])
                printf("O");
            else
                printf(" ");
            printf("]");
        }
        printf("  |\n");

        printf("*---------------------------*\n");

        //钱
        printf("|                    [$%2d]  |\n", deposit);

        printf("|                           |\n");
        printf("|           [=%s=]           |\n", x);
        printf("*---------------------------*\n\n");
        return 0;
    }
    while (quit == 0)
    {
        x = "=";