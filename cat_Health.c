#include"head.h"

void catHealthCalc(struct PET_CAT *cat){
    float stdWeight = 5.0, coeff = 1.0;
    for(int i=0; i<catBreedCount; i++){
        if(strcmp(cat->variety, catBreeds[i].name) == 0){
            stdWeight = catBreeds[i].weight;
            coeff = catBreeds[i].coeff;
            break;
        }
    }
    float w = cat->weight / stdWeight;
    if(w > 1.2) w = 1.2;
    
    float t;
    if(cat->temp >= 38.0 && cat->temp <= 39.0) t = 1.0;
    else if(cat->temp <= 39.5) t = 0.5;
    else t = 0;
    
    int vc = 0;
    for(int i=0; i<3; i++) if(cat->vaccineYear[i] != -1) vc++;
    
    cat->healthScore = (w*0.3 + t*0.3 + vc/3.0*0.3 + cat->litterScore*0.1) * coeff * 100;
}
