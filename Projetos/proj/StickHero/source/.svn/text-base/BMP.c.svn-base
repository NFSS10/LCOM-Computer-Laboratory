#include "BMP.h"


Imagem* LoadBitmapFile(const char* nome_ficheiro)
 {
    FILE *fPtr;

    //Abre o ficheiro em modo binario

    fPtr = fopen(nome_ficheiro, "rb");
    if (fPtr == NULL)
        return NULL;

    //////////////////////////////////////////////////////////////////////////////////
    //File Header
    /////////////////////////////////////////////////////////////////////////////////
    //Le o file header
    BMP_File_Header file_header;
    fread(&file_header, 2, 1, fPtr);

    //Verifica assinatura
    if (file_header.assinatura != BMP_ASSINATURA)
    {
        fclose(fPtr);
        return NULL;
    }

    int rd;
    do
    {
    	rd = fread(&file_header.tamanho, 4, 1, fPtr);
        if ( rd != 1)
            break;

        rd = fread(&file_header.reservado, 4, 1, fPtr);
        if (rd != 1)
            break;

        (rd = fread(&file_header.offset, 4, 1, fPtr));
        if (rd != 1)
            break;
    }
    while (0);

    if (rd = !1)
    {
        fprintf(stderr, "Erro no ficheiro \n");
        exit(-1);
    }
    //////////////////////////////////////////////////////////////////////////////



    /////////////////////////////////////////////////////////////////////////////
    //Info Header
    ////////////////////////////////////////////////////////////////////////////
    //Le o info Header

    BMP_Info_Header info_header;
    fread(&info_header, sizeof(BMP_Info_Header), 1, fPtr);
    ////////////////////////////////////////////////////////////////////////////


    /////////////////////////////////////////////////////////////////////////////
    //Le data da imagem
    ////////////////////////////////////////////////////////////////////////////
    fseek(fPtr, file_header.offset, SEEK_SET);

    //reservar memoria para a imagem
    unsigned char* BMP_data = (unsigned char*) malloc(info_header.tamanho);

    //verifica alocacao de memoria
    if (BMP_data == NULL)
    {
        free(BMP_data);
        fclose(fPtr);
        return NULL;
    }

    //passa a data
    fread(BMP_data, info_header.tamanho, 1, fPtr);

    // make sure bitmap image data was read
    if (BMP_data == NULL)
    {
        fclose(fPtr);
        return NULL;
    }


    fclose(fPtr);

    Imagem* img = (Imagem*) malloc(sizeof(Imagem));
    img->Data = BMP_data;
    img->BMP_info = info_header;

    return img;
}

void apagaImagem(Imagem* img)
{
	free(img->Data);
	free(img);
}
