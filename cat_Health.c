#include"head.h"

//技术亮点pipei函数
int pipei(char*a,char*b){
    while(*a&&*b){
        if(*a!=*b)return 0;
        a++;
        b++;
    }
    return(*a==*b);
}

void cathealth(struct PET_CAT*cat, struct CAT_BREED catBreeds[], int catBreedCount){
    float biaozhunWeight=5.0,canshu=1.0;//先设默认值
    for(int i=0;i<catBreedCount;i++){
        if(pipei(cat->variety,catBreeds[i].name)){
            biaozhunWeight=catBreeds[i].weight;
            canshu=catBreeds[i].canshu;
            break;
        }
    }
    float w=cat->weight/biaozhunWeight;
    float t;
    if(cat->temp>=38.0&&cat->temp<=39.0)t=1.0;
    else if(cat->temp<=39.5)t=0.5;
    else t = 0;
    
    int yimiao = 0;
    for(int i=0;i<3;i++)if(cat->vaccineYear[i]!=-1)yimiao++;
    cat->healthScore=(w*0.3+t*0.3+yimiao/3.0*0.3+cat->paiyi*0.1)*canshu*100;
}
