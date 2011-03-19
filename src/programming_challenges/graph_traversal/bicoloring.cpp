#include <iostream>
#include <fstream>
#include <utility>
#include <map>
#include <string>
#include <stdexcept>

const unsigned int MAXV = 100;
const unsigned int MAXDEGREE = 50;
using namespace std;

/**
 * An adjancency list representation of a graph.
 */
class graph {
public:
    // Contains the edge information for a vertex
    int edges[MAXV+1][MAXDEGREE];

    // Number of edges on a vertex
    int degree[MAXV+1];

    // Number of vertices in the graph
    int nvertices;

    // Number of edges in the graph
    int nedges;

    /**
     * Constructor
     */
    graph() {
        nvertices = 0;
        nedges    = 0;

        for (int i = 0; i <= MAXV; i++) {
            degree[i] = 0;
        }
    }

    /**
     * Insert an edge into an undirected graph.
     */
    void insert_edge(int x, int y) {
        if ((degree[x] > MAXDEGREE) || (degree[y] > MAXDEGREE)) {
            throw out_of_range("exceeded max degree");
        }

        // connect x to y
        edges[x][degree[x]] = y;
        degree[x]++;

        // connect y to x
        edges[y][degree[y]] = x;
        degree[y]++;
    }

    void print_info() {
        cout << "V: " << nvertices << " E: " << nedges << endl;
    }

    void print_graph() {
        for (int i = 0; i < nvertices; i++) {
            cout << i << ":";
            for (int j = 0; j < degree[i]; j++) {
                cout << " " <<  edges[i][j];
            }
            cout << endl;
        }
    }

    /**
     * Search related functions
     */
    bool processed[MAXV];
    bool discovered[MAXV];
    int parent[MAXV];
    bool finished;

    /**
     * Initialize the various state used for
     * searching.
     */
    void intialize_search()
    {
        for (int i = 0; i < MAXV; i++) {
            processed[i]  = false;
            discovered[i] = false;
            parent[i] = -1;
        }
    }

    /**
     * Depth First Search of the Graph
     */
    void dfs(int v)
    {
        discovered[v] = true;
        process_vertex(v);

        for (int i = 0; i < degree[v]; i++) {
            int successor_vertex = edges[v][i];
            if (valid_edge(edges[v][i])) {
                if (!discovered[v]) {
                    // This vertex was not discovered before.
                    parent[successor_vertex] = v;
                    dfs(successor_vertex);
                } else {
                    if (!processed[successor_vertex]) {
                        process_edge(v, successor_vertex);
                    }
                }
            }

            if (finished) 
                return;
        }

        processed[v] = true;
    }

    void process_vertex(int v) 
    {
        cout << "Processed vertex " << v << endl; 
    }

    void process_edge(int x, int y)
    {
        if (parent[x] == y) {
            cout << "Processed tree edge " << x << ", " << y << endl;
        } else {
            cout << "Processed back edge " << x << ", " << y << endl;
        }
    }

    bool valid_edge(int e) 
    {
        return true;
    }
}; 

int main(int argc, char** argv)
{
    if (argc > 1) {
        ifstream ifs(argv[1]);

        while (ifs.good()) {
            graph g;

            // Read vertex num
            ifs >> g.nvertices;
            if (g.nvertices == 0) {
                return 0;
            }

            // Read edge num
            ifs >> g.nedges;

            // Read edges
            for (int i = 0; i < g.nedges; i++) {
                int x;
                int y;
                ifs >> x;
                ifs >> y;
                g.insert_edge(x,y);
            }

            g.print_info();
            g.print_graph();

            g.intialize_search();
            g.dfs(0);
        }

        ifs.close();

    }

    return 0;
}
