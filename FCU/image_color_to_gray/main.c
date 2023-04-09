#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    // File header: 14 bytes.
    char Type[2] ; // Two fixed characters, "BM" for bitmap images.
    unsigned Size ; // File size in bytes.
    char Reserved[4] ; // Reserved field.
    unsigned OffsetBits ; // Offset, i.e., the starting address of the byte where the bitmap image data (pixel array) are stored
    // Image information: 40 bytes.
    unsigned InfoSize ; // Information size in byte.
    unsigned Width ; // Image width in pixel.
    unsigned Height ; // Image height in pixel.
    unsigned short Planes ; // Number of image planes in the image, must be 1.
    unsigned short BitPerPixel ; // Number of bits used to represent the data for each pixel.
    unsigned Compression ; // Value indicating what type of compression, if any, is used, (0: uncompressed).
    unsigned ImageSize ; // Size of the actual pixel data, in bytes.
    unsigned XResolution ; // Preferred horizontal resolution of the image, in pixels per meter.
    unsigned YResolution ; // Preferred vertical resolution of the image, in pixels per meter.
    unsigned Colors ; // Value is zero except for indexed images using fewer than the maximum number of colors.
    unsigned ImportantColors ; // Number of colors that are considered important when rendering the image.
} Header ;

int main (int argc , char *argv[])
{
    FILE *fptr ;
    Header header ;
    unsigned char *palette ;
    unsigned char *imageData ;
    int rowSize ;
    int fillings ;
    int pos ;
    if (argc==1)
    {
        printf("Please enter the file name.\n") ;
        return 1;
    }
    if (argc>3)
    {
        printf("Too many arguments.\n") ;
        return 1;
    }
    fptr = fopen(argv[1] , "rb") ;
    if (fptr==NULL)
    {
        printf("File %s doesn't exist.\n" , argv[1]) ;
        return 1;
    }
    fread(&header.Type , 1 , 2 , fptr) ;
    fread(&header.Size , 4 , 1 , fptr) ;
    fread(&header.Reserved , 1 , 4 , fptr) ;
    fread(&header.OffsetBits , 4 , 1 , fptr) ;
    fread(&header.InfoSize , 4 , 1 , fptr) ;
    fread(&header.Width , 4 , 1 , fptr) ;
    fread(&header.Height , 4 , 1 , fptr) ;
    fread(&header.Planes , 2 , 1 , fptr) ;
    fread(&header.BitPerPixel , 2 , 1 , fptr) ;
    fread(&header.Compression , 4 , 1 , fptr) ;
    fread(&header.ImageSize , 4 , 1 , fptr) ;
    fread(&header.XResolution , 4 , 1 , fptr) ;
    fread(&header.YResolution, 4, 1, fptr) ;
    fread(&header.Colors , 4 , 1 , fptr) ;
    fread(&header.ImportantColors , 4 , 1 , fptr) ;

    palette = (unsigned char*) malloc(header.OffsetBits - header.InfoSize - 14) ;
    fread(palette , header.OffsetBits - header.InfoSize - 14 , 1 , fptr) ;

    imageData = (unsigned char*) malloc(header.ImageSize) ;
    fread(imageData , header.ImageSize , 1 , fptr) ;

    fclose(fptr) ;
    fillings = (4 - (header.Width * 3) % 4) % 4 ;
    rowSize = header.Width * 3 + fillings ;
    for (int i=0 ; i<header.Height ; ++i)
    {
        for (int j=0 ; j<header.Width ; ++j)
        {
            pos = i * rowSize + j * 3 ;
            imageData[pos] = (imageData[pos] * 28 + imageData[pos+1] * 151 + imageData[pos+2] * 77) / 256 ;
            imageData[pos+1] = imageData[pos] ;
            imageData[pos+2] = imageData[pos] ;
        }
    }

    if (argc==3)
    {
        fptr = fopen(argv[2] , "wb") ;
        printf("\nThe gray-level image is \"%s\".\n\n", argv[2]) ;
    }
    else
    {
        fptr = fopen("grey_level.bmp" , "wb") ;
        printf("\nThe gray-level image is \"gray_level.bmp\".\n\n");
    }
    fwrite(&header.Type , 1 , 2 , fptr) ;
    fwrite(&header.Size , 4 , 1 , fptr) ;
    fwrite(&header.Reserved , 1 , 4 , fptr) ;
    fwrite(&header.OffsetBits , 4 , 1 , fptr) ;
    fwrite(&header.InfoSize , 4 , 1 , fptr) ;
    fwrite(&header.Width , 4 , 1 , fptr) ;
    fwrite(&header.Height , 4 , 1 , fptr) ;
    fwrite(&header.Planes , 2 , 1 , fptr) ;
    fwrite(&header.BitPerPixel , 2 , 1 , fptr) ;
    fwrite(&header.Compression , 4 , 1 , fptr) ;
    fwrite(&header.ImageSize , 4 , 1 , fptr) ;
    fwrite(&header.XResolution , 4 , 1 , fptr) ;
    fwrite(&header.YResolution, 4, 1, fptr) ;
    fwrite(&header.Colors , 4 , 1 , fptr) ;
    fwrite(&header.ImportantColors , 4 , 1 , fptr) ;
    fwrite(palette , header.OffsetBits - header.InfoSize - 14 , 1 , fptr) ;
    fwrite(imageData , header.ImageSize , 1 , fptr) ;
    fclose(fptr) ;

    // Print the gray-level image file head.
    printf("Type:             %c%c\n", header.Type[0], header.Type[1]); // Two fixed characters, "BM".
    printf("Size:             %u\n", header.Size); // File size in bytes.
    printf("Resserved:        %c%c%c%c\n", header.Reserved[0], header.Reserved[1],
           header.Reserved[2], header.Reserved[3]); // Reserved field.
    printf("OffsetBits:       %u\n", header.OffsetBits); // Offset.
    printf("InfoSize:         %u\n", header.InfoSize); // Information size in byte.
    printf("Width:            %u\n", header.Width); // Image width in pixel.
    printf("Height:           %u\n", header.Height); // Image height in pixel.
    printf("Planes:           %d\n", header.Planes); // Number of image planes in the image, must be 1.
    printf("BitPerPixel:      %d\n", header.BitPerPixel); // Number of bits used to represent the data for each pixel.
    printf("Compression:      %u\n", header.Compression); // Value indicating what type of compression.
    printf("ImageSize:        %u\n", header.ImageSize); // Size of the actual pixel data, in bytes.
    // Preferred horizontal resolution of the image, in pixels per meter.
    printf("XResolution:      %u\n", header.XResolution);
    // Preferred vertical resolution of the image, in pixels per meter.
    printf("YResolution:      %u\n", header.YResolution);
    // Value is zero except for indexed images using fewer than the maximum number of colors.
    printf("Colors:           %u\n", header.Colors);
    // Number of colors that are considered important when rendering the image.
    printf("ImportantColors:  %u\n", header.ImportantColors);
    /* End of output commands */

    free(palette) ;
    free(imageData) ;
    return 0;
}
