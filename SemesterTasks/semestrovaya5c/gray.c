#include "qdbmp.h"
#include <stdio.h>

int main(void)
{
    BMP*    bmp;
    UCHAR   r, g, b;
    UINT    width, height;
    UINT    x, y;
    int values;

    bmp = BMP_ReadFile( "/home/argo/Desktop/For-PenzGTU/S-E-M-E-S-T-R-O-V-I-E/semestrovaya5c/lena.bmp" );
    BMP_CHECK_ERROR( stderr, -1 ); /* If an error has occurred, notify and exit */

    width = BMP_GetWidth( bmp );
    height = BMP_GetHeight( bmp );

    for ( x = 0 ; x < width-2 ; ++x )
    {
        for ( y = 0 ; y < height-2 ; ++y )
        {
            /* Get pixel's RGB values */
            BMP_GetPixelRGB( bmp, x, y, &r, &g, &b );
            values = (r+g+b)*0.2;
            /* Invert RGB values */
            BMP_SetPixelRGB( bmp, x, y, values, values, values);

        }
    }

    BMP_WriteFile( bmp, "/home/argo/Desktop/For-PenzGTU/S-E-M-E-S-T-R-O-V-I-E/semestrovaya5c/output.bmp");
    BMP_CHECK_ERROR( stderr, -2 );

    BMP_Free( bmp );

    return 0;
}
