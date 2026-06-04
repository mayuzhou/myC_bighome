#include"head.h"

// 狗品种数组初始化
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

void doghealth(struct PET_DOG*dog){
    float stdWeight=10.0,canshu=1.0;
    for(int i=0;i<dogBreedCount;i++){
        if(pipei(dog->variety,dogBreeds[i].name)){
            stdWeight=dogBreeds[i].weight;
            canshu=dogBreeds[i].canshu;
            break;
        }
    }
    float w=dog->weight/stdWeight;
    if(w>1.2)w=1.2;
    
    float t;
    if(dog->temp>=37.5&&dog->temp<=38.5)t=1.0;
    else if(dog->temp<=39.0)t=0.5;
    else t = 0;
    
    int yimiao = 0;
    for(int i=0;i<3;i++)if(dog->vaccineYear[i]!=-1)yimiao++;
    
    dog->healthScore=(w*0.3+t*0.3+yimiao/3.0*0.3+dog->sportScore*0.1)*canshu*100;
}
