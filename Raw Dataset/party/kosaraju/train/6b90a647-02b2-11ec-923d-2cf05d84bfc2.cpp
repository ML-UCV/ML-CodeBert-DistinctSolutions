#include <stdio.h>
#include <cstring>
#include <vector>






using namespace std;



class TKosarajuGraph

{

    protected:

        int m_iLength;

        int Non (int X);

    public:

        void Kosaraju ();

        void ReadData (FILE * fIn);



        int m_vSolution[200005 ];



        int GetLength();

    private:

        int m_vTSort[200005 ];



        void DFM (int X);

        void DFP (int X);



        vector <int> m_vGraph[200005 ], m_vGraphT[200005 ];

        bool m_vUsed[200005 ];

};





int TKosarajuGraph::GetLength()

{

    return m_iLength;

}



int TKosarajuGraph::Non (int X)

{

    if (X<=m_iLength)

    {

        return X+m_iLength;

    }

    return X-m_iLength;

}



void Print (TKosarajuGraph * objGraph)

{

    FILE * fOut = fopen("party.out", "w");



    for (int i=1; i<=objGraph->GetLength(); ++i)

    {

        objGraph->m_vSolution[0] +=objGraph->m_vSolution[i];

    }

    fprintf (fOut,"%d\n", objGraph->m_vSolution[0]);

    for (int i=1; i<=objGraph->GetLength(); ++i)

    {

        if (objGraph->m_vSolution[i]!=0)

        {

            fprintf (fOut,"%d\n", i);

        }

    }



}



void TKosarajuGraph::ReadData (FILE * fIn)

{

    int M;

    fscanf (fIn,"%d %d", &m_iLength, &M);

    for (; M>0; --M)

    {

        int X, Y, iType;

        fscanf (fIn,"%d %d %d", &X, &Y, &iType);

        if (iType==0)

        {

            m_vGraph[Non (X)].push_back (Y);

            m_vGraph[Non (Y)].push_back (X);

            m_vGraphT[X].push_back (Non (Y));

            m_vGraphT[Y].push_back (Non (X));

        }

        if (iType==1)

        {

            m_vGraph[Non (X)].push_back (Non (Y));

            m_vGraph[Y].push_back (X);

            m_vGraphT[Non (Y)].push_back (Non (X));

            m_vGraphT[X].push_back (Y);

        }

        if (iType==2)

        {

            m_vGraph[Non (Y)].push_back (Non (X));

            m_vGraph[X].push_back (Y);

            m_vGraphT[Non (X)].push_back (Non (Y));

            m_vGraphT[Y].push_back (X);

        }

        if (iType==3)

        {

            m_vGraph[X].push_back (Non (Y));

            m_vGraph[Y].push_back (Non (X));

            m_vGraphT[Non (X)].push_back (Y);

            m_vGraphT[Non (Y)].push_back (X);

        }

    }

}



void TKosarajuGraph::DFP (int X)

{

    m_vUsed[X]=true;

    for (vector <int> :: iterator V=m_vGraph[X].begin (); V!=m_vGraph[X].end (); ++V)

    {

        if (!m_vUsed[*V])

        {

            DFP (*V);

        }

    }

    m_vTSort[++m_vTSort[0]]=X;

}



void TKosarajuGraph::DFM (int X)

{

    m_vUsed[X]=true;

    m_vSolution[Non (X)]=1;

    for (vector <int> :: iterator V=m_vGraphT[X].begin (); V!=m_vGraphT[X].end (); ++V)

    {

        if (!m_vUsed[*V])

        {

            DFM (*V);

        }

    }

}



void TKosarajuGraph::Kosaraju ()

{

    for (int i=1; i<=this->m_iLength+this->m_iLength; ++i)

    {

        if (!m_vUsed[i])

        {

            DFP (i);

        }

    }

    memset (m_vUsed, 0, sizeof (m_vUsed));

    for (int i=m_vTSort[0]; i>0; --i)

    {

        if (!m_vUsed[m_vTSort[i]] and !m_vUsed[Non (m_vTSort[i])])

        {

            DFM (m_vTSort[i]);

        }

    }

}



int main()

{

    TKosarajuGraph * objGraph = new TKosarajuGraph();



    FILE * fIn = fopen("party.in","r");

    objGraph->ReadData (fIn);

    objGraph->Kosaraju ();

    Print (objGraph);



    return 0;

}
