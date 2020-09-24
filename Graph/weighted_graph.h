#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>

template <typename T>
struct Edge {
	std::pair<T, T> v_pair;
	int weight;
};

template <typename T>
std::pair<T, T> reverse_pair(const std::pair<T, T>& p) {
	return std::make_pair(p.second, p.first);
}

template <typename T>
class WeightedGraph {

private:
	std::unordered_map< 
		T, 
		std::vector<Edge<T>> 
	> adjList;

public:

	WeightedGraph() = default;

	WeightedGraph(const std::vector<Edge<T>>& edges) {
		for (const auto& edge : edges) {
			adjList[edge.v_pair.first].push_back(edge);
			adjList[edge.v_pair.second].push_back(
				{ reverse_pair(edge.v_pair), edge.weight }
			);
		}
	}

	// return true if such edge is already exist
	bool exist(const Edge<T>& edge) const {
		try {
			return
				std::count_if(
					adjList.at(edge.v_pair.first).begin(),
					adjList.at(edge.v_pair.first).end(),
					[edge](const Edge& e)
					{ return edge.v_pair == e.v_pair; }
			) != 0;
		}
		catch (...) { return false; }
	}

	// will return false if such edge is already exist
	bool insert(const Edge<T>& edge) {
		
		if (exist(edge)) 
			return false;
		
		adjList[edge.v_pair.first].push_back(edge);
		adjList[edge.v_pair.second].push_back(
			{ reverse_pair(edge.v_pair), edge.weight }
		);
		
		return true;
	}

	void print_edges() const {
		for (const auto& item : adjList) {
			for (const auto& edge : item.second) {
				std::cout << edge.v_pair.first << " - "
					<< edge.v_pair.second << "\tweight: " << edge.weight << "\n";
			}
		}
	}

	void print_vertexes() const {
		for (const auto& item : adjList)
			std::cout << item.first << "\n";
	}

};


