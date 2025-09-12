#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

using ll = long long;

vector<int> unionFind;

class Edge {
public:
    ll pos;
    ll start;
    ll end;
    ll index;
    
    Edge(ll pos, ll start, ll end, ll idx) 
        : pos(pos), start(start), end(end), index(idx) {}
};

int findRoot(int x) {
    if (unionFind[x] == x) {
        return x;
    }
    unionFind[x] = findRoot(unionFind[x]);
    return unionFind[x];
}

void unionSets(int x, int y) {
    int rootX = findRoot(x);
    int rootY = findRoot(y);
    
    if (rootX != rootY) {
        if (rootX < rootY) {
            swap(rootX, rootY);
        }
        unionFind[rootY] = rootX;
    }
}

int main() {
    int numStones;
    
    while (cin >> numStones) {
        unionFind.resize(numStones);
        vector<tuple<int, int, int, int>> stones;
        vector<Edge> verticalEdges, horizontalEdges;
        
        // Initialize union-find and read stone data
        for (int i = 0; i < numStones; i++) {
            int x, y, width, height;
            cin >> x >> y >> width >> height;
            
            unionFind[i] = i;
            stones.push_back({x, y, width, height});
            
            // Create vertical edges (left and right boundaries)
            verticalEdges.push_back(Edge(x, y, y + height, i));
            verticalEdges.push_back(Edge(x + width, y, y + height, i));
            
            // Create horizontal edges (bottom and top boundaries)
            horizontalEdges.push_back(Edge(y, x, x + width, i));
            horizontalEdges.push_back(Edge(y + height, x, x + width, i));
        }
        
        // Sort edges by position, then by start point
        auto edgeComparator = [](const Edge& a, const Edge& b) {
            if (a.pos == b.pos) {
                return a.start < b.start;
            }
            return a.pos < b.pos;
        };
        
        sort(verticalEdges.begin(), verticalEdges.end(), edgeComparator);
        sort(horizontalEdges.begin(), horizontalEdges.end(), edgeComparator);
        
        // Check for vertical adjacency (left-right neighbors)
        for (int i = 0; i < verticalEdges.size(); i++) {
            for (int j = i + 1; j < verticalEdges.size() && 
                 verticalEdges[i].pos == verticalEdges[j].pos; j++) {
                if (verticalEdges[i].end >= verticalEdges[j].start) {
                    unionSets(verticalEdges[i].index, verticalEdges[j].index);
                }
            }
        }
        
        // Check for horizontal adjacency (top-bottom neighbors)
        for (int i = 0; i < horizontalEdges.size(); i++) {
            for (int j = i + 1; j < horizontalEdges.size() && 
                 horizontalEdges[i].pos == horizontalEdges[j].pos; j++) {
                if (horizontalEdges[i].end >= horizontalEdges[j].start) {
                    unionSets(horizontalEdges[i].index, horizontalEdges[j].index);
                }
            }
        }
        
        // Calculate total area for each connected component
        vector<ll> componentArea(numStones, 0);
        for (int i = 0; i < numStones; i++) {
            int componentRoot = findRoot(i);
            ll stoneArea = get<2>(stones[i]) * get<3>(stones[i]); // width * height
            componentArea[componentRoot] += stoneArea;
        }
        
        // Output the largest area
        cout << *max_element(componentArea.begin(), componentArea.end()) << "\n";
    }
    
    return 0;
}