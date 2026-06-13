#include"head.h"

void vetMenu(struct CAT_BREED catBreeds[], int *catBreedCount,
             struct DOG_BREED dogBreeds[], int *dogBreedCount){
    int choice;
    
    while(1){
    printf("\n========================================\n");
    printf("         宠物健康管理系统 - 兽医用户端\n");
    printf("========================================\n");
    printf("  1. 添加新宠物信息\n");
    printf("  2. 查看已有宠物\n");
    printf("  3. 修改宠物信息\n");
    printf("  4. 删除宠物信息\n");
    printf("  5. 品种管理\n");
    printf("  6. 健康预警(<70分)\n");
    printf("  0. 退出系统\n");
    printf("========================================\n");
    printf("请选择: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:{
            int type;
            printf("\n请选择宠物类型:\n");
            printf("1. 猫\n");
            printf("2. 狗\n");
            printf("选择: ");
            scanf("%d",&type);
            if(type==1)
                addCat(catBreeds, catBreedCount);
            else if(type==2)
                addDog(dogBreeds, dogBreedCount);
            break;
        }
        case 2:{
            int type;
            printf("\n请选择宠物类型:\n");
            printf("1. 猫\n");
            printf("2. 狗\n");
            printf("选择: ");
            scanf("%d",&type);
            if(type==1)
                catSystem(catBreeds, catBreedCount);
            else if(type==2)
                dogSystem(dogBreeds, dogBreedCount);
            break;
        }
        case 3:{
            int type;
            printf("\n请选择宠物类型:\n");
            printf("1. 猫\n");
            printf("2. 狗\n");
            printf("选择: ");
            scanf("%d",&type);
            if(type==1)
                modifyCat(catBreeds, *catBreedCount);
            else if(type==2)
                modifyDog(dogBreeds, *dogBreedCount);
            break;
        }
        case 4:{
            int type;
            printf("\n请选择宠物类型:\n");
            printf("1. 猫\n");
            printf("2. 狗\n");
            printf("选择: ");
            scanf("%d",&type);
            if(type==1)
                deleteCat();
            else if(type==2)
                deleteDog();
            break;
        }
        case 5:{
            int type;
            printf("\n1.猫品种  2.狗品种  0.返回: ");
            scanf("%d",&type);
            if(type==1)
                manageCatBreeds(catBreeds, catBreedCount);
            else if(type==2)
                manageDogBreeds(dogBreeds, dogBreedCount);
            break;
        }
        case 6:
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
