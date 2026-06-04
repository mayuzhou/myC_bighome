#include"head.h"

void viewLowHealth(){
    int count=0;
    printf("\n========== 健康预警(健康分<70) ==========\n");

    // 检查猫
    FILE*fp=fopen("data/cats.dat","rb");
    if(fp!=NULL){
        struct PET_CAT cat;
        while(fread(&cat,sizeof(struct PET_CAT),1,fp)==1){
            if(cat.healthScore<70){
                count++;
                printf("\n[猫] %s | 品种:%s | 体重:%.1fkg | 体温:%.1f℃ | 评分:%.1f分\n",
                       cat.name,cat.variety,cat.weight,cat.temp,cat.healthScore);
            }
        }
        fclose(fp);
    }

    // 检查狗
    fp=fopen("data/dogs.dat","rb");
    if(fp!=NULL){
        struct PET_DOG dog;
        while(fread(&dog,sizeof(struct PET_DOG),1,fp)==1){
            if(dog.healthScore<70){
                count++;
                printf("\n[狗] %s | 品种:%s | 体重:%.1fkg | 体温:%.1f℃ | 评分:%.1f分\n",
                       dog.name,dog.variety,dog.weight,dog.temp,dog.healthScore);
            }
        }
        fclose(fp);
    }

    if(count==0)printf("\n暂无健康分低于70的宠物！\n");
    else printf("\n共 %d 只宠物需要关注。\n",count);
}
