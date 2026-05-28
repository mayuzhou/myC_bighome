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
    float litterScore;
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
    float coeff;
};

struct DOG_BREED{
    char name[50];
    float weight;
    float coeff;
};
void vetMenu();
void mainMenu();
void catSystem();
void dogSystem();

void addCat();

void viewCats();
void addDog();
void viewDogs();

void catHealthCalc(struct PET_CAT *cat);
void dogHealthCalc(struct PET_DOG *dog);
void manageCatBreeds();

void manageDogBreeds();

void loadCatBreeds();
void saveCatBreeds();

void loadDogBreeds();
void saveDogBreeds();

extern struct CAT_BREED catBreeds[20];
extern int catBreedCount;

extern struct DOG_BREED dogBreeds[20];
extern int dogBreedCount;
#endif
