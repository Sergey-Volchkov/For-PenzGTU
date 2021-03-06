#include "qdbmp.h"
#include <stdio.h>
#include <math.h>

void
Get_pixels_Gx(const BMP *bmp, unsigned long x, unsigned long y, unsigned char *r, unsigned char *r1, unsigned char *r2,
           unsigned char *r3, unsigned char *r4, unsigned char *r5, unsigned char *g, unsigned char *b);

void
Get_pixels_Gy(const BMP *bmp, unsigned long x, unsigned long y, unsigned char *r, unsigned char *r1, unsigned char *r2,
unsigned char *r3, unsigned char *r4, unsigned char *r5, unsigned char *g, unsigned char *b);

int main(void)
{
    BMP*    bmp;
    UCHAR   r,r1,r2,r3,r4,r5, g, b;
    UINT    width, height;
    UINT    x, y;
    int Gx,Gy, Gint;

    bmp = BMP_ReadFile( "/home/argo/Desktop/For-PenzGTU/S-E-M-E-S-T-R-O-V-I-E/semestrovaya5c/lena.bmp" );
    BMP_CHECK_ERROR( stderr, -1 ); /* If an error has occurred, notify and exit */

    width = BMP_GetWidth( bmp );
    height = BMP_GetHeight( bmp );
    for ( x = 0 ; x < width-2 ; ++x )
    {
        for ( y = 0 ; y < height-2 ; ++y )
        {
            Get_pixels_Gx(bmp, x, y, &r, &r1, &r2, &r3, &r4, &r5, &g, &b);
            Gx = (r+r1+r2) - (r3+r4+r5);
            Get_pixels_Gy(bmp, x, y, &r, &r1, &r2, &r3, &r4, &r5, &g, &b);
            Gy = (r+r1+r2) - (r3+r4+r5);
            Gint = (int)(sqrt(Gx * Gx + Gy * Gy));

            BMP_SetPixelRGB( bmp, x, y, Gint, Gint, Gint);

        }
    }

    BMP_WriteFile( bmp, "/home/argo/Desktop/For-PenzGTU/S-E-M-E-S-T-R-O-V-I-E/semestrovaya5c/output.bmp");
    BMP_CHECK_ERROR( stderr, -2 );

    BMP_Free( bmp );

    return 0;
}

void
Get_pixels_Gy(const BMP *bmp, unsigned long x, unsigned long y, unsigned char *r, unsigned char *r1, unsigned char *r2,
unsigned char *r3, unsigned char *r4, unsigned char *r5, unsigned char *g, unsigned char *b) {
    BMP_GetPixelRGB(bmp, x, y + 2, r, g, b);
    BMP_GetPixelRGB(bmp, x+1, y+2, r1, g, b);
    BMP_GetPixelRGB(bmp, x+2, y+2, r2, g, b);
    BMP_GetPixelRGB(bmp, x, y, r3, g, b);
    BMP_GetPixelRGB(bmp, x+1, y, r4, g, b);
    BMP_GetPixelRGB(bmp, x+2, y, r5, g, b);
}

void
Get_pixels_Gx(const BMP *bmp, unsigned long x, unsigned long y, unsigned char *r, unsigned char *r1, unsigned char *r2,
unsigned char *r3, unsigned char *r4, unsigned char *r5, unsigned char *g, unsigned char *b) {
    BMP_GetPixelRGB(bmp, x + 2, y, r, g, b);
    BMP_GetPixelRGB(bmp, x+2, y+1, r1, g, b);
    BMP_GetPixelRGB(bmp, x+2, y+2, r2, g, b);
    BMP_GetPixelRGB(bmp, x, y, r3, g, b);
    BMP_GetPixelRGB(bmp, x, y+1, r4, g, b);
    BMP_GetPixelRGB(bmp, x, y+2, r5, g, b);
}
