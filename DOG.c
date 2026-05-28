#include"head.h"

// 狗品种数组
struct DOG_BREED dogBreeds[20] = {
    {"法斗", 11.0, 1.0},
    {"金毛", 28.0, 0.9},
    {"贵宾", 5.0, 1.1},
    {"柯基", 12.0, 1.0},
    {"拉布拉多", 25.0, 0.9},
    {"哈士奇", 22.0, 0.95},
    {"柴犬", 9.0, 1.0},
    {"边牧", 16.0, 1.0},
    {"比熊", 5.5, 1.1},
    {"泰迪", 4.5, 1.1}
};
int dogBreedCount = 10;

void saveDogBreeds(){
    FILE *fp = fopen("data/dog_breeds.dat", "w");
    if(fp == NULL){
        system("mkdir data 2>nul");
        fp = fopen("data/dog_breeds.dat", "w");
    }
    fprintf(fp, "%d\n", dogBreedCount);
    for(int i=0; i<dogBreedCount; i++){
        fprintf(fp, "%s %f %f\n", dogBreeds[i].name, dogBreeds[i].weight, dogBreeds[i].coeff);
    }
    fclose(fp);
}

void loadDogBreeds(){
    FILE *fp = fopen("data/dog_breeds.dat", "r");
    if(fp == NULL) return;
    fscanf(fp, "%d", &dogBreedCount);
    for(int i=0; i<dogBreedCount; i++){
        fscanf(fp, "%s %f %f", dogBreeds[i].name, &dogBreeds[i].weight, &dogBreeds[i].coeff);
    }
    fclose(fp);
}

void addDog(){
    struct PET_DOG dog;
    
    printf("\n========== 添加狗信息 ==========\n");
    printf("名字: ");
    scanf("%s", dog.name);
    
    printf("\n品种列表:\n");
    for(int i=0; i<dogBreedCount; i++){
        printf("%d.%s ", i+1, dogBreeds[i].name);
    }
    printf("%d.添加新品种\n", dogBreedCount+1);
    printf("选择: ");
    int ch;
    scanf("%d", &ch);
    
    if(ch == dogBreedCount + 1){
        printf("新品种名称: ");
        scanf("%s", dogBreeds[dogBreedCount].name);
        printf("标准体重(kg): ");
        scanf("%f", &dogBreeds[dogBreedCount].weight);
        printf("修正系数: ");
        scanf("%f", &dogBreeds[dogBreedCount].coeff);
        dogBreedCount++;
        strcpy(dog.variety, dogBreeds[dogBreedCount-1].name);
        saveDogBreeds();
    }else{
        strcpy(dog.variety, dogBreeds[ch-1].name);
    }
    
    printf("性别(1=雄 2=雌): ");
    scanf("%d", &dog.sex);
    printf("年龄: ");
    scanf("%d", &dog.age);
    printf("体重(kg): ");
    scanf("%f", &dog.weight);
    printf("体温(℃): ");
    scanf("%f", &dog.temp);
    
    printf("\n运动评分(0/0.5/1):\n");
    printf("0-大型犬运动<1小时,爆冲\n");
    printf("0.5-中型犬运动1-2小时\n");
    printf("1-按品种完成运动需求\n");
    scanf("%f", &dog.sportScore);
    
    printf("\n疫苗注射情况:\n");
    for(int i=0; i<3; i++){
        printf("第%d种疫苗(1=已注射 2=未注射): ", i+1);
        int flag;
        scanf("%d", &flag);
        if(flag == 1){
            printf("  日期(年 月 日): ");
            scanf("%d%d%d", &dog.vaccineYear[i], &dog.vaccineMonth[i], &dog.vaccineDay[i]);
        }else{
            dog.vaccineYear[i] = -1;
        }
    }
    
    // 后台健康评估计算
    dogHealthCalc(&dog);
    
    // 保存到文件
    FILE *fp = fopen("data/dogs.dat", "a");
    if(fp == NULL){
        system("mkdir data 2>nul");
        fp = fopen("data/dogs.dat", "a");
    }
    fprintf(fp, "%s %s %d %d %.1f %.1f %.1f %d %d %d %d %d %d %d %.1f\n",
            dog.name, dog.variety, dog.sex, dog.age, dog.weight, dog.temp, dog.sportScore,
            dog.vaccineYear[0], dog.vaccineMonth[0], dog.vaccineDay[0],
            dog.vaccineYear[1], dog.vaccineMonth[1], dog.vaccineDay[1],
            dog.vaccineYear[2], dog.healthScore);
    fclose(fp);
    
    printf("\n添加成功！健康评分: %.1f分\n", dog.healthScore);
}

void viewDogs(){
    FILE *fp = fopen("data/dogs.dat", "r");
    if(fp == NULL){
        printf("\n暂无狗信息！\n");
        return;
    }
    
    struct PET_DOG dog;
    int count = 0;
    
    printf("\n========== 狗信息列表 ==========\n");
    while(fscanf(fp, "%s %s %d %d %f %f %f %d %d %d %d %d %d %d %f",
                 dog.name, dog.variety, &dog.sex, &dog.age, &dog.weight, &dog.temp, 
                 &dog.sportScore,
                 &dog.vaccineYear[0], &dog.vaccineMonth[0], &dog.vaccineDay[0],
                 &dog.vaccineYear[1], &dog.vaccineMonth[1], &dog.vaccineDay[1],
                 &dog.vaccineYear[2], &dog.healthScore) != EOF){
        count++;
        printf("\n--- 第%d只狗 ---\n", count);
        printf("名字: %s\n", dog.name);
        printf("品种: %s\n", dog.variety);
        printf("性别: %s\n", dog.sex==1?"雄":"雌");
        printf("年龄: %d岁\n", dog.age);
        printf("体重: %.1fkg\n", dog.weight);
        printf("体温: %.1f℃\n", dog.temp);
        printf("运动评分: %.1f\n", dog.sportScore);
        printf("健康评分: %.1f分\n", dog.healthScore);
        printf("疫苗: ");
        char *vname[3] = {"狂犬","犬瘟热","细小"};
        for(int i=0; i<3; i++){
            if(dog.vaccineYear[i] != -1){
                printf("%s(%d年%d月%d) ", vname[i], dog.vaccineYear[i], 
                       dog.vaccineMonth[i], dog.vaccineDay[i]);
            }else{
                printf("%s(未注射) ", vname[i]);
            }
        }
        printf("\n");
    }
    fclose(fp);
    
    if(count == 0) printf("\n暂无狗信息！\n");
}

void manageDogBreeds(){
    int choice;
    while(1){
        printf("\n========== 狗品种管理 ==========\n");
        printf("当前品种数: %d\n\n", dogBreedCount);
        printf("品种列表:\n");
        for(int i=0; i<dogBreedCount; i++){
            printf("%2d. %-8s 标准体重: %4.1fkg 系数: %.2f\n", 
                   i+1, dogBreeds[i].name, dogBreeds[i].weight, dogBreeds[i].coeff);
        }
        printf("\n1.添加新品种  0.返回: ");
        scanf("%d", &choice);
        
        if(choice == 1){
            printf("品种名称: ");
            scanf("%s", dogBreeds[dogBreedCount].name);
            printf("标准体重(kg): ");
            scanf("%f", &dogBreeds[dogBreedCount].weight);
            printf("修正系数: ");
            scanf("%f", &dogBreeds[dogBreedCount].coeff);
            dogBreedCount++;
            saveDogBreeds();
            printf("添加成功！\n");
        }else if(choice == 0){
            break;
        }
    }
}
