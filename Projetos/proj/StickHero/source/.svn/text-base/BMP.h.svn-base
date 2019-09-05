#ifndef BMP_H_
#define BMP_H_

#include "macros.h"
#include "stdio.h"

typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef int LONG;


//Baseado em:
// http://stackoverflow.com/questions/14279242/read-bitmap-file-into-structure e http://difusal.blogspot.pt/2014/09/minixtutorial-8-loading-bmp-images.html

//Um BMP tem dois Header um File Header com informacao do ficheiro e um Info Header com informacao da imagem
//	e depois e que tem as informacoes propriamente ditas dos pixeis
//(na wikipedia tem uma imagem onde se ve facilmente a estrutura de um bitmap)


typedef struct {
	WORD assinatura;  /**< @brief Assinatura do BMP */
	DWORD tamanho;  /**< @brief Tamanho do ficheiro em bytes */
	DWORD reservado;  /**< @brief Reservado tem de ser 0 */
	DWORD offset;  /**< @brief Offset em bytes from the bitmapfileheader to the bitmap */
} BMP_File_Header;

typedef struct {
	DWORD tamanho_header; /**< @brief Tamanho da Info_Header */
	LONG largura; /**< @brief Largura da imagem */
	LONG altura; /**< @brief Altura da imagem */
    WORD planes; /**< @brief Especifica o numero de planos de cores */
    WORD bits_por_pixel; /**< @brief Numero de bits por pixel */
    DWORD compressao; /**< @brief Tipo de compressao */
    DWORD tamanho; /**< @brief Tamanho da imagem em bytes */
    LONG x_pixeis; /**< @brief Numero de pixeis por metro em x */
    LONG y_pixeis; /**< @brief Numero de pixeis por metro em y */
    DWORD num_cores; /**< @brief Numero de cores*/
    DWORD num_cores_imp; /**< @brief Numero de cores importantes */
} BMP_Info_Header;


typedef struct
{
    BMP_Info_Header BMP_info; /**< @brief Struct com a informacao do BMP */
    unsigned char* Data; /**< @brief A informacao de onde se guarda a imagem */
} Imagem;


/**
 * @brief Le uma imagem e guarda toda a informacao da imagem em BMP numa struct Imagem alocada.
 *
 * @param filename o diretorio e o nome da imagem que se quer abrir.
 * @return Uma struct com a informacao da imagem.
 */
Imagem* LoadBitmapFile(const char* filename);

/**
 * @brief Apaga uma struct de imagem que foi alocado anteriormente.
 *
 *	@param img a struct de imagem que queremos apagar da memoria.
 * @return void.
 */
void apagaImagem(Imagem* img);

#endif
