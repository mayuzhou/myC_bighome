#include"head.h"

void doghealth(struct PET_DOG*dog, struct DOG_BREED dogBreeds[], int dogBreedCount){
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
