#include<stdio.h>
#include<stdlib.h>
#include"lab52.h"

int main(void)
{
	int command,choice=0;
	GoodsList l;
	GoodsInfo item;
	char goods_id;
	init_list(&l);
	
	printf("Please enter a number to start:\n");
	printf("Command\tOperation\t\n");
	printf("0\tAll information\t\n");
	printf("1\tInsert\t\n");
	printf("2\tChange\t\n");
	printf("3\tDelet\t\n");
	printf("4\tSearch\t\n");
	printf("5\tSort\t\n");
	printf("6\tExit\n");
	
	scanf("%d",&command);
	
	while(1)
	{
		switch(command)
		{
			case 0:output_all_items(&l);
			break;
			case 1:
			{
				insert_item(&l,item,choice);
			}
			break;
			case 2:change_item(&l,goods_id,item);
			break;
			case 3:delete_item(&l,goods_id);
			break;
			case 4:search_item(&l,goods_id);
			break;
			case 5:bubble_sort(&l);
			break;
			case 6:destroy_list(&l);
			return 0;
			default:break; 
		}
	}
	
	return 0;
}
