#ifndef GRID_H
#define GRID_H

#include "SimTypes.h"
#include "Cell.h"
#include <utility>
#include <map>

#define MAX_CELLS 2566
#define NUM_FOUNDERS 1


using namespace std;

namespace SimEco
{
	class Grid{


	 public:
		
		Specie *species;
		uint speciesSize;
		
		//static Cell *cells;
		static int cellsSize;

		static Connectivity *connectivityMatrix;   //matriz esparça compactada ( ver CUsparse)
		static  MatIdx_2D *indexMatrix;
		static map<uint, uint> mapLine_to_Compact_Idx;	//mapeia indice de linha (normal) para o indice na matriz compactada
		//troquei int por u_int, pois 50k x 50k dá um valor maior que MAX_INT, mas unsinged int aguenta
		static u_int matrixSize;


		constexpr static float connThreshold = 0.1f;

		Grid(uint num_cells, uint num_especies);
		~Grid();    
		void setCells(Cell celulas[], size_t size);    //seta as celulas
		void setCellsConnectivity(Connectivity *adjMatrix, size_t size);    //passa a matriz de adjacencia, e lá dentro compacta ela

		void setFounders(Specie sp[], size_t sp_num);
		void addCell(const Cell &novaCelula);
		void addCells(const array<Cell, MAX_CELLS> &novasCelulas);    //pega o vector novasCelulas e copia/passa os elementos para a Grid


		Cell* getCellat(uint index);

		//lê a serie climatica das celulas, e retorna o número de celulas lidas
		static int load_CellsClimate(FILE *minTemp_src, FILE *maxTemp_src, FILE *minPptn_src, FILE *maxPptn_src, FILE *NPP_src,
								size_t timeSteps);

		//lê a conectividade de todas as celulas, e retorna o número de celulas lidas
		static int load_CellsConnectivity(FILE *geo_src, FILE *topo_src, FILE *rivers_src);
	};
}

#endif