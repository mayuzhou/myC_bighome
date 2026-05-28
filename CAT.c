#include"head.h"

// 猫品种数组
struct CAT_BREED catBreeds[20] = {
    {"布偶", 5.0, 1.0},
    {"英短", 5.0, 1.0},
    {"美短", 4.5, 1.0},
    {"暹罗", 4.0, 1.0},
    {"波斯", 4.5, 1.0},
    {"加菲", 4.5, 1.0},
    {"狸花", 4.0, 1.1},
    {"橘猫", 5.0, 1.1},
    {"缅因", 7.0, 0.9},
    {"无毛", 4.0, 0.95}
};
int catBreedCount = 10;

void saveCatBreeds(){
    FILE *fp = fopen("data/cat_breeds.dat", "w");
    if(fp == NULL){
        system("mkdir data 2>nul");
        fp = fopen("data/cat_breeds.dat", "w");
    }
    fprintf(fp, "%d\n", catBreedCount);
    for(int i=0; i<catBreedCount; i++){
        fprintf(fp, "%s %f %f\n", catBreeds[i].name, catBreeds[i].weight, catBreeds[i].coeff);
    }
    fclose(fp);
}

void loadCatBreeds(){
    FILE *fp = fopen("data/cat_breeds.dat", "r");
    if(fp == NULL) return;
    fscanf(fp, "%d", &catBreedCount);
    for(int i=0; i<catBreedCount; i++){
        fscanf(fp, "%s %f %f", catBreeds[i].name, &catBreeds[i].weight, &catBreeds[i].coeff);
    }
    fclose(fp);
}

void addCat(){
    struct PET_CAT cat;
    
    printf("\n========== 添加猫信息 ==========\n");
    printf("名字: ");
    scanf("%s", cat.name);
    
    printf("\n品种列表:\n");
    for(int i=0; i<catBreedCount; i++){
        printf("%d.%s ", i+1, catBreeds[i].name);
    }
    printf("%d.添加新品种\n", catBreedCount+1);
    printf("选择: ");
    int ch;
    scanf("%d", &ch);
    
    if(ch == catBreedCount + 1){
        printf("新品种名称: ");
        scanf("%s", catBreeds[catBreedCount].name);
        printf("标准体重(kg): ");
        scanf("%f", &catBreeds[catBreedCount].weight);
        printf("修正系数: ");
        scanf("%f", &catBreeds[catBreedCount].coeff);
        catBreedCount++;
        strcpy(cat.variety, catBreeds[catBreedCount-1].name);
        saveCatBreeds();
    }else{
        strcpy(cat.variety, catBreeds[ch-1].name);
    }
    
    printf("性别(1=雄 2=雌): ");
    scanf("%d", &cat.sex);
    printf("年龄: ");
    scanf("%d", &cat.age);
    printf("体重(kg): ");
    scanf("%f", &cat.weight);
    printf("体温(℃): ");
    scanf("%f", &cat.temp);
    
    printf("\n猫砂盆评分(0/0.5/1):\n");
    printf("0-拒绝使用,乱尿\n");
    printf("0.5-偶尔乱尿\n");
    printf("1-定点使用\n");
    scanf("%f", &cat.litterScore);
    
    printf("\n疫苗注射情况:\n");
    for(int i=0; i<3; i++){
        printf("第%d种疫苗(1=已注射 2=未注射): ", i+1);
        int flag;
        scanf("%d", &flag);
        if(flag == 1){
            printf("  日期(年 月 日): ");
            scanf("%d%d%d", &cat.vaccineYear[i], &cat.vaccineMonth[i], &cat.vaccineDay[i]);
        }else{
            cat.vaccineYear[i] = -1;
        }
    }
    //评估 
    catHealthCalc(&cat);
    
    // 保存到文件
    FILE *fp = fopen("data/cats.dat", "a");
    if(fp == NULL){
        system("mkdir data 2>nul");
        fp = fopen("data/cats.dat", "a");
    }
    fprintf(fp, "%s %s %d %d %.1f %.1f %.1f %d %d %d %d %d %d %d %.1f\n",
            cat.name, cat.variety, cat.sex, cat.age, cat.weight, cat.temp, cat.litterScore,
            cat.vaccineYear[0], cat.vaccineMonth[0], cat.vaccineDay[0],
            cat.vaccineYear[1], cat.vaccineMonth[1], cat.vaccineDay[1],
            cat.vaccineYear[2], cat.healthScore);
    fclose(fp);
    
    printf("\n添加成功！健康评分: %.1f分\n", cat.healthScore);
}

void viewCats(){
    FILE *fp = fopen("data/cats.dat", "r");
    if(fp == NULL){
        printf("\n暂无猫信息！\n");
        return;
    }
    
    struct PET_CAT cat;
    int count = 0;
    
    printf("\n========== 猫信息列表 ==========\n");
    while(fscanf(fp, "%s %s %d %d %f %f %f %d %d %d %d %d %d %d %f",
                 cat.name, cat.variety, &cat.sex, &cat.age, &cat.weight, &cat.temp, 
                 &cat.litterScore,
                 &cat.vaccineYear[0], &cat.vaccineMonth[0], &cat.vaccineDay[0],
                 &cat.vaccineYear[1], &cat.vaccineMonth[1], &cat.vaccineDay[1],
                 &cat.vaccineYear[2], &cat.healthScore) != EOF){
        count++;
        printf("\n--- 第%d只猫 ---\n", count);
        printf("名字: %s\n", cat.name);
        printf("品种: %s\n", cat.variety);
        printf("性别: %s\n", cat.sex==1?"雄":"雌");
        printf("年龄: %d岁\n", cat.age);
        printf("体重: %.1fkg\n", cat.weight);
        printf("体温: %.1f℃\n", cat.temp);
        printf("猫砂盆评分: %.1f\n", cat.litterScore);
        printf("健康评分: %.1f分\n", cat.healthScore);
        printf("疫苗: ");
        char *vname[3] = {"狂犬","猫瘟","猫鼻支"};
        for(int i=0; i<3; i++){
            if(cat.vaccineYear[i] != -1){
                printf("%s(%d年%d月%d) ", vname[i], cat.vaccineYear[i], 
                       cat.vaccineMonth[i], cat.vaccineDay[i]);
            }else{
                printf("%s(未注射) ", vname[i]);
            }
        }
        printf("\n");
    }
    fclose(fp);
    
    if(count == 0) printf("\n暂无猫信息！\n");
}

void manageCatBreeds(){
    int choice;
    while(1){
        printf("\n========== 猫品种管理 ==========\n");
        printf("当前品种数: %d\n\n", catBreedCount);
        printf("品种列表:\n");
        for(int i=0; i<catBreedCount; i++){
            printf("%2d. %-8s 标准体重: %4.1fkg 系数: %.2f\n", 
                   i+1, catBreeds[i].name, catBreeds[i].weight, catBreeds[i].coeff);
        }
        printf("\n1.添加新品种  0.返回: ");
        scanf("%d", &choice);
        
        if(choice == 1){
            printf("品种名称: ");
            scanf("%s", catBreeds[catBreedCount].name);
            printf("标准体重(kg): ");
            scanf("%f", &catBreeds[catBreedCount].weight);
            printf("修正系数: ");
            scanf("%f", &catBreeds[catBreedCount].coeff);
            catBreedCount++;
            saveCatBreeds();
            printf("添加成功！\n");
        }else if(choice == 0){
            break;
        }
    }
}


