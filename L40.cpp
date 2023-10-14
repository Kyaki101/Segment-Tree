#include <bits/stdc++.h>
#include "fenwick.cpp"


void show(lista & test){
    for(ll i : test){
        std::cout<< i << " ";
    }
    std::cout << '\n';
}

int main(){
    int n, q;

    int ppl;

    char consult;

    int a;

    int b;

    std::cin >> n >> q;

    ll apartment[n];

    lista segmented;

    for(int i = 0; i < n; i ++){
        std::cin >> apartment[i];
    }

    segmentation(apartment, n, lambda, segmented);

    // show(segmented);

    for(int i = 0; i < q; i ++){

        // show(segmented);
        
        std::cin >> consult >> a >> b;

        if(consult == 'u')updateAdd(a - 1, b, segmented, n);
        else std::cout << sumRange(a - 1, b - 1, segmented, 0, n - 1, 0) << std::endl;
    }
}