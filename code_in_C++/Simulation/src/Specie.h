#ifndef SPECIE_H
#define SPECIE_H

#include "SimTypes.h"
#include <array>

namespace SimEco{
    

    class Specie{
      public:
        static uint _nSpecies;
        uint _name;
        
        array<NicheValue, NUM_ENV_VARS> niche;        //niche of the specie

        //NUMCell *celula_ptr;        //pointer to current Cell
        uint *celulas_Idx;        //indice das celulas que esta presente
        uint celulas_IdxSize;
        float curSize;          //number of members/population;    Mas pra que float???  10.5 animais?
        float growth;           //taxa de crescimento

        //Capacity of dispersion over geographic distance, river barriers and topographic heterogeneity
        Dispersion dispCap;

        //ideia para achar espécie, um MAP

        //criação de uma espécie numa única célula
        Specie(array<NicheValue, NUM_ENV_VARS> niche, Dispersion dispCapacity, uint CellIdx);
        //criação de uma especie já espalhada por várias células
        Specie(array<NicheValue, NUM_ENV_VARS> niche, Dispersion dispCapacity, uint cellIdxs[], uint cellIdxsSize);
        
        
        //usar um array de bits de comprimento fixo, tamanho = total de células na grid
        
        //retorna se já está ocupando uma celula, -1 se nao estiver ou índice dessa célula no vetor de celulas ocupadas ( se estiver)
        long occupingCell(uint cellIdx);

        Specie();
        ~Specie();
        
    };

}

#endif