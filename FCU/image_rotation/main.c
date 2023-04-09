#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define swap(a , b) temp = a ; a = b ; b = temp

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

typedef struct
{
    Header header ;
    unsigned char *palette ;
    unsigned char *imageData ;
} Image ;

void readImage (Image *image , char *filename)
{
    FILE *fptr ;
    fptr = fopen(filename , "rb") ;
    if (fptr==NULL)
    {
        printf("File %s doesn't exist.\n" , filename) ;
        return ;
    }
    fread(&image->header.Type , 1 , 2 , fptr) ;
    fread(&image->header.Size , 4 , 1 , fptr) ;
    fread(&image->header.Reserved , 1 , 4 , fptr) ;
    fread(&image->header.OffsetBits , 4 , 1 , fptr) ;
    fread(&image->header.InfoSize , 4 , 1 , fptr) ;
    fread(&image->header.Width , 4 , 1 , fptr) ;
    fread(&image->header.Height , 4 , 1 , fptr) ;
    fread(&image->header.Planes , 2 , 1 , fptr) ;
    fread(&image->header.BitPerPixel , 2 , 1 , fptr) ;
    fread(&image->header.Compression , 4 , 1 , fptr) ;
    fread(&image->header.ImageSize , 4 , 1 , fptr) ;
    fread(&image->header.XResolution , 4 , 1 , fptr) ;
    fread(&image->header.YResolution, 4, 1, fptr) ;
    fread(&image->header.Colors , 4 , 1 , fptr) ;
    fread(&image->header.ImportantColors , 4 , 1 , fptr) ;
    image->palette = (unsigned char*) malloc(image->header.OffsetBits - image->header.InfoSize - 14) ;
    fread(image->palette , image->header.OffsetBits - image->header.InfoSize - 14 , 1 , fptr) ;
    image->imageData = (unsigned char*) malloc(image->header.ImageSize) ;
    fread(image->imageData , image->header.ImageSize , 1 , fptr) ;
    fclose(fptr) ;
}

void printImageHeader (Image image)
{
    // Print the gray-level image file head.
    printf("Type:             %c%c\n", image.header.Type[0], image.header.Type[1]); // Two fixed characters, "BM".
    printf("Size:             %u\n", image.header.Size); // File size in bytes.
    printf("Resserved:        %c%c%c%c\n", image.header.Reserved[0], image.header.Reserved[1],
           image.header.Reserved[2], image.header.Reserved[3]); // Reserved field.
    printf("OffsetBits:       %u\n", image.header.OffsetBits); // Offset.
    printf("InfoSize:         %u\n", image.header.InfoSize); // Information size in byte.
    printf("Width:            %u\n", image.header.Width); // Image width in pixel.
    printf("Height:           %u\n", image.header.Height); // Image height in pixel.
    printf("Planes:           %d\n", image.header.Planes); // Number of image planes in the image, must be 1.
    printf("BitPerPixel:      %d\n", image.header.BitPerPixel); // Number of bits used to represent the data for each pixel.
    printf("Compression:      %u\n", image.header.Compression); // Value indicating what type of compression.
    printf("ImageSize:        %u\n", image.header.ImageSize); // Size of the actual pixel data, in bytes.
    // Preferred horizontal resolution of the image, in pixels per meter.
    printf("XResolution:      %u\n", image.header.XResolution);
    // Preferred vertical resolution of the image, in pixels per meter.
    printf("YResolution:      %u\n", image.header.YResolution);
    // Value is zero except for indexed images using fewer than the maximum number of colors.
    printf("Colors:           %u\n", image.header.Colors);
    // Number of colors that are considered important when rendering the image.
    printf("ImportantColors:  %u\n", image.header.ImportantColors);
    /* End of output commands */
}

void writeImage (Image image , char *filename)
{
    printf("\nThe rotation image is \"%s\".\n\n" , filename) ;
    FILE *fptr ;
    fptr = fopen(filename , "wb") ;
    fwrite(&image.header.Type , 1 , 2 , fptr) ;
    fwrite(&image.header.Size , 4 , 1 , fptr) ;
    fwrite(&image.header.Reserved , 1 , 4 , fptr) ;
    fwrite(&image.header.OffsetBits , 4 , 1 , fptr) ;
    fwrite(&image.header.InfoSize , 4 , 1 , fptr) ;
    fwrite(&image.header.Width , 4 , 1 , fptr) ;
    fwrite(&image.header.Height , 4 , 1 , fptr) ;
    fwrite(&image.header.Planes , 2 , 1 , fptr) ;
    fwrite(&image.header.BitPerPixel , 2 , 1 , fptr) ;
    fwrite(&image.header.Compression , 4 , 1 , fptr) ;
    fwrite(&image.header.ImageSize , 4 , 1 , fptr) ;
    fwrite(&image.header.XResolution , 4 , 1 , fptr) ;
    fwrite(&image.header.YResolution, 4, 1, fptr) ;
    fwrite(&image.header.Colors , 4 , 1 , fptr) ;
    fwrite(&image.header.ImportantColors , 4 , 1 , fptr) ;
    fwrite(image.palette , 1 , image.header.OffsetBits - image.header.InfoSize - 14 , fptr) ;
    fwrite(image.imageData , 1 , image.header.ImageSize , fptr) ;
    fclose(fptr) ;
    printImageHeader(image) ;
}

Image rotateImage (Image image)
{
    unsigned char *imageData ;
    int temp , fillings ;
    Header header = image.header ;
    unsigned imageSize = ceil((float) header.Height * 3.0 / 4.0) * 4 * header.Width ;
    unsigned size = header.Size - header.ImageSize + imageSize ;
    swap(header.Width , header.Height) ;
    header.ImageSize = imageSize ;
    header.Size = size ;
    int pos , rotate_pos ;
    int rowSize , rotate_rowSize ;
    fillings = (4 - (header.Width * 3) % 4) % 4 ;
    rotate_rowSize = header.Width * 3 + fillings ;
    fillings = (4 - (image.header.Width * 3) % 4) % 4 ;
    rowSize = image.header.Width * 3 + fillings ;
    imageData = (unsigned char*) malloc(header.ImageSize) ;
    for (int i=0 ; i<image.header.Height ; ++i)
    {
        for (int j=0 ; j<image.header.Width ; ++j)
        {
            pos = i * rowSize + j * 3 ;
            rotate_pos = (header.Height - j - 1) * rotate_rowSize + i * 3 ;
            imageData[rotate_pos] = image.imageData[pos] ;
            imageData[rotate_pos+1] = image.imageData[pos+1] ;
            imageData[rotate_pos+2] = image.imageData[pos+2] ;
        }
    }
    free(image.imageData) ;
    image.header = header ;
    image.imageData = imageData ;
    return image ;
}

int main (int argc , char *argv[])
{
    FILE *fptr ;
    Image image ;
    int rowSize ;
    int fillings ;
    int pos , rotate ;
    char *filename ;
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
    readImage(&image , argv[1]) ;
    do
    {
        printf("Enter the parament of rotation between 0 and 3: ") ;
        scanf("%d" , &rotate) ;
    }
    while (rotate<0 || rotate>3) ;
    for (int i=0 ; i<rotate ; ++i)
    {
        image = rotateImage(image) ;
    }

    if (argc==3) filename = argv[2] ;
    else filename = "rotate.bmp" ;

    writeImage(image , filename) ;
    free(image.palette) ;
    free(image.imageData) ;
    return 0;
}
