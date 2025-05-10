#include "graph.hpp"
#include <iostream>
#include <stack>
#include <set>

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

    // Exercice 2

    void Graph::WeightedGraph::print_DFS(int const start) const
    {
        std::stack<int> stack;
        std::set<int> visited;

        stack.push(start);

        std::cout << "Visited nodes: ";

        while (!stack.empty()) 
        {
            int current = stack.top();
            stack.pop();

            if (visited.find(current) == visited.end()) 
            {
                std::cout << current << " ";
                visited.insert(current);

                if (adjacency_list.find(current) != adjacency_list.end())
                {
                    for (auto const& edge : adjacency_list.find(current)->second)
                    {
                        if (visited.find(edge.to) == visited.end())
                        {
                            stack.push(edge.to);
                        }
                    }
                }
            }
        }
        std::cout << std::endl;
    }

    void Graph::WeightedGraph::print_BFS(int const start) const
    {
        std::queue<int> queue;
        std::set<int> visited;

        queue.push(start);
        visited.insert(start);

        std::cout << "Visited nodes: ";

        while (!queue.empty()) 
        {
            int current = queue.front();
            queue.pop();

            std::cout << current << " ";

            auto it = adjacency_list.find(current);
            if (it != adjacency_list.end())
            {
                for (auto const& edge : it->second)
                {
                    if (visited.find(edge.to) == visited.end())
                    {
                        queue.push(edge.to);
                        visited.insert(edge.to);
                    }
                }
            }
        }
        std::cout << std::endl;
    }

    void Graph::WeightedGraph::DFS(int const start, std::function<void(int const)> const& callback) const
    {
        std::stack<int> stack;
        std::set<int> visited;

        stack.push(start);

        while (!stack.empty())
        {
            int current = stack.top();
            stack.pop();

            if (visited.find(current) == visited.end())
            {
                callback(current);
                visited.insert(current);

                auto it = adjacency_list.find(current);
                if (it != adjacency_list.end())
                {
                    for (auto const& edge : it->second)
                    {
                        if (visited.find(edge.to) == visited.end())
                        {
                            stack.push(edge.to);
                        }
                    }
                }
            }
        }
    }
}