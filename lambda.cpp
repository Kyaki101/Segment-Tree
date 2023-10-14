#include <bits/stdc++.h>

typedef std::vector<int> lista;

void forEach(lista & values, void(*func)(int)){
    for (int value : values){
        func(value);
    }
}

int main(){
    lista values = {1, 2, 3, 4, 5, 6, 7, 8};
    forEach(values, [](int value) {std::cout << "Value: " << value << std::endl;});

}