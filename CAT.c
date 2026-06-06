#include"head.h"

void saveCatBreeds(struct CAT_BREED catBreeds[], int catBreedCount){
    FILE*fp=fopen("data/cat_breeds.dat","wb");
    if(fp==NULL){
        system("mkdir data 2>nul");
        fp=fopen("data/cat_breeds.dat","wb");
    }
    fwrite(&catBreedCount,sizeof(int),1,fp);
    fwrite(catBreeds,sizeof(struct CAT_BREED),catBreedCount,fp);
    fclose(fp);
}

void loadCatBreeds(struct CAT_BREED catBreeds[], int *catBreedCount){
    FILE*fp=fopen("data/cat_breeds.dat","rb");
    if(fp==NULL)return;
    fread(catBreedCount,sizeof(int),1,fp);
    fread(catBreeds,sizeof(struct CAT_BREED),*catBreedCount,fp);
    fclose(fp);
}

void addCat(struct CAT_BREED catBreeds[], int *catBreedCount){
    struct PET_CAT cat;
    
    printf("\n========== 添加猫信息 ==========\n");
    printf("名字: ");
    scanf("%s",cat.name);
    
    printf("\n品种列表:\n");
    for(int i=0;i<*catBreedCount;i++){
        printf("%d.%s ",i+1,catBreeds[i].name);
    }
    printf("%d.添加新品种\n",*catBreedCount+1);
    printf("选择: ");
    int ch;
    scanf("%d",&ch);
    
    if(ch==*catBreedCount+1){
        printf("新品种名称: ");
        scanf("%s",catBreeds[*catBreedCount].name);
        printf("标准体重(kg): ");
        scanf("%f",&catBreeds[*catBreedCount].weight);
        printf("修正系数: ");
        scanf("%f",&catBreeds[*catBreedCount].canshu);
        (*catBreedCount)++;
        strcpy(cat.variety,catBreeds[*catBreedCount-1].name);
        saveCatBreeds(catBreeds, *catBreedCount);
    }else{
        strcpy(cat.variety,catBreeds[ch-1].name);
    }
    
    printf("性别(1=雄 2=雌): ");
    scanf("%d",&cat.sex);
    printf("年龄: ");
    scanf("%d",&cat.age);
    printf("体重(kg): ");
    scanf("%f",&cat.weight);
    printf("体温(℃): ");
    scanf("%f",&cat.temp);
    
    printf("\n猫砂盆评分(0/0.5/1):\n");
    printf("0-拒绝使用,乱尿\n");
    printf("0.5-偶尔乱尿\n");
    printf("1-定点使用\n");
    scanf("%f",&cat.paiyi);
    
    printf("\n疫苗注射情况:\n");
    for(int i=0;i<3;i++){
        printf("第%d种疫苗(1=已注射 2=未注射): ",i+1);
        int flag;
        scanf("%d",&flag);
        if(flag==1){
            printf("  日期(年 月 日): ");
            scanf("%d%d%d",&cat.vaccineYear[i],&cat.vaccineMonth[i],&cat.vaccineDay[i]);
        }else{
            cat.vaccineYear[i]=-1;
        }
    }
    //评估 
    cathealth(&cat, catBreeds, *catBreedCount);
    
    // 保存到文件（二进制追加）
    FILE*fp=fopen("data/cats.dat","ab");
    if(fp==NULL){
        system("mkdir data 2>nul");
        fp=fopen("data/cats.dat","ab");
    }
    fwrite(&cat,sizeof(struct PET_CAT),1,fp);
    fclose(fp);
    
    printf("\n添加成功！健康评分: %.1f分\n",cat.healthScore);
}

void viewCats(){
    FILE*fp=fopen("data/cats.dat","rb");
    if(fp==NULL){
        printf("\n暂无猫信息！\n");
        return;
    }
    
    struct PET_CAT cat;
    int count=0;
    
    printf("\n========== 猫信息列表 ==========\n");
    while(fread(&cat,sizeof(struct PET_CAT),1,fp)==1){
        count++;
        printf("\n--- 第%d只猫 ---\n",count);
        printf("名字: %s\n",cat.name);
        printf("品种: %s\n",cat.variety);
        printf("性别: %s\n",cat.sex==1?"雄":"雌");
        printf("年龄: %d岁\n",cat.age);
        printf("体重: %.1fkg\n",cat.weight);
        printf("体温: %.1f℃\n",cat.temp);
        printf("猫砂盆评分: %.1f\n",cat.paiyi);
        printf("健康评分: %.1f分\n",cat.healthScore);
        printf("疫苗: ");
        char*vname[3]={"狂犬","猫瘟","猫鼻支"};
        for(int i=0;i<3;i++){
            if(cat.vaccineYear[i]!=-1){
                printf("%s(%d年%d月%d) ",vname[i],cat.vaccineYear[i],
                       cat.vaccineMonth[i],cat.vaccineDay[i]);
            }else{
                printf("%s(未注射) ",vname[i]);
            }
        }
        printf("\n");
    }
    fclose(fp);
    
    if(count==0)printf("\n暂无猫信息！\n");
}

void manageCatBreeds(struct CAT_BREED catBreeds[], int *catBreedCount){
    int choice;
    while(1){
        printf("\n========== 猫品种管理 ==========\n");
        printf("当前品种数: %d\n\n",*catBreedCount);
        printf("品种列表:\n");
        for(int i=0;i<*catBreedCount;i++){
            printf("%2d. %-8s 标准体重: %4.1fkg 系数: %.2f\n",
                   i+1,catBreeds[i].name,catBreeds[i].weight,catBreeds[i].canshu);
        }
        printf("\n1.添加新品种  0.返回: ");
        scanf("%d",&choice);
        
        if(choice==1){
            printf("品种名称: ");
            scanf("%s",catBreeds[*catBreedCount].name);
            printf("标准体重(kg): ");
            scanf("%f",&catBreeds[*catBreedCount].weight);
            printf("修正系数: ");
            scanf("%f",&catBreeds[*catBreedCount].canshu);
            (*catBreedCount)++;
            saveCatBreeds(catBreeds, *catBreedCount);
            printf("添加成功！\n");
        }else if(choice==0){
            break;
        }
    }
}


