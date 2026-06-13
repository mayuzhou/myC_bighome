#include"head.h"

// 修改已有猫信息
void modifyCat(struct CAT_BREED catBreeds[], int catBreedCount){
    struct PET_CAT cats[M];
    int count=0;
    FILE*fp=fopen("cats.dat","rb");
    if(fp==NULL){
        printf("\n暂无猫信息，无法修改！\n");
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
    printf("\n========== 修改猫信息 ==========\n");
    for(int i=0;i<count;i++){
        printf("%d. %-10s 品种:%-8s 体重:%.1fkg 健康:%.1f分\n",
               i+1,cats[i].name,cats[i].variety,cats[i].weight,cats[i].healthScore);
    }
    printf("选择要修改的编号(0=返回): ");
    int idx;
    scanf("%d",&idx);
    if(idx<1||idx>count){
        printf("已取消。\n");
        return;
    }
    idx--;

    struct PET_CAT *cat=&cats[idx];
    printf("\n--- 正在修改 [%s] ---\n",cat->name);
    printf("(直接回车保留原值，输入新值则修改)\n\n");

    // 名字
    printf("名字[%s]: ",cat->name);
    char buf[50];
    getchar(); // 吃掉上一行的换行
    fgets(buf,sizeof(buf),stdin);
    if(buf[0]!='\n'){  // 如果输入了内容
        buf[strcspn(buf,"\n")]=0;
        strcpy(cat->name,buf);
    }

    // 品种
    printf("\n品种列表:\n");
    for(int i=0;i<catBreedCount;i++){
        printf("%d.%s ",i+1,catBreeds[i].name);
    }
    printf("\n当前品种[%s]\n选择新品种(0=不改): ",cat->variety);
    int ch;
    scanf("%d",&ch);
    if(ch>=1&&ch<=catBreedCount){
        strcpy(cat->variety,catBreeds[ch-1].name);
    }

    // 性别
    printf("性别[当前:%s] (1=雄 2=雌, 0=不改): ",cat->sex==1?"雄":"雌");
    int tmp;
    scanf("%d",&tmp);
    if(tmp==1||tmp==2)cat->sex=tmp;

    // 年龄
    printf("年龄[当前:%d] (0=不改): ",cat->age);
    scanf("%d",&tmp);
    if(tmp>0)cat->age=tmp;

    // 体重
    printf("体重(kg)[当前:%.1f] (0=不改): ",cat->weight);
    float ftmp;
    scanf("%f",&ftmp);
    if(ftmp>0)cat->weight=ftmp;

    // 体温
    printf("体温(℃)[当前:%.1f] (0=不改): ",cat->temp);
    scanf("%f",&ftmp);
    if(ftmp>0)cat->temp=ftmp;

    // 猫砂盆评分
    printf("猫砂盆评分[当前:%.1f] (0/0.5/1, -1=不改): ",cat->paiyi);
    scanf("%f",&ftmp);
    if(ftmp>=0)cat->paiyi=ftmp;

    // 疫苗
    char*vname[3]={"狂犬","猫瘟","猫鼻支"};
    for(int i=0;i<3;i++){
        if(cat->vaccineYear[i]!=-1){
            printf("%s[已注射 %d-%d-%d] (1=改日期 2=改未注射 0=不改): ",
                   vname[i],cat->vaccineYear[i],cat->vaccineMonth[i],cat->vaccineDay[i]);
        }else{
            printf("%s[未注射] (1=改已注射 0=不改): ",vname[i]);
        }
        scanf("%d",&tmp);
        if(tmp==1){
            printf("  日期(年 月 日): ");
            scanf("%d%d%d",&cat->vaccineYear[i],&cat->vaccineMonth[i],&cat->vaccineDay[i]);
        }else if(tmp==2){
            cat->vaccineYear[i]=-1;
        }
    }

    // 重新评估健康分
    cathealth(cat, catBreeds, catBreedCount);

    // 写回文件
    fp=fopen("cats.dat","wb");
    if(fp==NULL){
        printf("无法写入文件！\n");
        return;
    }
    fwrite(cats,sizeof(struct PET_CAT),count,fp);
    fclose(fp);
    printf("\n修改成功！新健康评分: %.1f分\n",cat->healthScore);
}

// 修改已有狗信息
void modifyDog(struct DOG_BREED dogBreeds[], int dogBreedCount){
    struct PET_DOG dogs[M];
    int count=0;
    FILE*fp=fopen("dogs.dat","rb");
    if(fp==NULL){
        printf("\n暂无狗信息，无法修改！\n");
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
    printf("\n========== 修改狗信息 ==========\n");
    for(int i=0;i<count;i++){
        printf("%d. %-10s 品种:%-8s 体重:%.1fkg 健康:%.1f分\n",
               i+1,dogs[i].name,dogs[i].variety,dogs[i].weight,dogs[i].healthScore);
    }
    printf("选择要修改的编号(0=返回): ");
    int idx;
    scanf("%d",&idx);
    if(idx<1||idx>count){
        printf("已取消。\n");
        return;
    }
    idx--;

    struct PET_DOG *dog=&dogs[idx];
    printf("\n--- 正在修改 [%s] ---\n",dog->name);
    printf("(直接回车保留原值，输入新值则修改)\n\n");

    // 名字
    printf("名字[%s]: ",dog->name);
    char buf[50];
    getchar();
    fgets(buf,sizeof(buf),stdin);
    if(buf[0]!='\n'){
        buf[strcspn(buf,"\n")]=0;
        strcpy(dog->name,buf);
    }

    // 品种
    printf("\n品种列表:\n");
    for(int i=0;i<dogBreedCount;i++){
        printf("%d.%s ",i+1,dogBreeds[i].name);
    }
    printf("\n当前品种[%s]\n选择新品种(0=不改): ",dog->variety);
    int ch;
    scanf("%d",&ch);
    if(ch>=1&&ch<=dogBreedCount){
        strcpy(dog->variety,dogBreeds[ch-1].name);
    }

    // 性别
    printf("性别[当前:%s] (1=雄 2=雌, 0=不改): ",dog->sex==1?"雄":"雌");
    int tmp;
    scanf("%d",&tmp);
    if(tmp==1||tmp==2)dog->sex=tmp;

    // 年龄
    printf("年龄[当前:%d] (0=不改): ",dog->age);
    scanf("%d",&tmp);
    if(tmp>0)dog->age=tmp;

    // 体重
    printf("体重(kg)[当前:%.1f] (0=不改): ",dog->weight);
    float ftmp;
    scanf("%f",&ftmp);
    if(ftmp>0)dog->weight=ftmp;

    // 体温
    printf("体温(℃)[当前:%.1f] (0=不改): ",dog->temp);
    scanf("%f",&ftmp);
    if(ftmp>0)dog->temp=ftmp;

    // 运动评分
    printf("运动评分[当前:%.1f] (0/0.5/1, -1=不改): ",dog->sportScore);
    scanf("%f",&ftmp);
    if(ftmp>=0)dog->sportScore=ftmp;

    // 疫苗
    char*vname[3]={"狂犬","犬瘟热","细小"};
    for(int i=0;i<3;i++){
        if(dog->vaccineYear[i]!=-1){
            printf("%s[已注射 %d-%d-%d] (1=改日期 2=改未注射 0=不改): ",
                   vname[i],dog->vaccineYear[i],dog->vaccineMonth[i],dog->vaccineDay[i]);
        }else{
            printf("%s[未注射] (1=改已注射 0=不改): ",vname[i]);
        }
        scanf("%d",&tmp);
        if(tmp==1){
            printf("  日期(年 月 日): ");
            scanf("%d%d%d",&dog->vaccineYear[i],&dog->vaccineMonth[i],&dog->vaccineDay[i]);
        }else if(tmp==2){
            dog->vaccineYear[i]=-1;
        }
    }

    // 重新评估健康分
    doghealth(dog, dogBreeds, dogBreedCount);

    // 写回文件
    fp=fopen("dogs.dat","wb");
    if(fp==NULL){
        printf("无法写入文件！\n");
        return;
    }
    fwrite(dogs,sizeof(struct PET_DOG),count,fp);
    fclose(fp);
    printf("\n修改成功！新健康评分: %.1f分\n",dog->healthScore);
}
