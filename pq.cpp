#include <bits/stdc++.h>


typedef std::priority_queue<int> pq;
std::vector<std::vector<std::string> > people(100000);



int main(){

    auto quitar = [&](int index){
        people[index].erase(people[index].begin());
    };
    int priority;

    std::string name;

    pq priorityQ;

    while(std::cin >> name){
        if(name == "V"){
            if(!priorityQ.empty()){
                int number = priorityQ.top() ;
                priorityQ.pop();
                std::cout << people[number][0] << std::endl;
                quitar(number);
            }
            else std::cout<<std::endl;
        }
        else{
            std::cin >> priority;
            priorityQ.emplace(priority);
            people[priority].push_back(name);
        }
    }
}