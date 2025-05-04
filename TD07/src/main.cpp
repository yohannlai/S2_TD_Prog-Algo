#include "graph.cpp"

int main()
{
    std::vector<std::vector<int>> matrix = {
        {0, 2, 1, 0, 3},
        {2, 0, 4, 0, 0},
        {1, 4, 0, 5, 1},
        {0, 0, 5, 0, 2},
        {3, 0, 1, 2, 0}
    };

    Graph::WeightedGraph graph_from_matrix = Graph::build_from_adjacency_matrix(matrix);

    Graph::WeightedGraph graph_manual;
    // Pas besoin d'ajouter les sommets manuellement, ils seront ajoutés automatiquement lors de l'ajout des arêtes
    graph_manual.add_undirected_edge(0, 1, 2.0f);
    graph_manual.add_undirected_edge(0, 2, 1.0f);
    graph_manual.add_undirected_edge(0, 4, 3.0f);
    graph_manual.add_undirected_edge(1, 2, 4.0f);
    graph_manual.add_undirected_edge(2, 3, 5.0f);
    graph_manual.add_undirected_edge(2, 4, 1.0f);
    graph_manual.add_undirected_edge(3, 4, 2.0f);

    if (graph_from_matrix == graph_manual) 
    {
        std::cout << "Les deux graphes sont identiques." << std::endl;
    }
    else 
    {
        std::cout << "Les deux graphes sont différents." << std::endl;
    }

    return 0;
}