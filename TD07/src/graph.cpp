#include "graph.hpp"
#include <iostream>

// Exercice 1

void WeightedGraph::add_vertex(int const id)
{
    if (adjacency_list.find(id) == adjacency_list.end())
    {
        adjacency_list[id] = {};
    }
}

void WeightedGraph::add_directed_edge(int const from, int const to, float const weight = 1.0f)
{
    add_vertex(from);
    add_vertex(to);
    adjacency_list[from].push_back({to, weight});
}

void WeightedGraph::add_undirected_edge(int const from, int const to, float const weight = 1.0f)
{
    add_directed_edge(from, to, weight);
    add_directed_edge(to, from, weight);
}
