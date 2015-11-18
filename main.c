//
//  main.c
//  Quad
//
//  Created by Hank Lee on 11/17/15.
//  Copyright © 2015 Hank Lee. All rights reserved.
//

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>

#include "Quad.h"

static uint8_t ImgY[WIDTH * HEIGHT];
static uint8_t ImgU[WIDTH * HEIGHT / 4];
static uint8_t ImgV[WIDTH * HEIGHT / 4];
static uint8_t QuadY[2 * WIDTH * 2 *  HEIGHT];
static uint8_t QuadU[WIDTH * HEIGHT];
static uint8_t QuadV[WIDTH * HEIGHT];

int main(int argc, const char * argv[]) {
    int fd_rd;
    int fd_wr;
    
    int w;
    int h;

    if (argc < 2)
    {
        fprintf(stderr, "useage: %s [input_file]\n", argv[0]);
        
        return -1;
    }
    
    fd_rd = open(argv[1], O_RDONLY);
    if (fd_rd < 0)
    {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }
    fd_wr = open("quad.yuv",
                 O_WRONLY | O_CREAT | O_TRUNC,
                 S_IRUSR);
    
    w = WIDTH;
    h = HEIGHT;
    
    read(fd_rd, ImgY, sizeof(ImgY));
    read(fd_rd, ImgU, sizeof(ImgU));
    read(fd_rd, ImgV, sizeof(ImgV));
    
    
    quad_u
    (
        h,
        (PixelRowY_t *) QuadY,
        (PixelRowY_t *) ImgY,
        (PixelRowY_t *) ImgY,
        (PixelRowY_t *) ImgY,
        (PixelRowY_t *) ImgY
    );
    
    
    
    quad_c
    (
        h / 2,
        (PixelRowC_t *) QuadU,
        (PixelRowC_t *) ImgU,
        (PixelRowC_t *) ImgU,
        (PixelRowC_t *) ImgU,
        (PixelRowC_t *) ImgU
    );
    
    
    quad_c
    (
        h / 2,
        (PixelRowC_t *) QuadV,
        (PixelRowC_t *) ImgV,
        (PixelRowC_t *) ImgV,
        (PixelRowC_t *) ImgV,
        (PixelRowC_t *) ImgV
    );
    
    
    write(fd_wr, QuadY, sizeof(QuadY));
    write(fd_wr, QuadU, sizeof(QuadU));
    write(fd_wr, QuadV, sizeof(QuadV));
    
    close(fd_rd);
    close(fd_wr);
    
    return 0;
}
