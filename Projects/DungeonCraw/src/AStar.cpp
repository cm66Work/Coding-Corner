#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include "AStar.h"


std::vector<Point> AStarPathfinding(
    const std::vector<std::vector<int>>& grid,
    const Point& start,
    const Point& goal
) {
    int rows = grid.size(), cols = grid[0].size();
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    std::vector<std::vector<Point>> cameFrom(rows, std::vector<Point>(cols, {-1, -1}));

    auto heuristic = [&](Point a, Point b) {
        return std::abs(a.x - b.x) + std::abs(a.y - b.y);
    };

    auto cmp = [](const Node& a, const Node& b) { return a.f() > b.f(); };
    std::priority_queue<Node, std::vector<Node>, decltype(cmp)> openSet(cmp);
    openSet.push({start, 0, heuristic(start, goal), {-1, -1}});

    std::vector<Point> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    while (!openSet.empty()) {
        Node current = openSet.top(); openSet.pop();
        Point p = current.position;

        if (visited[p.y][p.x]) continue;
        visited[p.y][p.x] = true;
        cameFrom[p.y][p.x] = current.parent;

        if (p == goal) {
            std::vector<Point> path;
            for (Point at = goal; at.x != -1; at = cameFrom[at.y][at.x])
                path.push_back(at);
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (Point d : directions) {
            int nx = p.x + d.x, ny = p.y + d.y;
            if (nx >= 0 && ny >= 0 && nx < cols && ny < rows && grid[ny][nx] == 0 && !visited[ny][nx]) {
                openSet.push({{nx, ny}, current.g + 1, heuristic({nx, ny}, goal), p});
            }
        }
    }

    return {}; // No path found
}