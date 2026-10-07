#include "student.h"
#include <array>

namespace KimYewon2649007{
    void printStudentStatus(const student a[], const int n){
        for(int i=0; i<n; i++){
            std::cout<<a[i];
        }
    }
}


int main(){
    using namespace KimYewon2649007;

    const int n = 4;
    student a[n];
    a[0] = student{"yewon", 2649007, 100, 'A'};
    a[1].setName("Kim"); a[1].setID(1234567); a[1].setScore(89); a[1].setGrade('B');
    a[2].input();
    std::cin>>a[3];
    printStudentStatus(a, n);

    std::array<student, n> arr;
    for(int i=0; i<arr.size(); i++){
        arr.at(i) = a[i];
    }
    for(const auto& arri : arr){
        arri.print();
    }

    return 0;
}