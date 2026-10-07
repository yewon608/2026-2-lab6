#pragma once
#include "student.h"

namespace KimYewon2649007{
    class studentStatus{
        student s;
        bool status;
    public:
    // -생성자: 모든 멤버변수 초기화, 기본값 설정
    // -print: 표준스트림출력으로 멤버변수들 출력
    // -클래스1형 객체의 접근함수를 참조형식으로 구현
        studentStatus (student s0 = student{1234567,0,'F'}, bool st = false)
            :s{s0}, status{st}
            {}
        void print() const {
            s.print();
            if (status) std::cout<<" on school\n";
            else std::cout<<" Not on school\n";
        }
        const student& getStudent() const{return s;}
        void setStudent(const student& s0){s=s0;}
    };
}