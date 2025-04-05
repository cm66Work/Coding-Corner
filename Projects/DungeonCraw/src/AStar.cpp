#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include "AStar.h"


std::vector<Vector2Int> AStarPathfinding(
    const std::vector<std::vector<int>>& grid,
    const Vector2Int& start,
    const Vector2Int& goal
) {
    int rows = grid.size(), cols = grid[0].size();
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    std::vector<std::vector<Vector2Int>> cameFrom(rows, std::vector<Vector2Int>(cols, {-1, -1}));

    auto heuristic = [&](Vector2Int a, Vector2Int b) {
        return std::abs(a.x - b.x) + std::abs(a.y - b.y);
    };

    auto cmp = [](const Node& a, const Node& b) { return a.f() > b.f(); };
    std::priority_queue<Node, std::vector<Node>, decltype(cmp)> openSet(cmp);
    openSet.push({start, 0, heuristic(start, goal), {-1, -1}});

    std::vector<Vector2Int> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    while (!openSet.empty()) {
        Node current = openSet.top(); openSet.pop();
        Vector2Int p = current.position;

        if (visited[p.x][p.y]) continue;
        visited[p.x][p.y] = true;
        cameFrom[p.x][p.y] = current.parent;

        if (p == goal) {
            std::vector<Vector2Int> path;
            for (Vector2Int at = goal; at.x != -1; at = cameFrom[at.x][at.y])
                path.push_back(at);
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (Vector2Int d : directions) {
            int nx = p.x + d.x, ny = p.y + d.y;
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 0 && !visited[nx][ny]) {
                openSet.push({{nx, ny}, current.g + 1, heuristic({nx, ny}, goal), p});
            }
        }
    }

    return {}; // No path found
}