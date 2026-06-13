#ifndef HEAD_H
#define HEAD_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 100

struct PET_CAT{
    char name[50];
    char variety[50];
    int sex;
    int age;
    float weight;
    float temp;
    float paiyi;
    int vaccineYear[3];
    int vaccineMonth[3];
    int vaccineDay[3];
    float healthScore;
};

struct PET_DOG{
    char name[50];
    char variety[50];
    int sex;
    int age;
    float weight;
    float temp;
    float sportScore;
    int vaccineYear[3];
    int vaccineMonth[3];
    int vaccineDay[3];
    float healthScore;
};

struct CAT_BREED{
    char name[50];
    float weight;
    float canshu;
};

struct DOG_BREED{
    char name[50];
    float weight;
    float canshu;
};
void vetMenu(struct CAT_BREED catBreeds[], int *catBreedCount,
             struct DOG_BREED dogBreeds[], int *dogBreedCount);
void catSystem(struct CAT_BREED catBreeds[], int *catBreedCount);
void dogSystem(struct DOG_BREED dogBreeds[], int *dogBreedCount);

void addCat(struct CAT_BREED catBreeds[], int *catBreedCount);

void viewCats();
void addDog(struct DOG_BREED dogBreeds[], int *dogBreedCount);
void viewDogs();

int pipei(char*a,char*b);
void cathealth(struct PET_CAT*cat, struct CAT_BREED catBreeds[], int catBreedCount);
void doghealth(struct PET_DOG*dog, struct DOG_BREED dogBreeds[], int dogBreedCount);
void viewLowHealth();
void manageCatBreeds(struct CAT_BREED catBreeds[], int *catBreedCount);

void manageDogBreeds(struct DOG_BREED dogBreeds[], int *dogBreedCount);

void loadCatBreeds(struct CAT_BREED catBreeds[], int *catBreedCount);
void saveCatBreeds(struct CAT_BREED catBreeds[], int catBreedCount);

void loadDogBreeds(struct DOG_BREED dogBreeds[], int *dogBreedCount);
void saveDogBreeds(struct DOG_BREED dogBreeds[], int dogBreedCount);

void modifyCat(struct CAT_BREED catBreeds[], int catBreedCount);
void modifyDog(struct DOG_BREED dogBreeds[], int dogBreedCount);
void deleteCat();
void deleteDog();
#endif
