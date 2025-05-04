#include "graph.hpp"
#include <iostream>

// Exercice 1

namespace Graph
{
    void WeightedGraph::add_vertex(int const id)
    {
        if (adjacency_list.find(id) == adjacency_list.end())
        {
            adjacency_list[id] = {};
        }
    }

    void WeightedGraph::add_directed_edge(int const from, int const to, float const weight)
    {
        add_vertex(from);
        add_vertex(to);
        adjacency_list[from].push_back({to, weight});
    }

    void WeightedGraph::add_undirected_edge(int const from, int const to, float const weight)
    {
        add_directed_edge(from, to, weight);
        add_directed_edge(to, from, weight);
    }

    WeightedGraph build_from_adjacency_matrix(std::vector<std::vector<int>> const& adjacency_matrix)
    {
        WeightedGraph graph;
        int n = adjacency_matrix.size();
        for (int from = 0; from < n; from++)
        {
            for (int to = 0; to < adjacency_matrix[from].size(); to++)
            {
                float weight = adjacency_matrix[from][to];
                if (weight != 0.0f)
                {
                    graph.add_directed_edge(from, to, weight);
                }
            }
        }

        return graph;
    }
}

