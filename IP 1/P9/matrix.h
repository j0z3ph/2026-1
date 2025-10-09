/**
 * @file matrix.h
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Archivo de encabezado de la bibliotea matrix
 * @version 0.1
 * @date 2025-10-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include<stdbool.h>

/// @brief Calcula el determinante de cualquier matriz de 3x3
/// @param matrix La matriz
/// @return El determinante
int determinante(int matrix[3][3]);

/// @brief Calcula la traspuesta de cualquier matriz de 3x3
/// @param matrix La matriz
/// @param tras La traspuesta
void traspuesta(int matrix[3][3], int tras[3][3]);

void adjunta(int matrix[3][3], int adj[3][3]);

bool inversa(int matrix[3][3], float inv[3][3]);

void imprime(float matrix[3][3]);

#endif