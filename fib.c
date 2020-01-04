#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"

typedef enum {
    up,
    right,
    down,
    left
} direction;

char* stringCato(char* s1, char* s2){
    int m = strlen(s1);
    int n = strlen(s2);
    char *ans = malloc((m + n + 1) * sizeof(char));
    if(ans == NULL){
        return NULL;
    }
    
    strcpy(ans, s1);
    strcat(ans, s2);
    return ans;
}

char* fibBuild(int n, char* u1, char* u2){
    if(n <= 1){
        return u2;
    }

    char *u3 = stringCato(u2, u1);
    return fibBuild(n - 1, u2, u3);

}

void draw(int x, int y, direction dir, int step, int w, RGB* im, RGB c)
{
#define I(i, j) im[(i)*w + j]
    int j;
    if (dir == up)
        for (j = 0; j < step; j++)
            I(x + j, y) = c;
    if (dir == down)
        for (j = 0; j < step; j++)
            I(x - j, y) = c;
    if (dir == right)
        for (j = 0; j < step; j++)
            I(x, y + j) = c;
    if (dir == left)
        for (j = 0; j < step; j++)
            I(x, y - j) = c;
#undef I
}

int fibDraw(int x, int y, int step, RGB b, RGB fc, int w, int h, RGB* image, char* d, int flag, direction dir, int count){
    
    if(*d == '\0'){
        
        return count;
        
    }
    count += 1;
    draw(x, y, dir, step, w, image, fc);
    if (dir == up){
        x += step;
        
    }
    if(dir == down){
        x -= step;
        
    }
    if(dir == right){
        y += step;
        
    }
    if(dir == left){
        y -= step;
        
    }
    if (*d == 48 && flag == 1){
        
        dir = (dir + 1) % 4;
    }
    if (*d == 48 && flag == 0){
       
        dir = (dir + 3) % 4;
    }
    
    flag = (flag + 1) % 2;
    fibDraw(x, y, step, b, fc, w, h, image, d + 1, flag, dir, count);
    
}



int fib(int n, int x, int y, int step, RGB bc, RGB fc, int w, int h, RGB* image){
    int i;

    
    for (i = 0; i < w * h; i++)
        image[i] = bc;

    
    char *f1 = "1";
    char *f2 = "0";
    
    char *f3 = stringCato(f2, f1);
    
    char *f4 = fibBuild(n - 2, f2, f3);
    
    free(f3);
    
    return fibDraw(x , y, step, bc, fc, w, h, image, f4, 1, up, 0);
    
}



