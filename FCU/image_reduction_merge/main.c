#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void printHeader (Header header)
{
    // Print the banded_filter image file head.
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
}

void writeFile (char *filename , Header header , unsigned char *palette , unsigned char *imageData)
{
    FILE *fptr ;
    fptr = fopen(filename , "wb") ;
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
}

int main (int argc , char *argv[])
{
    FILE *fptr ;
    Header io_header ;
    unsigned char *io_palette ;
    unsigned char *io_imageData ;
    Header reduced_header ;
    unsigned char *reduced_imageData ;
    char filename[40] ;
    int rowSize , reduced_rowSize ;
    int fillings ;
    int pos , reduced_pos ;
    int pos_1 , pos_2 , pos_3 , pos_4 ;
    if (argc==1)
    {
        printf("Please enter the file name.\n") ;
        return 1;
    }
    if (argc>2)
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
    fread(&io_header.Type , 1 , 2 , fptr) ;
    fread(&io_header.Size , 4 , 1 , fptr) ;
    fread(&io_header.Reserved , 1 , 4 , fptr) ;
    fread(&io_header.OffsetBits , 4 , 1 , fptr) ;
    fread(&io_header.InfoSize , 4 , 1 , fptr) ;
    fread(&io_header.Width , 4 , 1 , fptr) ;
    fread(&io_header.Height , 4 , 1 , fptr) ;
    fread(&io_header.Planes , 2 , 1 , fptr) ;
    fread(&io_header.BitPerPixel , 2 , 1 , fptr) ;
    fread(&io_header.Compression , 4 , 1 , fptr) ;
    fread(&io_header.ImageSize , 4 , 1 , fptr) ;
    fread(&io_header.XResolution , 4 , 1 , fptr) ;
    fread(&io_header.YResolution, 4, 1, fptr) ;
    fread(&io_header.Colors , 4 , 1 , fptr) ;
    fread(&io_header.ImportantColors , 4 , 1 , fptr) ;

    io_palette = (unsigned char*) malloc(io_header.OffsetBits - io_header.InfoSize - 14) ;
    fread(io_palette , io_header.OffsetBits - io_header.InfoSize - 14 , 1 , fptr) ;

    io_imageData = (unsigned char*) malloc(io_header.ImageSize) ;
    fread(io_imageData , io_header.ImageSize , 1 , fptr) ;

    fclose(fptr) ;

    printf(">>>> File header of the input image, %s:\n\n" , strcat(strcpy(filename , argv[1]) , ".bmp")) ; // Print the file header message.
    printHeader(io_header) ;
    printf("******************************************************************\n\n") ; // Print a separate line.

    // Write header of reduced image
    reduced_header.Type[0] = 'B' ;
    reduced_header.Type[1] = 'M' ;
    reduced_header.Size = io_header.Size ;
    for (int i=0 ; i<4 ; ++i) reduced_header.Reserved[i] = io_header.Reserved[i] ;
    reduced_header.OffsetBits = io_header.OffsetBits ;
    reduced_header.InfoSize = io_header.InfoSize ;
    reduced_header.Width = ceil((float) io_header.Width / 2.0) ;
    reduced_header.Height = ceil((float) io_header.Height / 2.0) ;
    reduced_header.Planes = io_header.Planes ;
    reduced_header.BitPerPixel = io_header.BitPerPixel ;
    reduced_header.Compression = io_header.Compression ;
    reduced_header.ImageSize = ceil((float) reduced_header.Width * 3.0 / 4.0) * 4 * reduced_header.Height ;
    reduced_header.Size = io_header.Size - io_header.ImageSize + reduced_header.ImageSize ;
    reduced_header.XResolution = io_header.XResolution ;
    reduced_header.YResolution = io_header.YResolution ;
    reduced_header.Colors = io_header.Colors ;
    reduced_header.ImportantColors = io_header.ImportantColors ;
    reduced_imageData = (unsigned char*) malloc(reduced_header.ImageSize) ;
    fillings = (4 - (io_header.Width * 3) % 4) % 4 ;
    rowSize = io_header.Width * 3 + fillings ;
    fillings = (4 - (reduced_header.Width * 3) % 4) % 4 ;
    reduced_rowSize = reduced_header.Width * 3 + fillings ;
    for (int i=0 ; i<reduced_header.Height ; ++i)
    {
        for (int j=0 ; j<reduced_header.Width ; ++j)
        {
            pos = i * 2 * rowSize + j * 2 * 3 ;
            reduced_pos = i * reduced_rowSize + j * 3 ;
            reduced_imageData[reduced_pos] = io_imageData[pos] ;
            reduced_imageData[reduced_pos+1] = io_imageData[pos+1] ;
            reduced_imageData[reduced_pos+2] = io_imageData[pos+2] ;
        }
    }
    printf(">>>> File header of the reduced image, %s:\n\n" , strcat(strcat(strcpy(filename , argv[1]) , "_reduced") , ".bmp")) ; // Print the file header message.
    printHeader(reduced_header) ;
    printf("******************************************************************\n\n") ; // Print a separate line.
    writeFile(filename , reduced_header , io_palette , reduced_imageData) ;

    for (int i=0 ; i<reduced_header.Height ; ++i)
    {
        for (int j=0 ; j<reduced_header.Width ; ++j)
        {
            reduced_pos = i * reduced_rowSize + j * 3 ;
            pos_1 = (i + io_header.Height / 2) * rowSize + (io_header.Width - j - 1) * 3 ;
            pos_2 = (i + io_header.Height / 2) * rowSize + j * 3 ;
            pos_3 = (reduced_header.Height - i - 1) * rowSize + j * 3 ;
            pos_4 = (reduced_header.Height - i - 1) * rowSize + (io_header.Width - j - 1) * 3 ;
            io_imageData[pos_1] = reduced_imageData[reduced_pos] ;
            io_imageData[pos_1+1] = reduced_imageData[reduced_pos+1] ;
            io_imageData[pos_1+2] = reduced_imageData[reduced_pos+2] ;
            io_imageData[pos_2] = reduced_imageData[reduced_pos] ;
            io_imageData[pos_2+1] = reduced_imageData[reduced_pos+1] ;
            io_imageData[pos_2+2] = reduced_imageData[reduced_pos+2] ;
            io_imageData[pos_3] = reduced_imageData[reduced_pos] ;
            io_imageData[pos_3+1] = reduced_imageData[reduced_pos+1] ;
            io_imageData[pos_3+2] = reduced_imageData[reduced_pos+2] ;
            io_imageData[pos_4] = reduced_imageData[reduced_pos] ;
            io_imageData[pos_4+1] = reduced_imageData[reduced_pos+1] ;
            io_imageData[pos_4+2] = reduced_imageData[reduced_pos+2] ;
        }
    }
    printf(">>>> File header of the merged image, %s:\n\n" , strcat(strcat(strcpy(filename , argv[1]) , "_merged") , ".bmp")) ; // Print the file header message.
    printHeader(io_header) ;
    printf("******************************************************************\n\n") ; // Print a separate line.
    writeFile(filename , io_header , io_palette , io_imageData) ;

    free(io_palette) ;
    free(io_imageData) ;
    free(reduced_imageData) ;
    return 0;
}
