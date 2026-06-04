#include"head.h"

void vetMenu(){
    int choice;
    
    while(1){
    printf("\n========================================\n");
    printf("         宠物健康管理系统 - 兽医用户端\n");
    printf("========================================\n");
    printf("  1. 添加新宠物信息\n");
    printf("  2. 查看已有宠物\n");
    printf("  3. 品种管理\n");
    printf("  4. 健康预警(<70分)\n");
    printf("  0. 退出系统\n");
    printf("========================================\n");
    printf("请选择: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        case 2:{  // 共用宠物类型选择逻辑
            int type;
            printf("\n请选择宠物类型:\n");
            printf("1. 猫\n");
            printf("2. 狗\n");
            printf("选择: ");
            scanf("%d",&type);
            if(type==1)
                catSystem();
            else if(type==2)
                dogSystem();
            break;
        }
        case 3:{
            int type;
            printf("\n1.猫品种  2.狗品种  0.返回: ");
            scanf("%d",&type);
            if(type==1)
                manageCatBreeds();
            else if(type==2)
                manageDogBreeds();
            break;
        }
        case 4:
            viewLowHealth();
            break;
        case 0:
            printf("再见！\n");
            return;
        default:
            printf("无效输入，请重新选择！\n");
            break;
    }
}
}
