#include"head.h"

void dogHealthCalc(struct PET_DOG *dog){
    float stdWeight = 10.0, coeff = 1.0;
    for(int i=0; i<dogBreedCount; i++){
        if(strcmp(dog->variety, dogBreeds[i].name) == 0){
            stdWeight = dogBreeds[i].weight;
            coeff = dogBreeds[i].coeff;
            break;
        }
    }
    float w = dog->weight / stdWeight;
    if(w > 1.2) w = 1.2;
    
    float t;
    if(dog->temp >= 37.5 && dog->temp <= 38.5) t = 1.0;
    else if(dog->temp <= 39.0) t = 0.5;
    else t = 0;
    
    int vc = 0;
    for(int i=0; i<3; i++) if(dog->vaccineYear[i] != -1) vc++;
    
    dog->healthScore = (w*0.3 + t*0.3 + vc/3.0*0.3 + dog->sportScore*0.1) * coeff * 100;
}
