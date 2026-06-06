#include"head.h"
int main(){
    // 猫品种本地数组
    struct CAT_BREED catBreeds[20]={
        {"布偶",5.0,1.0},
        {"英短",5.0,1.0},
        {"美短",4.5,1.0},
        {"暹罗",4.0,1.0},
        {"波斯",4.5,1.0},
        {"加菲",4.5,1.0},
        {"狸花",4.0,1.1},
        {"橘猫",5.0,1.1},
        {"缅因",7.0,0.9},
        {"无毛",4.0,0.95}
    };
    int catBreedCount=10;
    // 狗品种本地数组
    struct DOG_BREED dogBreeds[20]={
        {"法斗",11.0,1.0},
        {"金毛",28.0,0.9},
        {"贵宾",5.0,1.1},
        {"柯基",12.0,1.0},
        {"拉布拉多",25.0,0.9},
        {"哈士奇",22.0,0.95},
        {"柴犬",9.0,1.0},
        {"边牧",16.0,1.0},
        {"比熊",5.5,1.1},
        {"泰迪",4.5,1.1}
    };
    int dogBreedCount=10;

    loadCatBreeds(catBreeds, &catBreedCount);
    loadDogBreeds(dogBreeds, &dogBreedCount);
    vetMenu(catBreeds, &catBreedCount, dogBreeds, &dogBreedCount);
    
    return 0;
}