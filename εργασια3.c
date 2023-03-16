#include <stdio.h>
#define SIZE 2


struct student
{
    int am;
    int grades[5];
    char name;
    double average[10];
};

int main()
{
    int i,j,min_el,min_pos,sum,temp;
    struct student pers_arr[SIZE];
    for (i = 0; i<SIZE; i++)
    {
        printf("Give the name and press enter: ");
        scanf("%s", &pers_arr[i].name);
        printf("Give the am and press enter: ");
        scanf("%d", &pers_arr[i].am);
        printf("Give the 5 grades: ");
          for (j = 0; j<5; j++)
          {
            scanf("%d", &pers_arr[i].grades);
            sum = sum + pers_arr[i].grades;
          }
          pers_arr[i].average[i] = sum / 5;
    }
    fflush(stdin);

    for (i = 0; i<SIZE; i++)
    {
        min_pos = i;

        min_el = pers_arr[i].average[i];

        for (j = i + 1; j<10; j++)
        {
            if( pers_arr[j].average[i] < min_el)
            {
                min_el = pers_arr[j].average[i];
                min_pos = j;
            }
            temp = pers_arr[min_pos].average[i];
            pers_arr[min_pos].average[i] = pers_arr[i].average[i];
            pers_arr[i].average[i] = temp;
        }
    }

    printf("|Name  |Average|");
    for (i = 0; i<SIZE; i++)
    {
        printf("|%s  |%f|" ,pers_arr[i].name,pers_arr[i].average[i]);
    }
return 0;
}
