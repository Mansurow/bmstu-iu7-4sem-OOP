#ifndef EDGES_H
#define EDGES_H

#include <cstdio>
#include <cstdlib>

#include "points.h"
#include "errors.h"

struct edge
{
    int first_point;
    int second_point;
};

using edge_t = struct edge;

struct edges
{
    edge_t *array_edges;
    int size;
};

using edges_t = struct edges;

error_t allocate_edges(edges_t &edges);

void free_edges(edges_t &edges);

void edges_default(edges_t &edges);

error_t fread_amount_edges(edges_t &edges, FILE *fin);

error_t fread_inf_about_edges(edges_t &edges, FILE *fin);

error_t fread_all_edges(edges_t &edges, FILE *fin);

error_t fread_edge(edge_t &edge, FILE *fin);

error_t save_all_edges(const edges_t &edges, FILE *fin);

error_t save_edge(const edge_t &edge, FILE *fin);

#endif // EDGES_H
