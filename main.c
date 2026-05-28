#include"head.h"
#include<windows.h>

int main(){
    SetConsoleOutputCP(936);
    loadCatBreeds();
    loadDogBreeds();
    vetMenu();
    
    return 0;
}
