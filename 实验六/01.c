#include "lab52.h" // 请不要删除本行头文件，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    GoodsList* goodsList;
    init_list(&goodsList);
    GoodsInfo item;
    char temp_id[MAX_ID_LEN];
    while (1) {
        int choice;
        printf("超市商品管理系统\n");
        printf("********************************************\n");
        printf("1.显示所有商品的信息:\n");
        printf("2.修改某个商品的信息:\n");
        printf("3.插入某个商品的信息:\n");
        printf("4.删除某个商品的信息:\n");
        printf("5.查找某个商品的信息:\n");
        printf("6.商品存盘并退出系统:\n");
        printf("7.对商品价格进行排序:\n");
        printf("8.(慎用)删除所有内容:\n");
        printf("其他.不存盘并退出系统:\n");
        printf("********************************************\n");
        printf("输入您的选择: ");

        scanf("%d", &choice);
        switch (choice) {
        case 1:
            output_all_items(goodsList);
            break;
        case 2:
            item = read_goods_info();
            printf("输入要修改记录的 ID：");
            read_line(temp_id, MAX_ID_LEN);
            change_item(goodsList, temp_id, item);
            break;
        case 3:
            item = read_goods_info();
            int pos;
            printf("输入数字表明你要插入的商品位置：0.商品列表尾部 1.商品列表头部 i.商品列表中间第i号位置\n");
            scanf("%d", &pos);
            insert_item(goodsList, item, pos);
            break;
        case 4:
            printf("输入要删除记录的 ID：");
            read_line(temp_id, MAX_ID_LEN);
            delete_item(goodsList, temp_id);
            break;
        case 5:
            printf("输入要查找记录的 ID：");
            read_line(temp_id, MAX_ID_LEN);
            search_item(goodsList, temp_id);
            break;
        case 6:
            save_to_file(goodsList);
            printf("您已经存盘并退出超市商品管理系统!\n");
            return 0;
        case 7:
            bubble_sort(goodsList);
            break;
        case 8:
            destory_list_and_file(&goodsList);
            printf("您已经删除商品文件内容以及链表内容!\n");
            break;
        default:
            printf("您已经退出超市商品管理系统!\n");
            destory_list(&goodsList);
            return 0;
        }
    }
}
