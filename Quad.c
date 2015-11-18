//
//  Quad.c
//  Quad
//
//  Created by Hank Lee on 11/18/15.
//  Copyright (c) 2015 Hank Lee. All rights reserved.
//

#include <stdint.h>

#include "Quad.h"

void quad_u
(
        uint32_t h,
        PixelRowY_t *dst,
  const PixelRowY_t *srcTopLeft,
  const PixelRowY_t *srcTopRight,
  const PixelRowY_t *srcBotLeft,
  const PixelRowY_t *srcBotRight
)
{
    int i;
    for (i = 0; i < h; i++)
    {
        *dst = *srcTopLeft;
        dst++;
        srcTopLeft++;
        
        *dst = *srcTopRight;
        dst++;
        srcTopRight++;
    }
    for (i = 0; i < h; i++)
    {
        *dst = *srcBotLeft;
        dst++;
        srcBotLeft++;
        
        *dst = *srcBotRight;
        dst++;
        srcBotRight++;
    }
}

void quad_c
(
        uint32_t h,
        PixelRowC_t *dst,
  const PixelRowC_t *srcTopLeft,
  const PixelRowC_t *srcTopRight,
  const PixelRowC_t *srcBotLeft,
  const PixelRowC_t *srcBotRight
)
{
    int i;
    for (i = 0; i < h; i++)
    {
        *dst = *srcTopLeft;
        dst++;
        srcTopLeft++;
        
        *dst = *srcTopRight;
        dst++;
        srcTopRight++;
    }
    for (i = 0; i < h; i++)
    {
        *dst = *srcBotLeft;
        dst++;
        srcBotLeft++;
        
        *dst = *srcBotRight;
        dst++;
        srcBotRight++;
    }
}
