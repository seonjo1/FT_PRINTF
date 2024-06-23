# FT_PRINTF
printf() 함수의 기능을 일부분 구현한 ft_printf()를 포함한 정적 라이브러리
## 구현한 printf() 기능
- %c 를 통해 single character 출력
- %s 를 통해 string 출력
- %p 를 통해 pointer 출력
- %d 를 통해 demical number 출력
- %i 를 통해 integer in base 10 출력
- %u 를 통해 unsigned demical number 출력
- %x 를 통해 number in hexadecimal (lowercase) 출력
- %X 를 통해 number in hexadecimal (uppercase) 출력
- %% 를 통해 '%' 출력

## 구현 시 필요한 개념
- 가변인자를 통해 함수를 구현하는 법
  - va_list
  - va_start()
  - va_arg()
  - va_end()

## 사용법
```
make
```
- 정적 라이브러리 libftprintf.a 생성

```
make clean
```
- make 로 인해 만들어진 .o 파일 삭제

```
make fclean
```
- make clean + libftprintf.a 삭제
  
```
make re
```
- make fclean + make

--- 

<img width="227" alt="스크린샷 2024-06-23 오후 9 22 35" src="https://github.com/seonjo1/FT_PRINTF/assets/127729846/509a920a-8eb0-42ff-b7ab-0245cc489615">
