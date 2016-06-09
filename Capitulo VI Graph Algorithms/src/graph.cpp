#include "graph.h"

graph::graph(int cant)
{
    m_matrix.resize(cant);
    for(int i=0;i<cant;i++)
    {
        m_matrix[i].resize(cant);
    }
}



void graph::add_arista(int a1, int a2, int peso)
{
    m_matrix[a1][a2]=peso;

}
