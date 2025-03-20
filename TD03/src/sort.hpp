#pragma once

#include <vector>
#include <algorithm>

bool is_sorted(std::vector<int> const& vec);

void print_vector(const std::vector<int> & vec);
void print_vector(const std::vector<float> & vec);

void bubble_sort(std::vector<int> & vec);

size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot);
void quick_sort(std::vector<float> & vec, size_t const left, size_t const right);
void quick_sort(std::vector<float> & vec);