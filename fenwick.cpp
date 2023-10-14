#include <bits/stdc++.h>
#define LEFT(i) 2 * i + 1;
#define RIGHT(i) 2 * i + 2;

typedef std::vector<long long int> lista;
typedef long long int ll;

auto lambda = [](int n) {
        if(!(n &(n-1)))return n;
        if (n <= 1) {
            return 1;
        }
        int msbPos = 0;
        while (n > 0) {
            n >>= 1;
            msbPos++;
        }
        return 1 << msbPos;
    };

void coalesence(ll * array, lista & segTree, int low, int high, int pos){
    if(low == high){
        segTree[pos] = array[low]; 
        return;
    }
    int mid = (low + high) / 2;
    coalesence(array, segTree, low, mid, 2 * pos + 1);
    coalesence(array, segTree, mid + 1, high, 2 * pos + 2);
    segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
}

void segmentation(ll * array, int size, int(*nearPot)(int), lista & mod){
    int vecSize = nearPot(size) * 2 - 1;

    lista segmented(vecSize, 0);

    coalesence(array, segmented, 0, size - 1, 0);

    mod = segmented;

}

auto noOverlap = [](int a, int b, int low, int high){
    if(a > high || low > b){
        return true;
    }
    return false;
};

auto totalOverlap = [](int a, int b, int low, int high){
    if(low >= a && high <= b){
        return true;
    }
    return false;
};



ll sumRange(int a, int b, lista & segmentTree, int low, int high, int pos){
    if(noOverlap(a, b, low, high)){
        return (0);
    }
    if(totalOverlap(a, b, low, high)){
        return segmentTree[pos];
    }

    int mid = (high + low)/2;
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    return sumRange(a, b, segmentTree, low, mid, left) + sumRange(a, b, segmentTree, mid + 1, high, right);
}

int deep(int a, int b, lista & segmentTree, int low, int high, int pos){
    if(noOverlap(a, b, low, high)){
        return 0;
    }
    if(totalOverlap(a, b, low, high)){
        return pos;
    }

    int mid = (high + low)/2;
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    return deep(a, b, segmentTree, low, mid, left) + deep(a, b, segmentTree, mid + 1, high, right);
}



void update(int index, int value, lista & segTree, int size){
    index = deep(index, index, segTree, 0, size - 1, 0);
    segTree[index] = value;
    std::function<void(int)> climb = [&](int index){
        segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
        if(!index)return;
        climb((index - 1)/2);
    };
    climb((index - 1) / 2);
}

void updateAdd(int index, ll value, lista & segTree, ll size){
    index = deep(index, index, segTree, 0, size - 1, 0);
    segTree[index] += value;
    std::function<void(int)> climb = [&](int index){
        segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
        if(!index)return;
        climb((index - 1)/2);
    };
    climb((index - 1) / 2);
}

// int main(){
//     ll test[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

//     int size = sizeof(test)/sizeof(test[0]);

//     lista seg;

//     segmentation(test, size, lambda, seg);

//     for(int i : seg){
//         std::cout << i << " ";
//     }
//     std::cout << std::endl;

//     std::cout << sumRange(1, 2, seg, 0, size - 1, 0) << std::endl;

//     updateAdd(0, 9, seg, size);


//     for(int i : seg){
//         std::cout << i << " ";
//     }

//     std::cout << std::endl;

//     std::cout << sumRange(0, 2, seg, 0, size - 1, 0) << std::endl;



    
// }
