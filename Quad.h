//
//  Quad.h
//  Quad
//
//  Created by Hank Lee on 11/18/15.
//  Copyright © 2015 Hank Lee. All rights reserved.
//

#ifndef Quad_h
#define Quad_h


#define WIDTH   1920
#define HEIGHT  1080


typedef struct
{
    uint8_t data[WIDTH];
} PixelRowY_t;

typedef struct
{
    uint8_t data[WIDTH / 2];
} PixelRowC_t;

void quad_u
(
        uint32_t h,
        PixelRowY_t *dst,
  const PixelRowY_t *srcTopLeft,
  const PixelRowY_t *srcTopRight,
  const PixelRowY_t *srcBotLeft,
  const PixelRowY_t *srcBotRight
);

void quad_c
(
       uint32_t h,
       PixelRowC_t *dst,
 const PixelRowC_t *srcTopLeft,
 const PixelRowC_t *srcTopRight,
 const PixelRowC_t *srcBotLeft,
 const PixelRowC_t *srcBotRight
);

#endif /* Quad_h */
