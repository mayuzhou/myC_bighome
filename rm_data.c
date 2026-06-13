#include"head.h"

// 删除已有猫信息
void deleteCat(){
    struct PET_CAT cats[M];
    int count=0;
    FILE*fp=fopen("cats.dat","rb");
    if(fp==NULL){
        printf("\n暂无猫信息，无法删除！\n");
        return;
    }
    while(fread(&cats[count],sizeof(struct PET_CAT),1,fp)==1){
        count++;
    }
    fclose(fp);
    if(count==0){
        printf("\n暂无猫信息！\n");
        return;
    }

    // 显示列表
    printf("\n========== 删除猫信息 ==========\n");
    for(int i=0;i<count;i++){
        printf("%d. %-10s 品种:%-8s 体重:%.1fkg 健康:%.1f分\n",
               i+1,cats[i].name,cats[i].variety,cats[i].weight,cats[i].healthScore);
    }
    printf("选择要删除的编号(0=返回): ");
    int idx;
    scanf("%d",&idx);
    if(idx<1||idx>count){
        printf("已取消。\n");
        return;
    }
    idx--;

    // 确认删除
    printf("\n确认删除 [%s] 吗？(1=确认 0=取消): ",cats[idx].name);
    int confirm;
    scanf("%d",&confirm);
    if(confirm!=1){
        printf("已取消删除。\n");
        return;
    }

    // 删除：后面的元素前移
    for(int i=idx;i<count-1;i++){
        cats[i]=cats[i+1];  // 结构体直接赋值
    }
    count--;

    // 写回文件
    fp=fopen("cats.dat","wb");
    if(fp==NULL){
        printf("无法写入文件！\n");
        return;
    }
    if(count>0){
        fwrite(cats,sizeof(struct PET_CAT),count,fp);
    }
    fclose(fp);
    printf("\n删除成功！\n");
}

// 删除已有狗信息
void deleteDog(){
    struct PET_DOG dogs[M];
    int count=0;
    FILE*fp=fopen("dogs.dat","rb");
    if(fp==NULL){
        printf("\n暂无狗信息，无法删除！\n");
        return;
    }
    while(fread(&dogs[count],sizeof(struct PET_DOG),1,fp)==1){
        count++;
    }
    fclose(fp);
    if(count==0){
        printf("\n暂无狗信息！\n");
        return;
    }

    // 显示列表
    printf("\n========== 删除狗信息 ==========\n");
    for(int i=0;i<count;i++){
        printf("%d. %-10s 品种:%-8s 体重:%.1fkg 健康:%.1f分\n",
               i+1,dogs[i].name,dogs[i].variety,dogs[i].weight,dogs[i].healthScore);
    }
    printf("选择要删除的编号(0=返回): ");
    int idx;
    scanf("%d",&idx);
    if(idx<1||idx>count){
        printf("已取消。\n");
        return;
    }
    idx--;

    // 确认删除
    printf("\n确认删除 [%s] 吗？(1=确认 0=取消): ",dogs[idx].name);
    int confirm;
    scanf("%d",&confirm);
    if(confirm!=1){
        printf("已取消删除。\n");
        return;
    }

    // 删除：后面的元素前移
    for(int i=idx;i<count-1;i++){
        dogs[i]=dogs[i+1];
    }
    count--;

    // 写回文件
    fp=fopen("dogs.dat","wb");
    if(fp==NULL){
        printf("无法写入文件！\n");
        return;
    }
    if(count>0){
        fwrite(dogs,sizeof(struct PET_DOG),count,fp);
    }
    fclose(fp);
    printf("\n删除成功！\n");
}
