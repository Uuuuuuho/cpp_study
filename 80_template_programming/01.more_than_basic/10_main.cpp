#include "10_square.h"

int main() {

    /* 컴파일 타임에 int와 double에 대한 함수를 생성해야한다. 
     * 그런데 template은 그게 안됨. 
     * Template의 코딩 관례
     * => 함수 템플릿의 "구현부를 헤더 파일에 포함"     
     * 헤더 파일과 구현의 분리를 하려면 template specialization을 사용하면 됨.
     */
    square(3);
    square(3.3);
}