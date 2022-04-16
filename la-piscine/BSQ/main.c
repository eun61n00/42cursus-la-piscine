#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int check_map(map)
{
    return (1);

}

int main(int argc, char **argv)
{
    int     fd;
    char    c;
    int     i;
    int     j;
    int     row_num;
    int     col_num;
    int     new_line_cnt;
    char    **map;

    j = 1;
    new_line_cnt = 0;
    while (j < argc) //argc의 개수만큼 맵 입력 받아 체크하고 sol 출력하기
    {
        fd = open(argv[j], O_RDONLY);
        read(fd, &c, 1);
        row_num = c - '0';
        printf("row_num: $d\n", row_num);
        //check_map(map);
        
        while (new_line_cnt <= 1) //new line이 2개 나올 때까지
        {
            if (c == '\n')
                new_line_cnt++;
            col_num++; //column num ++;
        }
        col_num -= 5; //정보주는 5글자 빼주기

        map = (char **)malloc(sizeof(char*) * (row_num));
        if (map == 0)
            return (0);
        fd = open(argv[j], O_RDONLY);
        i = 0;
        while (i <= row_num)
        {
            char *arr;
            arr = (char *)malloc(sizeof(char) * col_num + 1);
            if (!arr)
                return (0);
            read(fd, arr, col_num + 1);
            arr[col_num] = 0;
            map[j] = arr;
        }
    }
}