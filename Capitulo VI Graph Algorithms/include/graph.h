#ifndef GRAPH_H
#define GRAPH_H
#include "nodo.h"

class graph
{
    public:
        graph(int cant);
        vector<nodo> m_nodos;

        vector<vector<int> > m_matrix;

        void add_arista(int a1, int a2,int peso);

    protected:
    private:
};

#endif // GRAPH_H
