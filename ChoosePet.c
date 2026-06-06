#include"head.h"

// 猫子系统菜单
void catSystem(struct CAT_BREED catBreeds[], int *catBreedCount){
    int choice;
    while(1){
        printf("\n========== 猫子系统 ==========\n");
        printf("1.添加猫信息\n");
        printf("2.查看猫信息\n");
        printf("3.品种管理\n");
        printf("0.返回\n");
        printf("选择: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                addCat(catBreeds, catBreedCount);
                break;
            case 2:
                viewCats();
                break;
            case 3:
                manageCatBreeds(catBreeds, catBreedCount);
                break;
            case 0:
                return;
            default:
                printf("无效选择！\n");
        }
    }
}

// 狗子系统菜单
void dogSystem(struct DOG_BREED dogBreeds[], int *dogBreedCount){
    int choice;
    while(1){
        printf("\n========== 狗子系统 ==========\n");
        printf("1.添加狗信息\n");
        printf("2.查看狗信息\n");
        printf("3.品种管理\n");
        printf("0.返回\n");
        printf("选择: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                addDog(dogBreeds, dogBreedCount);
                break;
            case 2:
                viewDogs();
                break;
            case 3:
                manageDogBreeds(dogBreeds, dogBreedCount);
                break;
            case 0:
                return;
            default:
                printf("无效选择！\n");
        }
    }
}
