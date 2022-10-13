


/*
Program name : BSQ
Turn in files : Makefile and all the necessary files
Makefile : Yes
Arguments : File(s) in which to read the square
External functs : 

open - 파일을 연다 open files and directories //// int open(const char* pathname, int flags[,mode_t mode]);
close - 파일을 닫는다 delete a descriptor /////// int close(int fd);
read - 파일을 읽는다 ssize_t read(int fd, void* buf, size_t nbytes); 
write - 파일을 읽는다 ssize_t write(int fd, const void* buf, size_t nbytes);
malloc - memory allocation, malloc(size_t size);
free - deallocates the memory allocation pointed yto by ptr. 
exit - Shell bulitin commands are commands that can be executed within 
the running shell's process. 



파일을 열고 난 후에 데이터를 쓰거나 읽어올 때는 read와 write 함수를 사용합니다. 



Libft authorized : Not applicable

description : 
Write a program 
that draws 
and print 
the biggest possible square 
in the given area. 

1) 주어진 영역 안에서 만들 수 있는 
2) 가장 큰 
3) 사각형을 
4) 그리고 
5) 프린트하는
6) 프로그램을 작성하세요 


- 프로젝트 목표: 
The aim of this project is 
to find 
the biggest square 
on a map, 
avoiding obstacles.
장애물을 피해
지도에서 
가장 큰 
사각형을 
찾기 


A file containing the map will be provided. 
It'll have to be passed as an argument for your program. 


- 프로그램 목표 : 
The aim of the program is 
to replace 
;"empty" characters 
by '" full characters'
in order to represent 
the biggest square possible. 

가능한 가장 큰 사각형을 만들기 위해 
'"빈' 문자'를 
'"차 있는" 문자'로 
교체


- 하나 이상의 방법이 존재할 경우 : 
In the case that more than one solution exists, 
we'll choose to represent the square that's closest to the top of the map
then the one that's most to the left. 

지도의 상단 및 왼쪽에 
가장 가까운
사각형을 
선택


Your program must handle 1 to n files as parameters. 

 - 프로그램이 인자에 하나 이상의 지도를 받은 경우 :
 When your program receives more than one map in argument, 
 each solution or map error 
 must be followed by a line break. 
 각 해결 방법 
 또는 지도 오류 
 다음에
 줄바꿈


 - 전달된 인자가 없는 경우 : 
 Should there be no passed arguments, 
 your program must be able to read on the standard input. 
 표준 입력을 바탕으로 
 읽을 수 있어야


You should have a valid Makefile that'll compile your project. 
Your Makefile musn't relink. 
- 유효한 makefile 이 
반드시 있어야
relink 되어서는 안 된다. 


- 프로그램은 
1 n 개의 파일을 
매개변수로 
처리해야 한다


Definition of a valid map
- 유효한 지도의 정의 : 
All lines must have the same length
1) 모든 행의 길이가 
같아야

2) 최소 한 개의 상자에 
최소한 한 개의 행이 있어야

At each end of line, 
there's a line break. 
3)  행의 양쪽 끝에는 
각각 줄바꿈이 있어야

The characters on the map can only be 
those introduced in the first line. 
4) 지도의 문자는 
첫 번째 행에서 등장한 문자만
나올 수 있다

The map is invalid if a character is missing from the first line, 
or if two characters (of empty, full and obstacle) are identical. 
5) 첫 번째 행에 어떤 문자가 없거나
두 개의 문자 (빈 문자, 차 있는 문자, 장애물 문자)가 동일한 경우
지도는 유효하지 않다. 

The characters can be any printable character, 
even numbers. 
6) 출력 가능한 모든 문자가
문자가 될 수 있다. 
숫자도 가능하다. 

In case of an invalid map, 
your program should display map error on the error output
followed by a line break. 
Your program will then move on to the next map. 

7) 지도가 유효하지 않을 경우
프로그램은 오류 출력값에 
지도 오류를 표시
줄바꿈이 되어야
그러고서 다음 지도로 넘어간다





The first line of te map contains information on how to read the map: 
- 지도의 첫 번째 행 : 지도를 읽는 방법에 대한 정보들
The number of lines on the map
* 지도에 있는 줄의 수;
The "empty" character
* "빈" 문자;
The "obstacle" character;
* "장애물" 문자;
The "full" character.
* "차 있는" 문자;



The map is made up of '"empty' characters' 
lines and ;
'obstacle" characters.'
지도는 
'"빈" 문자,
 줄과 '
"장애물' 문자' 줄로 구성되어 있습니다.




EXAMPLE
It is a square indeed. 
Even thour it might not look lit it visually. 
안 그래 보이지만 사각형입니다. 


Perl map generator. 

#!/usr/bin/perl

use warnings;
use strict;

die "program x y density" unless (scalar(ARGV) == 3);

my ($x, $y, $density) = ARGV;

print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
    if (int(rand($y) * 2) < $density) {
        print "o";
    } else {
        print ".";
        }
    }
    print "\n";
}
*/

