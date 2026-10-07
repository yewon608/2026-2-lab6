#pragma once
#include <iostream>



namespace KimYewon2649007{
    class student{
            int id{};
            int score{};
            char grade{};
            void testId(){
                if(id<1000000 || id>9999999){
                    std::cout<<"Invalid ID\n";
                    std::exit(1);
                }
            }
            void testScore(){
                if(score<0 || score>100){
                    std::cout<<"Invalid score\n";
                    std::exit(1);
                }
            }
            void testGrade(){
                if(grade<'A'||grade>'F'){
                    std::cout<<"Invalid grade\n";
                    std::exit(1);
                }
            }
        public:
            //constructor(생성자): 모든 멤버변수 초기화, 기본값 설정, test함수들 호출
            student(int d = 1234567, int s = 0, char g = 'F')
                :id{d}, score{s}, grade{g}{
                    testId(); testScore(); testGrade();
            }
            void input(){
                std::cout<<"Enter id: ";
                std::cin>>id; testId();
                std::cout<<"Enter score: ";
                std::cin>>score; testScore();
                std::cout<<"Enter grade: ";
                std::cin>>grade; testGrade();
            }
            friend std::istream& operator>>(std::istream& is, student& s){
                std::cout<<"Enter id: ";
                is>>s.id; s.testId();
                std::cout<<"Enter score: ";
                is>>s.score; s.testScore();
                std::cout<<"Enter grade: ";
                is>>s.grade; s.testGrade();
                return is;
            }
     


            void setID(int d){id = d; testId();}
            void setScore(int s){score = s; testScore();}
            void setGrade(int g){grade = g; testGrade();}
            //const 멤버함수
            void print() const {
                std::cout<<id<<", "<<score<<", "<<grade<<"\n";
            }
            friend std::ostream& operator<<(std::ostream& os, const student& s){
                os<<s.id<<", "<<s.score<<", "<<s.grade<<"\n";
                return os;
            }
            int getId() const {return id;}
            int getScore() const {return score;}
            char getGrade() const {return grade;}

//멘버함수로 전위증가연산자, 후위증가연산자 정의
            student operator++(){
                return student{id, ++score, grade};
            }

            student operator++(int){
                return student{id, score++, grade};
            }
//이항연산자 ==, 이항연산자 + 정의
            friend bool operator==(const student& s1, const student& s2){
                return s1.id==s2.id;
            }
            friend int operator+(const student& s1, const student& s2){
                return s1.score+s2.score;
            }
    };
}

// 1. 본인이름학번의 네임스페이스
// -본인이름학번 네임스페이스 예: 이름이 김프로이고 학번이 1234567일 경우 KimPro1234567
// using 지시자는 cpp파일에서는 영역 { block } 안에서 사용, 헤더파일엔 using 지시자는 사용하지 않고 네임스페이스 지정자를 사용합니다.
// -using 지시자 예: { using namespace std; cout << "Enter your id: "; }
// -네임스페이스 지정자 예: std::cout << "Enter your id: ";

// 2. 클래스명.h: 클래스 정의
// 1의 본인이름학번의 네임스페이스 안에 클래스를 정의하고 멤버함수들도 모두 인라인으로 구현합니다. 
// private 멤버변수 선언 (2개 이상)
// private 멤버함수 정의
// -test멤버변수1: 멤버변수1 범위가 아니면 프로그램 종료
// -test멤버변수2: 멤버변수2 범위가 아니면 프로그램 종료
// public 멤버함수 정의
// -input: 표준스트림입력으로 멤버변수들 입력, test함수들 호출
// -set 접근함수들: 멤버변수 값 설정 및 test함수 호출
// -print: 표준스트림출력으로 멤버변수들 출력
// -get 접근함수들: 멤버변수 값 리턴