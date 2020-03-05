#include <stdio.h>
#include <string.h>

char goods[5][2] = {"A", "B", "C", "D", "E"};
int price[5] = {10, 6, 5, 8, 7};
int stock[5] = {5, 1, 2, 1, 9};
int deposit = 0; //押金
char *x = "=";
int choice;
int code = 1110; //密码
int revenue = 0; //收入
char goodsname[][20] = {"Juice", "Cola", "Tea", "Water", "Coffee"};


int showcase() //贩卖机展示
{
    printf("*---------------------------*\n");
    printf("|     Vending   Machine     |\n");
    printf("*---------------------------*\n");

    //商品
    printf("| ");
    for (int i = 0; i < 5; i++)
    {
        printf(" %s   ", goods[i]);
    }
    printf("|\n");

    //价格
    printf("|");
    for (int i = 0; i < 5; i++)
    {
        printf("  $%2d", price[i]);
    }
    printf("  |\n");

    //购买数
    printf("|");
    for (int i = 0; i < 5; i++)
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
    printf("*---------------------------*\n");
    return 0;
}

int mainmenu()
{
    printf("What would you like to do?\n");
    printf(" 1. Read product information\n");
    printf(" 2. Insert coin\n");
    printf(" 3. Press product button\n");
    printf(" 4. Press return button\n");
    printf(" 9. Open service menu (code required)\n");
    printf(" 0. Quit\n");
    printf("you choice:");
    return 0;
}

int choice1(void)
{
    printf("\n");
    printf("(1) The displayed products are:\n");
    printf("A. Juice (¥10)\n");
    printf("B. Cola (¥6)\n");
    printf("C. Tea (¥5)\n");
    printf("D. Water (¥8)\n");
    printf("E. Coffee (¥7)\n");
    printf("\n");
    return 0;
}

int menu2(void)
{
    printf("(2) Which coin would you like to insert?\n");
    printf("1. $1\n");
    printf("2. $2\n");
    printf("3. $5\n");
    printf("4. $10\n");
    printf("0. Go back\n");
    printf("\n");
    printf("Your choice:");
    return 0;
}

int choice2(void)
{
    int quit2 = 0;
    printf("\n");
    while (quit2 == 0)
    {
        menu2();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            deposit += 1;
            printf("You have inserted $1.\n\n");
            break;
        case 2:
            deposit += 2;
            printf("You have inserted $2.\n\n");
            break;
        case 3:
            deposit += 5;
            printf("You have inserted $5.\n\n");
            break;
        case 4:
            deposit += 10;
            printf("You have inserted $10.\n\n");
            break;
        case 0:
            quit2 = 1;
            printf("Going back!\n\n");
            break;
        default:
            printf("Invalid choice!\n\n");
            break;
        }
        if (deposit > 99)
        {
            deposit = 99;
        }
        showcase();
    }
    return 0;
}

int menu3(void)
{
    printf("(3) Which product button would you like to press?\n");
    printf("1. A\n");
    printf("2. B\n");
    printf("3. C\n");
    printf("4. D\n");
    printf("5. E\n");
    printf("0. Go back\n");
    printf("\n");
    printf("Your choice:");
    return 0;
}

int choice3(void)
{
    int quit3 = 0;
    while (quit3 == 0)
    {
        menu3();
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 5)
        {
            printf("You have pressed button %s.\n", goods[choice - 1]);
            if (stock[choice - 1] > 0 && deposit >= price[choice - 1])
            {
                stock[choice - 1] -= 1;
                deposit = deposit - price[choice - 1];
                revenue = revenue + price[choice - 1];
                x = goods[choice - 1];
                printf("\n");
                showcase();
                quit3 = 1;
            }
            else
            {
                printf("Invalid choice!\n");
                showcase();
            }
        }
        else if (choice == 0)
        {
            printf("Going back!\n\n");
            quit3 = 1;
        }
        else
        {
            printf("Invalid choice!\n\n");
        }
    }
    return 0;
}

int choice4(void)
{
    printf("(4) Return button is pressed.\n $%d has been returned.", deposit);
    deposit = 0;
    printf("\n");
    showcase();
    return 0;
}

int menu9(void)
{
    printf("(9) What would you like to do?\n");
    printf("1. Inspect machine status\n");
    printf("2. Withdraw all money\n");
    printf("3. Refill product\n");
    printf("4. Change product\n");
    printf("0. Go back\n\n");
    printf("Your choice:\n");
    return 0;
}

int choice911(void)
{
    if (stock[choice - 1] > 0)
    {
        printf("(%d left)\n", stock[choice - 1]);
    }
    else
    {
        printf("sold out\n");
    }
    return 0;
}

int choice91(void)
{
    printf("(9-1) Machine status\n");
    printf("Amount of revenue: $%d\n", revenue);
    printf("Amount of inserted coins: $%d\n", deposit);
    printf("A. Juice ($10)");
    choice911();
    printf("B. Cola ($6)");
    choice911();
    printf("C. Tea ($5) ");
    choice911();
    printf("D. Water ($8) ");
    choice911();
    printf("E. Coffee ($7) ");
    choice911();
    return 0;
}

int choice92(void)
{
    printf("(9-2) All money is being withdrawn.\n");
    printf("$%d is withdrawn.\n\n", deposit + revenue);
    deposit = 0;
    revenue = 0;
    return 0;
}

int menu93(void)
{
    printf("(9-3) Which product would you like to refill?\n");
    printf("1.A\n");
    printf("2.B\n");
    printf("3.C\n");
    printf("4.D\n");
    printf("5.E\n");
    printf("0.Go back\n\n");
    printf("Your choice:");
    return 0;
}

int choice93(void)
{
    int quit93=0;
    while(quit93==0)
    {
    menu93();
    scanf("%d",&choice);
    if(choice>0&&choice<6)
    {
        stock[choice-1]=10;
        printf("You have refilled product %s to full.\n\n", goods[choice - 1]);
        quit93=1;
    }
    else if(choice ==0)
    {
        printf("Going back!\n\n");
        quit93=1;
    }
    }
    return 0;
}

int menu94(void)
{
    printf("(4-4) Which product would you like to change?\n");
    printf("1.A\n");
    printf("2.B\n");
    printf("3.C\n");
    printf("4.D\n");
    printf("5.E\n");
    printf("0.Go back\n\n");
    printf("Your choice:");
    return 0;
}

int choice94(void)
{
    int quit94=0;
    while (quit94==0)
    {
        menu94();
        scanf("%d",&choice);
        if(choice>0&&choice<6)
        {
            printf("You are changing product %s.\n",goods[choice-1]);
			printf("Enter new product name: ");
            scanf("%s", goodsname[choice - 1]);
            printf("Enter new product price: ");
			scanf("%d", &price[choice - 1]);
            stock[choice -1]=10;
            printf("The new product %s has been filled to full.\n\n", goods[choice - 1]);
            quit94=1;
        }
        else if(choice == 0)
        {
            printf("Going back!\n\n");
			quit94 = 1;
        }
    }
    return 0;
}

int choice9(void)
{
    int input;
    int quit9 = 0;
    printf("(9) Opening service menu. Access code is required.\n");
    printf("Enter access code:");
    scanf("%d", &input);
    if (input == code)
    {
        printf("Correct code!\n\n");
        while (quit9 == 0)
        {
            menu9();
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                choice91();
                break;
            case 2:
                choice92();
                break;
            case 3:choice93();
            break;
            case 4:choice94();
            break;
			case 0: printf("Going back!\n\n"); quit9 = 1; break;
            default: printf("Invalid choice!\n\n"); break;
            }
        }
    }
    else
    {
		printf("Incorrect code!\n\n");
		showcase();
    }
    return 0;
}
int main(void)
{
    int quit = 0; //判断函数执行
    showcase();
    printf("\n");
    while (quit == 0)
    {
        x = "=";
        mainmenu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            choice1();
            break;
        case 2:
            choice2();
            break;
        case 3:
            choice3();
            break;
        case 4:
            choice4();
            break;
        case 9:
            choice9();
            break;
        case 0: quit = 1; printf("\n\nProcess finished with exit code 0\n"); break;
		default: printf("Invalid choice!\n\n"); break;
        }
    }
    return 0;
}
