#include <bits/stdc++.h>
#include "segment.cpp"

void show(lista & sh){
    for(int i : sh){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main(){
    int stars, queries;
    std::cin >> stars >> queries;

    ll atlas[stars];

    std::string input;

    int a, b;

    lista segMin;
    lista segMax;

    for(int i = 0; i < stars; i ++){
        std::cin >> atlas[i];
    }

    segmentation(atlas, stars, lambda, segMin);
    segmentationMax(atlas, stars, lambda, segMax);

    for(int i = 0; i < queries; i ++){
        std::cin >> input >> a >> b;
        if(input == "MAX"){
            std::cout << maxRange(a - 1, b - 1, segMax, 0, stars - 1, 0) << std::endl;
        }
        else if(input == "MIN"){
            std::cout << minRange(a - 1, b - 1, segMin, 0, stars - 1, 0) << std::endl;
        }
        else{update(a - 1, b, segMin, stars); updateMax(a - 1, b, segMax, stars);}
    }

    

}